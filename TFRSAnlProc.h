#ifndef TFRSANLPROC_H
#define TFRSANLPROC_H
#include "TFRSBasicProc.h"

 class TFRSAnlEvent;
 class TFRSSortEvent;
 class TFRSCalibrEvent;

 class TFRSUnpackEvent;

 class TFRSAnlProc : public TFRSBasicProc {
    public:
       TFRSAnlProc();
       TFRSAnlProc(const char* name);
       void FRSEventAnalysis(TFRSAnlEvent* target);
       virtual ~TFRSAnlProc() ;

		Bool_t bDrawHist;

    private:

     

   ClassDef(TFRSAnlProc,1)
};

#endif //--------------- TFRSANLPROC_H
