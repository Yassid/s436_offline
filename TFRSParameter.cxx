
#include "TFRSParameter.h"

#include "Riostream.h"



TFRSParameter::TFRSParameter() : TGo4Parameter("FRSParameter") {
  fill_raw_histos = kTRUE;
  //  fill_raw_histos = kFALSE;
  after_run176 = kTRUE;    // flag it off to analyze data before run176
  
  dist_focS2 = 0;
  dist_MW21 = 0; 
  dist_MW22 = 0;
  dist_SC21 = 0;
  dist_SC22 = 0;
  dist_focS4 = 0;
  dist_MW41 = 0;
  dist_MW42 = 0;
  dist_SC41 = 0;
  dist_SC42 = 0;
  dist_SC43 = 0;
  dist_itag_42 = 0;
  dist_itag_stopper = 0;
  dist_itag_43 = 0;

  dist_MUSICa1 = 0;
  dist_MUSICa2 = 0;
  dist_MUSICa3 = 0;
  dist_MUSICa4 = 0;
  dist_MUSIC1 = 0;
  dist_MUSIC2 = 0;
  dist_MUSIC3 = 0;
  dist_focS8 = 0;
  dist_MW81 = 0;
  dist_MW82 = 0;
  dist_SC81 = 0;
  
  max_scaler = 0;
  
  for(int i=0;i<7;i++) {
    dispersion[i] = 0.;  
    rho0[i] = 0.;  
    bfield[i] = 0.;
    magnification[i] = 0.;
  }
  
  primary_z = 0.;
  offset_z = 0.;
  offset_z2 = 0.;
  offset_z3 = 0.;
  
}

TFRSParameter::TFRSParameter(const char* name) : TGo4Parameter(name) { 
  //fill_raw_histos = kFALSE;
  fill_raw_histos = kTRUE;
  after_run176 = kTRUE;
  
  
  // FRS part
  
  dist_focS2		= 2280.0;        // !* Abstand TS3QT33 - Focus S2    !
  dist_MW21		=  604.0;        // !  Abstand TS3QT33 - MW21        !
  dist_MW22		= 1697.0;        // !  Abstand TS3QT33 - MW22        !
  dist_SC21		= 1469.0;        // !  Abstand TS3QT33 - SC21        !
  
  //    !  LAND "finger" scint 
	dist_SC22		= 3740.0;        // !  Abstand TS3QT33 - SC22        !
    
	dist_focS4		= 4290.0;        // !* MW_ZXS4 => ~ 3m 22.09.2003     !
	dist_MW41		= 1031.1;        // !  Abstand HFSQT13 - MW41        !
	dist_MW42		= 1853.0;        // !  Abstand HFSQT13 - MW42        !
	dist_MW43		= 4324.0;
	dist_SC41		= 2769.9;        // !  Abstand HFSQT13 - SC41        !
	dist_SC42		= 3378.0;
	dist_SC43		= 4132.0;		
    
   dist_MUSICa1	=  230.0;	     // ! Distance window-anode1         !
	dist_MUSICa2	=  230.0;	     // ! Distance window-anode2         !
	dist_MUSICa3	=  230.0;	     // ! Distance window-anode3         !
	dist_MUSICa4	=  230.0;	     // ! Distance window-anode4         !
    
	dist_MUSIC1	    = 1251.2;        // !  HFSQT13 - MUSIC1              !
	dist_MUSIC2	    = 3030.0;        // !  HFSQT13 - MUSIC2              !
	dist_MUSIC3	    = 3030.0;        // !  HFSQT13 - MUSIC3              !
    
	dist_focS8		= 3789.0;		 // !* Abstand TH4QD12 - Focus S8    !
	dist_MW81		= 1021.0;		 // !  Abstand TH4QD12 - MW81        !
	dist_MW82		= 4500.0;		 // !  Abstand TH4QD12 - MW82        !
	dist_SC81		= 4000.0;		 // !  Abstand TH4QD12 - SC81        !
 
    
    // MON part
        
    max_scaler      = 32;
    
   for(int i=0;i<7;i++) {
      dispersion[i] = 0.;  
      rho0[i] = 0.;  
      bfield[i] = 0.;
      magnification[i] = 0.;
    }
    
   dispersion[0] = -6.474;    // !  FRS Dispersion TA-S2 (Run114)  !
   dispersion[1] =  7.239;    // !  FRS Dispersion S2-S4 (Run114)  !
   magnification[0] = 0.730;  // !  FRS Vergroesserung  TA-S2      !
   magnification[1] = 1.12;   // !  FRS Vergroesserung  S2-S4      !
   
   bfield[0] = 0.59655;      // !  FRS D1 Feld [Tesla]  !
   bfield[1] = 0.59594;      // !  FRS D2 Feld [Tesla]  !
   bfield[2] = 0.6167;       // !  FRS D3 Feld [Tesla]  !
   bfield[3] = 0.6180;       // !  FRS D4 Feld [Tesla]  !
                            // !--------------------------------!
                            // ! effective   Rho1..Rho4	       !
                            // !--------------------------------!
   rho0[0] = 11.26840;       // ! FRS TA/S2 Sollbahnradius [m]   !
   rho0[1] = 11.2794;        // ! FRS S2/S4 Sollbahnradius [m]   !
   
   primary_z = 54.0;
   offset_z = 0.;
   offset_z2 = 0.;
   offset_z3 = 0.;

	a2AoQCorr = 0.;
	a4AoQCorr = 0.;
}

TFRSParameter::~TFRSParameter() { 
}

Int_t TFRSParameter::Print(Text_t * n, Int_t) {	
  cout << "Parameter " << GetName()<<":" << endl;	
  
  cout << "fill_raw_histos = " << fill_raw_histos << endl;
  cout << "after_run176 = " << after_run176  << endl;
  
  cout << "max_scaler = " << max_scaler << endl;
  
  cout << "Dist_FocS2="<< dist_focS2<< endl;				
  cout << "Dist_MW21=" << dist_MW21 << endl; 				       
  cout << "Dist_MW22=" << dist_MW22 << endl; 					
  cout << "Dist_SC21=" << dist_SC21 << endl; 	
  cout << "Dist_SC22=" << dist_SC22 << endl; 			
  
  cout << "Dist_FocS4="<< dist_focS4<< endl;			
  cout << "Dist_MW41=" << dist_MW41 << endl;				       
  cout << "Dist_MW42=" << dist_MW42 << endl; 				
  cout << "Dist_MW43=" << dist_MW43 << endl;				
  cout << "Dist_SC41=" << dist_SC41 << endl;					
  cout << "Dist_SC42=" << dist_SC42 << endl;					
  cout << "Dist_SC43=" << dist_SC43 << endl;				 
  cout << "Dist_MUSICa1=" << dist_MUSICa1 << endl;			
  cout << "Dist_MUSICa2=" << dist_MUSICa2 << endl; 		
  cout << "Dist_MUSICa3=" << dist_MUSICa3 << endl; 			
  cout << "Dist_MUSICa4=" << dist_MUSICa4 << endl;		
  cout << "Dist_MUSIC1="  << dist_MUSIC1  << endl;  			
  cout << "Dist_MUSIC2="  << dist_MUSIC2  << endl; 				
  cout << "Dist_MUSIC3="  << dist_MUSIC3  << endl; 	

  cout << "Dist_FocS8="<< dist_focS8<< endl; 				
  cout << "Dist_MW81=" << dist_MW81 << endl; 				
  cout << "Dist_MW82=" << dist_MW82 << endl; 			
  cout << "Dist_SC81=" << dist_SC81 << endl;  					
  
  cout << "primary_z = " << primary_z << endl;
  cout << "offest_z = " << offset_z << endl;
  cout << "offest_z2 = " << offset_z2 << endl;
  cout << "offest_z3 = " << offset_z3 << endl;  
  return 0; 
}

Bool_t TFRSParameter::UpdateFrom(TGo4Parameter *pp) { 
    TFRSParameter *from = dynamic_cast<TFRSParameter*> (pp);
    if (from==0) {
       cout << "Wrong parameter object: " << pp->ClassName() << endl; 
       return kFALSE;   
    }
    //fill_raw_histos = from->fill_raw_histos;
    after_run176    = from->after_run176;

    dist_focS2=from->dist_focS2;				
    dist_MW21 =from->dist_MW21;					       
    dist_MW22 =from->dist_MW22;					
    dist_SC21 =from->dist_SC21;
    dist_SC22 =from->dist_SC22;					
                                                                    
    dist_focS4=from->dist_focS4;				
    dist_MW41 =from->dist_MW41;					       
    dist_MW42 =from->dist_MW42;					
    dist_MW43 =from->dist_MW43;					
    dist_SC41 =from->dist_SC41;					
    dist_SC42 =from->dist_SC42;					
    dist_SC43 =from->dist_SC43;
    dist_itag_42 =from->dist_itag_42;
    dist_itag_stopper =from->dist_itag_stopper;
    dist_itag_43 =from->dist_itag_43;
    
    dist_MUSICa1=from->dist_MUSICa1;			
    dist_MUSICa2=from->dist_MUSICa2;		
    dist_MUSICa3=from->dist_MUSICa3;			
    dist_MUSICa4=from->dist_MUSICa4;			
    dist_MUSIC1=from->dist_MUSIC1;			
    dist_MUSIC2=from->dist_MUSIC2;
    dist_MUSIC3=from->dist_MUSIC3;				
                                                            
    dist_focS8=from->dist_focS8;				
    dist_MW81 =from->dist_MW81;					
    dist_MW82 =from->dist_MW82;					
    dist_SC81 =from->dist_SC81;		
             
    max_scaler = from->max_scaler;
    if (max_scaler>32) max_scaler = 32;  
    
    for(int i=0;i<7;i++) {
      dispersion[i] = from->dispersion[i];  
      magnification[i] = from->magnification[i];
      rho0[i] = from->rho0[i];  
      bfield[i] = from->bfield[i];
    }
    
    primary_z = from->primary_z;
    offset_z = from->offset_z;
    offset_z2 = from->offset_z2;
    offset_z3 = from->offset_z3;
   
	a2AoQCorr = from->a2AoQCorr;
	a4AoQCorr = from->a4AoQCorr;

    cout << "Updated Parameter: " << GetName() << endl;    
    
    return kTRUE; 
}

ClassImp(TFRSParameter)


// ----------------------------------------------------------

TMWParameter::TMWParameter() : TGo4Parameter("TMWParameter") {
   for (int i=0;i<13;i++) {
      x_factor[i] = 0.1;
      x_offset[i] = 0.;
      y_factor[i] = 0.1;
      y_offset[i] = 0.;
   }

   for(int i=0;i<5;i++)
     for(int j=0;j<13;j++)
       gain_tdc[i][j] = 0.;
}

TMWParameter::TMWParameter(const char* name) : TGo4Parameter(name) {
   x_factor[0]  = 0.0696;    //! (~2ns/mm) ! meas. 238U 06-JUL-03 
   x_factor[1]  = 0.0732;    //! (2ns/mm)
   x_factor[2]  = 0.0732;    //! (2ns/mm)
   x_factor[3]  = 0.0732;    //! (2ns/mm)
   x_factor[4]  = 0.0751;    //! 
   x_factor[5]  = 0.07829;   //! 
   x_factor[6]  = 0.0732;    //!  
   x_factor[7]  = 0.0732;    //! 
   x_factor[8]  = 0.0732;    //! 
   x_factor[9]  = 0.0732;    //! (2ns/mm)
   x_factor[10] = 0.0366;    //! (4ns/mm) 
   x_factor[11] = 0.0732;    //! (2ns/mm)
   x_factor[12] = 0.0732;    //! (2ns/mm)

   x_offset[0]  =  0.0;      //
   x_offset[1]  =  0.0;      //
   x_offset[2]  =  0.0;      //
   x_offset[3]  =  0.0;      //
   x_offset[4]  =  0.0;      //
   x_offset[5]  =  0.0;      //
   x_offset[6]  =  0.0;      //
   x_offset[7]  =  0.0;      //
   x_offset[8]  =  0.0;      // 
   x_offset[9]  =  0.0;      // 
   x_offset[10] =  0.0;      // 
   x_offset[11] =  0.0;      // 
   x_offset[12] =  0.0;      // 

   y_factor[0]  = 0.0696;    //! (2ns/mm) ! =x 238U 06-JUL-03 
   y_factor[1]  = 0.0732;
   y_factor[2]  = 0.0732;
   y_factor[3]  = 0.0732;
   y_factor[4]  = 0.0732; 
   y_factor[5]  = 0.0751; 
   y_factor[6]  = 0.07829;  
   y_factor[7]  = 0.0732; 
   y_factor[8]  = 0.0732;
   y_factor[9]  = 0.0732;
   y_factor[10] = 0.0366;     //! (4ns/mm)
   y_factor[11] = 0.0732; 
   y_factor[12] = 0.0732;

   y_offset[0]  = 0.0;
   y_offset[1]  = 0.0;
   y_offset[2]  = 0.0;
   y_offset[3]  = 0.0;
   y_offset[4]  = 0.0;
   y_offset[5]  = 0.0;
   y_offset[6]  = 0.0;
   y_offset[7]  = 0.0;
   y_offset[8]  = 0.0;
   y_offset[9]  = 0.0;
   y_offset[10] = 0.0;
   y_offset[11] = 0.0;
   y_offset[11] = 0.0;

    for(int i=0;i<5;i++)
     for(int j=0;j<13;j++)
       gain_tdc[i][j] = 0.;
} 

TMWParameter::~TMWParameter() {
}

Int_t TMWParameter::Print(Text_t*, Int_t) {
   cout << "Parameter " << GetName() << endl;	    
   
   for(int i=0;i<13;i++) 
      cout << "x_factor[" << i << "]= " << x_factor[i] 
           << "  x_offset[" << i << "]= " << x_offset[i] << endl;
   for(int i=0;i<13;i++) 
      cout << "y_factor[" << i << "]= " << y_factor[i]
           << "  y_offset[" << i << "]= " << y_offset[i] << endl;

   return 0;
}

Bool_t TMWParameter::UpdateFrom(TGo4Parameter* par) {
   TMWParameter *from = dynamic_cast<TMWParameter*> (par);
   if (from==0) {
      cout << "Wrong parameter object: " << par->ClassName() << endl; 
      return kFALSE;   
   }
   
   for(int i=0;i<13;i++) {
      x_factor[i] = from->x_factor[i];
      x_offset[i] = from->x_offset[i];
      y_factor[i] = from->y_factor[i];
      y_offset[i] = from->y_offset[i];
   }

    for(int i=0;i<5;i++)
     for(int j=0;j<13;j++)
       gain_tdc[i][j] = from->gain_tdc[i][j];
   
   return kTRUE;
}

ClassImp(TMWParameter)


  // ----------------------------------------------------------
  // TPC Parameters
  
TTPCParameter::TTPCParameter() : TGo4Parameter("TTPCParameter") {

    //TPC3   //23/04/08 VALUE SET ACCORDING TO CALIBRATION
   x_factor[2][0] = 0.070155;  //L-R time 0
   x_factor[2][1] = 0.069089;  //L-R time 1
   y_factor[2][0] = -0.0373246; //drift time 0
   y_factor[2][1] = -0.0379154; //drift time 1
   y_factor[2][2] = -0.0382496; //drift time 2
   y_factor[2][3] = -0.0378421; //drift time 3
	 
   x_offset[2][0] = -3.3;
   x_offset[2][1] = -1.15;
   y_offset[2][0] = 46.9423;
   y_offset[2][1] = 46.8563;
   y_offset[2][2] = 47.118;
   y_offset[2][3] = 46.9655;

   // TPC4
  x_factor[3][0] = 0.070797;
  x_factor[3][1] = 0.069579;
  y_factor[3][0] = -0.0379319;
  y_factor[3][1] = -0.0388858;
  y_factor[3][2] = -0.0377925;
  y_factor[3][3] = -0.0383422; 
	
  x_offset[3][0] = -0.9;
  x_offset[3][1] = 2.88;
  y_offset[3][0] = 55.5394;
  y_offset[3][1] = 55.781;
  y_offset[3][2] = 55.5143;
  y_offset[3][3] = 55.5203;
  

  // TPC5
  x_factor[4][0] = 0.073641;
  x_factor[4][1] = 0.075485;
  y_factor[4][0] =-0.041;
  y_factor[4][1] =-0.040;
  y_factor[4][2] =-0.0396;
  y_factor[4][3] =-0.0387; 
  
  x_offset[4][0] = 2.79;
  x_offset[4][1] =-0.83;
  y_offset[4][0] = 44.2;
  y_offset[4][1] = 43.2;
  y_offset[4][2] = 41.4;
  y_offset[4][3] = 40.6; 

   // TPC6
 
  x_factor[5][0] = 0.07755;
  x_factor[5][1] = 0.07683;
  y_factor[5][0] =0.040;
  y_factor[5][1] =0.039;
  y_factor[5][2] =0.039;
  y_factor[5][3] =0.039;

  x_offset[5][0] = -0.15221;
  x_offset[5][1] = 1.5;
  y_offset[5][0] = -41-6;
  y_offset[5][1] =-39.2-6;
  y_offset[5][2] =-39.5-6;
  y_offset[5][3] =-40.8-6;
   


   // TPC1
  x_factor[0][0] = 0.070623;
  x_factor[0][1] = 0.07248;
  y_factor[0][0] =-0.036;
  y_factor[0][1] =-0.035;
  y_factor[0][2] =-0.035;
  y_factor[0][3] =-0.036; 
	 
  x_offset[0][0] =-0.5;
  x_offset[0][1] =-1.058;
  y_offset[0][0] = 39.3;
  y_offset[0][1] = 38.6;
  y_offset[0][2] = 39.6;
  y_offset[0][3] = 40.0; 

   // TPC2
  x_factor[1][0] = 0.0716;
  x_factor[1][1] = 0.070329;
  y_factor[1][0] = -0.035;
  y_factor[1][1] = -0.035;
  y_factor[1][2] = -0.034;
  y_factor[1][3] = -0.034;  

  x_offset[1][0] = -0.81;
  x_offset[1][1] =  1.9;
  y_offset[1][0] =  37.4;
  y_offset[1][1] =  37.1;
  y_offset[1][2] =  36.1;
  y_offset[1][3] =  35.7; 

 

  for(int i=0;i<32;i++){
        tdc1_factor[i]=1;
        tdc2_factor[i]=1;
  }
}


TTPCParameter::TTPCParameter(Text_t * name) : TGo4Parameter(name) {



    //TPC3   //23/04/08 VALUE SET ACCORDING TO CALIBRATION
   x_factor[2][0] = 0.070155;  //L-R time 0
   x_factor[2][1] = 0.069089;  //L-R time 1
   y_factor[2][0] = -0.0373246; //drift time 0
   y_factor[2][1] = -0.0379154; //drift time 1
   y_factor[2][2] = -0.0382496; //drift time 2
   y_factor[2][3] = -0.0378421; //drift time 3
	 
   x_offset[2][0] = -3.3;
   x_offset[2][1] = -1.15;
   y_offset[2][0] = 46.9423;
   y_offset[2][1] = 46.8563;
   y_offset[2][2] = 47.118;
   y_offset[2][3] = 46.9655;

   // TPC4
  x_factor[3][0] = 0.070797;
  x_factor[3][1] = 0.069579;
  y_factor[3][0] = -0.0379319;
  y_factor[3][1] = -0.0388858;
  y_factor[3][2] = -0.0377925;
  y_factor[3][3] = -0.0383422; 
	
  x_offset[3][0] = -0.9;
  x_offset[3][1] = 2.88;
  y_offset[3][0] = 55.5394;
  y_offset[3][1] = 55.781;
  y_offset[3][2] = 55.5143;
  y_offset[3][3] = 55.5203;
  

  // TPC5
  x_factor[4][0] = 0.073641;
  x_factor[4][1] = 0.075485;
  y_factor[4][0] =-0.041;
  y_factor[4][1] =-0.040;
  y_factor[4][2] =-0.0396;
  y_factor[4][3] =-0.0387; 
  
  x_offset[4][0] = 2.79;
  x_offset[4][1] =-0.83;
  y_offset[4][0] = 44.2;
  y_offset[4][1] = 43.2;
  y_offset[4][2] = 41.4;
  y_offset[4][3] = 40.6; 

   // TPC6
 
  x_factor[5][0] = 0.07755;
  x_factor[5][1] = 0.07683;
  y_factor[5][0] =0.040;
  y_factor[5][1] =0.039;
  y_factor[5][2] =0.039;
  y_factor[5][3] =0.039;

  x_offset[5][0] = -0.15221;
  x_offset[5][1] = 1.5;
  y_offset[5][0] = -41-6;
  y_offset[5][1] =-39.2-6;
  y_offset[5][2] =-39.5-6;
  y_offset[5][3] =-40.8-6;
   


   // TPC1
  x_factor[0][0] = 0.070623;
  x_factor[0][1] = 0.07248;
  y_factor[0][0] =-0.036;
  y_factor[0][1] =-0.035;
  y_factor[0][2] =-0.035;
  y_factor[0][3] =-0.036; 
	 
  x_offset[0][0] =-0.5;
  x_offset[0][1] =-1.058;
  y_offset[0][0] = 39.3;
  y_offset[0][1] = 38.6;
  y_offset[0][2] = 39.6;
  y_offset[0][3] = 40.0; 

   // TPC2
  x_factor[1][0] = 0.0716;
  x_factor[1][1] = 0.070329;
  y_factor[1][0] = -0.035;
  y_factor[1][1] = -0.035;
  y_factor[1][2] = -0.034;
  y_factor[1][3] = -0.034;  

  x_offset[1][0] = -0.81;
  x_offset[1][1] =  1.9;
  y_offset[1][0] =  37.4;
  y_offset[1][1] =  37.1;
  y_offset[1][2] =  36.1;
  y_offset[1][3] =  35.7; 


  for(int i=0;i<32;i++){
        tdc1_factor[i]=1;
        tdc2_factor[i]=1;
  }
} 

TTPCParameter::~TTPCParameter() {
}

Int_t TTPCParameter::Print(Text_t*, Int_t) {
  cout << "Parameter " << GetName() << endl;       
  
  for(int i=0;i<6;i++) 
    for(int j=0;j<2;j++){ 
      cout << "x_factor[" << i << "][" << j <<"]= " << x_factor[i][j] 
	   << "  x_offset[" << i << "][" << j <<"]= " << x_offset[i][j] << endl;
    }
  return 0;
}

Bool_t TTPCParameter::UpdateFrom(TGo4Parameter* par) {
  TTPCParameter *from = dynamic_cast<TTPCParameter*> (par);
  if (from==0) {
    cout << "Wrong parameter object: " << par->ClassName() << endl; 
    return kFALSE;   
  }
  
  for(int i=0;i<6;i++) {
    for(int j=0;j<2;j++){ 
      x_factor[i][j] = from->x_factor[i][j];
      x_offset[i][j] = from->x_offset[i][j];
   } 
    for(int j=0;j<4;j++){ 
    	y_factor[i][j] = from->y_factor[i][j];
    	y_offset[i][j] = from->y_offset[i][j];
    }
  }

  for(int i=0;i<32;i++){
	tdc1_factor[i]=from->tdc1_factor[i];
	tdc2_factor[i]=from->tdc2_factor[i];
  }
  return kTRUE;
}


// ----------------------------------------------------------

TMWDCParameter::TMWDCParameter() : TGo4Parameter("TMWDCParameter") {

  /////////////////////////////////////
  //  Parameters used in CalibrProc  //
  /////////////////////////////////////
  //

  test=4.0;
  b_selfcorr1 = kFALSE;  
  first_event=1;
  focal_z= 1.000;//(mm/(mrad)
  focal_aa= 0.083;//(mm/(mrad)^2)
  focal_a= 10.; //tan(Theta)
  focal_y= 0.; 

}

TMWDCParameter::TMWDCParameter(const char* name) : TGo4Parameter(name) {
  /////////////////////////////////////
  //  Parameters used in CalibrProc  //
  /////////////////////////////////////
  
  //
  test=4.0;
  b_selfcorr1 = kFALSE;  
  first_event=1;
  focal_z= 1.000;//(mm/(mrad)
  focal_aa= 0.083;//(mm/(mrad)^2)
  focal_a= 10.; //tan(Theta)
  focal_y= 0.; 
   cout << "set MWDC parameters" << endl;
} 


TMWDCParameter::~TMWDCParameter() {
}

Int_t TMWDCParameter::Print(Text_t*, Int_t) {
   cout << "Parameter " << GetName() << endl;
   cout << "b_selfcorr1 = " << b_selfcorr1 << endl;
    cout << "test = " << test << endl;
   return 0;
}

Bool_t TMWDCParameter::UpdateFrom(TGo4Parameter* par) {
   TMWDCParameter *from = dynamic_cast<TMWDCParameter*> (par);
   if (from==0) {
      cout << "Wrong parameter object: " << par->ClassName() << endl; 
      return kFALSE;   
   }
 
   b_selfcorr1 = from->b_selfcorr1;
   test = from->test;
   first_event=1;
   focal_z = from->focal_z ;
   focal_a = from->focal_a ;
   focal_aa= from->focal_aa ;
   focal_y= from->focal_y ;

   return kTRUE;
}

ClassImp(TMWDCParameter)


// ----------------------------------------------------------

TMUSICParameter::TMUSICParameter() : TGo4Parameter("TMUSICParameter") {
  for (int i=0;i<8;i++){
      e1_off[i] = 0;
      e1_gain[i] = 1.;
      e2_off[i] = 0;
      e2_gain[i] = 1.;
  }

  for (int i=0;i<4;i++){
      e3_off[i] = 0;
      e3_gain[i] = 1.;

  }


   b_selfcorr1 = kFALSE;  
    
   for(int i=0;i<7;i++)
     pos_a1[i] = 0.;
}

TMUSICParameter::TMUSICParameter(const char* name) : TGo4Parameter(name) {
  //   e1_off[0]  = 133;  //          ! ADC offset MUSIC1 A1       !
  //   e1_off[1]  =  95;  //          ! ADC offset MUSIC1 A2       !
  //   e1_off[2]  = 123;  //          ! ADC offset MUSIC1 A3       !
  //   e1_off[3]  = 150;  //          ! ADC offset MUSIC1 A4       !
  //   e1_off[4]  = 117;  //          ! ADC offset MUSIC1 A5       !
  //   e1_off[5]  = 130;  //          ! ADC offset MUSIC1 A6       !
  //   e1_off[6]  = 136;  //          ! ADC offset MUSIC1 A7       !
  //   e1_off[7]  =  86;  //          ! ADC offset MUSIC1 A8       !
   
   e1_off[0]  = 0;  //          ! ADC offset MUSIC1 A1       !
   e1_off[1]  = 0;  //          ! ADC offset MUSIC1 A2       !
   e1_off[2]  = 0;  //          ! ADC offset MUSIC1 A3       !
   e1_off[3]  = 0;  //          ! ADC offset MUSIC1 A4       !
   e1_off[4]  = 0;  //          ! ADC offset MUSIC1 A5       !
   e1_off[5]  = 0;  //          ! ADC offset MUSIC1 A6       !
   e1_off[6]  = 0;  //          ! ADC offset MUSIC1 A7       !
   e1_off[7]  = 0;  //          ! ADC offset MUSIC1 A8       !

   e1_gain[0]  = 1.0368;  //      ! ADC gain MUSIC1 A1       !
   e1_gain[1]  = 1.0378;  //      ! ADC gain MUSIC1 A2       !
   e1_gain[2]  = 1.0181;  //      ! ADC gain MUSIC1 A3       !
   e1_gain[3]  = 1.0000;  //      ! ADC gain MUSIC1 A4       !
   e1_gain[4]  = 1.0152;  //      ! ADC gain MUSIC1 A5       !
   e1_gain[5]  = 1.0200;  //      ! ADC gain MUSIC1 A6       !
   e1_gain[6]  = 1.0220;  //      ! ADC gain MUSIC1 A7       !
   e1_gain[7]  = 1.0249;  //      ! ADC gain MUSIC1 A8       !

   e2_off[0]  = 0;  //          ! ADC offset MUSIC2 A1       !
   e2_off[1]  = 0;  //          ! ADC offset MUSIC2 A2       !
   e2_off[2]  = 0;  //          ! ADC offset MUSIC2 A3       !
   e2_off[3]  = 0;  //          ! ADC offset MUSIC2 A4       !
   e2_off[4]  = 0;  //          ! ADC offset MUSIC2 A5       !
   e2_off[5]  = 0;  //          ! ADC offset MUSIC2 A6       !
   e2_off[6]  = 0;  //          ! ADC offset MUSIC2 A7       !
   e2_off[7]  = 0;  //          ! ADC offset MUSIC2 A8       !

   e2_gain[0]  = 1.0135;  //      ! ADC gain MUSIC2 A1       !
   e2_gain[1]  = 1.5205;  //      ! ADC gain MUSIC2 A2       !
   e2_gain[2]  = 1.1795;  //      ! ADC gain MUSIC2 A3       !
   e2_gain[3]  = 1.1040;  //      ! ADC gain MUSIC2 A4       !
   e2_gain[4]  = 1.0000;  //      ! ADC gain MUSIC2 A5       !
   e2_gain[5]  = 1.0243;  //      ! ADC gain MUSIC2 A6       !
   e2_gain[6]  = 1.0529;  //      ! ADC gain MUSIC2 A7       !
   e2_gain[7]  = 1.2172;  //      ! ADC gain MUSIC2 A8       !


   e3_off[0]  = 0;  //          ! ADC offset MUSIC3 A1       !
   e3_off[1]  = 0;  //          ! ADC offset MUSIC3 A2       !
   e3_off[2]  = 0;  //          ! ADC offset MUSIC3 A3       !
   e3_off[3]  = 0;  //          ! ADC offset MUSIC3 A4       ! 


   e3_gain[0]  = 1.;  //          ! ADC gain MUSIC3 A1       !
   e3_gain[1]  = 1.;  //          ! ADC gain MUSIC3 A2       !
   e3_gain[2]  = 1.;  //          ! ADC gain MUSIC3 A3       !
   e3_gain[3]  = 1.;  //          ! ADC gain MUSIC3 A4       !

   b_selfcorr1 = kFALSE;

   
   //   pos_a1[0] = 2027.98;      //   ! 22 sep03 calib
   pos_a1[0] = 1.0;          //   !
   pos_a1[1] = 0.0;          //   ! 
   pos_a1[2] = 0.0;          //	  ! 
   pos_a1[3] = 0.0;          //   !
   pos_a1[4] = 0.0;          //   !
   pos_a1[5] = 0.0;          //   !
   pos_a1[6] = 0.0;          //   !
   cout << "set MUSIC parameters" << endl;

} 


TMUSICParameter::~TMUSICParameter() {
}

Int_t TMUSICParameter::Print(Text_t*, Int_t) {
   cout << "Parameter " << GetName() << endl;
   
   for (int i=0;i<8;i++){
      cout << "e1_off[" << i << "] = " << e1_off[i] << endl;
      cout << "e1_gain[" << i << "] = " << e1_gain[i] << endl;
   }
   cout << "b_selfcorr1 = " << b_selfcorr1 << endl;
    
   for (int i=0;i<7;i++)
      cout << "pos_a1[" << i << "] = " << pos_a1[i] << endl; 
        
   return 0;
}

Bool_t TMUSICParameter::UpdateFrom(TGo4Parameter* par) {
   TMUSICParameter *from = dynamic_cast<TMUSICParameter*> (par);
   if (from==0) {
      cout << "Wrong parameter object: " << par->ClassName() << endl; 
      return kFALSE;   
   }
   
   for (int i=0;i<8;i++){
     e1_off[i] = from->e1_off[i];
     e1_gain[i] = from->e1_gain[i];
   }
   b_selfcorr1 = from->b_selfcorr1;
    
   for (int i=0;i<7;i++)
     pos_a1[i] = from->pos_a1[i];
   
   return kTRUE;
}

ClassImp(TMUSICParameter)




// ----------------------------------------------------------

TSCIParameter::TSCIParameter() : TGo4Parameter("TSCIParameter") {
   for(int i=0;i<12;i++) {
       le_a[0][i] = 0.;
       le_a[1][i] = 1.;
       re_a[0][i] = 0.;
       re_a[1][i] = 1.;
    }

   for(int i=0;i<3;i++) {
       le_veto_a[0][i] = 0.;
       le_veto_a[1][i] = 1.;
       re_veto_a[0][i] = 0.;
       re_veto_a[1][i] = 1.;
    }
 
   for(int i=0;i<8;i++){
     tac_factor[i] =1.0;
     tac_off[i] = 0.;
   }
   
   for(int i=0;i<7;i++)
     for(int j=0;j<12;j++)
       x_a[i][j] = 0.;
        
   for(int i=0;i<7;i++)
     y5_a[i] = 0.;
      
   tof_bll2 = 1.0;        /* [ps/channel]             */
   tof_brr2 = 1.0;        /* [ps/channel]             */
   tof_a2   = 0.0;        /* shift [ps]         */
   tof_bll3 = 1.0;        /* [ps/channel]             */
   tof_brr3 = 1.0;        /* [ps/channel]             */
   tof_a3   = 0.0;        /* shift [ps]         */
}

TSCIParameter::TSCIParameter(const char* name) : TGo4Parameter(name) {
   for(int i=0;i<12;i++) {
     le_a[0][i] = 0.;
     le_a[1][i] = 1.;
     re_a[0][i] = 0.;
     re_a[1][i] = 1.;
   }

   for(int i=0;i<3;i++) {
       le_veto_a[0][i] = 0.;
       le_veto_a[1][i] = 1.;
       re_veto_a[0][i] = 0.;
       re_veto_a[1][i] = 1.;
    }


   tac_off[0] = 0.;  //SC21L-R
   tac_off[1] = 0.;  //SC41L-R
   tac_off[2] = 0.;  //SC41L-SC21L
   tac_off[3] = 0.;  //SC41R-SC21R
   tac_off[4] = 0.;  //SC42L-SC42R
   tac_off[5] = 0.;  //SC42L-SC21L
   tac_off[6] = 0.;  //SC42R-SC21R

   tac_factor[0] = 0.00537;    //SC21L-R [ps/ch]
   tac_factor[1] = 0.00558;    //SC41L-R
   tac_factor[2] = 0.0106462;  //SC41L-SC21L
   tac_factor[3] = 0.0111732;  //SC41R-SC21R
   tac_factor[4] = 0.00567;    //SC42L-SC42R
   tac_factor[5] = 0.00566;    //SC42L-SC21L
   tac_factor[6] = 0.00559;    //SC42R-SC21R


   for(int i=0;i<7;i++)
     for(int j=0;j<12;j++)
       x_a[i][j] = 0.;
   
   x_a[0][2] =  672.101;   // ! SC21 calibration ch->mm    !
   x_a[1][2] =  -0.371043; // ! 22sep03                    !
   x_a[2][2] =  -2.68163e-7;//! slope from eyeballing width!
   x_a[3][2] =  0.000000; // !                            !
   x_a[4][2] =  0.000000; // !                            !
   x_a[5][2] =  0.000000; // !                            !
   x_a[6][2] =  0.000000; // !                            !

   x_a[0][3] =   781.;    // ! SC21 calibration ch->mm    !
   x_a[1][3] =  -0.4483;  // ! offset 23-Jul-03           !
   x_a[2][3] =  0.000000; // ! slope from eyeballing width!
   x_a[3][3] =  0.000000; // !                            !
   x_a[4][3] =  0.000000; // !                            !
   x_a[5][3] =  0.000000; // !                            !
   x_a[6][3] =  0.000000; // !                            !

   x_a[0][5] =  282.097;  // ! SC41 calibration ch->mm    !
   x_a[1][5] = -5.09955e-4;  // ! offset 23-Jul-03        !
   x_a[2][5] = -7.15792e-5; // ! coeffs guessed!          !
   x_a[3][5] = 0.000000;  // !                            !
   x_a[4][5] = 0.000000;  // !                            !
   x_a[5][5] = 0.000000;  // !                            !
   x_a[6][5] = 0.000000;  // !                            !

   x_a[0][6] =    752;   // ! SC42 calibration ch->mm   !
   x_a[1][6] =   -0.4;   // !                           !
   x_a[2][6] = 0.000000; // !                           !
   x_a[3][6] = 0.000000; // !                           !
   x_a[4][6] = 0.000000; // !                           !
   x_a[5][6] = 0.000000; // !                           !
   x_a[6][6] = 0.000000; // !                           !
   
   y5_a[0] = 164.9;        // ! SC41 calibration ch->mm    !
   y5_a[1] = -0.0985331;        // ! offset 23-Jul-03           ! 
   y5_a[2] = 0.000000;    // ! coeffs guessed!            !
   y5_a[3] = 0.000000;    // !                            !
   y5_a[4] = 0.000000;    // !                            !
   y5_a[5] = 0.000000;    // !                            !
   y5_a[6] = 0.000000;    // !                            !
   
   tof_bll2 = 32.625;        //RUN113, 150 ns range         
   tof_brr2 = 32.176;        //RUN113, 150 ns range         
   tof_a2   = 0.0;          // ????????  (remnant)
   tof_bll3 = 37.7;         // RUN106, 150 ns range         
   tof_brr3 = 38.6;         // RUN106, 150 ns range
   tof_a3   = 264473.;      // to center tof peak at 352800 ps
} 

TSCIParameter::~TSCIParameter() {
}

Int_t TSCIParameter::Print(Text_t*, Int_t) {
   cout << "Parameter " << GetName() << endl;	    
   
   for(int i=0;i<12;i++) 
      cout << "le_a[0]["<<i<<"] = " << le_a[0][i] << 
              "    le_a[1]["<<i<<"] = " << le_a[1][i] << endl;
              
   for(int i=0;i<12;i++) 
      cout << "re_a[0]["<<i<<"] = " << re_a[0][i] << 
              "  re_a[1]["<<i<<"] = " << re_a[1][i] << endl;

   for(int i=0;i<3;i++) 
      cout << "le_veto_a[0]["<<i<<"] = " << le_veto_a[0][i] << 
              "    le_veto_a[1]["<<i<<"] = " << le_veto_a[1][i] << endl;
              
   for(int i=0;i<3;i++) 
      cout << "re_veto_a[0]["<<i<<"] = " << re_veto_a[0][i] << 
              "  re_veto_a[1]["<<i<<"] = " << re_veto_a[1][i] << endl;
   
   for(int i=0;i<8;i++) 
     cout << "tac_factor["<<i<<"] = " << tac_factor[i] << endl;

   for(int i=0;i<8;i++) 
     cout << "tac_off["<<i<<"] = " << tac_off[i] << endl;
           
   for(int i=0;i<7;i++)
     for(int j=0;j<12;j++)
       cout << "x_a["<<i<<"]["<<j<<"] = "  << x_a[i][j] << endl;
   
   for(int i=0;i<7;i++)
     cout << "y5_a[" << i << "] = " << y5_a[i] << endl;
     
   cout << "tof_bll2 = " << tof_bll2 << endl;
   cout << "tof_brr2 = " << tof_brr2 << endl;
   cout << "tof_a2   = " << tof_a2   << endl;
   cout << "tof_bll3 = " << tof_bll3 << endl;
   cout << "tof_brr3 = " << tof_brr3 << endl;
   cout << "tof_a3   = " << tof_a3   << endl;
              
   return 0;
}

Bool_t TSCIParameter::UpdateFrom(TGo4Parameter* par) {
   TSCIParameter *from = dynamic_cast<TSCIParameter*> (par);
   if (from==0) {
      cout << "Wrong parameter object: " << par->ClassName() << endl; 
      return kFALSE;   
   }
   
   for(int i=0;i<12;i++) {
      le_a[0][i] = from->le_a[0][i];
      le_a[1][i] = from->le_a[1][i];
      re_a[0][i] = from->re_a[0][i];
      re_a[1][i] = from->re_a[1][i];
   }

   for(int i=0;i<3;i++) {
       le_veto_a[0][i] = from->le_veto_a[0][i];
       le_veto_a[1][i] = from->le_veto_a[1][i];
       re_veto_a[0][i] = from->re_veto_a[0][i];
       re_veto_a[1][i] = from->re_veto_a[0][i];
    }


   for(int i=0;i<8;i++){
     tac_factor[i] = from->tac_factor[i];
     tac_off[i] = from->tac_off[i];
   }

   for(int i=0;i<7;i++)
     for(int j=0;j<12;j++)
       x_a[i][j] = from->x_a[i][j];
        
   for(int i=0;i<7;i++)
     y5_a[i] = from->y5_a[i];
      
   tof_bll2 = from->tof_bll2;
   tof_brr2 = from->tof_brr2;
   tof_a2 = from->tof_a2;
   tof_bll3 = from->tof_bll3;
   tof_brr3 = from->tof_brr3;
   tof_a3 = from->tof_a3;
   
   return kTRUE;
}

ClassImp(TSCIParameter)


// ----------------------------------------------------------

TIDParameter::TIDParameter() : TGo4Parameter("TIDParameter") {
   x2_select = 1;  
   x4_select = 0;
   x8_select = 0;

   id_tofoff2 = 0.;   
   id_tofoff3 = 0.;
   id_tofcorr2 = 0.;   
   id_tofcorr3 = 0.;
   id_path2 = 0.;
   id_path3 = 0.;

   for (int i=0;i<4;i++){
     vel_a[i] = 0.;
     vel_a2[i] = 0.;
     vel_a3[i] = 0.;
   }

}

TIDParameter::TIDParameter(const char* name) : TGo4Parameter(name) {
   x2_select = 1;  
   x4_select = 1;  
   x8_select = 1;  

   id_tofoff2 = 267690.0;    // Offset (ps), 22sep03
   id_path2 =   123000.0;    // Path/c (ps)
   id_tofcorr2 = 0.0;        // Correction for x4, 23sep03

   id_tofoff3 = 267690.0;    // Offset (ps)
   id_path3 =   271850.0;    // Path/c (ps)
   id_tofcorr3 = 0.0;        // Correction for x8, 
   
   vel_a[0] =  0.;   // 160310 calib
   vel_a[1] =  1.;   // 
   vel_a[2] =  0.;   //
   vel_a[3] =  0.;   // Used in ID part 

   vel_a2[0] =  0.;   // 160310 calib
   vel_a2[1] =  1.;   // 
   vel_a2[2] =  0.;   // 
   vel_a2[3] =  0.;   // Used in ID part 

   vel_a3[0] =  0.;   // 160310 calib
   vel_a3[1] =  1.;   // 
   vel_a3[2] =  0.;   // 
   vel_a3[3] =  0.;   // Used in ID part 
        
} 

TIDParameter::~TIDParameter() {
}

Int_t TIDParameter::Print(Text_t*, Int_t) {
   cout << "Parameter " << GetName() << endl;
   
   cout << "x2_select = " << x2_select << endl;  
   cout << "x4_select = " << x4_select << endl;  
   cout << "x8_select = " << x8_select << endl; 

   cout << "id_tofoff2 = " << id_tofoff2 << endl;
   cout << "id_tofoff3 = " << id_tofoff3 << endl;
   cout << "id_tofcorr2 = " << id_tofcorr2 << endl;
   cout << "id_tofcorr3 = " << id_tofcorr3 << endl;
   cout << "id_path2 = " << id_path2 << endl;
   cout << "id_path3 = " << id_path3 << endl;

   for (int i=0;i<4;i++){
     cout << "vel_a["<<i<<"] = " << vel_a[i] << endl;
     cout << "vel_a2["<<i<<"] = " << vel_a2[i] << endl;
     cout << "vel_a3["<<i<<"] = " << vel_a3[i] << endl;
   }

   return 0;
}

Bool_t TIDParameter::UpdateFrom(TGo4Parameter* par) {
   TIDParameter *from = dynamic_cast<TIDParameter*> (par);
   if (from==0) {
      cout << "Wrong parameter object: " << par->ClassName() << endl; 
      return kFALSE;   
   }
   
   x2_select = from->x2_select;
   x4_select = from->x4_select;
   x8_select = from->x8_select;

   id_tofoff2 = from->id_tofoff2;
   id_tofoff3 = from->id_tofoff3;
   id_tofcorr2 = from->id_tofcorr2;
   id_tofcorr3 = from->id_tofcorr3;
   id_path2 = from->id_path2; 
   id_path3 = from->id_path3; 

   for (int i=0;i<4;i++){
     vel_a[i] = from->vel_a[i];
     vel_a2[i] = from->vel_a2[i];
     vel_a3[i] = from->vel_a3[i];
   }   

   return kTRUE;
}

ClassImp(TIDParameter)


// ----------------------------------------------------------

TSIParameter::TSIParameter() : TGo4Parameter("TSIParameter") {

}

TSIParameter::TSIParameter(const char* name) : TGo4Parameter(name) {

} 

  
TSIParameter::~TSIParameter() {

}

Int_t TSIParameter::Print(Text_t*, Int_t) {
  	cout << "Parameter " << GetName() << endl;
   return 0;
}

Bool_t TSIParameter::UpdateFrom(TGo4Parameter* par) {
   TSIParameter *from = dynamic_cast<TSIParameter*> (par);
   if (from==0) {
      cout << "Wrong parameter object: " << par->ClassName() << endl; 
      return kFALSE;   
   }

		
		si_factor1 = from->si_factor1;
		si_factor2 = from->si_factor2;

		si_offset1 = from->si_offset1;
		si_offset2 = from->si_offset2;

		for(int i=0;i<32;i++){
		dssd_factor[i] = from->dssd_factor[i];
    	dssd_offset[i] = from->dssd_offset[i];
	}

return kTRUE;		
}

ClassImp(TSIParameter)

