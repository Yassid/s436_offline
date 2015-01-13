#include "TFRSUserEvent.h"

#include "TFRSUserProc.h"

TFRSUserEvent::TFRSUserEvent() : 
   TGo4EventElement("FRSUserEvent"), fxProc(0) { 
}

TFRSUserEvent::TFRSUserEvent(Text_t * name) 
  :TGo4EventElement(name), fxProc(0) { 
}

TFRSUserEvent::~TFRSUserEvent() { 
}

Int_t TFRSUserEvent::Init() { 
  Int_t rev=0;
  Clear();
  if(CheckEventSource("TFRSUserProc")){
    fxProc = (TFRSUserProc*)GetEventSource();
  } else rev=1;
  return rev;
}

Int_t TFRSUserEvent::Fill() { 
  Clear();
  if(fxProc) fxProc->FRSUserProc(this);  // user event processing method
  return 0;
}

void TFRSUserEvent::Clear(Option_t *t) { 
}

ClassImp(TFRSUserEvent)
