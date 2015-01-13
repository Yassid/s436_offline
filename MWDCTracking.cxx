#include "MWDCTracking.h"
#include "TFRSParameter.h"
#include "TMinuit.h"
#include "TMatrixFSym.h"

MWDCTracking::MWDCTracking(){
  //
  max_hit_combination=10;// initial value. can be changed
  min_plane_enabled=6;   // initial value. can be changed
  min_uv_plane_enabled=5;   // initial value. can be changed
  tracking_status=-1;
  chi2_track=99999.9; x_track=-99999.9; y_track=-99999.9; a_track=-99999.9; b_track=-99999.9;  
  chi2_temp=99999.9; x_temp=-99999.9; y_temp=-99999.9; a_temp=-99999.9; b_temp=-99999.9;
  for(int i_plane=0;i_plane<16;i_plane++){
    LR_fixed[i_plane]=0;
    numhit[i_plane]=0; // <<== this must be here
    plane_enabled_temp[i_plane]=0;
    plane_enabled_track[i_plane]=0;
    theta[i_plane] =-99999.9;
    zplane[i_plane]=-99999.9;
    residual_track[i_plane]=-99999.9;
    residual_temp[i_plane]=-99999.9;
    time_wMaxToT[i_plane] = -9999;
    tot_max[i_plane] = -99999.9;
    for(int i_hit=0; i_hit<64; i_hit++){
      length[i_plane][i_hit]  = -99999.9;
      wirepos[i_plane][i_hit] = -99999.9;
    }
  }
}

MWDCTracking::~MWDCTracking(){}


//--------------------------------------
//     AMSC tracking fit functions 
//
// par[i]  >>  i: 0:x0, 1:a0, 2:y0, 3:b0 /////
// temp[i_plane][m] >>  m: 0:theta, 1:wpos, m:zplane, 3:drift length, 
//                         4:factor in chi2 (=1./(dof*sigma*sigma), or 0 if plane disabled)
//

static double temp[16][5]={}; 

double distance_wire_track(int i_plane, Float_t par0, Float_t par1, Float_t par2, Float_t par3){
  return (abs(par0*cos(temp[i_plane][0])+par2*sin(temp[i_plane][0]) -temp[i_plane][1] + (par1*cos(temp[i_plane][0])+par3*sin(temp[i_plane][0]))*temp[i_plane][2]))/sqrt(1.0+pow((par1*cos(temp[i_plane][0])+par3*sin(temp[i_plane][0])), 2)) ;
}

double drift_length(int i_plane){
  return temp[i_plane][3];
}

void CylindricalChi2Funct(int& nDim, double* gout, double& result, double par[], int flg){
  double ans;  ///// par >> 0:x0, 1:y0, 2:a0, 3:b0 /////
  ans = 0.0;
  for(int i_plane=0; i_plane<16; i_plane++){
    if(0.0!=temp[i_plane][4]){
      ans += temp[i_plane][4] * pow((distance_wire_track(i_plane,par[0],par[1],par[2],par[3]) - drift_length(i_plane)), 2) ;
    }
  }
  result = ans;
}


//-------------------------------------------------
//   Functions for MWDCTracking::Tracking

void MWDCTracking::StoreHit(int i_plane, Float_t wirepos_hit, Float_t length_hit, Float_t tot_hit, Float_t time_hit,  Float_t theta_hit, Float_t zplane_hit){
  if(0<= i_plane && i_plane<16){
    length[i_plane][ (numhit[i_plane]) ]  = length_hit  ;
    wirepos[i_plane][ (numhit[i_plane]) ] = wirepos_hit ;
    tot[i_plane][ (numhit[i_plane]) ]  = tot_hit  ;
    time[i_plane][ (numhit[i_plane]) ]  = time_hit  ;
    theta[i_plane]  = theta_hit  ;
    zplane[i_plane] = zplane_hit ;
    numhit[i_plane]++;
  }else{
    cout << "Wrong i_plane value (" << i_plane <<") is set..." << endl;
  }
  return ;
}

void MWDCTracking::SetMaxHitCombination(int setvalue){
  max_hit_combination = setvalue;
  return ;
}

void MWDCTracking::SetMinPlaneEnebaled(int setvalue){
  min_plane_enabled = setvalue;
  return ;
}
  


//-------------------------------------------------
//   Functions for MWDCTracking::Tracking

int MWDCTracking::Tracking(void){ 
	// 1: done
	// 0: give up because of too many combination
	//-1: give up because # of planes with hits is small.

	//------ set plane_enabled[] ----
	for(int i_plane=0; i_plane<16; i_plane++){
		if(0<numhit[i_plane]){
			plane_enabled_temp[i_plane]=1; // presently, just require all planes with hits to participate
		}
	}
	
	//------ condition for giving up -----
	if(NumHitCombinationTemp()>max_hit_combination){
	  //	cout << "too many combination... "<< endl;
		return 0;
	}

	if(NumEnabledPlaneTemp()<min_plane_enabled){
	  //cout << "num of hit planes is not enough... "<< endl;
		return -1;	
	}
	
	//------try all combination by inverse matrix method------
	chi2_track = 999999.9;
	SetHitCombinationTemp0();
	for(int i=0; i<NumHitCombinationTemp(); i++){
	  SetLRCombinationTemp0();
	  for(int j=0; j<NumLRCombinationTemp(); j++){
	    int status_tracking_matrix;
	    status_tracking_matrix = TrackingInverseMatrix();
	    if(1!=status_tracking_matrix){
	      cout << "enabled plane choice seems bad..."<< endl;
	      exit(-1);
	    }
	    if(chi2_temp < chi2_track){ // overwrite result (*_track)
	      x_track = x_temp; 
	      y_track = y_temp;
	      a_track = a_temp;
	      b_track = b_temp;
	      chi2_track = chi2_temp;
	      CopyHitCombination(i_hit_used_temp, i_hit_used_track);
	      CopyLRCombination(LR_used_temp, LR_used_track);
	      CopyPlaneEnabled(plane_enabled_temp, plane_enabled_track);
	      for(int i_plane=0;i_plane<16; i_plane++){
		residual_track[i_plane] = residual_temp[i_plane];
	      }
	    }
	    LRCombinationTempIncrement(); // _temp is incremented (in enabled planes)
	  }//j-end
	  HitCombinationTempIncrement();// _temp is incremented (in enabled planes)
	}//i-end
       
	
	/* // comment out for cosmic test

	// ------- fit again (chi2 calculation = cylindrically) -------
        // ------- use previous result for initial values.
	//
	x_temp = x_track; 
	y_temp = y_track;
	a_temp = a_track;
	b_temp = b_track;
	CopyHitCombination(i_hit_used_track, i_hit_used_temp);
	CopyLRCombination(LR_used_track, LR_used_temp);
	CopyPlaneEnabled(plane_enabled_track, plane_enabled_temp);
	TrackingFitCylindrical();
	x_track = x_temp; 
	y_track = y_temp;
	a_track = a_temp;
	b_track = b_temp;
	cout << "chi2_before=" << chi2_track <<"   / chi2_new="<< chi2_temp <<endl;  
	chi2_track = chi2_temp;
	CopyHitCombination(i_hit_used_temp, i_hit_used_track);
	CopyLRCombination(LR_used_temp, LR_used_track);
	CopyPlaneEnabled(plane_enabled_temp, plane_enabled_track);
	for(int i_plane=0;i_plane<16; i_plane++){
	  residual_track[i_plane] = residual_temp[i_plane];
	}
	*/
	

	return 1;
}


// tracking method with FitCylindrical method
int MWDCTracking::Tracking_FitCylindrical(void){ 
	// 1: done
	// 0: give up because of too many combination
	//-1: give up because # of planes with hits is small.

	//------ set plane_enabled[] ----

	for(int i_plane=0; i_plane<16; i_plane++){
		if(0<numhit[i_plane]){
			plane_enabled_temp[i_plane]=1; // presently, just require all planes with hits to participate
		}
	}	
	//------ condition for giving up -----
	if(NumHitCombinationTemp()>max_hit_combination){
	  //	cout << "too many combination... "<< endl;
		return 0;
	}
	if(NumEnabledPlaneTemp()<min_plane_enabled){
	  //cout << "num of hit planes is not enough... "<< endl;
		return -1;	
	}
	
	//------try all combination by FitCylindrical method------
	chi2_track = 999999.9;
	SetHitCombinationTemp0();
	for(int i=0; i<NumHitCombinationTemp(); i++){
	  SetLRCombinationTemp0();
	  //for(int j=0; j<NumLRCombinationTemp(); j++){
	  int status_tracking_matrix;
	  int status_tracking_fit = TrackingFitCylindrical();
	  if(1!=status_tracking_fit){
	      cout << "enabled plane choice seems bad..."<< endl;
	      exit(-1);
	    }
	  if(chi2_temp < chi2_track){ // overwrite result (*_track)
	    x_track = x_temp; 
	    y_track = y_temp;
	    a_track = a_temp;
	    b_track = b_temp;
	    chi2_track = chi2_temp;
	    CopyHitCombination(i_hit_used_temp, i_hit_used_track);
	    CopyPlaneEnabled(plane_enabled_temp, plane_enabled_track);
	    for(int i_plane=0;i_plane<16; i_plane++){
	      residual_track[i_plane] = residual_temp[i_plane];
	    }       
	  }
	  HitCombinationTempIncrement();// _temp is incremented (in enabled planes)
	}//i-end       		      
	return 1;
}

int MWDCTracking::Tracking_LRfixed(void){ 
  //TMWDCParameter* mwdc = (TMWDCParameter*) GetParameter("MWDCPar");
	// 1: done
	// 0: give up because of too many combination
	//-1: give up because # of planes with hits is small.
	//-2: give up because # of uv planes with hits is small.

	//------ set plane_enabled[] ----
  int nuvhit=0;
  for(int i_plane=0; i_plane<16; i_plane++){
    if(0<numhit[i_plane]){
      plane_enabled_temp[i_plane]=1; // presently, just require all planes with hits to participate	   
      if(i_plane>3&&i_plane<8) nuvhit++;
      if(i_plane>11&&i_plane<16) nuvhit++;
    }
  }
  //	plane_enabled_temp[2]=0; plane_enabled_temp[3]=0; plane_enabled_temp[8]=0; plane_enabled_temp[9]=0;
  
  //------ condition for giving up -----
  if(NumHitCombinationTemp()>max_hit_combination){
    //	cout << "too many combination... "<< endl;
    return 0;
  }
  
  if(NumEnabledPlaneTemp()<min_plane_enabled){
    //	cout << "num of hit planes is not enough... "<< endl;
    return -1;	
  }
  
  if(nuvhit<min_uv_plane_enabled){
    //	cout << "num of hit planes is not enough... "<< endl;
    return -2;	
  }
  
  //------try all combination by inverse matrix method------
  chi2_track = 999999.9;
  SetHitCombinationTemp0();
  for(int i=0; i<NumHitCombinationTemp(); i++){
    SetLRCombinationTemp0();
#if 1
    bool WRONGCOMB=false;
    int plane_enabled_save[16];
    CopyPlaneEnabled(plane_enabled_temp, plane_enabled_save);
    for(int i_pair=0;i_pair<8;i_pair++){
      if(numhit[i_pair*2]>0&&numhit[i_pair*2+1]>0&&false==LR_fixed[i_pair*2]&&false==LR_fixed[i_pair*2+1]){
	double tmp1=wirepos[i_pair*2][i_hit_used_temp[i_pair*2]];
	double tmp2=wirepos[i_pair*2+1][i_hit_used_temp[i_pair*2+1]];
	//if(length[i_pair*2][i_hit_used_temp[i_pair*2]]<0.2||
	//length[i_pair*2+1][i_hit_used_temp[i_pair*2+1]]<0.2)		
	//continue;	      
	// if(0||i_pair!=0&&i_pair!=1&&i_pair!=4&&i_pair!=5)
	// 	continue;
	double addlength=length[i_pair*2][i_hit_used_temp[i_pair*2]];
	addlength+=length[i_pair*2+1][i_hit_used_temp[i_pair*2+1]];
	if( addlength>4.){
	  plane_enabled_temp[i_pair*2]=0;
	  plane_enabled_temp[i_pair*2+1]=0;
	  // WRONGCOMB=true;
	  // break;
	}
	if(fabs(tmp1-tmp2)<=4.){
	  LR_fixed[i_pair*2]=true;	  
	  LR_fixed[i_pair*2+1]=true;	  
	  plane_enabled_temp[i_pair*2]=1;
	  plane_enabled_temp[i_pair*2+1]=1;
	  if(tmp1-tmp2<0){
	    LR_used_temp[i_pair*2]=0;
	    LR_used_temp[i_pair*2+1]=1;
	  }else{
	    LR_used_temp[i_pair*2]=1;
	    LR_used_temp[i_pair*2+1]=0;
	  }
	}else{
	  plane_enabled_temp[i_pair*2]=0;
	  plane_enabled_temp[i_pair*2+1]=0;
	  //	  WRONGCOMB=true;
	  //	  break;
	}
      }
    }
    if(NumHitCombinationTemp()>max_hit_combination) continue;
    nuvhit=0;
    for(int i_plane=0; i_plane<16; i_plane++){
      if(0<plane_enabled_temp[i_plane]){
	if(i_plane>3&&i_plane<8) nuvhit++;
	if(i_plane>11&&i_plane<16) nuvhit++;
      }
    }    
    if(nuvhit<min_uv_plane_enabled) continue;
    //    if(WRONGCOMB) continue;
#endif

    for(int j=0; j<NumLRCombinationTemp(); j++){
      int status_tracking_matrix;
      status_tracking_matrix = TrackingInverseMatrix();
      if(1!=status_tracking_matrix){
	cout << "enabled plane choice seems bad..."<< endl;
	exit(-1);
      }
      if(chi2_temp < chi2_track){ // overwrite result (*_track)
	x_track = x_temp; 
	y_track = y_temp;
	a_track = a_temp;
	b_track = b_temp;
	chi2_track = chi2_temp;
	CopyHitCombination(i_hit_used_temp, i_hit_used_track);
	CopyLRCombination(LR_used_temp, LR_used_track);
	CopyPlaneEnabled(plane_enabled_temp, plane_enabled_track);
	for(int i_plane=0;i_plane<16; i_plane++){
	  residual_track[i_plane] = residual_temp[i_plane];
	}
      }
      LRCombinationTempIncrement(); // _temp is incremented (in enabled planes)
    }//j-end
    HitCombinationTempIncrement();// _temp is incremented (in enabled planes)
  }//i-end
	
  //if(chi2_track>10000) return -3;
  return 1;
}

int MWDCTracking::ResidualExCalc(void){  
  double w_hit_temp;
  CopyHitCombination(i_hit_used_track, i_hit_used_temp);
  CopyLRCombination(LR_used_track, LR_used_temp);
  CopyPlaneEnabled(plane_enabled_track, plane_enabled_temp);
  for(int i_plane=0;i_plane<16;i_plane++){        
    if(plane_enabled_temp[i_plane]==1){
      plane_enabled_temp[i_plane]=0;
      TrackingInverseMatrix();
      w_hit_temp = wirepos[i_plane][(i_hit_used_temp[i_plane])] + (1.0-2.0*((float)(LR_used_temp[i_plane])))*length[i_plane][(i_hit_used_temp[i_plane])];
      residual_track_ex[i_plane] = ((x_temp+a_temp*zplane[i_plane])*cos(theta[i_plane])+(y_temp+b_temp*zplane[i_plane])*sin(theta[i_plane])-w_hit_temp);
      //for(int j_plane=0;j_plane<16;j_plane++)cout<<" "<<plane_enabled_temp[j_plane]; 
      //cout<<endl;
      //cout<<i_plane<<" "<<residual_woSelfData[i_plane]<<endl;
      plane_enabled_temp[i_plane]=1;
    }
    else residual_track_ex[i_plane] = -99999.9;
  }
}

int MWDCTracking::FindTime_wMaxToT(void){  
  for(int i_plane=0; i_plane<16; i_plane++){
    for(int ihit =0; ihit < numhit[i_plane]; ihit++){
      if(tot[i_plane][ihit]>tot_max[i_plane]){
	tot_max[i_plane] = tot[i_plane][ihit];  
	time_wMaxToT[i_plane] = time[i_plane][ihit];  
      }
    }
  }
  return 1;
}
int MWDCTracking::TrackingInverseMatrix(){ 
	//  1 = done 
	//  0 = no inverse matrix exist
	
	// calculation of matrix elements (note p.63)
        Float_t m00=0.0;
	Float_t m01=0.0;
	Float_t m02=0.0;
	Float_t m03=0.0;
	Float_t m11=0.0;
	Float_t m12=0.0;
	Float_t m13=0.0;
	Float_t m22=0.0;
	Float_t m23=0.0;
	Float_t m33=0.0;
        Float_t v[4] = {0.0, 0.0 ,0.0 ,0.0}; // vector on right-hand side
	Float_t w_hit[16];  
	for(int i_plane=0; i_plane<16; i_plane++){  
		if(1==plane_enabled_temp[i_plane]){
		  w_hit[i_plane] = wirepos[i_plane][(i_hit_used_temp[i_plane])] + (1.0-2.0*((float)(LR_used_temp[i_plane])))*length[i_plane][(i_hit_used_temp[i_plane])];
		  m00 += cos(theta[i_plane])*cos(theta[i_plane]);
		  m01 += zplane[i_plane]*cos(theta[i_plane])*cos(theta[i_plane]);
		  m02 += sin(theta[i_plane])*cos(theta[i_plane]);
		  m03 += zplane[i_plane]*sin(theta[i_plane])*cos(theta[i_plane]);
		  m11 += zplane[i_plane]*zplane[i_plane]*cos(theta[i_plane])*cos(theta[i_plane]);
		  m12 += zplane[i_plane]*sin(theta[i_plane])*cos(theta[i_plane]);
		  m13 += zplane[i_plane]*zplane[i_plane]*sin(theta[i_plane])*cos(theta[i_plane]);
		  m22 += sin(theta[i_plane])*sin(theta[i_plane]);
		  m23 += zplane[i_plane]*sin(theta[i_plane])*sin(theta[i_plane]);
		  m33 += zplane[i_plane]*zplane[i_plane]*sin(theta[i_plane])*sin(theta[i_plane]);
		  v[0] += w_hit[i_plane]*cos(theta[i_plane]);
		  v[1] += w_hit[i_plane]*zplane[i_plane]*cos(theta[i_plane]);
		  v[2] += w_hit[i_plane]*sin(theta[i_plane]);
		  v[3] += w_hit[i_plane]*zplane[i_plane]*sin(theta[i_plane]);
		}
	}
	

	// define matrix, set values
	TMatrixFSym M1(4);
	Float_t *M1_element = M1.GetMatrixArray();
	*(M1_element+(4*0+0)) = m00;
	*(M1_element+(4*0+1)) = m01;
	*(M1_element+(4*0+2)) = m02;
	*(M1_element+(4*0+3)) = m03;
	*(M1_element+(4*1+0)) = m01;
	*(M1_element+(4*1+1)) = m11;
	*(M1_element+(4*1+2)) = m12;
	*(M1_element+(4*1+3)) = m13;
	*(M1_element+(4*2+0)) = m02;
	*(M1_element+(4*2+1)) = m12;
	*(M1_element+(4*2+2)) = m22;
	*(M1_element+(4*2+3)) = m23;
	*(M1_element+(4*3+0)) = m03;
	*(M1_element+(4*3+1)) = m13;
	*(M1_element+(4*3+2)) = m23;
	*(M1_element+(4*3+3)) = m33;
	
	// Invert and check determinant
	Double_t det;
	M1.InvertFast(&det);
	// no inverted matrix
	if(0==det){
	  	chi2_temp = 999999.9;
		return 0;
	}
	
	// calculate (x,a,y,b) and chi2
	x_temp = 0.0; a_temp = 0.0; y_temp = 0.0; b_temp = 0.0;	chi2_temp = 0.0;
	for(int i=0; i<4; i++){
	  x_temp += (*(M1_element+(4*0+i))) * v[i] ;
	  a_temp += (*(M1_element+(4*1+i))) * v[i] ;
	  y_temp += (*(M1_element+(4*2+i))) * v[i] ;
	  b_temp += (*(M1_element+(4*3+i))) * v[i] ;
	}

	Float_t dof;
	dof = (Float_t)(NumEnabledPlaneTemp()-4); // 4 is num. of parameter
	for(int i_plane=0;i_plane<16;i_plane++){
	  if(1==plane_enabled_temp[i_plane]){
	    residual_temp[i_plane] = ((x_temp+a_temp*zplane[i_plane])*cos(theta[i_plane])+(y_temp+b_temp*zplane[i_plane])*sin(theta[i_plane])-w_hit[i_plane]);
	    chi2_temp += pow((residual_temp[i_plane])/(MWDC_RESOLUTION_ASSUMED),2)/dof;
	  }else{
	    residual_temp[i_plane]=99999.9;
	  }
	}
	return 1;	
}
		

int MWDCTracking::TrackingFitCylindrical(void){
  //  1 = done 
  //  0 = fit failed
  // -1 = hit information missing 
	
  Float_t dof;
  dof = (Float_t)(NumEnabledPlaneTemp()-4); // 4 is num. of parameter
  
  //-----Set information in temp[][]-----
  for(int i_plane=0; i_plane<16; i_plane++){
    if(1==plane_enabled_temp[i_plane]){
      temp[i_plane][0] = theta[i_plane];
      temp[i_plane][1] = wirepos[i_plane][i_hit_used_temp[i_plane]];
      temp[i_plane][2] = zplane[i_plane];
      temp[i_plane][3] = length[i_plane][i_hit_used_temp[i_plane]];
      temp[i_plane][4] = 1.0/(dof*(MWDC_RESOLUTION_ASSUMED)*(MWDC_RESOLUTION_ASSUMED));
    }else{
      temp[i_plane][4] = 0.0;
    }
  }
  
  //----Minimization----
  TMinuit minimizer(4);
  minimizer.SetFCN(CylindricalChi2Funct);
  minimizer.SetPrintLevel(-1);
  minimizer.DefineParameter(0,"x0",x_temp,0.01,-300.,300.);
  minimizer.DefineParameter(1,"a0",a_temp,0.01,-2.,2.);
  minimizer.DefineParameter(2,"y0",y_temp,0.01,-300.,300.);
  minimizer.DefineParameter(3,"b0",b_temp,0.01,-2.,2.);
  minimizer.Migrad();
  //minimizer.Release(0);
 
  //------ result -------
  minimizer.GetParameter(0, x_temp, xerr_temp);
  minimizer.GetParameter(1, a_temp, aerr_temp);
  minimizer.GetParameter(2, y_temp, yerr_temp);
  minimizer.GetParameter(3, b_temp, berr_temp);

  //----- residual_temp[], chi2_temp-----
  chi2_temp=0.0;
  for(int i_plane=0; i_plane<16; i_plane++){
    if(1==plane_enabled_temp[i_plane]){
      residual_temp[i_plane] = 1.0 * (distance_wire_track(i_plane,x_temp,a_temp,y_temp,b_temp) - drift_length(i_plane));
      chi2_temp += temp[i_plane][4] * pow(residual_temp[i_plane], 2) ;
    }else{
      residual_temp[i_plane] = 99999.9;
    }
  }

  return 1;
}	



//-------------------------------------------------
//   Functions to treat  
//     plane_enable[], i_hit_used[], LR_used[]

int MWDCTracking::NumEnabledPlaneTemp(){
	int count=0;
	for(int i_plane=0; i_plane<16; i_plane++){
		if(1==plane_enabled_temp[i_plane]){
			count++;
		}
	}
	return count;
}

int MWDCTracking::NumLRCombinationTemp(){
  int count=0;
  for(int i_plane=0; i_plane<16; i_plane++){
    if(1==plane_enabled_temp[i_plane]&&0==LR_fixed[i_plane]){
      count++;
    }
  }
  return (0x0001 << count); // 2^n
}


int MWDCTracking::NumHitCombinationTemp(){
	int count=1;
	for(int i_plane=0; i_plane<16; i_plane++){
		if(1==plane_enabled_temp[i_plane]){
			count*=numhit[i_plane];
		}
	}
	return count;
}


int MWDCTracking::HitCombinationTempIncrement(){ // go to next combination
	// 1 : done
	// 0 : can not increment any more... 
	for(int i_plane=0; i_plane<16; i_plane++){
		if(1==plane_enabled_temp[i_plane]){
			if(i_hit_used_temp[i_plane]==(numhit[i_plane]-1)){
				i_hit_used_temp[i_plane]=0; // (kuriagari) continue 
			}else{
				i_hit_used_temp[i_plane]+=1; 
				return 1;
			}
		}
	}
	return 0; 
}

int MWDCTracking::LRCombinationTempIncrement(){
	// 1 : done
	// 0 : can not increment any more...  
	for(int i_plane=0; i_plane<16; i_plane++){
	  if(0==LR_fixed[i_plane]&&1==plane_enabled_temp[i_plane]){
	    if(1==LR_used_temp[i_plane]){
	      LR_used_temp[i_plane]=0; // kuriagari, continue 
	    }else{
	      LR_used_temp[i_plane]=1; 
	      return 1;
	    }
	  }
	}
	return 0; 
}

void MWDCTracking::SetHitCombinationTemp0(){
	for(int i_plane=0; i_plane<16; i_plane++){
		i_hit_used_temp[i_plane]=0;
	}
}

void MWDCTracking::SetLRCombinationTemp0(){
  for(int i_plane=0; i_plane<16; i_plane++){
    LR_used_temp[i_plane]=0;
  }
  return ;
}
 
void MWDCTracking::CopyHitCombination(int* array_src, int* array_tgt){
  for(int i_plane=0; i_plane<16; i_plane++){
    array_tgt[i_plane] = array_src[i_plane];
  }
  return ;      
}

void MWDCTracking::CopyLRCombination(int* array_src, int* array_tgt){
 for(int i_plane=0; i_plane<16; i_plane++){
    array_tgt[i_plane] = array_src[i_plane];
  }
 return ; 
}

 void MWDCTracking::CopyPlaneEnabled(int* array_src, int* array_tgt){
 for(int i_plane=0; i_plane<16; i_plane++){
    array_tgt[i_plane] = array_src[i_plane];
  }
 return ; 
}


//-----------------
//    Get****()

Float_t MWDCTracking::GetX(void){
	return x_track;
}

Float_t MWDCTracking::GetY(void){
	return y_track;
}

Float_t MWDCTracking::GetA(void){
	return a_track;
}

Float_t MWDCTracking::GetB(void){
	return b_track;
}


Float_t MWDCTracking::GetXError(void){
	return xerr_track;
}

Float_t MWDCTracking::GetYError(void){
	return yerr_track;
}

Float_t MWDCTracking::GetAError(void){
	return aerr_track;
}

Float_t MWDCTracking::GetBError(void){
	return berr_track;
}

Float_t MWDCTracking::GetTime_wMaxToT(int iplane){
	return time_wMaxToT[iplane];
}

int MWDCTracking::GetTrackingStatus(void){
	return tracking_status;
}

Float_t MWDCTracking::GetChi2(void){
	return chi2_track;
}

Float_t MWDCTracking::GetResidual(int i_plane){
         return residual_track[i_plane];
}

Float_t MWDCTracking::GetExclusiveResidual(int i_plane){
         return residual_track_ex[i_plane];
}
 
void MWDCTracking::GetLRCombination(int* lr_combi){
  for(int i_plane=0; i_plane<16; i_plane++){
    lr_combi[i_plane] = LR_used_track[i_plane];
  }
  return ;
}
 
void MWDCTracking::GetHitCombination(int* hit_combi){
   for(int i_plane=0; i_plane<16; i_plane++){
     hit_combi[i_plane] = i_hit_used_track[i_plane];
   }
   return ;
}

int MWDCTracking::GetNumEnabledPlane(void){
  int count=0;
  for(int i_plane=0; i_plane<16; i_plane++){
    if(1==plane_enabled_track[i_plane]){
      count++;
    }
  }
  return count;
}

int MWDCTracking::GetNumLRCombination(void){
  return (0x0001 << GetNumEnabledPlane()); // 2^n
}

int MWDCTracking::GetNumHitCombination(void){
  int count=1;
  for(int i_plane=0; i_plane<16; i_plane++){
    if(1==plane_enabled_track[i_plane]){
      count*=numhit[i_plane];
    }
  }
  return count;
}
