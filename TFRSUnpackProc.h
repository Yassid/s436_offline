#ifndef TFRSUNPACKPROCESSOR_H
#define TFRSUNPACKPROCESSOR_H

#include "TFRSBasicProc.h"



class TFRSUnpackEvent;
class TGo4MbsSubEvent;

class TFRSUnpackProc : public TFRSBasicProc {
   public:
      TFRSUnpackProc() ;
      TFRSUnpackProc(const char* name);
      virtual ~TFRSUnpackProc();
   
      void FRSUnpack(TFRSUnpackEvent* tgt);
      
   private:

      void UnpackUserSubevent(TGo4MbsSubEvent* psubevt, TFRSUnpackEvent* tgt);

   
      TH1I* MakeH1ISeries(const char* foldername,
			  const char* histo_name, 
                          Int_t seriesnumber,
                          Int_t crate,
                          Int_t number,
                          Bool_t remove); 
      TH1I* MakeH1ISeries4(const char* foldername,
                          Int_t seriesnumber,
                          Int_t crate,
                          Int_t number,
                          Bool_t remove);  
   
      TH1I* MakeH1ISeriesV830(const char* foldername,
			  const char* histo_name, 
                          Int_t seriesnumber,
                          Int_t crate,
                          Int_t number,
                          Bool_t remove);
      TH1I* MakeH1ISeriesV1290(const char* foldername,
			  const char* histo_name, 
                          Int_t seriesnumber,
                          Int_t crate,
                          Int_t number,
                          Bool_t remove);                      
                      
      TH1I* MakeH1ISeries3(const char* foldername,
			   Int_t seriesnumber,
			   Int_t crate,
			   Int_t number,
			   Bool_t remove);  

    
      TGo4Picture* MakeSeriesPicture(const char* foldername,
                                     Int_t seriesnumber,
                                     Bool_t remove);              
                
      TH1I            *hTrigger;
      TH1I            *hAMSCL_0[64];
      TH1I            *hAMSCL_1[64];
      TH1I            *hAMSCL_2[64];
      TH1I            *hAMSCL_3[64];
      TH1I            *hAMSCL_4[64];
      TH1I            *hAMSCL_5[64];
      TH1I            *hAMSCL_6[64];
      TH1I            *hAMSCL_7[64];
      TH1I            *hAMSCL_8[64];
      TH1I            *hAMSCL_9[64];
      TH1I            *hAMSCL_10[64];
      TH1I            *hAMSCL_11[64];
      TH1I            *hAMSCL_12[64];
      TH1I            *hAMSCL_13[64];
      TH1I            *hAMSCL_14[64];
      TH1I            *hAMSCL_15[64];    
      TH1I            *hAMSCT_0[64];
      TH1I            *hAMSCT_1[64];
      TH1I            *hAMSCT_2[64];
      TH1I            *hAMSCT_3[64];
      TH1I            *hAMSCT_4[64];
      TH1I            *hAMSCT_5[64];
      TH1I            *hAMSCT_6[64];
      TH1I            *hAMSCT_7[64];
      TH1I            *hAMSCT_8[64];
      TH1I            *hAMSCT_9[64];
      TH1I            *hAMSCT_10[64];
      TH1I            *hAMSCT_11[64];
      TH1I            *hAMSCT_12[64];
      TH1I            *hAMSCT_13[64];
      TH1I            *hAMSCT_14[64];
      TH1I            *hAMSCT_15[64];
      TH1I            *hAMSC_MODULE_LEN[16];
      TH1I            *hAMSC_ERROR;
      //V775(TDC, tensor)
      TH1I            *hV775T[32]; // time
      TH1I            *hV775_LENGTH;
      TH1I            *hV775_ITRY;
      //V830(scaler)
      TH1I            *hV830N[32];
      TH1I            *hV830_LENGTH;
      TH1I            *hV830_ITRY;
      //V1290(TDC)
      TH1I            *hV1290L_0[32]; // leading time
      TH1I            *hV1290L_1[32]; // leading time
      TH1I            *hV1290T_0[32]; // trailing time
      TH1I            *hV1290T_1[32]; // trailing time
      TH1I            *hV1290_LENGTH[2];
      TH1I            *hV1290_ITRY[2];
      //V792(QDC)
      TH1I            *hV792Q_0[16];
      TH1I            *hV792Q_1[16];
      TH1I            *hV792_LENGTH[2];
      TH1I            *hV792_ITRY[2];
      //V1742(fADC)
      TH1I            *hV1742Q[32];
      TH1I            *hV1742T[32];
      TH1I            *hV1742B[32];
      
      TH1I            *hV1742V[32];
      TH2I            *hV1742VT[32];
      TH2I            *hV1742VT_CUT[32];
      //V830 (in fadc crate inside MH) 
      TH1I            *hV830N_MH[32];
      TH1I            *hV830_LENGTH_MH;
      TH1I            *hV830_ITRY_MH;

   //
      Int_t cntBELENWarning;

      TH1I            *hVME0_8[32];      //! FRS crate
      TH1I            *hVME0_9[32];      //!
      TH1I            *hVME0_11[32];     //!
      TH1I            *hVME0_12[32];     //!
      TH1I            *hVME0_13[32];     //!
      TH1I            *hVME0_14[32];     //!

      TH1I            *hVME1_8[32];      //! TPC User crate
      TH1I            *hVME1_9[32];      //!
      TH1I            *hVME1_16[32];     //!
      TH1I            *hVME1_17[32];     //!      
      TH1I            *hVME2_TDC[32];
            

   ClassDef(TFRSUnpackProc,1)
};

#endif //TFRSUNPACKPROCESSOR_H

