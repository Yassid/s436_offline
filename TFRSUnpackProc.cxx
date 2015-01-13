

#include "TFRSUnpackProc.h"
#include "TH1.h"
#include "TH2.h"
#include "Go4StatusBase/TGo4Picture.h"
#include "Go4EventServer/TGo4MbsEvent.h"
#include "TFRSAnalysis.h"
#include "TFRSUnpackEvent.h"
#include "TFRSParameter.h"
#include  <stdio.h>



TFRSUnpackProc::TFRSUnpackProc() : TFRSBasicProc("FRSUnpackProc") {
}

TFRSUnpackProc::TFRSUnpackProc(const char* name) : 
   TFRSBasicProc(name) 
{ 
  hTrigger = MakeH1I("Raw data", "newTrigger", 16, 0.5, 16.5); 

  TFRSParameter* frs = (TFRSParameter*) GetParameter("FRSPar");
 
  bool remove_histos = (frs!=0) && (!frs->fill_raw_histos);

 
  for(int i_amsc=0; i_amsc<16; i_amsc++){
    char foldername_amsc_module_len[100];
    char fullname_amsc_module_len[100];
    sprintf(foldername_amsc_module_len, "Raw data/Status/AMSC_LENGTH");
    sprintf(fullname_amsc_module_len, "AMSC_LENGTH_%d",i_amsc);
    hAMSC_MODULE_LEN[i_amsc] = MakeH1I(foldername_amsc_module_len, fullname_amsc_module_len,101,-0.5,100.5, "Length of AMSC Data",2,3);
  }
  char foldername_amsc_error[100];
  char fullname_amsc_error[100];
  sprintf(foldername_amsc_error, "Raw data/Status/AMSC_ERROR");
  sprintf(fullname_amsc_error, "AMSC_ERROR");
  hAMSC_ERROR    = MakeH1I(foldername_amsc_error, fullname_amsc_error, 32, -0.5, 31.5, "ERROR Module ID",2,3);
  for(int n=0;n<64;n++) {
    hAMSCL_0[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  0, 10, n, remove_histos);
    hAMSCL_1[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  1, 10, n, remove_histos);
    hAMSCL_2[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  2, 10, n, remove_histos);
    hAMSCL_3[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  3, 10, n, remove_histos); 
    hAMSCL_4[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  4, 10, n, remove_histos);
    hAMSCL_5[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  5, 10, n, remove_histos);
    hAMSCL_6[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  6, 10, n, remove_histos);
    hAMSCL_7[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  7, 10, n, remove_histos); 
    hAMSCL_8[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  8, 10, n, remove_histos);
    hAMSCL_9[n]  = MakeH1ISeries("Raw data/AMSCL","amscl",  9, 10, n, remove_histos);
    hAMSCL_10[n] = MakeH1ISeries("Raw data/AMSCL","amscl", 10, 10, n, remove_histos); 
    hAMSCL_11[n] = MakeH1ISeries("Raw data/AMSCL","amscl", 11, 10, n, remove_histos);
    hAMSCL_12[n] = MakeH1ISeries("Raw data/AMSCL","amscl", 12, 10, n, remove_histos);
    hAMSCL_13[n] = MakeH1ISeries("Raw data/AMSCL","amscl", 13, 10, n, remove_histos);
    hAMSCL_14[n] = MakeH1ISeries("Raw data/AMSCL","amscl", 14, 10, n, remove_histos); 
    hAMSCL_15[n] = MakeH1ISeries("Raw data/AMSCL","amscl", 15, 10, n, remove_histos);
    //
    hAMSCT_0[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  0, 10, n, remove_histos);
    hAMSCT_1[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  1, 10, n, remove_histos);
    hAMSCT_2[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  2, 10, n, remove_histos);
    hAMSCT_3[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  3, 10, n, remove_histos); 
    hAMSCT_4[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  4, 10, n, remove_histos);
    hAMSCT_5[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  5, 10, n, remove_histos);
    hAMSCT_6[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  6, 10, n, remove_histos);
    hAMSCT_7[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  7, 10, n, remove_histos); 
    hAMSCT_8[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  8, 10, n, remove_histos);
    hAMSCT_9[n]  = MakeH1ISeries("Raw data/AMSCT","amsct",  9, 10, n, remove_histos);
    hAMSCT_10[n] = MakeH1ISeries("Raw data/AMSCT","amsct", 10, 10, n, remove_histos);
    hAMSCT_11[n] = MakeH1ISeries("Raw data/AMSCT","amsct", 11, 10, n, remove_histos);
    hAMSCT_12[n] = MakeH1ISeries("Raw data/AMSCT","amsct", 12, 10, n, remove_histos);
    hAMSCT_13[n] = MakeH1ISeries("Raw data/AMSCT","amsct", 13, 10, n, remove_histos); 
    hAMSCT_14[n] = MakeH1ISeries("Raw data/AMSCT","amsct", 14, 10, n, remove_histos);
    hAMSCT_15[n] = MakeH1ISeries("Raw data/AMSCT","amsct", 15, 10, n, remove_histos);
  }
  
  //
  //
  //-----v775------
  hV775_LENGTH    = MakeH1I("Raw data/Status", "v775datalen", 50, -0.5, 49.5, "V775 Data Length [word]",2,3);
  hV775_ITRY      = MakeH1I("Raw data/Status", "v775itry", 20, -5.5, 14.5, "V775 ITRY ",2,3);
  for(int n=0;n<32;n++) {
    hV775T[n]    = MakeH1ISeries("Raw data/V775","v775t",0,10,n,remove_histos); 
  }

  //------v830------
  hV830_LENGTH    = MakeH1I("Raw data/Status", "v830datalen", 50, -0.5, 49.5, "V830 Data Length [word]",2,3);
  hV830_ITRY      = MakeH1I("Raw data/Status", "v830itry", 20, -5.5, 14.5, "V830 ITRY ",2,3);
  for(int n=0;n<32;n++) {
    hV830N[n]    = MakeH1ISeriesV830("Raw data/V830","v830",0,10,n,remove_histos); 
  }

  //------v830 in messuhueete------
  hV830_LENGTH_MH    = MakeH1I("Raw data/Status", "v830datalen_mh", 50, -0.5, 49.5, "V830(MH) Data Length [word]",2,3);
  hV830_ITRY_MH      = MakeH1I("Raw data/Status", "v830itry_mh", 20, -5.5, 14.5, "V830(MH) ITRY ",2,3);
  for(int n=0;n<32;n++) {
    hV830N_MH[n]    = MakeH1ISeriesV830("Raw data/V830_MH","v830_mh",0,10,n,remove_histos); 
  }


  //------v792------
  hV792_LENGTH[0]    = MakeH1I("Raw data/Status", "v792datalen0", 60, -0.5, 59.5, "V792 Data Length [word]",2,3);
  hV792_LENGTH[1]    = MakeH1I("Raw data/Status", "v792datalen1", 60, -0.5, 59.5, "V792 Data Length [word]",2,3);
  hV792_ITRY[0]      = MakeH1I("Raw data/Status", "v830itry0", 20, -5.5, 14.5, "V792 ITRY",2,3);
  hV792_ITRY[1]      = MakeH1I("Raw data/Status", "v830itry1", 20, -5.5, 14.5, "V792 ITRY ",2,3);
  for(int n=0;n<16;n++) {
    hV792Q_0[n]  = MakeH1ISeries("Raw data/V792","v792q",  0, 10, n, remove_histos);
    hV792Q_1[n]  = MakeH1ISeries("Raw data/V792","v792q",  1, 10, n, remove_histos);
  }
  
  //------v1290------
  hV1290_LENGTH[0]    = MakeH1I("Raw data/Status", "v1290datalen0", 60, -0.5, 59.5, "V1290 Data Length [word]",2,3);
  hV1290_LENGTH[1]    = MakeH1I("Raw data/Status", "v1290datalen1", 60, -0.5, 59.5, "V1290 Data Length [word]",2,3);
  hV1290_ITRY[0]      = MakeH1I("Raw data/Status", "v1290itry0", 20, -5.5, 14.5, "V1290 ITRY",2,3);
  hV1290_ITRY[1]      = MakeH1I("Raw data/Status", "v1290itry1", 20, -5.5, 14.5, "V1290 ITRY ",2,3);
  for(int n=0;n<32;n++) {
    hV1290L_0[n]  = MakeH1ISeriesV1290("Raw data/V1290-L","v1290l_0",  0, 10, n, remove_histos);
    hV1290L_1[n]  = MakeH1ISeriesV1290("Raw data/V1290-L","v1290l_1",  1, 10, n, remove_histos);
    hV1290T_0[n]  = MakeH1ISeriesV1290("Raw data/V1290-T","v1290t_0",  0, 10, n, remove_histos);
    hV1290T_1[n]  = MakeH1ISeriesV1290("Raw data/V1290-T","v1290t_1",  1, 10, n, remove_histos);
  }


  //------v1742------
  for(int n=0;n<8;n++) {
    char fullname_v1742vt[100];
    char fullname_v1742vt_cut[100];
    hV1742Q[n]  = MakeH1ISeries("Raw data/V1742Q","v1742q",  0, 10, n, remove_histos);
    hV1742T[n]  = MakeH1ISeries("Raw data/V1742T","v1742t",  0, 10, n, remove_histos);
    hV1742B[n]  = MakeH1ISeries("Raw data/V1742B","v1742b",  0, 10, n, remove_histos);
    hV1742V[n]  = MakeH1ISeries("Raw data/V1742V","v1742v",  0, 10, n, remove_histos);
    sprintf(fullname_v1742vt,"v1742vt_%d",n);
    sprintf(fullname_v1742vt_cut,"v1742vt_cut_%d",n);
    hV1742VT[n] = MakeH2I("Raw data/V1742VT", fullname_v1742vt , 130, 0.0, 130.0, 1024, -0.5, 4095.5, "i_sample","voltage", 2);
    hV1742VT_CUT[n] = MakeH2I("Raw data/V1742VT_CUT", fullname_v1742vt_cut , 130, 0.0, 130.0, 1024, -0.5, 4095.5, "i_sample","voltage", 2);
  }
  
  

  for(int n=0;n<32;n++) {
    
    hVME0_8[n]  = MakeH1ISeries4("Raw data/VME0",  8, 0, n, remove_histos);
    hVME0_9[n]  = MakeH1ISeries4("Raw data/VME0",  9, 0, n, remove_histos);
    hVME0_11[n] = MakeH1ISeries4("Raw data/VME0", 11, 0, n, remove_histos);
    hVME0_12[n] = MakeH1ISeries4("Raw data/VME0", 12, 0, n, remove_histos);
  
    hVME1_8[n]  = MakeH1ISeries4("Raw data/VME1", 8, 1, n, remove_histos);
    hVME1_9[n]  = MakeH1ISeries4("Raw data/VME1", 9, 1, n, remove_histos);
    hVME1_16[n] = MakeH1ISeries4("Raw data/VME1", 16, 1, n, remove_histos);
    hVME1_17[n] = MakeH1ISeries4("Raw data/VME1", 17, 1, n, remove_histos);
  }

  cntBELENWarning =0;
}

TFRSUnpackProc::~TFRSUnpackProc(){
}


TH1I* TFRSUnpackProc::MakeH1ISeries4(const char* foldername,
                                    Int_t seriesnumber,
                                    Int_t crate,
                                    Int_t number,
                                    Bool_t remove) {
  char fullfoldername[100];                                    
  sprintf(fullfoldername,"%s/%02d", foldername, seriesnumber);
  char histoname[50];
  sprintf(histoname,"newVME%02d_%02d_%02d", crate, seriesnumber, number); 
  if (remove) {
    char fullname[200]; 
    sprintf(fullname,"%s/%s",fullfoldername,histoname);
    RemoveHistogram(fullname); 
    return 0;   
  }
  return MakeH1I(fullfoldername, histoname, 4096, 0, 4096);
}



TH1I* TFRSUnpackProc::MakeH1ISeries(const char* foldername, const char* histo_name,
                                    Int_t seriesnumber,
                                    Int_t crate,
                                    Int_t number,
                                    Bool_t remove) {
   char fullfoldername[100];                                    
   sprintf(fullfoldername,"%s/%02d", foldername, seriesnumber);
   char histoname[50];
   sprintf(histoname,"newVME%s%02d_%02d_%02d",histo_name, crate, seriesnumber, number); 
   if (remove) {
      char fullname[200]; 
      sprintf(fullname,"%s/%s",fullfoldername,histoname);
      RemoveHistogram(fullname); 
      return 0;   
   }
   return MakeH1I(fullfoldername, histoname, 4096, 0, 4096);
}


TH1I* TFRSUnpackProc::MakeH1ISeriesV830(const char* foldername, const char* histo_name,
                                    Int_t seriesnumber,
                                    Int_t crate,
                                    Int_t number,
                                    Bool_t remove) {
   char fullfoldername[100];                                    
   sprintf(fullfoldername,"%s/%02d", foldername, seriesnumber);
   char histoname[50];
   sprintf(histoname,"newVME%s%02d_%02d_%02d",histo_name, crate, seriesnumber, number); 
   if (remove) {
      char fullname[200]; 
      sprintf(fullname,"%s/%s",fullfoldername,histoname);
      RemoveHistogram(fullname); 
      return 0;   
   }
   return MakeH1I(fullfoldername, histoname, 0x100, 0, 0xFFFFFFFF);
}


TH1I* TFRSUnpackProc::MakeH1ISeriesV1290(const char* foldername, const char* histo_name,
                                    Int_t seriesnumber,
                                    Int_t crate,
                                    Int_t number,
                                    Bool_t remove) {
   char fullfoldername[100];                                    
   sprintf(fullfoldername,"%s/%02d", foldername, seriesnumber);
   char histoname[50];
   sprintf(histoname,"newVME%s%02d_%02d_%02d",histo_name, crate, seriesnumber, number); 
   if (remove) {
      char fullname[200]; 
      sprintf(fullname,"%s/%s",fullfoldername,histoname);
      RemoveHistogram(fullname); 
      return 0;   
   }
   return MakeH1I(fullfoldername, histoname, 10000,-20000,80000);
}


TH1I* TFRSUnpackProc::MakeH1ISeries3(const char* foldername,
				     Int_t seriesnumber,
				     Int_t crate,
				     Int_t number,
				     Bool_t remove) 
{
  char fullfoldername[100];                                    
  sprintf(fullfoldername,"%s/%02d", foldername, seriesnumber);
  char histoname[50];
  sprintf(histoname,"newVME%02d_%02d_%02d", crate, seriesnumber, number); 
  if (remove) {
    char fullname[200]; 
    sprintf(fullname,"%s/%s",fullfoldername,histoname);
    RemoveHistogram(fullname); 
    return 0;   
  }
  return MakeH1I(fullfoldername, histoname, 8192, 0, 262144);
}
TGo4Picture* TFRSUnpackProc::MakeSeriesPicture(const char* foldername,
                                               Int_t seriesnumber,
                                               Bool_t remove) {
   char picname[100];
   sprintf(picname,"Pic_VME0_%02d", seriesnumber);
   
   if (remove) {
      char fullname[200]; 
      sprintf(fullname,"%s/%s",foldername,picname);
      RemovePicture(fullname); 
      return 0;   
   }
   
   TGo4Picture* pic = MakePic(foldername, picname, 4, 8);
   
   if (ObjWasCreated())
     for(int i=0;i<4;i++)
       for(int j=0;j<8;j++) {
         char histoname[100];
         sprintf(histoname,"newVME0_%02d_%02d", seriesnumber, i*8+j);    
         pic->AddObjName(i, j, histoname);
      }
      
   return pic;
}

Int_t getbits(Int_t value, int nword, int start, int length) {
   UInt_t buf = (UInt_t) value;
   buf = buf >> ((nword-1)*16 + start - 1);
   buf = buf & ((1 << length) - 1);
   return buf;
}

Int_t get2bits(Int_t value, int nword, int start, int length) {
  UInt_t buf = (UInt_t) value;
  buf = buf >> ((nword-1)*32 + start - 1);
  buf = buf & ((1 << length) - 1);
  return buf;
}

void TFRSUnpackProc::UnpackUserSubevent(TGo4MbsSubEvent* psubevt, TFRSUnpackEvent* tgt)
{

  Int_t *pdata = psubevt->GetDataField();	
  Int_t len = 0;  

  /* read the header longword and extract slot, type & length  */
  Int_t vme_geo = getbits(*pdata,2,12,5);
  //Int_t vme_type = getbits(*pdata,2,9,3);
  Int_t vme_nlw =  getbits(*pdata,1,1,6);
  pdata++; len++;

  /* read the data from scaler */
  if (vme_nlw > 0) {
    for(int i=0;i<vme_nlw;i++) {
      tgt->vme1[vme_geo][i] = *pdata;
      pdata++; len++;
    }
    /* read and ignore the expected "end-of-block" longword   */
    pdata++; len++;
  }

  /* for ProcID = 20 - rest of the unpacking */

  while (len < (psubevt->GetDlen()-2)/2) {
    
    /* read the header longword and extract slot, type & length  */
    Int_t vme_chn = 0;
    Int_t vme_geo = getbits(*pdata,2,12,5);
    Int_t vme_type = getbits(*pdata,2,9,3);
    Int_t vme_nlw =  getbits(*pdata,1,1,6);
    pdata++; len++;

    //    cout<<"type = "<<vme_type<<"nlw = "<<vme_nlw<<endl;
    /* read the data */
    if ((vme_type == 2) && (vme_nlw > 0)) {
      for(int i=0;i<vme_nlw;i++) {  
	vme_geo = getbits(*pdata,2,12,5);
	vme_type = getbits(*pdata,2,9,3);
	vme_chn = getbits(*pdata,2,1,5);
	tgt->vme1[vme_geo][vme_chn] = getbits(*pdata,1,1,16);	                 
	//printf("DATA:%d %d %d\n",vme_geo,vme_chn,tgt->vme1[vme_geo][vme_chn] ); 
	pdata++; len++;
      }
      
      /* read and ignore the expected "end-of-block" longword */
      pdata++; len++;
    }
	  
  }  /* end of the while... loop  */
		
  TFRSParameter* frs = (TFRSParameter*) GetParameter("FRSPar");

  if ((frs!=0) && frs->fill_raw_histos)
    for(int i=0;i<32;i++) {
      if (hVME1_8[i]) hVME1_8[i]->Fill(tgt->vme1[8][i] & 0xfff);
      if (hVME1_9[i]) hVME1_9[i]->Fill(tgt->vme1[9][i] & 0xfff);
      if (hVME1_16[i]) hVME1_16[i]->Fill(tgt->vme1[15][i] & 0xfff);
      if (hVME1_17[i]) hVME1_17[i]->Fill(tgt->vme1[17][i] & 0xfff);


    }
}  

void TFRSUnpackProc::FRSUnpack(TFRSUnpackEvent* tgt) 
{
  
  TFRSParameter* frs = (TFRSParameter*) GetParameter("FRSPar");
  TMWDCParameter* mwdc = (TMWDCParameter*) GetParameter("MWDCPar");
  tgt->SetValid(kFALSE);  // by default output event rejected
  TGo4MbsEvent *fInput = dynamic_cast<TGo4MbsEvent*> (GetInputEvent());
  if (fInput==0) return;
  
/* ---------------------- ProcID = 10 ------------------ */
/*  Check that the EVENT type and subtype are OK:  */
  if((fInput->GetType()!=10) || (fInput->GetSubtype()!=1)) {
    cout << "Wrong event type " << fInput->GetType() << endl;
    return;
    //  }else{
    //    cout << "Good event type " << fInput->GetType() << endl;
    //    return;
  }
  
  if (frs->fill_raw_histos) {
    hTrigger->Fill(fInput->GetTrigger());
  }

  // If trigger 14 or 15, event fully can be skipped
  if((fInput->GetTrigger()==14) || (fInput->GetTrigger()==15)) {
    //cout << "Trigger = " << fInput->GetTrigger() << ", event skipped" << endl;
     return;
  }

  /*  Put the event header stuff into output event  */
  tgt->qlength   = fInput->GetDlen()   ;
  tgt->qtype     = fInput->GetType()   ;
  tgt->qsubtype  = fInput->GetSubtype();
  tgt->qdummy    = fInput->GetDummy()  ;
  tgt->qtrigger  = fInput->GetTrigger();
  tgt->qevent_nr = fInput->GetCount()  ;

  // Special event
  if(fInput->GetCount()!=0) {

   // cout << "qtype : " << fInput->GetType() << endl;  
   // cout << "qlength(=GetDLen) : " << tgt->qlength  << endl;
   // cout << "qsubtype : " <<  tgt->qsubtype << endl;
  /*  Check event length: if it's <= 4 it is empty or screwed up! */
  
  if(fInput->GetDlen()<=4) {
     cout << "Wrong event length: " << fInput->GetDlen() << " =< 4" << endl;
     return;
  }
  
  /*  Event OK, now assign pointer to local subevent header! */
  //cout << "trigger = " << fInput->GetTrigger() << endl;

  fInput->ResetIterator();
  TGo4MbsSubEvent *psubevt = 0;

	while ((psubevt=fInput->NextSubEvent())!= 0)  // start subevents loop
	{
		//    printf("TRI:%d\n",fInput->GetTrigger());
		//printf("PROC:%d\n",psubevt->GetProcid());
		//cout << "subevent control " << int(psubevt->GetControl()) << endl;
		//cout << "cratesubevent : " << int(psubevt->GetSubcrate()) << endl; 
 
	  //	if (psubevt->GetControl()==29)  // for tpc crate
	  if((psubevt->GetProcid())==20)
	{
		if (fInput->GetTrigger()==1 || fInput->GetTrigger()==2 || fInput->GetTrigger()==3 || fInput->GetTrigger()==12 || fInput->GetTrigger()==13) 
		UnpackUserSubevent(psubevt, tgt);
		continue;
	}

    /* check for ProcID 10 = standard crate  */
    //    if((psubevt->GetProcid())!=10) {
	if((1!=psubevt->GetProcid()) && (10!=psubevt->GetProcid()) &&(20!=psubevt->GetProcid()) &&(30!=psubevt->GetProcid()) &&(40!=psubevt->GetProcid())){
      cout << "Wrong ProcID " << psubevt->GetProcid() << endl; 
      continue; // skip non standard event
    }
    
    /*  Check the SUBevent type and subtype!  */
    if((psubevt->GetType()!=10) || (psubevt->GetSubtype()!=1) ) {  // for all data 
              cout << "getsubtype " << psubevt->GetSubtype() << endl;
              cout << "gettype " << psubevt->GetType() << endl;
              cout << "Wrong subevent type " << psubevt->GetType() << endl;
              continue; // skip subevent SL
    }

     
    /*    Now select subcrate number:  */
    if((psubevt->GetSubcrate())!=0) {
      cout << "Non supported subcrate " << psubevt->GetSubcrate() << endl;
      continue; // skip subevent SL
    }
         
    /************************************************************************/
    /* Here we go for the different triggers.....                           */
    /************************************************************************/
    
    switch(fInput->GetTrigger()) {  // all-of-FRS readout trigger:  

    	case 1:
    	case 2:
    	case 3:
    	case 12: // start of extraction
    	case 13: // end of extraction 
		{
        switch(psubevt->GetProcid()) {
	             case 1 :
                     case 10: {  // proc ID=10 - FRS CRATE
	  
		       // get pointer on data   
		       Int_t *pdata = psubevt->GetDataField();
		       Int_t len = 0;
		       
		       /** \note FRS TIME STAMP module data (3 longwords)   
			*   has no header or end-of-block info, we must hardwire GEO = 20.
			*/
		       pdata++; len++; // 0x200
		       
		       Int_t vme_chn = 0;
		       /*
			 for (int i=0;i<3;i++) {
			 tgt->vme0[20][vme_chn++] = getbits(*pdata,1,1,16);
			 tgt->vme0[20][vme_chn++] = getbits(*pdata,2,1,16);
			 pdata++; len++;
			 }
		       */
		       
	  /** \note FRS SCALER module data (1 longword per channel)   
	   *  This module has sequential readout therefore no channel
	   *  number contained in the data longwords. 
	   */
 /*
	  // read the header longword and extract slot, type & length  
	  Int_t vme_geo = getbits(*pdata,2,12,5);
	  Int_t vme_type = getbits(*pdata,2,9,3);
	  Int_t vme_nlw =  getbits(*pdata,1,1,6);
	  pdata++; len++;
	  
	  // read the data 
	  if (vme_nlw > 0) {
	    for(int i=0;i<vme_nlw;i++) {
	      tgt->vme0[vme_geo][i] = *pdata;
	      pdata++; len++;
	    }
	    // cout<<"1Hz unpack, "<<tgt->vme0[6][3]<<endl;
	    // read and ignore the expected "end-of-block" longword   
	    pdata++; len++;
	  }
 */
	  //  now start with the REST of the unpacking...       
	  
	  while (len < (psubevt->GetDlen()-2)/2) {
	    
	    // read the header longword and extract slot, type & length  
	    Int_t vme_geo = getbits(*pdata,2,12,5);
	    Int_t vme_type = getbits(*pdata,2,9,3);
	    Int_t vme_nlw =  getbits(*pdata,1,1,6);
	    pdata++; len++;
	    
	    // read the data 
	    if ((vme_type == 2) && (vme_nlw > 0)) {
	      for(int i=0;i<vme_nlw;i++) {  
		vme_geo = getbits(*pdata,2,12,5);
		vme_type = getbits(*pdata,2,9,3);
		vme_chn = getbits(*pdata,2,1,5);
		tgt->vme0[vme_geo][vme_chn] = getbits(*pdata,1,1,16);
		pdata++; len++;
	      }
	      
	      // read and ignore the expected "end-of-block" longword 
	      pdata++; len++;
	    }
	    
	  }  // end of the while... loop  
	  
	  if (frs->fill_raw_histos) {
	    for(int i=0;i<32;i++) {
	      if (hVME0_8[i]) hVME0_8[i]->Fill(tgt->vme0[8][i] & 0xfff);
	      if (hVME0_9[i]) hVME0_9[i]->Fill(tgt->vme0[9][i] & 0xfff);
	      if (hVME0_11[i]) hVME0_11[i]->Fill(tgt->vme0[11][i] & 0xfff);
	      if (hVME0_12[i]) hVME0_12[i]->Fill(tgt->vme0[12][i] & 0xfff);
	      //if (hVME0_13[i]) hVME0_13[i]->Fill(tgt->vme0[13][i] & 0xfff);
	      //if (hVME0_14[i]) hVME0_14[i]->Fill(tgt->vme0[14][i] & 0xfff);
	    }
	  }
	  
	  break; 
	}  // end proc ID=10
	              case 30:   // COSY Test
			{
		         // get pointer on data    
		         Int_t *pdata = psubevt->GetDataField();
		         Int_t len = 0;
		         Int_t vme_chn;
		         Int_t vme_sub_sys_id=0;
		         Int_t amsc_len=0;
			 Int_t amsc_num=0;
			 Int_t header_s4crate, footer_s4crate, nw_s4crate, nw_read, time_s, time_us;
			 Int_t header_type, nw_type, mod_type, n_mod_type, ntry_type, nw_type_read, footer_type;
			 Int_t header_mod, nw_mod, i_mod, ntry_mod, footer_mod;
			 
		
			     // first 1 word is sub_sys_id (00000200)
			     vme_sub_sys_id = *pdata;
			     pdata++; len++;		
	     
			     // check S4 crate header
			     header_s4crate = *pdata;
			     pdata++; len++;
			     nw_s4crate = *pdata;
			     pdata++; len++;	
			     if(0x01aa0000!=header_s4crate){
			       fprintf(stderr,"S4 crate header wrong...\n");
			     }
			     nw_read = 2;
			   
			     
			     // loop for each module type
			     while(nw_read < (nw_s4crate -3) ){
			       
			       // check module type header
			       header_type = *pdata;
			       pdata++; len++; nw_read++;
			       nw_type = *pdata;
			       pdata++; len++; nw_read++;
			       n_mod_type = *pdata;
			       pdata++; len++; nw_read++;
			       ntry_type = *pdata;
			       pdata++; len++; nw_read++;
			       nw_type_read = 4;
    
			       if(0x02aa0000!=(0xffff0000 & header_type)){
				 fprintf(stderr,"S4 module type header wrong...\n");
			       }
			       mod_type = (0xffff & header_type);

			       while(nw_type_read < (nw_type - 1) ){
				 
				 // cheack each module header
				  header_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  nw_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  i_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  ntry_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  if(0x03aa0000!=(0xffff0000 & header_mod)){
				    fprintf(stderr,"S4 a module header wrong...\n");
				  }
				  
				  switch (mod_type){

				  case 0x0830:
				    tgt->v830_length = nw_mod;
				    tgt->v830_itry   = ntry_mod;
				    // skip first word
				    pdata++; len++; nw_read++; nw_type_read ++;
				    // read32 words
				    for(int ii=0; ii<32; ii++){
				      tgt->v830n[ii] = *pdata;
				      pdata++; len++; nw_read++; nw_type_read ++;
				    }
				    // skip last word
				    pdata++; len++; nw_read++; nw_type_read ++;				    
				    break;

				  case 0x0792:
				    tgt->v792_length[i_mod] = nw_mod;
				    tgt->v792_itry[i_mod]   = ntry_mod;
				    // skip first word
				    pdata++; len++; nw_read++; nw_type_read ++;
				    // read16 words
				    for(int ii=0; ii<16; ii++){
				       int idata, v792_type, v792_ch, v792_value, v792_un, v792_ov ;
				       idata= (*pdata);
				       pdata++; len++; nw_read++; nw_type_read ++;
				       v792_type=0x7&(idata>>24);
				       if(0==v792_type){
					 v792_ch    = 0xF   & (idata>>17); // V792N mode. V792 is different.
					 v792_value = 0xFFF & idata;
					 v792_un    = 0x1   & (idata>>13); 
					 v792_ov    = 0x1   & (idata>>12);
					 if(0==v792_un && 0==v792_ov){
					   tgt->v792q[i_mod][v792_ch] = v792_value;  
					 }else if(0==v792_un){
					   tgt->v792q[i_mod][v792_ch] = 99999; 
					 }else{ 
					   tgt->v792q[i_mod][v792_ch] = -99999;   
					 }
				       }
				    }
				    // skip last word
				    pdata++; len++; nw_read++; nw_type_read ++;	
				    break;

				  case 0x1290:
				    tgt->v1290_length[i_mod] = nw_mod;
				    tgt->v1290_itry[i_mod]   = ntry_mod;
				    for(int ii=0; ii<nw_mod-5; ii++){
				      int idata, v1290_type, v1290_edge, v1290_ch,v1290_value;
				      idata= (*pdata);
				      pdata++; len++; nw_read++; nw_type_read ++;
				      // 
				      v1290_type=0x1F&((idata)>>27);
				      // printf("idata=0x%8x, v1290_type=%d \n",idata,v1290_type);
				      if(0==v1290_type){//hit data
					v1290_edge = 0x1&(idata>>26);
					v1290_ch    = 0x1F   & (idata>>21);
					v1290_value = 0x1FFFFF & idata;
					// printf("hit data, edge=%d, ch=%d, value=%d\n",v1290_edge,v1290_ch,v1290_value);
					if(0==v1290_edge){ // leading            
					  int old_val = tgt->v1290l[i_mod][v1290_ch];
					  if((-999999==old_val) || ((-999999!=old_val)&& (v1290_value < old_val))){
					    tgt->v1290l[i_mod][v1290_ch] = v1290_value;
					  }
					  tgt->v1290ml[i_mod][v1290_ch] +=1;
					}else{ // trainling   
					  int old_val = tgt->v1290t[i_mod][v1290_ch];
					  if((-999999==old_val) || ((-999999!=old_val)&& (v1290_value < old_val))){
					    tgt->v1290t[i_mod][v1290_ch] = v1290_value;
					  }
					  tgt->v1290mt[i_mod][v1290_ch] +=1;
					}
				      }
				    }
				    break;
				    
				  case 0xa35c:
				    Int_t amsc_hit_channel,amsc_hit_time, amsc_edge_type;
				    tgt->amsc_length[i_mod] = nw_mod;
				    tgt->amsc_itry[i_mod]   = ntry_mod;
				    // skip [data status], skip [Com.stop/start]
				    pdata++; len++; nw_read++; nw_type_read ++;	
				    pdata++; len++; nw_read++; nw_type_read ++;	
				    //hit data
				    while(0==getbits(*pdata,2,14,3)){ // hit data
				      amsc_hit_time    = getbits(*pdata,1,1,20);
				      amsc_edge_type   = getbits(*pdata,2,13,1); // 0=rising,1=falling
				      amsc_hit_channel = getbits(*pdata,2,5,6);
				      pdata++; len++; nw_read++; nw_type_read ++;	
				      // 
				      if(0==amsc_edge_type){ // 0=rising=leading
					if(-999 == tgt->amscl[i_mod][amsc_hit_channel] ){
					  tgt->amscl[i_mod][amsc_hit_channel] = amsc_hit_time;
					}
				      }else if(1==amsc_edge_type){
					if(-999 == tgt->amsct[i_mod][amsc_hit_channel] ){
					  tgt->amsct[i_mod][amsc_hit_channel] = amsc_hit_time;
					}
				      }
				    }
				    // after hit data
				    while(3==getbits(*pdata,2,14,3)){
				      //Error Report exsisting.
				      tgt->amsc_error[i_mod] +=1 ;
				      pdata++; len++; nw_read++; nw_type_read ++;
				    }
				    //skip last word 
				    pdata++; len++; nw_read++; nw_type_read ++;
				    break;
				     
				  case 0x0775:
				    tgt->v775_length = nw_mod;
				    tgt->v775_itry   = ntry_mod;
				    for(int ii=0; ii<nw_mod-5; ii++){
				      int idata, v775_type, v775_ch, v775_value, v775_ov, v775_un, v775_vd;
				      idata= (*pdata);
				      pdata++; len++; nw_read++; nw_type_read ++;
				      // 
				      v775_type=0x7&((idata)>>24);
				      if(0==v775_type){//hit data                                                                                      
					v775_ch    = 0x1F   & (idata>>16);
					v775_value = 0xFFF & idata;
					v775_ov    = 0x1    & (idata>>12);
					v775_un    = 0x1    & (idata>>13);
					v775_vd    = 0x1    & (idata>>14);
					tgt->v775t[v775_ch] = v775_value;
				      }
				    }
				    break;

				  default :
				    fprintf(stderr,"module type is not defined (0x%4x)... type. skip...\n",mod_type);
				    // exit(-1);
				    //just skip
				    pdata += (nw_mod - 5);  len+=(nw_mod - 5); nw_read+=(nw_mod - 5); nw_type_read +=(nw_mod - 5);
				    break;
				  }

				  // cheack each module footer
				  footer_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  if(0x03bb0000!=(0xffff0000 & footer_mod)){
				    fprintf(stderr,"S4 module footer wrong (mod_type=0x%4x, i_mod=%d)...\n",mod_type, i_mod);
				  }else{
				    //  fprintf(stderr,"S4 module footer OK (mod_type=0x%4x, i_mod=%d)...\n",mod_type, i_mod);
				  }

			       }

			       // check module type footer
			       footer_type = *pdata;
			       pdata++; len++; nw_read++;
			       if(0x02bb0000!=(0xffff0000 & footer_type)){
				 fprintf(stderr,"S4 module type footer wrong (mod_type=0x%4x)...\n",mod_type);
			       }else{
				 //  fprintf(stderr,"S4 module type footer OK (mod_type=0x%4x)...\n",mod_type);
			       }

			     }// end of while
			     

			     // check S4 crate footer
			     footer_s4crate = *pdata;
			     pdata++; len++;
			     time_s = *pdata;
			     pdata++; len++;
			     time_us = *pdata;
			     pdata++; len++;	
			     if(0x01bb0000!=footer_s4crate){
			       fprintf(stderr,"S4 crate footer wrong...\n");
			     }
			     //-------------end of s4 crate--------------------
			    
			
			     while (len < (psubevt->GetDlen()-2)/2) {
			       pdata++; len++;
			     }

			     if (frs->fill_raw_histos) {
			       for(int i=0;i<64;i++) {
				 hAMSCL_0[i]->Fill(tgt->amscl[0][i]);
				 hAMSCL_1[i]->Fill(tgt->amscl[1][i]);
				 hAMSCL_2[i]->Fill(tgt->amscl[2][i]);
				 hAMSCL_3[i]->Fill(tgt->amscl[3][i]);
				 hAMSCL_4[i]->Fill(tgt->amscl[4][i]);
				 hAMSCL_5[i]->Fill(tgt->amscl[5][i]);
				 hAMSCL_6[i]->Fill(tgt->amscl[6][i]);
				 hAMSCL_7[i]->Fill(tgt->amscl[7][i]);
				 hAMSCL_8[i]->Fill(tgt->amscl[8][i]);
				 hAMSCL_9[i]->Fill(tgt->amscl[9][i]);
				 hAMSCL_10[i]->Fill(tgt->amscl[10][i]);
				 hAMSCL_11[i]->Fill(tgt->amscl[11][i]);
				 hAMSCL_12[i]->Fill(tgt->amscl[12][i]);
				 hAMSCL_13[i]->Fill(tgt->amscl[13][i]);
				 hAMSCL_14[i]->Fill(tgt->amscl[14][i]);
				 hAMSCL_15[i]->Fill(tgt->amscl[15][i]);
				 //
				 hAMSCT_0[i]->Fill(tgt->amsct[0][i]);
				 hAMSCT_1[i]->Fill(tgt->amsct[1][i]);
				 hAMSCT_2[i]->Fill(tgt->amsct[2][i]);
				 hAMSCT_3[i]->Fill(tgt->amsct[3][i]);
				 hAMSCT_4[i]->Fill(tgt->amsct[4][i]);
				 hAMSCT_5[i]->Fill(tgt->amsct[5][i]);
				 hAMSCT_6[i]->Fill(tgt->amsct[6][i]);
				 hAMSCT_7[i]->Fill(tgt->amsct[7][i]);
				 hAMSCT_8[i]->Fill(tgt->amsct[8][i]);
				 hAMSCT_9[i]->Fill(tgt->amsct[9][i]);
				 hAMSCT_10[i]->Fill(tgt->amsct[10][i]);
				 hAMSCT_11[i]->Fill(tgt->amsct[11][i]);
				 hAMSCT_12[i]->Fill(tgt->amsct[12][i]);
				 hAMSCT_13[i]->Fill(tgt->amsct[13][i]);
				 hAMSCT_14[i]->Fill(tgt->amsct[14][i]);
				 hAMSCT_15[i]->Fill(tgt->amsct[15][i]);
			       }
			       // error report
			       for(int i_amsc=0;i_amsc<amsc_num; i_amsc++){
				 hAMSC_MODULE_LEN[i_amsc] -> Fill(tgt->amsc_length[i_amsc]) ; 
				 for(int i=0;i<(tgt->amsc_error[i_amsc]);i++){
				   hAMSC_ERROR -> Fill(i_amsc);
				 } 
			       }
			       
			       //V775
			       hV775_LENGTH->Fill(tgt->v775_length);
			       hV775_ITRY->Fill(tgt->v775_itry);
			       for(int i=0; i<32; i++){
				 hV775T[i]->Fill(tgt->v775t[i]);
			       }
			       
			       //V830
			       hV830_LENGTH->Fill(tgt->v830_length);
			       hV830_ITRY->Fill(tgt->v830_itry);
			       for(int i=0; i<32; i++){
				 hV830N[i]->Fill(tgt->v830n[i]);
			       }
			       
			       //V1290
			       for(int i_v1290=0; i_v1290<2; i_v1290++){
				 hV1290_ITRY[i_v1290]->Fill(tgt->v1290_itry[i_v1290]);
				 hV1290_LENGTH[i_v1290]->Fill(tgt->v1290_length[i_v1290]);
			       }
			       for(int i=0; i<32; i++){
				 hV1290L_0[i]->Fill(tgt->v1290l[0][i]);
				 hV1290L_1[i]->Fill(tgt->v1290l[1][i]);
				 hV1290T_0[i]->Fill(tgt->v1290t[0][i]);
				 hV1290T_1[i]->Fill(tgt->v1290t[1][i]);
			       }
			       
			            
			       //V792
			       for(int i_v792=0; i_v792<2; i_v792++){
				 hV792_ITRY[i_v792]->Fill(tgt->v792_itry[i_v792]);
				 hV792_LENGTH[i_v792]->Fill(tgt->v792_length[i_v792]);
			       }
			       for(int i=0; i<16; i++){
				 hV792Q_0[i]->Fill(tgt->v792q[0][i]);
				 hV792Q_1[i]->Fill(tgt->v792q[1][i]);
			       }
			       
			       

			     }
			     
			     break;
		       } // end of ProcID (10:COSY)
			
	           case 40: // FADC crate 
		       {
			 
			 // get pointer on data    
		         Int_t *pdata = psubevt->GetDataField();
		         Int_t len = 0;
		         Int_t vme_chn;
		         Int_t vme_sub_sys_id=0;
		         Int_t amsc_len=0;
			 Int_t amsc_num=0;
			 Int_t header_s4crate, footer_s4crate, nw_s4crate, nw_read, time_s, time_us;
			 Int_t header_type, nw_type, mod_type, n_mod_type, ntry_type, nw_type_read, footer_type;
			 Int_t header_mod, nw_mod, i_mod, ntry_mod, footer_mod;
			 
			 
			 // first 1 word is sub_sys_id (00000200)
			 vme_sub_sys_id = *pdata;
			 pdata++; len++;		
			 
			 // check fADC crate header
			 header_s4crate = *pdata;
			 pdata++; len++;
			 nw_s4crate = *pdata;
			 pdata++; len++;	
			 if(0x01aa0000!=header_s4crate){
			   fprintf(stderr,"fADC crate header wrong...\n");
			 }
			 nw_read = 2;
			 
			     
			     // loop for each module type
			     while(nw_read < (nw_s4crate -3) ){
			       
			       // check module type header
			       header_type = *pdata;
			       pdata++; len++; nw_read++;
			       nw_type = *pdata;
			       pdata++; len++; nw_read++;
			       n_mod_type = *pdata;
			       pdata++; len++; nw_read++;
			       ntry_type = *pdata;
			       pdata++; len++; nw_read++;
			       nw_type_read = 4;
    
			       if(0x02aa0000!=(0xffff0000 & header_type)){
				 fprintf(stderr,"fADC crate module type header wrong...\n");
			       }
			       mod_type = (0xffff & header_type);

			       while(nw_type_read < (nw_type - 1) ){
				 int memo1,memo2,memo3,memo4;
				 // cheack each module header
				  header_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  nw_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  i_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  ntry_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				 
				  if(0x03aa0000!=(0xffff0000 & header_mod)){
				    fprintf(stderr,"fADC crate a module header wrong...\n");
				  }
			
				  switch (mod_type){

				  case 0x0830:
				    tgt->v830_length_mh = nw_mod;
				    tgt->v830_itry_mh   = ntry_mod;
				    // skip first word
				    pdata++; len++; nw_read++; nw_type_read ++;
				    // read32 words
				    for(int ii=0; ii<32; ii++){
				      tgt->v830n_mh[ii] = *pdata;
				      pdata++; len++; nw_read++; nw_type_read ++;
				    }
				    // skip last word
				    pdata++; len++; nw_read++; nw_type_read ++;				    
				    break;

				  case 0x1742:
				    tgt->v1742_length = nw_mod;
				    tgt->v1742_itry   = ntry_mod;
				    Int_t headercheck_v1742, evtsize_v1742, boardid_v1742, evtcount_v1742, evttime_v1742, num_2e2e2e2e;
				    Int_t groupheader_v1742[4],groupfooter_v1742[4],startindex_v1742[4];
				    Int_t v1742raw[32][512]; 
				    Int_t idata;
				    idata = (*pdata);
				    headercheck_v1742  = 0xF & (*pdata>>28);
				    evtsize_v1742 =  0x0FFFFFFF & (*pdata);
				    pdata++; len++;  nw_read++; nw_type_read ++;
				    if(0xA!=headercheck_v1742){
				      fprintf(stderr,"V1742 Event Header Wrong. 0x%8x \n",idata);
				      return ;
				    }
				    
				    num_2e2e2e2e=0;
				    while(0x2e2e2e2e==(*pdata)){
				      num_2e2e2e2e+=1;
				      pdata++; len++;  nw_read++; nw_type_read ++;
				    }
				    
				    boardid_v1742 = 0x1F & ((*pdata)>>27);
				    pdata++; len++;  nw_read++; nw_type_read ++;
				    
				    evtcount_v1742 = 0x003FFFFF & (*pdata);
				    pdata++; len++;  nw_read++; nw_type_read ++;
				    
				    evttime_v1742 = *pdata ;
				    pdata++; len++;  nw_read++; nw_type_read ++;
				    
				    for(int i_1742gr=0;i_1742gr<1;i_1742gr++){ //only first group enabled
				      groupheader_v1742[i_1742gr] = (*pdata);
				      startindex_v1742[i_1742gr] = 0x3FF & ((*pdata)>>20);
				      pdata++; len++;  nw_read++; nw_type_read ++;
				      
				      for(int j_1742sample=0;j_1742sample<136;j_1742sample++){
					Int_t buffer0,buffer1,buffer2;
					buffer0=*pdata; pdata++; len++;  nw_read++; nw_type_read ++;
					buffer1=*pdata; pdata++; len++;  nw_read++; nw_type_read ++;
					buffer2=*pdata; pdata++; len++;  nw_read++; nw_type_read ++;
					v1742raw[0+8*i_1742gr][j_1742sample]= 0xFFF & buffer0;
					v1742raw[1+8*i_1742gr][j_1742sample]= 0xFFF & (buffer0>>12);
					v1742raw[2+8*i_1742gr][j_1742sample]= (0x0FF & (buffer0>>24)) + (0xF00 & (buffer1<<8));
					v1742raw[3+8*i_1742gr][j_1742sample]= 0xFFF & (buffer1>>4);
					v1742raw[4+8*i_1742gr][j_1742sample]= 0xFFF & (buffer1>>16);
					v1742raw[5+8*i_1742gr][j_1742sample]= (0x00F & (buffer1>>28)) + (0xFF0 & (buffer2<<4));
					v1742raw[6+8*i_1742gr][j_1742sample]= 0xFFF & (buffer2>>8);
					v1742raw[7+8*i_1742gr][j_1742sample]= 0xFFF & (buffer2>>20);
					
					// V1742 quick analysis 
					for(int i=0; i<8; i++){
					  int i_ch;
					  i_ch = i + 8*i_1742gr;
					  // cell correction
					  if(1==(mwdc->v1742cellcorrection_enable)){
					    int cell_position;
					    cell_position = (j_1742sample + startindex_v1742[i_1742gr]) % 1024;
					    // printf("before correction [i_ch=%d][j_sample=%d], value=%d \n",i_ch,j_1742sample, v1742raw[i_ch][j_1742sample]);
					    v1742raw[i_ch][j_1742sample] -= ( (mwdc->v1742cellcorrection[i_ch][cell_position]) - (mwdc->v1742cellcorrection_offset)  );
					    // printf("after correction [i_ch=%d][j_sample=%d], value=%d \n",i_ch,j_1742sample, v1742raw[i_ch][j_1742sample]);
					  }
					  // q-sum
					  if((mwdc->v1742q_begin[i_ch]) <= j_1742sample &&  j_1742sample <= (mwdc->v1742q_end[i_ch]) ){
					    tgt->v1742q[i_ch] +=((Float_t)(v1742raw[i_ch][j_1742sample]))/((Float_t)((mwdc->v1742q_end[i_ch])-(mwdc->v1742q_begin[i_ch])+1));				    
					  }
					  // baseline-sum
					  if((mwdc->v1742baseline_begin[i_ch]) <= j_1742sample &&  j_1742sample <= (mwdc->v1742baseline_end[i_ch])){
					    tgt->v1742baseline[i_ch] += (v1742raw[i_ch][j_1742sample])/((Float_t)((mwdc->v1742baseline_end[i_ch])-(mwdc->v1742baseline_begin[i_ch])+1));
					  }
					  // tdc-check
					  if( v1742raw[i_ch][j_1742sample] < (mwdc->v1742t_threshold[i_ch]) &&  (tgt->v1742t[i_ch]<0) ){ // take first hit
					    tgt->v1742t[i_ch] = j_1742sample;
					  }
					  // stracnge event check
					  if((mwdc->v1742baseline_begin[i_ch]) <= j_1742sample &&  j_1742sample <= (mwdc->v1742baseline_end[i_ch])){
					    if(v1742raw[i_ch][j_1742sample] < (mwdc->v1742valid_threshold[i_ch])  ){
					      tgt->v1742valid[i_ch] = -1 ;
					    }
					  }
					  
					  
					  // fill waveform histogram
					  hV1742VT[i_ch] -> Fill(j_1742sample, v1742raw[i_ch][j_1742sample]);

					  // fill waveform with cut (temporary!)
					  // v1290 was filled before

					  int t21l, t21r,t41l, t41r, t42l, t42r,t21,t41,t42;
					  t21l = -(tgt->v1290l[1][1])+(tgt->v1290l[1][15]); 
					  t21r = -(tgt->v1290l[1][3])+(tgt->v1290l[1][15]);
					  t41l = -(tgt->v1290l[0][0])+(tgt->v1290l[0][31]);
					  t41r = -(tgt->v1290l[0][16])+(tgt->v1290l[0][31]);
					  t42l = -(tgt->v1290l[0][2])+(tgt->v1290l[0][31]);
					  t42r = -(tgt->v1290l[0][18])+(tgt->v1290l[0][31]);
					  t21 = (t21l + t21r)/2.0 ;
					  t41 = (t41l + t41r)/2.0 ;
					  t42 = (t42l + t42r)/2.0 ;
					  // fill waveform histogram
					  if( (mwdc->min_t2141) < (t21-t41)  && (t21-t41) < (mwdc->max_t2141) ){
					    if( (mwdc->min_t4142) < (t41-t42)  && (t41-t42) < (mwdc->max_t4142) ){
					      if(0==j_1742sample){						
						hV1742VT_CUT[i_ch]->Reset();
					      }
					      hV1742VT_CUT[i_ch]->Fill(j_1742sample, v1742raw[i_ch][j_1742sample]);    
					    }
					  }
					}
				      }
				      groupfooter_v1742[i_1742gr] = (*pdata);
				      pdata++; len++;  nw_read++; nw_type_read ++;
				    }	
	   
				    break;

				  default :
				    fprintf(stderr,"module type is not defined (0x%4x)... type. skip...\n",mod_type);
				    // exit(-1);
				    //just skip
				    pdata += (nw_mod - 5);  len+=(nw_mod - 5); nw_read+=(nw_mod - 5); nw_type_read +=(nw_mod - 5);
				    break;
				  }

				  // cheack each module footer
				  footer_mod = *pdata;
				  pdata++; len++; nw_read++; nw_type_read ++;
				  if(0x03bb0000!=(0xffff0000 & footer_mod)){
				    fprintf(stderr,"S4 module footer wrong (mod_type=0x%4x, i_mod=%d)...\n",mod_type, i_mod);
				  }else{
				    //  fprintf(stderr,"S4 module footer OK (mod_type=0x%4x, i_mod=%d)...\n",mod_type, i_mod);
				  }

			       }

			       // check module type footer
			       footer_type = *pdata;
			       pdata++; len++; nw_read++;
			       if(0x02bb0000!=(0xffff0000 & footer_type)){
				 fprintf(stderr,"S4 module type footer wrong (mod_type=0x%4x)...\n",mod_type);
			       }else{
				 //  fprintf(stderr,"S4 module type footer OK (mod_type=0x%4x)...\n",mod_type);
			       }

			     }// end of while
			     

			     // check S4 crate footer
			     footer_s4crate = *pdata;
			     pdata++; len++;
			     time_s = *pdata;
			     pdata++; len++;
			     time_us = *pdata;
			     pdata++; len++;	
			     if(0x01bb0000!=footer_s4crate){
			       fprintf(stderr,"S4 crate footer wrong...\n");
			     }
			     //-------------end of fadc crate--------------------


			     while (len < (psubevt->GetDlen()-2)/2) {
			       pdata++; len++;
			     }
			     

			     // V830_MH
			     hV830_LENGTH_MH->Fill(tgt->v830_length_mh);
			     hV830_ITRY_MH->Fill(tgt->v830_itry_mh
);
			     for(int i=0; i<32; i++){
			       hV830N_MH[i]->Fill(tgt->v830n_mh[i]);
			     }


			     // V1742 Unpack Fill
			     if (frs->fill_raw_histos) {
			       for(int i_v1742ch=0;i_v1742ch<8;i_v1742ch++){
				 // cout << "ch=" << i_v1742ch <<", value =" <<(tgt->v1742q[i_v1742ch]) << endl;
				 hV1742Q[i_v1742ch]->Fill(tgt->v1742q[i_v1742ch]);   
				 hV1742T[i_v1742ch]->Fill(tgt->v1742t[i_v1742ch]);   
				 hV1742B[i_v1742ch]->Fill(tgt->v1742baseline[i_v1742ch]);   
				 hV1742V[i_v1742ch]->Fill(tgt->v1742valid[i_v1742ch]);
			       }
			     }
			     

			 break;
		       } // end of Procid = 40


       	            }  // end of procid-switch
		} // end trigger 1,2,3,12,13
             
      case 14:  // start of acquisition (vme system):
      case 15:  // stop of acquisition (vme system):
	{  
	  break;   
	} // end case 14-15 

      default: { 
	cout << "Invalid trigger " << fInput->GetTrigger() << endl;
      }
    }  // switch on trigger value
    } // end subevents loop
    } // end special event
  tgt->SetValid(kTRUE); // accept event
}

ClassImp(TFRSUnpackProc)

