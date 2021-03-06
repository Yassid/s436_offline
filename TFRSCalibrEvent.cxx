#include "TFRSCalibrEvent.h"
#include "Riostream.h"
#include "TFRSCalibrProc.h"
#include "Go4EventServer/TGo4FileSource.h"

TFRSCalibrEvent::TFRSCalibrEvent() : 
   TGo4EventElement("FRSCalibrEvent"), fxProc(0), fxFileSrc(0) { 
}

TFRSCalibrEvent::TFRSCalibrEvent(const char* name) 
  :TGo4EventElement(name), fxProc(0), fxFileSrc(0) { 
}

TFRSCalibrEvent::~TFRSCalibrEvent() { 
}

Int_t TFRSCalibrEvent::Init() { 
  Int_t rev=0;
  Clear();
  if(CheckEventSource("TFRSCalibrProc")){
    fxProc = (TFRSCalibrProc*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by " << fxProc->GetName() << " ****" << endl;
  } else
  if(CheckEventSource("TGo4FileSource")) {
    fxFileSrc = (TGo4FileSource*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by File Source ****"<< endl;
  } else rev=1;
  return rev;
}

Int_t TFRSCalibrEvent::Fill() 
{
   //Clear();
   //if(fxProc) fxProc->FRSCalibr(this); else  // user event processing method
   //if(fxFileSrc)fxFileSrc->BuildEvent(this); // method from framework to restore event from file
   //return 0;
}

void TFRSCalibrEvent::Clear(Option_t *t) { 
  seconds = 0;
  tenthsecs = 0;
  hundrethsecs = 0;	//mik
  extraction_cycle = 1;

	freeTrig=0;
	acptTrig=0;

  for (int i=0;i<13;i++) {
    mw_xsum[i] = 0;
    mw_ysum[i] = 0;
    mw_x[i] = 0.;
    mw_y[i] = 0.;
    mw_wire[i] = 0.;
    b_mw_xsum[i] = kFALSE; 
    b_mw_ysum[i] = kFALSE; 
  }
  
  z_x_s2 = 0.;
  z_y_s2 = 0.;
  z_x_s4 = 0.;
  z_y_s4 = 0.;
  z_x_s8 = 0.;
  z_y_s8 = 0.;
  
  /* set some "specials" as defined by ancient gurus */

  focx_s2 = 999.;
  focy_s2 = 999.;
  focx_s4 = 999.;
  focy_s4 = 999.;
  focx_s8 = 999.;
  focy_s8 = 999.;
  
  /*  dummy values for dummy events...                             */
  /*  (for those later program parts that use these variables...   */
  angle_x_s2 = -999. ;
  angle_y_s2 = -999. ;
  angle_x_s4 = -999. ;
  angle_y_s4 = -999. ;
  angle_x_s8 = -999. ;
  angle_y_s8 = -999. ;
  focx_s2 = -999. ;
  focy_s2 = -999. ;
  focx_s4 = -999. ;
  focy_s4 = -999. ;
  focx_s8 = -999. ;
  focy_s8 = -999. ;

	tpc_angle_x_s2_foc=0;
	tpc_angle_y_s2_foc=0;
	tpc_angle_x_s4=0;
	tpc_angle_y_s4=0;

  tpc_sc21_x = 0.;      /* SC21                     */
  tpc_sc41_x = 0.;      /* SC41                     */
  tpc_sc21_y = 0.;      /* tracked SC21 Y pos       */
  tpc_sc41_y = 0.;      /* SC41 Y                   */
  
  sc21_x = 0.;          /* SC21                     */
  sc22_x = 0.;          /* SC22 (LAND finger)       */
  sc41_x = 0.;          /* SC41                     */
  itag_stopper_x = 0.;  /* ITAG Stopper             */
  sc42_x = 0.;          /* SC42                     */
  sc43_x = 0.;          /* SC43                     */
  sc21_y = 0.;          /* tracked SC21 Y pos       */
  sc41_y = 0.;          /* SC41 Y                   */
  sc42_y = 0.;          /* SC42 Y                   */
  sc43_y = 0.;          /* SC43 Y                   */
  sc81_x = 0.;          /* SC81          positions  */
  
  music1_x1 = 0.;       /* parameters to calibrate  */
  music1_x2 = 0.;       /* parameters to calibrate  */
  music1_x3 = 0.;       /* parameters to calibrate  */
  music1_x4 = 0.;       /* parameters to calibrate  */
  music2_x = 0.;        /* MUSIC1,2 positions       */

  //TPC Part
  for (int i = 0; i<6;i++){
    tpc_x[i] = 9999.9;
    tpc_y[i] = 9999.9;
    b_tpc_xy[i] = kFALSE;
    for (int j=0;j<4;j++){
      tpc_csum[i][j] =0;
      b_tpc_csum[i][j] = kFALSE;
    }
  }  

  //Etap-scaler//
  for(int i=0; i<64; i++){
    etap_scaler[i] = 0; // need parameters
    etap_scaler_increase[i]=0;
    etap_scaler_normalized[i]=0.0;
  }
  
  //MH-scaler//
  for(int i=0; i<64; i++){
    mh_scaler[i] = 0; // need parameters
    mh_scaler_increase[i]=0;
    mh_scaler_normalized[i]=0.0;
  }

 
  //--------------
   tof_21l_41l = -999999.9;
   tof_21r_41r = -999999.9;
   tof_21_41   = -999999.9;
   tof_41l_42l = -999999.9;
   tof_41r_42r = -999999.9;
   tof_41_42   = -999999.9;

  

	// MWDC
	for(int i=0;i<16;i++) {
	     mwdc_numhit[i]=0;
	     for (int ii=0;ii<64;ii++) {
	       mwdc_tot[i][ii]=-999.9;
	       mwdc_time[i][ii]=-999.9;
	       mwdc_wirepos[i][ii]=-999.9;  
	       mwdc_wireid[i][ii]=-999;  
	       mwdc_length[i][ii]=-999;  
	     }
	}
	//---MWDC-Fitting----
	mwdc_numtrack=0;
	mwdc_numtrack_estimate[0]=0;
	mwdc_numtrack_estimate[1]=0;
	mwdc_chi2   = 99999.9;
	mwdc_x = 99999.9;
	mwdc_y = 99999.9;
	mwdc_a = 99999.9;
	mwdc_b = 99999.9;

	focal_plane = 99999.9;
        for(int i=0; i<5; i++)  b_pi[i]=kFALSE;

	for(int i_plane=0; i_plane<16; i_plane++){
	  mwdc_res[i_plane] = 99999.9;
	}

	for(int i_mwdc=0; i_mwdc<2; i_mwdc++){
	  mwdc_chi2_test[i_mwdc] = 99999.9;
	  mwdc_x_test[i_mwdc]    = 99999.9;
	  mwdc_y_test[i_mwdc]    = 99999.9;
	  mwdc_a_test[i_mwdc]    = 99999.9;
	  mwdc_b_test[i_mwdc]    = 99999.9;
	  for(int i_plane=0; i_plane<8; i_plane++){
	    mwdc_res_test[i_mwdc][i_plane] = 99999.9;
	  }
	}


	//Etap-QDC check
	qdcvalid = 0;

	for(int i=0; i<16; i++){
	 sci_timeave[i] = -999.;// need parameters
	 sci_timedif[i] = -999.;// need parameters
	 sci_de[i]  = -999.; // need parameters
	 for(int ii=0; ii<2; ii++){
	   sci_qdc[i][ii] = -999. ;
	   sci_tdc[i][ii] = -999. ;
	   sci_t0_tdc[i][ii] = -999. ;
	   sci_time[i][ii]= -999. ; // need parameters
	   sci_ml[i][ii] = 0;
	   sci_mt[i][ii] = 0;
	 }
	}

	for(int i=0; i<2; i++){
	  mini_qdc[i] = -999.;
	  mini_tdc[i] = -999.;
	  mini_time[i]= -999.;
	  mini_pe[i]  = -999.;
	  mini_pesum  = -999.;
	  mini_numhit = -999; // int
	}

	for(int i=0; i<8; i++){
	  hirac_qdc_raw[i]=-999.;
	  hirac_qdc_base[i]=-999.;
	  hirac_qdc_cor[i] = -999.;
	  hirac_pe[i]  = -999.;
	  hirac_tdc_raw[i] = -999.;
	  hirac_tdc_t0cor[i] = -999.;
	  hirac_tdc_cor[i] = -999.;
	  hirac_pesum  = -999.;
	  hirac_x      = -999.;
	  hirac_numhit = -999; // int
	}
	
	for(int i=0; i<6; i++){
	  torch_qdc[i] = -999.;
	  torch_tdc[i] = -999.;
	  torch_time[i]= -999.;
	  torch_pe[i]  = -999.;
	  torch_pesum  = -999.;
	  torch_x  = -999.;
	  torch_numhit = -999; // int
	}


}

ClassImp(TFRSCalibrEvent)
