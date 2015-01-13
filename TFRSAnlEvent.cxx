#include "TFRSAnlEvent.h"
#include "Riostream.h"
#include "Go4EventServer/TGo4FileSource.h"
#include "TFRSAnlProc.h"

TFRSAnlEvent::TFRSAnlEvent() :TGo4EventElement("FRSAnlEvent"), fxProc(0), fxFileSrc(0) { 
}

TFRSAnlEvent::TFRSAnlEvent(const char* name) :TGo4EventElement(name), fxProc(0), fxFileSrc(0) { 
}

TFRSAnlEvent::~TFRSAnlEvent() { 
}

Int_t TFRSAnlEvent::Init() { 
//--- check for different source types
  Int_t rev = 0;
  if(CheckEventSource("TFRSAnlProc")) {
    fxProc = (TFRSAnlProc*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by " << fxProc->GetName() << " ****" << endl;
  } else 
  if(CheckEventSource("TGo4FileSource")) {
    fxFileSrc = (TGo4FileSource*)GetEventSource();
    cout << "**** " << GetName() << " will be filled by File Source ****"<< endl;
  }
  else rev=1;
  return rev;
}


Int_t TFRSAnlEvent::Fill() 
{
   Clear();
   if(fxProc) fxProc->FRSEventAnalysis(this); else
   if(fxFileSrc)fxFileSrc->BuildEvent(this); // method from framework to restore event from file

   return 0;
}

void TFRSAnlEvent::Clear(Option_t *t) {

}

ClassImp(TFRSAnlEvent)

