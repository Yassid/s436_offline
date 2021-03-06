#include "TFRSSortEvent.h"
#include "Riostream.h"
#include "TFRSSortProc.h"
#include "Go4EventServer/TGo4FileSource.h"


TFRSSortEvent::TFRSSortEvent() : 
   TGo4EventElement("FRSSortEvent"), fxProc(0), fxFileSrc(0) { 
}

TFRSSortEvent::TFRSSortEvent(const char* name) 
  :TGo4EventElement(name), fxProc(0), fxFileSrc(0) { 
}

TFRSSortEvent::~TFRSSortEvent() {
}

Int_t TFRSSortEvent::Init() 
{ 
  Int_t rev=0;
  Clear();
  if(CheckEventSource("TFRSSortProc")) {
    fxProc = (TFRSSortProc*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by " << fxProc->GetName() << " ****" << endl;
  } else
  if(CheckEventSource("TGo4FileSource")) {
    fxFileSrc = (TGo4FileSource*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by File Source ****"<< endl;
  } else rev=1;
  return rev;
}

Int_t TFRSSortEvent::Fill() 
{ 
   Clear();
   if(fxProc) fxProc->FRSSort(this); else    // user event processing method
   if(fxFileSrc)fxFileSrc->BuildEvent(this); // method from framework to restore event from file
   return 0;
}

void TFRSSortEvent::Clear(Option_t *t) { 
  ts_id = 0;
  for(int i=0;i<3;i++) ts_word[i] = 0;
  timestamp = 0;
  timespill = 0.;

  pattern = 0;
  
  for(int i=0;i<32;i++){
    sc_long[i] = 0;
    sc_long2[i] = 0;
  }
  //  ic_de = 0;
  
  for(int i=0;i<13;i++) {
    mw_an[i] = 0; 
    mw_xl[i] = 0;
    mw_xr[i] = 0;
    mw_yu[i] = 0; 
    mw_yd[i] = 0;
  }

  //TPC part
  for(int i=0;i<6;i++){
    tpc_l[i][0]=0;
    tpc_r[i][0]=0;
    tpc_lt[i][0]=0;
    tpc_rt[i][0]=0;
    tpc_l[i][1]=0;
    tpc_r[i][1]=0;
    tpc_lt[i][1]=0;
    tpc_rt[i][1]=0;
    for(int j=0;j<4;j++){
      tpc_dt[i][j]=0;
      tpc_a[i][j]=0;
    }
  }
  
  de_21l = 0;
  de_21r = 0;
  de_41l = 0;
  de_41r = 0;
  de_41u = 0;
  de_41d = 0;
  de_42l = 0;
  de_42r = 0;
  de_21ld = 0; 
  de_21rd = 0;
  de_v1l = 0;
  de_v1r = 0;
  de_v2l = 0;
  de_v2r = 0;
  de_v3  = 0;
  
//   dt_21l_21r = 0;
//   dt_41l_41r = 0;
//   dt_21l_41l = 0;
//   dt_21r_41r = 0;
//   dt_42l_42r = 0;
//   dt_42l_21l = 0;
//   dt_42r_21r = 0;
//   dt_41u_41d = 0;
  
//   for(int i=0;i<8;i++) {
//     music_e1[i] = 0;
//     music_e2[i] = 0;
//   }

//   for(int i=0;i<4;i++) {
//     music_e3[i] = 0;
//     music_t3[i] = 0;
//   }

  
//   music_pres[0] = 0; music_pres[1] = 0;
//   music_temp[0] = 0; music_temp[1] = 0;
//   music_pres[2] = 0; music_temp[2] = 0;

	
// //Si detectors

//   for (int i=0;i<32;i++) {
//     dssd_adc[i]=0;
//   }
//   si_adc1=0;
//   si_adc2=0;

  	
  // Etaprime-MWDC
  for (int i=0;i<16;i++) {
    mwdc_numhit[i]=0;
    for(int ii=0;ii<64;ii++){
      mwdc_wireid[i][ii]=-999;
      mwdc_tot[i][ii]=-999;
      mwdc_time[i][ii]=-999;
      mwdc_time_trail[i][ii]=-999;
    }
  }
  
  // Etaprime-SCI
  for(int i=0;i<16;i++){
    for(int ii=0;ii<2;ii++){
      etapsci_t[i][ii]=-999999; // [i_sci][i_LR]
      etapsci_t_trail[i][ii]=-999999; // [i_sci][i_LR]
      etapsci_q[i][ii]=-999;      
      etapsci_t0_t_trail[i][ii]=-999999; // [i_sci][i_LR]
      etapsci_t0_t[i][ii]=-999;      
       etapsci_mt[16][2] = 0;
       etapsci_ml[16][2] = 0;
    }
  }
  // Etaprime-HIRAC
  for(int i=0;i<8;i++){
      hirac_t[i]=-999;
      hirac_t_trail[i]=-999;
      hirac_q[i]=-999;   
  }

  // Etaprime-TORCH
  for(int i=0;i<6;i++){
      torch_t[i]=-999;
      torch_t_trail[i]=-999;
      torch_q[i]=-999;
  }

  // Etaprime-miniHIRAC
  for(int i=0;i<2;i++){
      mini_t[i]=-999;
      mini_t_trail[i]=-999;
      mini_q[i]=-999;
  }
  
  // Etaprime-scaler
  for(int i=0;i<32;i++){
    etap_scaler[i]=-999;
  }
  
  // Etaprime-scaler
  for(int i=0;i<32;i++){
    mh_scaler[i]=-999;
  }  

}

ClassImp(TFRSSortEvent)
