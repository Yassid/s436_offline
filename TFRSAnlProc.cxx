#include "TFRSAnlProc.h"
#include "TH1.h"
#include "TH2.h"
#include "Go4ConditionsBase/TGo4WinCond.h"
#include "Go4ConditionsBase/TGo4PolyCond.h"
#include "Go4ConditionsBase/TGo4CondArray.h"
#include "TFRSAnlEvent.h"
#include "TFRSSortEvent.h"
#include "TFRSCalibrEvent.h"
#include "TFRSParameter.h"


#include <stdlib.h>

//#include "Go4Analysis/TGo4Analysis.h"


TFRSAnlProc::TFRSAnlProc() : TFRSBasicProc("FRSAnlProc") {
}

TFRSAnlProc::TFRSAnlProc(const char* name): TFRSBasicProc(name) { 

  bDrawHist=kTRUE;
  
  
  
  

   TGo4CondArray* conarr = MakeCondArray(0, "Integral", 5);
   if (ObjWasCreated()) {
       ((*conarr)[0])->SetValues(0,10);
       ((*conarr)[1])->SetValues(20,30);
       ((*conarr)[2])->SetValues(40,50);
       ((*conarr)[3])->SetValues(60,70);
       ((*conarr)[4])->SetValues(80,90);
   }

}

TFRSAnlProc::~TFRSAnlProc() {
}

void TFRSAnlProc::FRSEventAnalysis(TFRSAnlEvent* poutevt) {
    
  poutevt->SetValid(kTRUE);  // events always accepted

	bDrawHist=kTRUE;

  TFRSSortEvent *srt = dynamic_cast<TFRSSortEvent*> (GetInputEvent("Calibr"));
  TFRSCalibrEvent *clb = dynamic_cast<TFRSCalibrEvent*> (GetInputEvent());
  
  if ((srt==0) || (clb==0)) return;

  // Procceed_MUSIC_Analysis(*srt, *clb, *poutevt);
  //  Procceed_SCI_Analysis(*srt, *clb, *poutevt);
  //  Procceed_ID_Analysis(*srt, *clb, *poutevt);
  //  Procceed_ITAG_Analysis(*srt, *clb, *poutevt);
	if (bDrawHist) {
//	  Procceed_SIMBA_Analysis(*srt, *clb, *poutevt);
//	  Procceed_ShiftCheck_Analysis(*srt, *clb, *poutevt);
	}
  
  //Procceed_Tree_Output(*srt,*clb,*poutevt);
}

ClassImp(TFRSAnlProc)
