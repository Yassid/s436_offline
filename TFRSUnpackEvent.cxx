#include "TFRSUnpackEvent.h"
#include "Riostream.h"
#include "TFRSUnpackProc.h"
#include "Go4EventServer/TGo4FileSource.h"

TFRSUnpackEvent::TFRSUnpackEvent() : TGo4EventElement("FRSUnpackEvent"),
  fxProc(0),fxFileSrc(0) { 
}

TFRSUnpackEvent::TFRSUnpackEvent(const char* name) 
  :TGo4EventElement(name), fxProc(0), fxFileSrc(0) { 
}

TFRSUnpackEvent::~TFRSUnpackEvent() { 
}

Int_t TFRSUnpackEvent::Init() 
{ 
  Int_t rev=0;
  Clear();
  if(CheckEventSource("TFRSUnpackProc")){
    fxProc = (TFRSUnpackProc*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by " << fxProc->GetName() << " ****" << endl;
  } else
  if(CheckEventSource("TGo4FileSource")) {
    fxFileSrc = (TGo4FileSource*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by File Source ****"<< endl;
  } else rev=1;
  return rev;
}

Int_t TFRSUnpackEvent::Fill() { 
  Int_t rev=0;
  Clear();
  if(fxProc)fxProc->FRSUnpack(this); else  // user event processing method
  if(fxFileSrc)fxFileSrc->BuildEvent(this); // method from framework to restore event from file
  return rev;
}

void TFRSUnpackEvent::Clear(Option_t *t) { 



  //----amsc----
  for(int i=0;i<16;i++){
     for(int j=0;j<64;j++){
       amscl[i][j] = -999;  
       amsct[i][j] = -999;
     }
     amsc_length[i]=-999;
     amsc_error[i] =-999;
     amsc_itry[i]  =-999;
  }   
  
  //----v830----
  for(int i=0;i<32;i++){
    v830n[i] = -999;
  }
  v830_length = -999;
  v830_itry   = -999;

 
  //----v830_MH----
  for(int i=0;i<32;i++){
    v830n_mh[i] = -999;
  }
  v830_length_mh = -999;
  v830_itry_mh   = -999;
  
  //-----v1742-----
  for(int i=0; i<32; i++){
    v1742q[i]=-999.;
    v1742t[i]=-999.;
    v1742baseline[i]=-999.;
    v1742valid[i]=-999;
    v1742_length=-999;
    v1742_itry=-999;
  }
  
  //----v1290 and v792-----
  for(int i=0;i<2;i++){
    for(int j=0;j<32;j++){
      v1290l[i][j]=-999999;  
      v1290t[i][j]=-999999;
      v1290ml[i][j]=0;
      v1290mt[i][j]=0;  
      v792q[i][j]=-999;
    }
    v1290_length[i]=-999;
    v1290_itry[i]  =-999;
    v792_length[i]=-999;
    v792_itry[i]  =-999;
  }  
  
  //----v775-----
  for(int i=0;i<32;i++){
    v775t[i] = -999;
  }
  v775_length = -999;
  v775_itry   = -999;
  
  //
  qlength = 0;
  qtype = 0;
  qsubtype = 0;
  qdummy = 0;
  qtrigger = 0;
  qevent_nr = 0;
}

ClassImp(TFRSUnpackEvent)
