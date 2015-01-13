#include <fstream>

void dtdxplot(){
  //
  //------------------------------------------------------
  int print_all_figures   = 0;    // (0:no, 1:make dtdxplot.ps)
  int make_table_output   = 1;    // (0:no, 1:write values in dtdxtable.txt)
  double drift_length_max = 2.5;  // in mm
  const int n_point_max   = 2000; // just give sufficiently large number.
  double xmin[16],xmax[16];
  TH1I *hdt[16];
  ///// name of histogram given by go4 could be changed every time...
  hdt[0] =  Time0_41_Xn__1;    xmin[0]=1300.0;   xmax[0]=1600.;  
  hdt[1] =  Time1_41_Xpn__2;  xmin[1]=1300.0;   xmax[1]=1600.;  
  hdt[2] =  Time2_41_X__3;    xmin[2]=1300.0;   xmax[2]=1600.;  
  hdt[3] =  Time3_41_Xp__4;   xmin[3]=1300.0;   xmax[3]=1600.;  
  hdt[4] =  Time4_41_U__5;    xmin[4]=1300.0;   xmax[4]=1600.;  
  hdt[5] =  Time5_41_Up__6;   xmin[5]=1300.0;   xmax[5]=1600.;  
  hdt[6] =  Time6_41_V__7;    xmin[6]=1300.0;   xmax[6]=1600.;  
  hdt[7] =  Time7_41_Vp__8;   xmin[7]=1300.0;   xmax[7]=1600.;  
  hdt[8] =  Time8_42_Xn__9;   xmin[8]=1300.0;   xmax[8]=1600.;  
  hdt[9] =  Time9_42_Xpn__10;  xmin[9]=1300.0;   xmax[9]=1600.;  
  hdt[10]= Time10_42_X__11;    xmin[10]=1300.0;   xmax[10]=1600.;  
  hdt[11]= Time11_42_Xp__12;   xmin[11]=1300.0;   xmax[11]=1600.;  
  hdt[12]= Time12_42_U__13;    xmin[12]=1300.0;   xmax[12]=1600.;  
  hdt[13]= Time13_42_Up__14;   xmin[13]=1300.0;   xmax[13]=1600.;  
  hdt[14]= Time14_42_V__15;    xmin[14]=1300.0;   xmax[14]=1600.;  
  hdt[15]= Time15_42_Vp__16;   xmin[15]=1300.0;   xmax[15]=1600.;  
  //---------------------------------------------------------
  
  TGraph *gdtdx[16];
  TGraph *gres[16];
  TF1 *fitFcn[16];
  TCanvas *c0[16];
  TCanvas *c1[16];
  if(1==make_table_output){std::ofstream ofs( "dtdxtable.txt" );}

  for(int i=0; i<16; i++){    
    // 
    c0[i]=new TCanvas(Form("c0_%d",i),Form("c0_%d",i),100,100,700,550);
    int n_hist_bin;
    double x_hist_min,x_hist_max;
    double dt[n_point_max]={0.0};
    double dx[n_point_max]={0.0};
    double res[n_point_max]={0.0};
    n_hist_bin = (hdt[i]->GetXaxis()->GetNbins());
    x_hist_min = (hdt[i]->GetXaxis()->GetXmin());
    x_hist_max = (hdt[i]->GetXaxis()->GetXmax());
    

    // count # of events in region on interest.
    double count_sum=0.0;
    for(int i_hist_bin=1; i_hist_bin<=n_hist_bin ; i_hist_bin++){
      double dt_temp;
      // take low edge. because time value is integer.  see convention of nbins in TH1F.
      dt_temp = hdt[i]->GetBinLowEdge(i_hist_bin);   
      if(xmin[i]<=dt_temp && dt_temp <= xmax[i]){
	count_sum +=  hdt[i]->GetBinContent(i_hist_bin);
      }
    }

    if(count_sum > 1000){
      // calculate dt and dx 
      double count_sum_before=0.0;
      int n_plot=0;
      for(int i_hist_bin=n_hist_bin; i_hist_bin>=1; i_hist_bin-=1 ){
	double dt_temp, count_here;
	dt_temp = hdt[i]->GetBinLowEdge(i_hist_bin);   
	if(xmin[i] <= dt_temp && dt_temp <= xmax[i]){
	  count_here = hdt[i]->GetBinContent(i_hist_bin);
	  dt[n_plot] = hdt[i]->GetBinLowEdge(i_hist_bin);
	  dx[n_plot] = drift_length_max *(count_sum_before+0.5*count_here)/count_sum; 
	  n_plot++;
	  count_sum_before += count_here;
	}
      }
      
      gdtdx[i]= new TGraph(n_plot,dt,dx);
      gdtdx[i]->SetMarkerStyle(21);
      gPad->SetGrid(1,1);
      gdtdx[i]->SetTitle(Form("dt-dx relation (i_plane=%d)",i));
      gdtdx[i]->GetXaxis()->SetTitle("drift time/0.78ns");
      gdtdx[i]->GetYaxis()->SetTitle("drift length [mm]");
      gdtdx[i]->Draw("AP"); 
      
      //Print Figures
      if(1==print_all_figures){
	for(int i=0;i<16;i++){
	  switch(i){
	  case 0:
	    c0[i]->Update();
	    c0[i]->Print("dtdxplot.ps(");
	    c1[i]->Update();
	    c1[i]->Print("dtdxresidual.ps(");
	    break;
	  case 15:
	    c0[i]->Update();
	    c0[i]->Print("dtdxplot.ps)");
	    c1[i]->Update();
	    c1[i]->Print("dtdxresidual.ps)");
	    break;
	  default:
	    c0[i]->Update();
	    c0[i]->Print("dtdxplot.ps");
	    c1[i]->Update();
	    c1[i]->Print("dtdxresidual.ps");
	    break; 
	  }
	}
      }//
      
      
      //write values
      //  i_plane  Npoint  Tmax  Tmin
      if(1==make_table_output){
        ofs << i << " " << n_plot  << " " << (int)(xmax[i]) << " " << (int)(xmin[i]);
	for(int j=0; j<n_plot; j++){
	  ofs <<" "<< (double)(dx[j]) ;
	} 
	ofs << std::endl;
	cout << "Plane(i=" << i <<"): Dt-Dx table was created. (n_plot=" <<n_plot << ")"<<endl;
      }
      
      
    }else{ // case for empty plane
      //write values for empty signal plane
      if(1==make_table_output){
        ofs << i << " " << 0  << " " << -1  << " " << 0;
        ofs << std::endl;
	cout << "Plane(i=" << i <<"): no table was created... "<<endl;
      }
    }
    //////
  }// end of for(i=0...16)
}// end of dtdxplot()
