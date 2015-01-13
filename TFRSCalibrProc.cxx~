#include "TFRSCalibrProc.h"
#include "TH1.h"
#include "TH2.h"
#include "Go4StatusBase/TGo4Picture.h"	//mik
#include "Go4ConditionsBase/TGo4WinCond.h"
#include "Go4ConditionsBase/TGo4PolyCond.h"
#include "TFRSCalibrEvent.h"
#include "TFRSSortEvent.h"
#include "TFRSParameter.h"
#include "TFRSAnalysis.h"
#include "TMinuit.h"
#include "TRandom.h"
#include "MWDCTracking.h"


const char* mw_folder_ext1[13]={"1", "2", "2", "3","4", "4", "5", "6","7", "8","8", "B", "B"};
const char* mw_folder_ext2[13]={"11", "21", "22", "31","41", "42", "51", "61","71", "81", "82", "B21", "B22"};

const char* mw_name_ext[13]={"(1:1)", "(2:1)", "(2:2)", "(3:1)",
                       "(4:1)", "(4:2)", "(5:1)", "(6:1)",
                       "(7:1)", "(8:1)", "(8:2)", "(9:1)", "(10:1)"};

const char* tpc_name_ext1[6]={"TPC1_","TPC2_","TPC3_","TPC4_","TPC5_","TPC6_"};
const char* tpc_folder_ext1[6]={"TPC1","TPC2","TPC3","TPC4","TPC5","TPC6"};

//-----
static int etap_scaler_previous[64];
static int mh_scaler_previous[64]; //YT26072014
unsigned int time_count_scaler=0;
unsigned int spill_on_count=0;
unsigned int spill_off_count=0;
unsigned int spill_count=0;
int time_count_sec_last=0;
int spill_on_count_last=0;
int spill_off_count_last=0;
int spill_count_last=0;
int scaler_memo[64]={0};
int scaler_memo_spill[64]={0};
int scaler_memo_mh[64]={0};//YT26072014
int scaler_memo_spill_mh[64]={0};//YT26072014
//-----
//JLRS 20-07-2014
int fill_hist_s436=0;



TFRSCalibrProc::TFRSCalibrProc() : TFRSBasicProc("FRSCalibrProc") {

  //TFRSAnalysis *myAnalysis = (TFRSAnalysis*) GetObject("FRSanalysis");                                                                                          

  bDrawHist=kTRUE;
  counter=0;
  Create_ETAP_Data();
  // Create_MON_Data();                                                                                                                                           
  Create_MW_Data();                                                                                                                                           
  Create_TPC_Data(); 
  Create_s436_Data();                                                                                                                                           
  // Create_ITAG_Data();                                                                                                                                          
  // Create_SIMBA_Data();                                                                                                                                         
  // Create_ShiftCheck_Data();                                                                                                                                    
  for(int i=0; i<64; i++){
    etap_scaler_previous[i]=-999; // -999 is initial value                                                                                                        
    mh_scaler_previous[i]=-999; // -999 is initial value                                                                                                        
     
  }
  
  Start_ext_0=-1;
  Clock_aux=0;

}

TFRSCalibrProc::TFRSCalibrProc(const char* name) : TFRSBasicProc(name) { 

	//TFRSAnalysis *myAnalysis = (TFRSAnalysis*) GetObject("FRSanalysis");

	bDrawHist=kTRUE;
	counter=0;
	Create_ETAP_Data();
	// Create_MON_Data();
	 Create_MW_Data();
        Create_TPC_Data();
        Create_s436_Data(); 
	// Create_ITAG_Data();
	// Create_SIMBA_Data();
	// Create_ShiftCheck_Data();
	for(int i=0; i<64; i++){
	  etap_scaler_previous[i]=-999; // -999 is initial value            
	  mh_scaler_previous[i]=-999; // -999 is initial value            
	}


	Start_ext_0=-1;
	Clock_aux=0;
        
}

TFRSCalibrProc::~TFRSCalibrProc() {
}   

void TFRSCalibrProc::FRSCalibr(TFRSCalibrEvent* tgt) {

  tgt->SetValid(kTRUE);  // output event always accepted

  TFRSSortEvent *src = dynamic_cast<TFRSSortEvent*> (GetInputEvent());
  if (src==0) return;
  //

  Process_TPC_ETAP_SCI_Analysis(*src, *tgt);
  Process_ETAP_MWDC_Analysis(*src, *tgt);
  Process_ETAP_Scaler_Analysis(*src, *tgt);
  Process_ETAP_Profile_Analysis(*src,*tgt);
  Process_MW_Analysis(*src, *tgt);
 
  return ;

}

//-----------------------------------------------------------------
void TFRSCalibrProc::Create_s436_Data() 
{
  // Created to s436 experiment - JLRS 20-07-2014
    // 20-07-2014
      hMWDC_s436_XZ= MakeH2I("s436","Beam_tracking_MWDC_XZ", 200, 1., 1000., 200, -150., 150., "Position Z[mm]","Position X[mm]",2);
      hMWDC_s436_YZ= MakeH2I("s436","Beam_tracking_MWDC_YZ", 200, 1., 1000., 200, -150., 150., "Position Z[mm]","Position Y[mm]",2);
    // 20-07-2014 JLRS 
    // 19-07-2014-JLRS
      hSCI_DE1_DE2[0]= MakeH2I("s436","DE_SC41_vs_DE_ToF41", 400, -0.5, 4095.5, 400, -0.5, 4095.5, "Delta E SC41","Delta E ToF41",2);
      hSCI_DE1_DE2[1]= MakeH2I("s436","DE_SC41_vs_DE_ToF42", 400, -0.5, 4095.5, 400, -0.5, 4095.5, "Delta E SC41","Delta E ToF42",2);
      hSCI_DE1_DE2[2]= MakeH2I("s436","DE_SC41_vs_DE_ToF43", 400, -0.5, 4095.5, 400, -0.5, 4095.5, "Delta E SC41","Delta E ToF43",2);
    // 19-07-2014-JLRS
      hSCI_Angle_DE[0]=  MakeH2I("s436","Angle_MWDC_vs_DE_SC41", 400, -100.5, 100.5, 400, -0.5, 4095.5, "Angle[mrad]","Delta E SC41",2);
      hSCI_Angle_DE[1]=  MakeH2I("s436","Angle_MWDC_vs_DE_ToF41", 400,-100.5, 100.5, 400, -0.5, 4095.5, "Angle[mrad]","Delta E ToF41",2);
      hSCI_Angle_DE[2]=  MakeH2I("s436","Angle_MWDC_vs_DE_ToF42", 400,-100.5, 100.5, 400, -0.5, 4095.5, "Angle[mrad]","Delta E ToF42",2);
      hSCI_Angle_DE[3]=  MakeH2I("s436","Angle_MWDC_vs_DE_ToF43", 400,-100.5, 100.5, 400, -0.5, 4095.5, "Angle[mrad]","Delta E ToF43",2);
    // 19-07-2014-JLRS
      hSCI_Pos_DE[0]=  MakeH2I("s436","Pos_X_MWDC_vs_DE_SC41", 400, -150., 150., 400, -0.5, 4095.5, "Position[mm]","Delta E SC41",2);
      hSCI_Pos_DE[1]=  MakeH2I("s436","Pos_X_MWDC_vs_DE_ToF41", 400, -150., 150., 400, -0.5, 4095.5, "Position[mm]","Delta E ToF41",2);
      hSCI_Pos_DE[2]=  MakeH2I("s436","Pos_X_MWDC_vs_DE_ToF42", 400, -150., 150., 400, -0.5, 4095.5, "Position[mm]","Delta E ToF42",2);
      hSCI_Pos_DE[3]=  MakeH2I("s436","Pos_X_MWDC_vs_DE_ToF43", 400, -150., 150., 400, -0.5, 4095.5, "Position[mm]","Delta E ToF43",2);

    // 20-07-2014 JLRS: Positions X and Y in different planes
      hMWDC_s436_plane[0]=  MakeH2I("s436","Pos_MWDC1_X_vs_Y", 400, -150., 150., 400, -150., 150., "X[mm]","Y[mm]",2);//First MWDC
      hMWDC_s436_plane[1]=  MakeH2I("s436","Pos_MWDC2_X_vs_Y", 400, -150., 150., 400, -150., 150., "X[mm]","Y[mm]",2);//Second MWDC
      hMWDC_s436_plane[2]=  MakeH2I("s436","Pos_ToF41_X_vs_Y", 400, -150., 150., 400, -150., 150., "X[mm]","Y[mm]",2);//ToF41
      //added by S.Tera
      hMWDC_s436_plane[3]=  MakeH2I("s436","Pos_Focal_X_vs_A", 400, -150., 150., 400, -15., 15., "X[mm]","A[mrad]",2);
    // 20-07-2014 JLRS: Energy loss vs ToF
      hSCI_DE_ToF[0]= MakeH2I("s436","Energy_loss_SC41_vs_ToF42_and_ToF41", 500, 1000., 2000.0, 500, 400., 900., "Delta E SC41","ToF(42-41)",2);
      hSCI_DE_ToF[1]= MakeH2I("s436","Energy_loss_SC41_vs_ToF43_and_ToF41", 500, 1000., 2000.0, 500, 400., 900., "Delta E SC41","ToF(43-41)",2);
      hSCI_DE_ToF[2]= MakeH2I("s436","Energy_loss_ToF41_vs_ToF42_and_ToF41",500, 0.0, 2000.0, 500, 400., 900., "Delta E ToF41","ToF(42-41)",2);
      hSCI_DE_ToF[3]= MakeH2I("s436","Energy_loss_ToF41_vs_ToF43_and_ToF41",500, 0.0, 2000.0, 500, 400., 900., "Delta E ToF41","ToF(43-41)",2);

    // 22-07-2014
      hTextraction_XS4= MakeH2I("s436","Time_extraction_vs_Pos_X_MWDC", 400, -150., 150., 500, 0., 500.,"Position X MWDC [mm]","Time extraction",2);
      hTextraction_AS4= MakeH2I("s436","Time_extraction_vs_Pos_A_MWDC", 400, -150., 150., 500, 0., 500.,"Position X MWDC [mm]","Time extraction",2);
      hTPC1_TPC2_X= MakeH2I("s436","TPC1_X_vs_TPC2_X", 400, -150., 150., 400, -150., 150.,"TPC1 X[mm]","TPC2 X[mm]",2);
      hTPC1_TPC2_Y= MakeH2I("s436","TPC1_Y_vs_TPC2_Y", 400, -150., 150., 400, -150., 150.,"TPC1 Y[mm]","TPC2 Y[mm]",2);

      // 23-07-2014
      hToF_s2_s4 = MakeH2I("s436","TOF_S4_S2_vs_DES4", 1000, -0.5, 4095.5, 250, -0.5, 4095.5,"Delta E SC41","ToF S4-S2",2);

      // 25-07-2014 
      hToF_ToF41_ToF42=MakeH1I("s436","ToF_TOF41vsTOF42", 1000, -0.5, 4095.5,"ToF ToF41-ToF42",2);

      hFocal_X = MakeH1I("s436","Pos_Focal_X_s4", 1000, -250.5, 250.5,"X[mm]",2);
      hFocal_X2= MakeH1I("s436","Pos_Focal_X_s4 with PI", 1000, -250.5, 250.5,"X[mm]",2);
      hFocal_XY=MakeH2I("s436","Pos_Focal_XY_s4",300, -150., 150., 200, -50., 50.,"Focal S4 X[mm]","Y[mm]",2);
      hFocal_X_ToF_s4=MakeH2I("s436","Pos_Focal_X_s4_vs_TOF_S4",1000, -250.5, 250.5, 250, -0.5, 1095.5,"Focal S4 X[mm]","ToF S4",2);
      hFocal_plane_s4_init= MakeH2I("s436","Pos_Focal_X_vs_A_not_corrections", 400, -150., 150., 400, -15., 15., "X[mm]","A[mrad]",2);

      MakePic("FOC","PI",2,2,hSCI_DE_ToF[0],hSCI_DE_ToF[1],
              hSCI_DE_ToF[2],hSCI_DE_ToF[3] );

      MakePic("FOC","Spectrum",2,2,hFocal_plane_s4_init,hMWDC_s436_plane[3],
              hFocal_X_ToF_s4,hFocal_X);
      /*
      //900 MeV
      Float_t cPI_detof_points1[4][2] = {{1800.,600.},{1200., 600.},{1200., 500.},{1800.,  500.}};
      Float_t cPI_detof_points2[4][2] = {{1800.,620.},{1200., 620.},{1200., 500.},{1800.,  500.}};
      Float_t cPI_detof_points3[4][2] = {{1500.,600.},{300., 600.},{300., 500.},{1500.,  500.}};
      Float_t cPI_detof_points4[4][2] = {{1500.,620.},{300., 620.},{300., 500.},{1500.,  500.}};
      */
      //600 MeV
      Float_t cPI_detof_points1[4][2] = {{1800.,630.},{1200., 630.},{1200., 500.},{1800.,  500.}};
      Float_t cPI_detof_points2[4][2] = {{1800.,650.},{1200., 650.},{1200., 500.},{1800.,  500.}};
      Float_t cPI_detof_points3[4][2] = {{1500.,630.},{300., 630.},{300., 500.},{1500.,  500.}};
      Float_t cPI_detof_points4[4][2] = {{1500.,650.},{300., 650.},{300., 500.},{1500.,  500.}};

      cPI_DE_TOF[0]=MakePolyCond("PI","SC41-TOF42", 4,cPI_detof_points1, hSCI_DE_ToF[0]->GetName());
      cPI_DE_TOF[1]=MakePolyCond("PI","SC41-TOF43", 4,cPI_detof_points2, hSCI_DE_ToF[1]->GetName());
      cPI_DE_TOF[2]=MakePolyCond("PI","TOF41-TOF42",4,cPI_detof_points3, hSCI_DE_ToF[2]->GetName());
      cPI_DE_TOF[3]=MakePolyCond("PI","TOF41-TOF43",4,cPI_detof_points4, hSCI_DE_ToF[3]->GetName());

      fill_hist_s436=1;

}
//------------------------------------------------------------------

TH1I* TFRSCalibrProc::MakeH1I_MW(const char* foldername, 
                                 const char* name, int nameindex,
                                 Int_t nbinsx, 
                                 Float_t xmin, Float_t xmax, 
                                 const char* xtitle,
                                 Color_t linecolor,
                                 Color_t fillcolor) {
   char fullname[100];
   if(nameindex>=0)
     sprintf(fullname,"%s%s",name, mw_name_ext[nameindex]);
   else
     strcpy(fullname, name);  
   
   return MakeH1I(foldername, fullname, nbinsx, xmin, xmax, xtitle, linecolor, fillcolor);
}




//Make Histograms for TPCs
TH1I* TFRSCalibrProc::MakeH1I_TPC(const char* foldername, 
                                 const char* name, int nameindex,
                                 Int_t nbinsx, 
                                 Float_t xmin, Float_t xmax, 
                                 const char* xtitle,
                                 Color_t linecolor,
                                 Color_t fillcolor) {
   char fullname[100];
   if(nameindex>=0)
     sprintf(fullname,"%s%s",tpc_name_ext1[nameindex],name);
   else
     strcpy(fullname, name);  
   return MakeH1I(foldername, fullname, nbinsx, xmin, xmax, xtitle, 
		  linecolor, fillcolor);
}


void TFRSCalibrProc::Create_MON_Data() 
{

	hTimeStamp = MakeH1I("MON","Time Stamp",3600,0,3600,"Time Stamp",2,5,"Time (s)");
	hTimeStampZoom = MakeH1I("MON","Time Stamp Zoom",60,0,60,"Time Stamp",2,5,"Time (s)");
	hTimeSpill = MakeH1I("MON","Time Spill",300,0,30,"Time Spill",2,5,"Time (s)");
   hMON_All = MakeH1I("MON","MON_All",32,0,32,"Scaler FRS Channel ",2,5,"Scaler Counts");
   hMON_All2 = MakeH1I("MON","MON_All2",32,0,32,"Scaler TPC Channel ",2,5,"Scaler Counts"); 
   
   char name[80];
   for(int i=0;i<64;i++) {
     sprintf(name,"MON_scaler_%02d",i);  
     hMON_scaler[i] = MakeH1I("MON/MON_scaler",name,28800,0,28800,"",2,5);  
     sprintf(name,"MON_diff_%02d",i);
     hMON_diff[i] = MakeH1I("MON/MON_diff",name,28800,0,28800,"",2,5);  
     sprintf(name,"MON_extr_%02d",i);
     hMON_extr[i] = MakeH1I("MON/MON_extr",name,28800,0,28800,"",2,5);  
   }
   
   if (ObjWasCreated()) {

      hMON_scaler[0] ->SetXTitle("Free Trigger (OR)");           // updated 28-08-11 
      hMON_scaler[1] ->SetXTitle("Accepted Trigger (OR)");
      hMON_scaler[2] ->SetXTitle("Spill counter");
      hMON_scaler[3] ->SetXTitle("1 Hz clock");
      hMON_scaler[4] ->SetXTitle("10 Hz clock");
      hMON_scaler[5] ->SetXTitle("SCI01");
      hMON_scaler[6] ->SetXTitle("IC01 current digitizer (new output)");
      hMON_scaler[7] ->SetXTitle("SCI21");
      hMON_scaler[8] ->SetXTitle("SCI41");
      hMON_scaler[9] ->SetXTitle("Seetram current digitizer (old output)");
      hMON_scaler[10]->SetXTitle("Seetram current digitizer (new output)");
      hMON_scaler[11]->SetXTitle("IC01 current digitizer (old output)");
      hMON_scaler[12]->SetXTitle("Start extraction");
      hMON_scaler[13]->SetXTitle("Stop extraction");
      hMON_scaler[14]->SetXTitle("SC81 not used");  
      hMON_scaler[15]->SetXTitle("Beam transformer digital gated");
      hMON_scaler[16]->SetXTitle("ITAG_SC42"); 
      hMON_scaler[17]->SetXTitle("ITAG_SC43");  
      hMON_scaler[18]->SetXTitle("GeL");
      hMON_scaler[19]->SetXTitle("GeR"); 
      hMON_scaler[20]->SetXTitle("BELEN OR after TrgBox3");
      hMON_scaler[21]->SetXTitle("Free Trg 1 after TrgBox ");
      hMON_scaler[22]->SetXTitle("Acc Trg 1");
      hMON_scaler[23]->SetXTitle("Free Trg 2 after TrgBox");
      hMON_scaler[24]->SetXTitle("Acc Trg 2");
      hMON_scaler[25]->SetXTitle("Free Trg 3 after TrgBox");
      hMON_scaler[26]->SetXTitle("Acc Trg 3");
      hMON_scaler[27]->SetXTitle("10Hz AND !TDT");
      hMON_scaler[28]->SetXTitle("");
      hMON_scaler[29]->SetXTitle("SIMBA DSSD+SSSD Trg after TrgBox1");
      hMON_scaler[30]->SetXTitle("SIMBA DSSD+SSSD Trg (cleaned)");
      hMON_scaler[31]->SetXTitle("BELEN OR");


      hMON_diff[0] ->SetXTitle("Free Trigger (OR)");           // FRS scaler update 13.08.11
      hMON_diff[1] ->SetXTitle("Accepted Trigger (OR)");
      hMON_diff[2] ->SetXTitle("Spill counter");
      hMON_diff[3] ->SetXTitle("1 Hz clock");
      hMON_diff[4] ->SetXTitle("10 Hz clock");
      hMON_diff[5] ->SetXTitle("SCI01");
      hMON_diff[6] ->SetXTitle("IC01 current digitizer (new output)");
      hMON_diff[7] ->SetXTitle("SCI21");
      hMON_diff[8] ->SetXTitle("SCI41");
      hMON_diff[9] ->SetXTitle("Seetram current digitizer (old output)");
      hMON_diff[10]->SetXTitle("Seetram current digitizer (new output)");
      hMON_diff[11]->SetXTitle("IC01 current digitizer (old output)");
      hMON_diff[12]->SetXTitle("Start extraction");
      hMON_diff[13]->SetXTitle("Stop extraction");
      hMON_diff[14]->SetXTitle("SC81 not used");  
      hMON_diff[15]->SetXTitle("Beam transformer digital gated");
      hMON_diff[16]->SetXTitle("ITAG_SC42");
      hMON_diff[17]->SetXTitle("ITAG_SC43");
      hMON_diff[18]->SetXTitle("GeL");
      hMON_diff[19]->SetXTitle("GeR");
      hMON_diff[20]->SetXTitle("Belen Or after TrgBox3");
      hMON_diff[21]->SetXTitle("Free Trg 1 after TrgBox");
      hMON_diff[22]->SetXTitle("Acc Trg 1");
      hMON_diff[23]->SetXTitle("Free Trg 2 after TrgBox");
      hMON_diff[24]->SetXTitle("Acc Trg 2");
      hMON_diff[25]->SetXTitle("Free Trg 3 after TrgBox");
      hMON_diff[26]->SetXTitle("Acc Trg 3");
      hMON_diff[27]->SetXTitle("10Hz AND Accepted Trg");
      hMON_diff[28]->SetXTitle("Impl Trg (XY) after TrgBox1");
      hMON_diff[29]->SetXTitle("Decay Free Trg after trgBox1");
      hMON_diff[30]->SetXTitle("Decay Free Trg (cleaned)");
      hMON_diff[31]->SetXTitle("BELEN OR");

      hMON_diff[32] ->SetXTitle("DSSD A");   // 2nd scaler module in the TPC crate update 13.08.11
      hMON_diff[33] ->SetXTitle("DSSD B");   
      hMON_diff[34] ->SetXTitle("DSSD C");
      hMON_diff[35] ->SetXTitle("SSSDs Front");
      hMON_diff[36] ->SetXTitle("SSSDs Rear");
      hMON_diff[37] ->SetXTitle("");
      hMON_diff[38] ->SetXTitle("");
      hMON_diff[39] ->SetXTitle("DSSD+SSSD (cleaned)");
      hMON_diff[40] ->SetXTitle("XY tracking");
      hMON_diff[41] ->SetXTitle("100 Hz clock");
      hMON_diff[42] ->SetXTitle("Direct BELEN OR");
      hMON_diff[43] ->SetXTitle("");
      hMON_diff[44] ->SetXTitle("100 kHz");
      hMON_diff[45] ->SetXTitle("");
      hMON_diff[46] ->SetXTitle("");
      hMON_diff[47] ->SetXTitle("");
      hMON_diff[48] ->SetXTitle("");   // from here not used
      hMON_diff[49] ->SetXTitle("");
      hMON_diff[50] ->SetXTitle("");
      hMON_diff[51] ->SetXTitle("");
      hMON_diff[52] ->SetXTitle("");
      hMON_diff[53] ->SetXTitle("");
      hMON_diff[54] ->SetXTitle("");
      hMON_diff[55] ->SetXTitle("");
      hMON_diff[56] ->SetXTitle("");
      hMON_diff[57] ->SetXTitle("");
      hMON_diff[58] ->SetXTitle("");
      hMON_diff[59] ->SetXTitle("");
      hMON_diff[60] ->SetXTitle("");
      hMON_diff[61] ->SetXTitle("");
      hMON_diff[62] ->SetXTitle("");
      hMON_diff[63] ->SetXTitle("");
   }

/*   
   for(int i=0;i<8;i++) {
      sprintf(name,"MON_seecalA(%d)",i); 
      hMON_seecalA[i] = MakeH1I("MON/seecalA",name,3600,0,36000,"",2,5);
      sprintf(name,"MON_seecalB(%d)",i); 
      hMON_seecalB[i] = MakeH1I("MON/seecalB",name,3600,0,36000,"",2,5);
   }
   
   if (ObjWasCreated()) {
     hMON_seecalA[0]->SetXTitle("free triggers");
     hMON_seecalA[1]->SetXTitle("acc. triggers");
     hMON_seecalA[2]->SetXTitle("SE01 old CD");
     hMON_seecalA[3]->SetXTitle("SC01 free");
     hMON_seecalA[4]->SetXTitle("SE01 new CD");
     hMON_seecalA[5]->SetXTitle("IC particles");
     hMON_seecalA[6]->SetXTitle("IC old CD");
     hMON_seecalA[7]->SetXTitle("IC new CD");
     hMON_seecalB[0]->SetXTitle("free triggers");
     hMON_seecalB[1]->SetXTitle("acc. triggers");
     hMON_seecalB[2]->SetXTitle("SE01 old CD");
     hMON_seecalB[3]->SetXTitle("SC01 free");
     hMON_seecalB[4]->SetXTitle("SE01 new CD");
     hMON_seecalB[5]->SetXTitle("IC particles");
     hMON_seecalB[6]->SetXTitle("IC old CD");
     hMON_seecalB[7]->SetXTitle("IC new CD");
   }
*/

   hMON_Pattern = MakeH1I("MON","MON_Pattern",4096,0,4096,"Pattern Unit Channel * 10",2,5,"Counts");
   hMON_PatternH = MakeH1I("MON","MON_Pattern_Hit",16,0,16,"Pattern Unit Channel",2,5,"Counts");

/*
   hMON_TOE = MakeH1I("MON","MON_TOE",40000,0,4000,"Time after start flat top [ms]",2,5,"Events");
   hMONDtDiff = MakeH1I("MON","MON_DtDiff",10000,0,1000000,"Time between adjacent events [us] bin=100!",2,5,"Events");
   hMON_SC01 = MakeH1I("MON/SC","MON_SC01",1000,0,10000,"Extraction Cycle",2,5,"Free SC01 counts/cycle");
   hMON_SC21 = MakeH1I("MON/SC","MON_SC21",1000,0,10000,"Extraction Cycle",2,5,"Free SC21 counts/cycle");
   hMON_SC41 = MakeH1I("MON/SC","MON_SC41",1000,0,10000,"Extraction Cycle",2,5,"Free SC41 counts/cycle");
   hMON_Trigger = MakeH1I("MON","MON_Trigger",1000,0,10000,"Extraction Cycle",2,5,"Ungated Triggers/1000/10 cycles");
   hMON_LAM = MakeH1I("MON","MON_LAM",1000,0,10000,"Extraction Cycle",2,5,"Gated Triggers(LAMs)/1000/10 cycles");
   hMON_SE01 = MakeH1I("MON","MON_SE01",32765,0,32765,"Time after start [sec]",2,5,"Seetram (Current digitizer)/1000 Counts/sec");
   hMON_ICDE = MakeH1I("MON","MON_ICDE",2048,0,4095,"IC Energy loss [channels]",2,5,"Counts");
   hMON_IC1 = MakeH1I("MON/IC1","MON_IC1",32765,0,32765,"Time after start [sec]",2,5,"IC scaler 1");
   hMON_IC1d = MakeH1I("MON/IC1","MON_IC1d",32765,0,32765,"Time after start [sec]",2,5,"IC scaler 1");
   hMON_IC2 = MakeH1I("MON/IC2","MON_IC2",32765,0,32765,"Time after start [sec]",2,5,"IC scaler 2");
   hMON_IC2d = MakeH1I("MON/IC2","MON_IC2d",32765,0,32765,"Time after start [sec]",2,5,"IC scaler 2");
   hMON_IC3 = MakeH1I("MON/IC3","MON_IC3",32765,0,32765,"Time after start [sec]",2,5,"IC scaler 3");
   hMON_IC3d = MakeH1I("MON/IC3","MON_IC3d",32765,0,32765,"Time after start [sec]",2,5,"IC scaler 3");
      

   MakePic("MON","Mon",3,1,hMON_SE01,hMON_Trigger,hMON_LAM);
   MakePic("MON","Mon_Deadtime",2,2,hMON_Trigger,hMON_TOE,hMON_LAM,hMON_DtDiff);
   MakePic("MON","Mon_Deadtime",2,2,hMON_Trigger,hMON_TOE,hMON_LAM,hMON_DtDiff);
   MakePic(0,"Seetram", 5,1,hMON_diff[2],  hMON_diff[5],  hMON_diff[10],  hMON_diff[11],  hMON_diff[12]);
   MakePic(0,"Seetram2",5,1,hMON_scaler[2],hMON_scaler[5],hMON_scaler[10],hMON_scaler[11],hMON_scaler[12]);
*/    

}


void TFRSCalibrProc::Create_ETAP_Data() 
{
   TMWDCParameter* mwdc = (TMWDCParameter*) GetParameter("MWDCPar");
    
    //---------------------------------------
    //      V830 - Scaler
    char foldername_v830_total[100],foldername_v830_rate[100],foldername_v830_spill_on[100],foldername_v830_spill[100];
    char fullname_v830_total[100],fullname_v830_rate[100],fullname_v830_spill_on[100],fullname_v830_spill[100];
    sprintf(foldername_v830_total,  "Scaler/S4/TOTAL");
    sprintf(foldername_v830_rate,   "Scaler/S4/RATE");
    sprintf(foldername_v830_spill_on,   "Scaler/S4/SPILL_ON");
    sprintf(foldername_v830_spill,   "Scaler/S4/SPILL");
    //
    for(int i=0;i<(mwdc->num_ch_v830);i++){
      int imod=(mwdc->imod_v830[i]);
      int ich=(mwdc->ich_v830[i]);
      int ich_normalized = mwdc->i_v830_normalization;
      char v830_xtitle_total[100],  v830_ytitle_time[100];
      sprintf(fullname_v830_total,"Total_%s_%d",mwdc->name_v830[i],i);
      sprintf(fullname_v830_rate, "Rate_%s_%d",mwdc->name_v830[i],i); 
      sprintf(fullname_v830_spill_on,  "Spill_On_%s_%d",mwdc->name_v830[i],i); 
      sprintf(fullname_v830_spill, "Spill_%s_%d",mwdc->name_v830[i],i); 
      sprintf(v830_xtitle_total,"Scaler (%s)",mwdc->name_v830[i]);
      sprintf(v830_ytitle_time ,"Rate (%s) [Hz]",mwdc->name_v830[i]);
      // 
      hSCALER_TOTAL[imod][ich]  = MakeH1I(foldername_v830_total,  fullname_v830_total,0x100,0,0xFFFFFFFF,v830_xtitle_total,2,3);
      hSCALER_TIME[imod][ich]   = MakeH1I(foldername_v830_rate, fullname_v830_rate ,3000,0,3000,"time [s]",2,3);
      hSCALER_TIME[imod][ich]   -> SetYTitle(v830_ytitle_time);
      //
      sprintf(v830_ytitle_time ,"Count(%s)/Spill-On",mwdc->name_v830[i]);
      //      hSCALER_SPILL_ON[imod][ich]    = MakeH1I(foldername_v830_spill_on, fullname_v830_spill_on ,3000,0,3000,"Spill ",2,3);
      //      hSCALER_SPILL_ON[imod][ich]   -> SetYTitle(v830_ytitle_time);
      //
      sprintf(v830_ytitle_time ,"Count(%s)/Spill",mwdc->name_v830[i]);
      hSCALER_SPILL[imod][ich]    = MakeH1I(foldername_v830_spill, fullname_v830_spill,201,-0.5,200.5,"Spill ",2,3);
      hSCALER_SPILL[imod][ich]   -> SetYTitle(v830_ytitle_time);
    }


    //---------------------------------------
    //      V830 - Scaler - Messuhuette
    char foldername_v830mh_total[100],foldername_v830mh_rate[100],foldername_v830mh_spill_on[100],foldername_v830mh_spill[100];
    char fullname_v830mh_total[100],fullname_v830mh_rate[100],fullname_v830mh_spill_on[100],fullname_v830mh_spill[100];
    sprintf(foldername_v830mh_total,  "Scaler/MH/TOTAL");
    sprintf(foldername_v830mh_rate,   "Scaler/MH/RATE");
    sprintf(foldername_v830mh_spill,   "Scaler/MH/SPILL");
    sprintf(foldername_v830mh_spill_on,   "Scaler/MH/SPILL_ON");
  //

   for(int i=0;i<(mwdc->num_ch_v830);i++){
      int imod=(mwdc->imod_v830_mh[i]);
      int ich=(mwdc->ich_v830_mh[i]);
      char v830mh_xtitle_total[100],  v830mh_ytitle_time[100];
      sprintf(fullname_v830mh_total,"Total_%s_mh_%d",mwdc->name_v830_mh[i],i);
      sprintf(fullname_v830mh_rate, "Rate_%s_mh_%d",mwdc->name_v830_mh[i],i); 
      sprintf(fullname_v830mh_spill_on, "Spill_On_%s_mh_%d",mwdc->name_v830_mh[i],i); 
      sprintf(fullname_v830mh_spill, "Spill_%s_mh_%d",mwdc->name_v830_mh[i],i); 
      sprintf(v830mh_xtitle_total,"Scaler (%s)",mwdc->name_v830_mh[i]);
      sprintf(v830mh_ytitle_time ,"Rate (%s) [Hz]",mwdc->name_v830_mh[i]);
      
      // 
      hSCALER_TOTAL_MH[imod][ich]  = MakeH1I(foldername_v830mh_total,  fullname_v830mh_total,0x100,0,0xFFFFFFFF,v830mh_xtitle_total,2,3);
      hSCALER_TIME_MH[imod][ich]   = MakeH1I(foldername_v830mh_rate, fullname_v830mh_rate ,3000,0,3000,"time [s]",2,3);
      hSCALER_TIME_MH[imod][ich]   -> SetYTitle(v830mh_ytitle_time);
      //
      sprintf(v830mh_ytitle_time ,"Count(%s)/Spill-On",mwdc->name_v830_mh[i]);
      //  hSCALER_SPILL_ON_MH[imod][ich]    = MakeH1I(foldername_v830mh_spill_on, fullname_v830mh_spill_on ,3000,0,3000,"Spill ",2,3);
      //  hSCALER_SPILL_ON_MH[imod][ich]   -> SetYTitle(v830mh_ytitle_time);
       //
      sprintf(v830mh_ytitle_time ,"Count(%s)/Spill",mwdc->name_v830_mh[i]);
      hSCALER_SPILL_MH[imod][ich]    = MakeH1I(foldername_v830mh_spill, fullname_v830mh_spill ,100,0,100,"Spill ",2,3);
      hSCALER_SPILL_MH[imod][ich]   -> SetYTitle(v830mh_ytitle_time);
    }


    //---S437----
    hTOFSC21LSC41L  = MakeH1I("S437", "TOF21L41L",4000,-20000,40000, "SC21L-SC41L [ch]",2,3); 
    hTOFSC21RSC41R  = MakeH1I("S437", "TOF21R41R",4000,-20000,40000, "SC21R-SC41R [ch]",2,3);
    hTOFSC21SC41    = MakeH1I("S437", "TOF2141",4000,-20000,40000, "SC21-SC41 [ch]",2,3);
    hTOFSC41SC42    = MakeH1I("S437", "TOF4142",4000,-20000,40000, "SC41-SC42 [ch]",2,3);
    hTOFSC21SC41SC42    = MakeH2I("S437", "TOF2141_TOF4142",1000,-20000,0, 1000, -10000,10000,"SC21-SC41 [ch]", "SC41-SC42 [ch]",2);
    hTOFDE41SC41SC42    = MakeH2I("S437", "TOF2141_DE41",1000,-20000,0, 1000, 0, 4000, "SC21-SC41 [ch]", "DE_SC41 [ch]",2);
    hTOFDE21SC41SC42    = MakeH2I("S437", "TOF2141_DE21",1000,-20000,0, 1000, 0, 4000, "SC21-SC41 [ch]", "DE_SC21 [ch]",2);
    

    // for MWDC_Calibration. 
    char foldername_numhit[100], foldername_tot[100], foldername_time[100], foldername_time_2[100];
    char foldername_wireid[100],foldername_length[100],foldername_wirepos[100];
    char fullname_numhit[100], fullname_numhitsum[100];
    char fullname_tot[100],fullname_time[100],fullname_time_2[100], fullname_wireid[100],fullname_length[100],fullname_wirepos[100];
    

    for(int i_plane=0;i_plane<16;i_plane++){  
      // foldername
      sprintf(foldername_numhit, "MWDC/NUMHIT");
      sprintf(foldername_tot,    "MWDC/TOT"); 
      sprintf(foldername_time,   "MWDC/TIME"); 
      sprintf(foldername_time_2, "MWDC/TIME_with_Max_ToT"); 
      sprintf(foldername_wireid, "MWDC/WIREID"); 
      sprintf(foldername_length, "MWDC/LENGTH"); 
      sprintf(foldername_wirepos,"MWDC/WIREPOS"); 
      // fullname
      sprintf(fullname_numhit,   "NumHit%d_%s",i_plane,mwdc->plane_name[i_plane]);
      sprintf(fullname_tot,      "ToT%d_%s",i_plane,mwdc->plane_name[i_plane]); 
      sprintf(fullname_time,     "Time%d_%s",i_plane,mwdc->plane_name[i_plane]); 
      sprintf(fullname_time_2,     "Time_wMaxToT%d_%s",i_plane,mwdc->plane_name[i_plane]); 
      sprintf(fullname_wireid,   "WireID%d_%s",i_plane,mwdc->plane_name[i_plane]);  
      sprintf(fullname_length,   "Length%d_%s",i_plane,mwdc->plane_name[i_plane]);
      sprintf(fullname_wirepos,  "WirePos%d_%s",i_plane,mwdc->plane_name[i_plane]);
      ///// **** MakeH1I(foldername, fullname, nbinsx, xmin, xmax, xtitle, linecolor, fillcolor);
      hMWDC_NUMHIT[i_plane]  = MakeH1I(foldername_numhit, fullname_numhit,60,-0.5,59.5,"Plane Multiplicity",2,3);
      hMWDC_WIREID[i_plane]  = MakeH1I(foldername_wireid, fullname_wireid, 48,-0.5,47.5,"Hit Pattern ",2,3);
      hMWDC_WIREPOS[i_plane] = MakeH1I(foldername_wirepos, fullname_wirepos,300, -150.0, 150.0,"Hit Wire coordinate (mm)",2,3);
      hMWDC_TIME[i_plane]    = MakeH1I(foldername_time, fullname_time,2000,0,2000,"Drift Time/0.78ns",2,3);
      hMWDC_TIME_wMaxToT[i_plane]    = MakeH1I(foldername_time_2, fullname_time_2,2000,0,2000,"Drift Time with maximum ToT /0.78ns",2,3);
      hMWDC_LENGTH[i_plane]  = MakeH1I(foldername_length, fullname_length,100,-1.00,4.0,"Drift Length (mm)",2,3);
      hMWDC_TOT[i_plane]     = MakeH1I(foldername_tot, fullname_tot,1000,-2000,2000,"ToT/0.78ns",2,3);
    }
    sprintf(fullname_numhitsum,   "NumHitSum");
    hMWDC_NUMHITSUM = MakeH1I(foldername_numhit, fullname_numhitsum,60,-0.5,59.5,"Total # of Hit",2,3);
    hMWDC_NUMHITSUM0= MakeH1I(foldername_numhit, "NumHitSum0",60,-0.5,59.5,"Total # of Hit",2,3);

    MakePic("MWDC","Hit41",4,2,hMWDC_WIREID[0],hMWDC_WIREID[1],
	    hMWDC_WIREID[2],hMWDC_WIREID[3],hMWDC_WIREID[4],
	    hMWDC_WIREID[5],hMWDC_WIREID[6],hMWDC_WIREID[7]);

    MakePic("MWDC","Hit42",4,2,hMWDC_WIREID[8],hMWDC_WIREID[9],
	    hMWDC_WIREID[10],hMWDC_WIREID[11],hMWDC_WIREID[12],
	    hMWDC_WIREID[13],hMWDC_WIREID[14],hMWDC_WIREID[15]);

    MakePic("MWDC","Hit42",4,2,hMWDC_WIREID[8],hMWDC_WIREID[9],
	    hMWDC_WIREID[10],hMWDC_WIREID[11],hMWDC_WIREID[12],
	    hMWDC_WIREID[13],hMWDC_WIREID[14],hMWDC_WIREID[15]);

    // ---------------------------------------
    //             MWDC_Tracking 

    char foldername_track[100],foldername_res[100], foldername_res_ex[100];
    char fullname_chi2[100], fullname_x[100], fullname_y[100], fullname_a[100], fullname_b[100], fullname_res[100];
    char fullname_xy[100], fullname_ab[100], fullname_xa[100], fullname_yb[100],fullname_res_ex[100] ;
    // foldername
    sprintf(foldername_track, "MWDC/TRACK");
    sprintf(foldername_res,"MWDC/RESIDUAL");
    sprintf(foldername_res_ex,"MWDC/RESIDUAL_EX");
    // fullname
    sprintf(fullname_chi2, "MWDC_CHI2");
    sprintf(fullname_x,  "MWDC_X");
    sprintf(fullname_y,  "MWDC_Y");
    sprintf(fullname_a,  "MWDC_A");
    sprintf(fullname_b,  "MWDC_B");
    sprintf(fullname_xy, "MWDC_XY");
    sprintf(fullname_ab, "MWDC_AB");
    sprintf(fullname_xa, "MWDC_XA");
    sprintf(fullname_yb, "MWDC_YB");
    Float_t hist_x_min,hist_y_min,hist_x_max,hist_y_max;
    Float_t hist_a_min,hist_b_min,hist_a_max,hist_b_max;
    hist_x_min=-150.; hist_x_max=150.; hist_y_min =-150.; hist_y_max=150.;
    hist_a_min=-0.1*10. ; hist_a_max=0.1*10.; hist_b_min=-0.1*10.; hist_b_max=0.1*10.; // beam time >> pm0.1 // cosmic >> pm1.0
    //  MakeH2I: foldername, fullname, nbin, min, max, nbin, min, max, title-x, title-y, 2 (?)
    hMWDC_X    = MakeH1I(foldername_track, fullname_x,  1500, hist_x_min, hist_x_max, "X[mm]",2,3);
    hMWDC_Y    = MakeH1I(foldername_track, fullname_y,  1500, hist_y_min, hist_y_max, "Y[mm]",2,3);
    hMWDC_A    = MakeH1I(foldername_track, fullname_a,  1000, hist_a_min, hist_a_max, "A[rad]",2,3);
    hMWDC_B    = MakeH1I(foldername_track, fullname_b,  1000, hist_b_min, hist_b_max, "B[rad]",2,3);
    hMWDC_XY   = MakeH2I(foldername_track, fullname_xy, 1500, hist_x_min, hist_x_max, 1500, hist_y_min, hist_y_max, "X[mm]","Y[mm]",2);
    hMWDC_AB   = MakeH2I(foldername_track, fullname_ab, 1000, hist_a_min, hist_a_max, 1000, hist_b_min, hist_b_max, "A[rad]","B[rad]",2);
    hMWDC_XA   = MakeH2I(foldername_track, fullname_xa, 1500, hist_x_min, hist_x_max, 1000, hist_a_min, hist_a_max, "X[mm]","A[rad]",2);
    hMWDC_YB   = MakeH2I(foldername_track, fullname_yb, 1500, hist_y_min, hist_y_max, 1000, hist_b_min, hist_b_max, "Y[mm]","B[rad]",2);
    hMWDC_CHI2 = MakeH1I(foldername_track, fullname_chi2, 1020,-0.5,50.5,"reduced chi square",2,3);
    // 
    for(int i_plane=0; i_plane<16; i_plane++){
      sprintf(fullname_res, "Residual%d_%s",i_plane,mwdc->plane_name[i_plane]);
      sprintf(fullname_res_ex, "Residual_ex_%d_%s",i_plane,mwdc->plane_name[i_plane]);
      hMWDC_RES[i_plane] = MakeH1I(foldername_res, fullname_res,800,-2,2,"Residual[mm]",2,3);
      hMWDC_RES_EX[i_plane] = MakeH1I(foldername_res_ex, fullname_res_ex,800,-2,2,"Residual_ex [mm]",2,3);
    }
    for(int i_plane=0; i_plane<16; i_plane++){
      sprintf(fullname_res, "Residual-DLength%d_%s",i_plane,mwdc->plane_name[i_plane]);
      hMWDC_RES_LENGTH[i_plane] = MakeH2I(foldername_res,fullname_res,120,-3,3,400,-2,2,"drift length[mm]","residual [mm]",2);
    }


    hMWDC_XA_s   = MakeH2I("s436","MWDC_PosX_vs_AngleX", 1500, hist_x_min, hist_x_max, 1000, hist_a_min, hist_a_max, "X[mm]","Angle in X[rad]",2);

    hMWDC_YB_s   = MakeH2I("s436","MWDC_PosY_vs_AngleY", 1500, hist_y_min, hist_y_max, 1000, hist_b_min, hist_b_max, "Y[mm]","Angle in Y[rad]",2);




    //----------------------------------------
    //    S4 Profile
    
    // S4 Focus
    hS4FOC_X    = MakeH1I("Profile/S4Focus", "S4_Focus_x",  1500, hist_x_min, hist_x_max, "X[mm]",2,3);
    hS4FOC_Y    = MakeH1I("Profile/S4Focus", "S4_Focus_y",  1500, hist_y_min, hist_y_max, "Y[mm]",2,3);
    hS4FOC_A    = MakeH1I("Profile/S4Focus", "S4_Focus_a",  1000, hist_a_min, hist_a_max, "A[rad]",2,3);
    hS4FOC_B    = MakeH1I("Profile/S4Focus", "S4_Focus_b",  1000, hist_b_min, hist_b_max, "B[rad]",2,3);
    hS4FOC_XY   = MakeH2I("Profile/S4Focus", "S4_Focus_xy", 1500, hist_x_min, hist_x_max, 1500, hist_y_min, hist_y_max, "X[mm]","Y[mm]",2);
    hS4FOC_AB   = MakeH2I("Profile/S4Focus", "S4_Focus_ab", 1000, hist_a_min, hist_a_max, 1000, hist_b_min, hist_b_max, "A[rad]","B[rad]",2);
    hS4FOC_XA   = MakeH2I("Profile/S4Focus", "S4_Focus_xa", 1500, hist_x_min, hist_x_max, 1000, hist_a_min, hist_a_max, "X[mm]","A[rad]",2);
    hS4FOC_YB   = MakeH2I("Profile/S4Focus", "S4_Focus_yb", 1500, hist_y_min, hist_y_max, 1000, hist_b_min, hist_b_max, "Y[mm]","B[rad]",2);

    // SC41

    // HIRAC
 
    // TORCH
    
    // SC42


    // ---------------------------------------
    //                ETAP SCI  

    char foldername_sci_qdc[100], foldername_sci_tdc[100],foldername_sci_tdc_m[100],foldername_sci_t0_tdc[100], foldername_sci_time[100], foldername_sci_de[100];
    char foldername_sci_timedif[100],foldername_sci_timeave[100], foldername_sci_tdc_qdc[100];
    char fullname_sci_qdc[100], fullname_sci_tdc[100],fullname_sci_tdc_m[100], fullname_sci_t0_tdc[100], fullname_sci_time[100], fullname_sci_de[100];
    char fullname_sci_timedif[100],fullname_sci_timeave[100], fullname_sci_tdc_qdc[100];
    // foldername
    sprintf(foldername_sci_qdc,    "SCI/QDC");
    sprintf(foldername_sci_tdc,    "SCI/TDC");
    sprintf(foldername_sci_tdc_m,  "SCI/TDC-M");
    sprintf(foldername_sci_t0_tdc, "SCI/T0-TDC");
    sprintf(foldername_sci_time,   "SCI/TIME");
    sprintf(foldername_sci_de,     "SCI/DE");
    sprintf(foldername_sci_timeave,"SCI/TIMEAVE");
    sprintf(foldername_sci_timedif,"SCI/TIMEDIF");
    sprintf(foldername_sci_tdc_qdc,"SCI/TDC_QDC");
    // fullname  
    for(int i=0;i<(mwdc->num_sci);i++){
      for(int i_lr=0; i_lr<(mwdc->sci_num_channel[i]); i_lr++){
	sprintf(fullname_sci_qdc, "SCI_QDC_%s", mwdc->sci_channel_name[i][i_lr]);
	sprintf(fullname_sci_t0_tdc, "SCI_T0_TDC_%s", mwdc->sci_channel_name[i][i_lr]);
	sprintf(fullname_sci_tdc,  "SCI_TDC_%s", mwdc->sci_channel_name[i][i_lr]);
	sprintf(fullname_sci_tdc_m,"SCI_TDC_M_%s", mwdc->sci_channel_name[i][i_lr]);
	sprintf(fullname_sci_time,"SCI_TIME_%s",mwdc->sci_channel_name[i][i_lr]);
	sprintf(fullname_sci_tdc_qdc,"SCI_TDC_QDC_%s",mwdc->sci_channel_name[i][i_lr]);
	hSCI_QDC[i][i_lr]    = MakeH1I(foldername_sci_qdc,  fullname_sci_qdc, 1024, -0.5, 4095.5, "QDC value",2,3);
	//20.07.2014 (tanaka)
	hSCI_TDC[i][i_lr]    = MakeH1I(foldername_sci_tdc,  fullname_sci_tdc , 10000,-20000,80000, "TDC value",2,3);
	hSCI_T0_TDC[i][i_lr] = MakeH1I(foldername_sci_t0_tdc,  fullname_sci_t0_tdc , 10000,-20000,80000, "T0-TDC value",2,3);
	hSCI_TDC_M[i][i_lr] = MakeH1I(foldername_sci_tdc_m,  fullname_sci_tdc_m , 16,-0.5,15.5, "TDC multiplicity",2,3);
	hSCI_TIME[i][i_lr]   = MakeH1I(foldername_sci_time, fullname_sci_time,2000,-100.,300.,"hit time[ns]",2,3);
	hSCI_TDC_QDC[i][i_lr]= MakeH2I(foldername_sci_tdc_qdc,fullname_sci_tdc_qdc, 1024, -0.5, 4095.5, 1024, -0.5, 4095.5, "TDC value","QDC value",2);
      }

     /* MakePic("SCI","QDC",5,2,hSCI_QDC[4][0],hSCI_QDC[4][1],hSCI_QDC[5][0],
              hSCI_QDC[5][1],hSCI_QDC[6][0],hSCI_QDC[6][1],hSCI_QDC[7][0],
              hSCI_QDC[7][1],hSCI_QDC[8][0],hSCI_QDC[8][1]);

      sprintf(fullname_sci_timeave, "SCI_TIMEACE_%s",mwdc->sci_name[i]);
      sprintf(fullname_sci_timedif, "SCI_TIMEDIF_%s" ,mwdc->sci_name[i]);
      sprintf(fullname_sci_de, "SCI_DE_%s",mwdc->sci_name[i]);
      hSCI_TIMEAVE[i] = MakeH1I(foldername_sci_timeave, fullname_sci_timeave, 4096, -0.5, 4095.5, "time average [ns]",2,3);
      hSCI_TIMEDIF[i] = MakeH1I(foldername_sci_timedif,  fullname_sci_timedif , 600,  -5.,    25., "time difference (L-R) [ns]",2,3);
      hSCI_DE[i]      = MakeH1I(foldername_sci_de, fullname_sci_de, 4096, -0.5, 4095.5, "Delta E",2,3);*/

     // 18-07-2014
     // sprintf(fullname_sci_de, "SCI_DE_vs_%s",mwdc->sci_name[i]);
     // hSCI_DE_ToF[i]= MakeH2I(foldername_sci_de,fullname_sci_de, 1000, -0.5, 4095.5, 250, -0.5, 4095.5, "Delta E","ToF",2);
    }

    // 19-07-2014-JLRS: Moved
    //  for(int i=0;i<4;i++){
      // 18-07-2014
    //     sprintf(fullname_sci_de,"SCI_DE1_vs_DE2_%i",i);
    //      hSCI_DE1_DE2[i]= MakeH2I(foldername_sci_de,fullname_sci_de, 700, -0.5, 4095.5, 700, -0.5, 4095.5, "Delta E1","Delta E2",2);
    //  }

    // ---------------------------------------
    //              miniHIRAC
    /*
    char foldername_mini_qdc[100], foldername_mini_tdc[100], foldername_mini_time[100], foldername_mini_pe[100], foldername_mini[100], foldername_mini_tdc_qdc[100];
    char fullname_mini_qdc[100], fullname_mini_tdc[100], fullname_mini_pe[100], fullname_mini_time[100], fullname_mini_tdc_qdc[100];
    char fullname_mini_pesum[100], fullname_mini_numhit[100];
    // foldername
    sprintf(foldername_mini_qdc, "miniHIRAC/QDC");
    sprintf(foldername_mini_tdc, "miniHIRAC/TDC");
    sprintf(foldername_mini_time, "miniHIRAC/Time");
    sprintf(foldername_mini_pe, "miniHIRAC/PE");
    sprintf(foldername_mini,    "miniHIRAC");
    sprintf(foldername_mini_tdc_qdc,"miniHIRAC/TDC_QDC");
    // fullname  
    for(int i=0; i<2; i++){
     
      sprintf(fullname_mini_qdc, "MINI_QDC_%s",mwdc->mini_channel_name[i]);
      sprintf(fullname_mini_pe,  "MINI_PE_%s" ,mwdc->mini_channel_name[i]);
      sprintf(fullname_mini_tdc, "MINI_TDC_%s",mwdc->mini_channel_name[i]);
      sprintf(fullname_mini_time,"MINI_TIME_%s",mwdc->mini_channel_name[i]);
      sprintf(fullname_mini_tdc_qdc,"MINI_TDC_QDC_%s",mwdc->mini_channel_name[i]);
      hMINI_QDC_RAW[i]         = MakeH1I(foldername_mini_qdc, fullname_mini_qdc, 4096, -0.5, 4095.5, "QDC value",2,3);
      hMINI_QDC_BASELINE[i]    = MakeH1I(foldername_mini_qdc, fullname_mini_qdc, 4096, -0.5, 4095.5, "QDC value",2,3);
      hMINI_QDC_RAW_BASELINE[i]= 
      hMINI_QDC_COR[i]         = MakeH1I(foldername_mini_qdc, fullname_mini_qdc, 4096, -0.5, 4095.5, "QDC value",2,3);
      hMINI_TDC_RAW[i]         = MakeH1I(foldername_mini_tdc, fullname_mini_tdc, 4096, -0.5, 4095.5, "TDC value",2,3);
      hMINI_TDC_T0[i]          = MakeH1I(foldername_mini_tdc, fullname_mini_tdc, 4096, -0.5, 4095.5, "TDC value",2,3);
      hMINI_TDC_SUB[i]         = MakeH1I(foldername_mini_tdc, fullname_mini_tdc, 4096, -0.5, 4095.5, "TDC value",2,3);
      

      hMINI_PE[i]     = MakeH1I(foldername_mini_pe,  fullname_mini_pe , 600,  -5.,    25., "number of p.e.",2,3);
      hMINI_TDC[i]    = MakeH1I(foldername_mini_tdc, fullname_mini_tdc, 4096, -0.5, 4095.5, "TDC value",2,3);
      hMINI_TIME[i]   = MakeH1I(foldername_mini_time,fullname_mini_time,2000,-100.,300.,"hit time[ns]",2,3);
      hMINI_TDC_QDC[i]= MakeH2I(foldername_mini_tdc_qdc, fullname_mini_tdc_qdc, 1024, -0.5, 4095.5, 1024, -0.5, 4095.5, "TDC value","QDC value",2);
      
    }
    sprintf(fullname_mini_pesum,"MINI_PESUM");
    sprintf(fullname_mini_numhit,"MINI_NUMHIT");
    hMINI_PESUM  = MakeH1I(foldername_mini_pe, fullname_mini_pesum,1500,-10.,140.,"number of p.e. ",2,3);
    hMINI_NUMHIT = MakeH1I(foldername_mini,    fullname_mini_numhit,11,-0.5,10.5, "number of hit PMTs",2,3);
    */

     

    // Conditions for the plastics

    Float_t lim_sci[6][2]={{100,20000},{100,20000},{100,20000},{100,20000},{100,20000},{100,20000}};


    char condname[40];
    sprintf(condname,"TDC_%s","SC41L");
    cTDC_SCI[0][0]=MakeWindowCond("TDC/TDC_SC41L",condname,lim_sci[0][0],lim_sci[0][1],"SCI_TDC_SC41L");
    sprintf(condname,"TDC_%s","SC41R");
    cTDC_SCI[0][1]=MakeWindowCond("TDC/TDC_SC41R",condname,lim_sci[1][0],lim_sci[1][1],"SCI_TDC_SC41R");
    sprintf(condname,"TDC_%s","SC42L");
    cTDC_SCI[1][0]=MakeWindowCond("TDC/TDC_SC42L",condname,lim_sci[2][0],lim_sci[2][1],"SCI_TDC_SC42L");
    sprintf(condname,"TDC_%s","SC42R");
    cTDC_SCI[1][1]=MakeWindowCond("TDC/TDC_SC42R",condname,lim_sci[3][0],lim_sci[3][1],"SCI_TDC_SC42R");
    sprintf(condname,"TDC_%s","SC43L");
    cTDC_SCI[2][0]=MakeWindowCond("TDC/TDC_SC43L",condname,lim_sci[4][0],lim_sci[4][1],"SCI_TDC_SC43L");
    sprintf(condname,"TDC_%s","SC43R");
    cTDC_SCI[2][1]=MakeWindowCond("TDC/TDC_SC43R",condname,lim_sci[5][0],lim_sci[5][1],"SCI_TDC_SC43R");


   // ---------------------------------------
   //             HIRAC

    char foldername_hirac_qdc_raw[100], foldername_hirac_qdc_base[100], foldername_hirac_qdc_raw_base[100], foldername_hirac_qdc_cor[100], foldername_hirac_pe[100];
    char foldername_hirac_tdc_raw[100], foldername_hirac_tdc_t0cor[100], foldername_hirac_tdc_qdc[100], foldername_hirac_tdc_cor[100], foldername_hirac[100];
    char fullname_hirac_qdc_raw[100], fullname_hirac_qdc_base[100], fullname_hirac_qdc_raw_base[100], fullname_hirac_qdc_cor[100], fullname_hirac_pe[100];
    char fullname_hirac_tdc_raw[100], fullname_hirac_tdc_t0cor[100], fullname_hirac_tdc_qdc[100], fullname_hirac_tdc_cor[100] ;
    char fullname_hirac_pesum[100], fullname_hirac_x[100], fullname_hirac_numhit[100];
   
    // foldername
    sprintf(foldername_hirac_qdc_raw,      "HIRAC/QDC_RAW"); 
    sprintf(foldername_hirac_qdc_base,     "HIRAC/QDC_BASE");
    sprintf(foldername_hirac_qdc_raw_base, "HIRAC/QDC_RAW_BASE"); 
    sprintf(foldername_hirac_qdc_cor,      "HIRAC/QDC_COR");
    sprintf(foldername_hirac_pe,           "HIRAC/PE"); 
    sprintf(foldername_hirac_tdc_raw,      "HIRAC/TDC_RAW"); 
    sprintf(foldername_hirac_tdc_t0cor,    "HIRAC/TDC_T0COR");
    sprintf(foldername_hirac_tdc_qdc,      "HIRAC/TDC_QDC");
    sprintf(foldername_hirac_tdc_cor,      "HIRAC/TDC_COR");
    sprintf(foldername_hirac,              "HIRAC");

    // fullname  
    for(int i=0; i<8; i++){
      sprintf(fullname_hirac_qdc_raw,     "HIRAC_QDC_RAW_%s",mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_qdc_base,    "HIRAC_QDC_BASE_%s" ,mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_qdc_raw_base,"HIRAC_QDC_RAW_BASE_%s",mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_qdc_cor,     "HIRAC_QDC_COR_%s",mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_pe,          "HIRAC_PE_%s" ,mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_tdc_raw,     "HIRAC_TDC_RAW_%s",mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_tdc_t0cor,   "HIRAC_TDC_T0COR_%s",mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_tdc_qdc,     "HIRAC_TDC_QDC_%s" ,mwdc->hirac_channel_name[i]);
      sprintf(fullname_hirac_tdc_cor,     "HIRAC_TDC_COR_%s",mwdc->hirac_channel_name[i]);
      hHIRAC_QDC_RAW[i]     = MakeH1I(foldername_hirac_qdc_raw, fullname_hirac_qdc_raw, 4096, -0.5, 1023.5, "QDC value",2,3);
      hHIRAC_QDC_BASE[i]    = MakeH1I(foldername_hirac_qdc_base, fullname_hirac_qdc_base, 4096, -0.5, 1023.5, "QDC value",2,3);
      hHIRAC_QDC_RAW_BASE[i]= MakeH2I(foldername_hirac_qdc_raw_base, fullname_hirac_qdc_raw_base, 1024, -0.5, 4095.5, 1024, -0.5, 4095.5, "TDC value","QDC value",2);
      hHIRAC_QDC_COR[i]     = MakeH1I(foldername_hirac_qdc_cor, fullname_hirac_qdc_cor, 2000, 450.0, 850.0, "QDC value",2,3);
      hHIRAC_PE[i]          = MakeH1I(foldername_hirac_pe,  fullname_hirac_pe , 600,  -5.,    25., "number of p.e.",2,3);
      hHIRAC_TDC_RAW[i]     = MakeH1I(foldername_hirac_tdc_raw, fullname_hirac_tdc_raw, 4096, -0.5, 4095.5, "TDC value",2,3);
      hHIRAC_TDC_T0COR[i]   = MakeH1I(foldername_hirac_tdc_t0cor,fullname_hirac_tdc_t0cor,2000,-100.,300.,"hit time[ns]",2,3);
      hHIRAC_TDC_QDC[i]     = MakeH2I(foldername_hirac_tdc_qdc, fullname_hirac_tdc_qdc, 1024, -0.5, 4095.5, 1024, -0.5, 4095.5, "TDC value","QDC value",2);
      hHIRAC_TDC_COR[i]     = MakeH1I(foldername_hirac_tdc_cor, fullname_hirac_tdc_cor, 4096, -0.5, 4095.5, "TDC value",2,3);
    }

    sprintf(fullname_hirac_pesum,"HIRAC_PESUM");
    sprintf(fullname_hirac_x,    "HIRAC_X");
    sprintf(fullname_hirac_numhit,"HIRAC_NUMHIT");
    hHIRAC_PESUM  = MakeH1I(foldername_hirac,    fullname_hirac_pesum,1500,-10.,140.,"number of p.e. ",2,3);
    hHIRAC_X      = MakeH1I(foldername_hirac,    fullname_hirac_x,   2000,-200.,200.,"hirac average x[mm]",2,3);
    hHIRAC_NUMHIT = MakeH1I(foldername_hirac,    fullname_hirac_numhit,11,-0.5,10.5, "number of hit PMTs",2,3);


    
    // ---------------------------------------
    //              TORCH

    char foldername_torch_qdc[100], foldername_torch_tdc[100], foldername_torch_time[100], foldername_torch_pe[100], foldername_torch[100], foldername_torch_tdc_qdc[100];
    char fullname_torch_qdc[100], fullname_torch_tdc[100], fullname_torch_pe[100], fullname_torch_time[100], fullname_torch_tdc_qdc[100];
    char fullname_torch_pesum[100], fullname_torch_x[100], fullname_torch_numhit[100];
    // foldername
    sprintf(foldername_torch_qdc, "TORCH/QDC");
    sprintf(foldername_torch_tdc, "TORCH/TDC");
    sprintf(foldername_torch_time,"TORCH/Time");
    sprintf(foldername_torch_pe,  "TORCH/PE");
    sprintf(foldername_torch,     "TORCH");
    sprintf(foldername_torch_tdc_qdc, "TORCH/TDC_QDC");
    // fullname  
    for(int i=0; i<6; i++){
      sprintf(fullname_torch_qdc, "TORCH_QDC_%s",mwdc->torch_channel_name[i]);
      sprintf(fullname_torch_pe,  "TORCH_PE_%s",mwdc->torch_channel_name[i]);
      sprintf(fullname_torch_tdc, "TORCH_TDC_%s",mwdc->torch_channel_name[i]);
      sprintf(fullname_torch_time,"TORCH_TIME_%s",mwdc->torch_channel_name[i]);
      sprintf(fullname_torch_tdc_qdc,"TORCH_TDC_QDC_%s",mwdc->torch_channel_name[i]);
      hTORCH_QDC[i]    = MakeH1I(foldername_torch_qdc, fullname_torch_qdc, 4096, -0.5, 4095.5, "QDC value",2,3);
      hTORCH_PE[i]     = MakeH1I(foldername_torch_pe,  fullname_torch_pe , 600,  -5.,    25., "number of p.e.",2,3);
      hTORCH_TDC[i]    = MakeH1I(foldername_torch_tdc, fullname_torch_tdc, 4096, -0.5, 4095.5, "TDC value",2,3);
      hTORCH_TIME[i]   = MakeH1I(foldername_torch_time,fullname_torch_time,2000,-100.,300.,"hit time [ns]",2,3);
      hTORCH_TDC_QDC[i]= MakeH2I(foldername_torch_tdc_qdc, fullname_torch_tdc_qdc, 1024, -0.5, 4095.5, 1024, -0.5, 4095.5, "TDC value","QDC value",2);
    }
    sprintf(fullname_torch_pesum,"TORCH_PESUM");
    sprintf(fullname_torch_x,"TORCH_X");
    sprintf(fullname_torch_numhit,"TORCH_NUMHIT");
    hTORCH_PESUM  = MakeH1I(foldername_torch_pe, fullname_torch_pesum, 1500,-10.,140.,"number of p.e. ",2,3);
    hTORCH_X      = MakeH1I(foldername_torch,    fullname_torch_x,    2000,-200.,200.,"TORCH average x[mm] ",2,3);
    hTORCH_NUMHIT = MakeH1I(foldername_torch,    fullname_torch_numhit,11,-0.5,10.5, "number of hit PMTs",2,3);




    return ;
}




void TFRSCalibrProc::Create_MW_Data() 
{
   Float_t lim_xsum[13][2] = {
     {1,8000},  // MW11
     {1,8000},  // MW21
     {1,8000},  // MW22
     {1,8000},  // MW31
     {1,8000},  // MW41
     {1,8000},  // MW42
     {1,8000},  // MW51
     {   1,8190},
     {   1,8190},
     {   1,8190},
     {   1,8190},
     {   1,8190},
     {   1,8190}};
   
   Float_t lim_ysum[13][2] = {
     {2,8000},
     {2,8000},
     {2,8000},
     {2,8000},
     {2,8000},
     {2,8000},
     {2,8000},
     {   1,8190},
     {   1,8190},
     {   1,8190},
     {   1,8190},
     {   1,8190},
     {   1,8190}};
    
   //   for(int i=0;i<13;i++) {
   for(int i=0;i<4;i++) {  // up to MW31
      char fname[100]; 
      sprintf(fname,"MW/MW%s/MW%s", mw_folder_ext1[i],mw_folder_ext2[i]); 
       
      hMW_AN[i] = MakeH1I_MW(fname,"MW_an",i,1000,1,4096,"Anode (channels)",2,3);
      hMW_XL[i] = MakeH1I_MW(fname,"MW_XL",i,1000,1,4096,"X-left (channels)",2,3);
      hMW_XR[i] = MakeH1I_MW(fname,"MW_XR",i,1000,1,4096,"X-right (channels)",2,3);
      hMW_YU[i] = MakeH1I_MW(fname,"MW_YU",i,1000,1,4096,"Y-up (channels)",2,3);
      hMW_YD[i] = MakeH1I_MW(fname,"MW_YD",i,1000,1,4096,"Y-down (channels)",2,3);
      
      hMW_XSUM[i] = MakeH1I_MW(fname,"MW_XSUM",i,800,5,8005,"Sum XL+XR (channels)",2,5);
      hMW_YSUM[i] = MakeH1I_MW(fname,"MW_YSUM",i,800,5,8005,"Sum YU+YD (channels)",2,5);
      
      char title[100];
      if((i==0) || (i>3))
        sprintf(title,"(stiff) X at MW%s [mm] (soft)", mw_folder_ext2[i]);
      else
        sprintf(title,"(soft) X at MW%s [mm] (stiff)", mw_folder_ext2[i]);
      hMW_X[i] = MakeH1I_MW(fname,"MW_X",i,201,-100.5,+100.5,title,2,7);
      
      sprintf(title,"Y at MW%s [mm]", mw_folder_ext2[i]);
      hMW_Y[i] = MakeH1I_MW(fname,"MW_Y",i,201,-100.5,+100.5,title,2,7);
      
      char xyname[100];
      sprintf(xyname,"MW_XY%s", mw_name_ext[i]);
      hMW_XY[i] = MakeH2I(fname,xyname,40,-100,100,40,-100,100,"x [mm]","y [mm]",2);

      //      hMW_WIRE[i] = MakeH1I_MW(fname,"MW_WIRE",i,201,-100.5,+100.5,"X*cos(45)+Y*sin(45) (mm)",2,5);
      
      char condname[40];
      sprintf(condname,"XSUM%s",mw_name_ext[i]);
      cMW_XSUM[i] = MakeWindowCond("MW/XSUM", condname, lim_xsum[i][0], lim_xsum[i][1], hMW_XSUM[i]->GetName());
      
      sprintf(condname,"YSUM%s",mw_name_ext[i]);
      cMW_YSUM[i] = MakeWindowCond("MW/YSUM", condname, lim_ysum[i][0], lim_ysum[i][1], hMW_YSUM[i]->GetName());
   }
   
   hMW_xas4   = MakeH1I("MW","MW_xas4",  300,-200,400,"X*A at S4 tracked focus",2,7);
   hMW_ybs4   = MakeH1I("MW","MW_ybs4",  300,-200,400,"Y*B at S4 tracked focus",2,7);
   
   hMW_SC21x  = MakeH1I("MW","MW_SC21x", 221,-110.5,110.5,"X tracked at SC21 [mm]",2,7);
   hMW_SC22x  = MakeH1I("MW","MW_SC22x", 221,-110.5,110.5,"X tracked at SC22 [mm]",2,7);
   hMW_SC41x  = MakeH1I("MW","MW_SC41x", 221,-110.5,110.5,"X tracked at SC41 [mm]",2,7);
   hMW_SC41y  = MakeH1I("MW","MW_SC41y", 221,-110.5,110.5,"Y tracked at SC41 [mm]",2,7);

   hitag_stopper_x = MakeH1I("ITAG","stopper_x",200,-100,100,"X tracked at stopper [mm]",2,7);  

   //   hMW_SC81x  = MakeH1I("MW","MW_SC81x", 221,-110.5,110.5,"X tracked at SC81 [mm]",2,7);
   //   hMW_MUSICx = MakeH1I("MW","MW_MUSICx",221,-110.5,110.5,"X tracked at MUSIC [mm]",2,7);
   
   hMW_xAngS2 = MakeH1I("MW/S2/Ang","MW_xAngS2",201,-100.5,100.5,"X-Angles at S2 [mrad]",2,7); 
   hMW_yAngS2 = MakeH1I("MW/S2/Ang","MW_yAngS2",201,-100.5,100.5,"Y-Angles at S2 [mrad]",2,7);
   hMW_xFocS2 = MakeH1I("MW/S2/Foc","MW_xFocS2",201,-100.5,100.5,"X-Position at S2 Focus [mm]",2,7);
   hMW_yFocS2 = MakeH1I("MW/S2/Foc","MW_yFocS2",201,-100.5,100.5,"Y-Position at S2 Focus [mm]",2,7);
   hMW_zxS2   = MakeH1I("MW/S2/Pos","MW_zxS2",350,-100,600,"Distance from TS3QT33 at S2 Focus [cm]",2,7);
   hMW_zyS2   = MakeH1I("MW/S2/Pos","MW_zyS2",350,-100,600,"Distance from TS3QT33 at S2 Focus [cm]",2,7);
   hMW_FocS2  = MakeH2I("MW/S2/Foc","MW_FocS2", 240,-120.,120.,  240,-120.,120.,
                          "X [mm] tracked to S2 focus","Y [mm] tracked to S2 focus", 2);

   hMW_xAngS4 = MakeH1I("MW/S4/Ang","MW_xAngS4",201,-100.5,100.5,"X-Angles at S4 [mrad]",2,7); 
   hMW_yAngS4 = MakeH1I("MW/S4/Ang","MW_yAngS4",201,-100.5,100.5,"Y-Angles at S4 [mrad]",2,7);
   hMW_xFocS4 = MakeH1I("MW/S4/Foc","MW_xFocS4",201,-100.5,100.5,"X-Position at S4 Focus [mm]",2,7);
   hMW_yFocS4 = MakeH1I("MW/S4/Foc","MW_yFocS4",201,-100.5,100.5,"Y-Position at S4 Focus [mm]",2,7);
   hMW_zxS4   = MakeH1I("MW/S4/Pos","MW_zxS4",350,-100,600,"Distance from HFSQT13 at S4 Focus [cm]",2,7);
   hMW_zyS4   = MakeH1I("MW/S4/Pos","MW_zyS4",350,-100,600,"Distance from HFSQT13 at S4 Focus [cm]",2,7);
   hMW_FocS4  = MakeH2I("MW/S4/Foc","MW_FocS4", 240,-120.,120.,  240,-120.,120.,
                          "X [mm] tracked to S4 focus","Y [mm] tracked to S4 focus", 2);
                          

   
   //   for (int i=0;i<13;i++) {
   for (int i=0;i<4;i++) {  // up to MW31
      char fname[100], pname[100];
      sprintf(fname,"MW/MW%s", mw_folder_ext1[i]);
      sprintf(pname,"MW%s", mw_folder_ext2[i]);
      MakePic(fname,pname,2,2,hMW_XL[i],hMW_XR[i],hMW_YU[i],hMW_YD[i]);
   }

}


//Creation of TPC data & histograms
void TFRSCalibrProc::Create_TPC_Data()
{

  /*  Float_t lim_csum1[6][2]={{1315,1800},{1200,1800},{1300,1800},{1325,1800},{1295,1800},{1280,1800}};
  Float_t lim_csum2[6][2]={{1330,1800},{1230,1800},{1345,1800},{1375,1800},{1240,1800},{1210,1800}};
  Float_t lim_csum3[6][2]={{1340,1800},{1290,1840},{1340,1820},{1275,1840},{1210,1875},{1250,1820}};
  Float_t lim_csum4[6][2]={{1310,1880},{1260,1810},{1345,1885},{1320,1880},{1280,1840},{1270,1870}};*/

  // changed during beam time at 00:49 25.July.2014 for Carbon, S4 trig
  Float_t lim_csum1[6][2]={{800,1000},{-1000,-1000},{-1000,3000},{-1000,3000},{800,1000},{1400,1600}};
  Float_t lim_csum2[6][2]={{400,600}, {-1000,-1000},{-1000,3000},{-1000,3000},{800,1000},{1400,1600}};
  Float_t lim_csum3[6][2]={{-1000,-1000},{2200,2400},{-1000,3000},{-1000,3000},{800,1000},{1400,1600}};
  Float_t lim_csum4[6][2]={{-1000,-1000},{2200,2400},{-1000,3000},{-1000,3000},{800,1000},{1400,1600}};

   for(int i=0;i<6;i++){
  		char condname[40];
   	 sprintf(condname,"CSUM1%s",tpc_name_ext1[i]);
	    cTPC_CSUM[i][0]=MakeWindowCond("TPC/CSUM1",condname,lim_csum1[i][0],
				 lim_csum1[i][1],"CSUM1");
	    sprintf(condname,"CSUM2%s",tpc_name_ext1[i]);
	    cTPC_CSUM[i][1]=MakeWindowCond("TPC/CSUM2",condname,lim_csum2[i][0],
				 lim_csum2[i][1],"CSUM2");
		 sprintf(condname,"CSUM3%s",tpc_name_ext1[i]);
	    cTPC_CSUM[i][2]=MakeWindowCond("TPC/CSUM3",condname,lim_csum3[i][0],
				 lim_csum3[i][1],"CSUM3");
	    sprintf(condname,"CSUM4%s",tpc_name_ext1[i]);
	    cTPC_CSUM[i][3]=MakeWindowCond("TPC/CSUM4",condname,lim_csum4[i][0],
				 lim_csum4[i][1],"CSUM4");
   }

  for(int i=0;i<6;i++){        
    char fname[100];
    char name[100];
    sprintf(fname,"TPC/%s/",tpc_folder_ext1[i]);
    //(HAPOL-25/03/06) Duplicated histograms for double delay line (0 and 1) in new TPCs

    hTPC_L0[i]=MakeH1I_TPC(fname,"L0",i,4000,5,4005,
                          "Left DL0 ADC (channels)",2,3);
    hTPC_R0[i]=MakeH1I_TPC(fname,"R0",i,4000,5,4005,
                          "Right DL0 ADc (channels)",2,3);
    hTPC_LT0[i]=MakeH1I_TPC(fname,"LT0",i,4000,5,4005,
                           "Left DL0 time (channels)",2,3);
    hTPC_RT0[i]=MakeH1I_TPC(fname,"RT0",i,4000,5,4005,
                           "Right DL0 time(channels)",2,3);
    hTPC_L1[i]=MakeH1I_TPC(fname,"L1",i,4000,5,4005,
                          "Left DL1 ADC (channels)",2,3);
    hTPC_R1[i]=MakeH1I_TPC(fname,"R1",i,4000,5,4005,
                          "Right DL1 ADC (channels)",2,3);
    hTPC_LT1[i]=MakeH1I_TPC(fname,"LT1",i,4000,5,4005,
                           "Left DL1 time (channels)",2,3);
    hTPC_RT1[i]=MakeH1I_TPC(fname,"RT1",i,4000,5,4005,
                           "Right DL1 time(channels)",2,3);
    hTPC_DT[i][0]=MakeH1I_TPC(fname,"DT1",i,4000,5,4005,
			    "drift time 1 (channels)",2,3);
    hTPC_DT[i][1]=MakeH1I_TPC(fname,"DT2",i,4000,5,4005,
			    "drift time 2(channels)",2,3);
    hTPC_DT[i][2]=MakeH1I_TPC(fname,"DT3",i,4000,5,4005,
			    "drift time 3(channels)",2,3);
    hTPC_DT[i][3]=MakeH1I_TPC(fname,"DT4",i,4000,5,4005,
			    "drift time 4(channels)",2,3);
    hTPC_A[i][0]=MakeH1I_TPC(fname,"A1",i,4000,5,4005,
			   "anode 1 ADC(channels)",2,3);
    hTPC_A[i][1]=MakeH1I_TPC(fname,"A2",i,4000,5,4005,
			   "anode 2 ADC(channels)",2,3);
    hTPC_A[i][2]=MakeH1I_TPC(fname,"A3",i,4000,5,4005,
			   "anode 3 ADC(channels)",2,3);
    hTPC_A[i][3]=MakeH1I_TPC(fname,"A4",i,4000,5,4005,
			   "anode 4 ADC(channels)",2,3);
    hTPC_CSUM[i][0]=MakeH1I_TPC(fname,"CSUM1",i,4000,-2000,4005,
			      "control sum 1(channels)",2,3);
    hTPC_CSUM[i][1]=MakeH1I_TPC(fname,"CSUM2",i,4000,-2000,4005,
			      "control sum 2(channels)",2,3);
    hTPC_CSUM[i][2]=MakeH1I_TPC(fname,"CSUM3",i,4000,-2000,4005,
			      "control sum 3(channels)",2,3);
    hTPC_CSUM[i][3]=MakeH1I_TPC(fname,"CSUM4",i,4000,-2000,4005,
			      "control sum 4(channels)",2,3);

    hTPC_XRAW0[i]=MakeH1I_TPC(fname,"Xraw0",i,1000,-2000,2000,
			  "First delay line  x(ch)",2,3);
    hTPC_XRAW1[i]=MakeH1I_TPC(fname,"Xraw1",i,1000,-2000,2000,
			  "Second delay line x(ch)",2,3);
    hTPC_YRAW[i]=MakeH1I_TPC(fname,"Yraw",i,4000,0.0,4000.,
			  "y(ch)",2,3);
    hTPC_X[i]=MakeH1I_TPC(fname,"X",i,800,-100.,100.,
			  "x[mm]",2,3);
    hTPC_Y[i]=MakeH1I_TPC(fname,"Y",i,800,-100.,100.,
			  "y[mm]",2,3);


    sprintf(name,"%s%s",tpc_name_ext1[i],"XY");
    hcTPC_XY[i]=MakeH2I(fname,name, 120,-120.,120., 120,-120.,120.,
                          "X [mm] ","Y [mm] ", 2);

    sprintf(name,"%s%s",tpc_name_ext1[i],"LTRT");
    hTPC_LTRT[i]=MakeH2I(fname,name, 2048,0,4095, 2048,0,4095,
                          "LT [ch]","RT[ch] ", 2);			
    hTPC_DELTAX[i]=MakeH1I_TPC(fname,"x0-x1",i,100,-10.,10.,
			  "x0-x1[mm]",2,3);
					
  }

  //Calculated positions and angles from tracking

  hTPC_X_S2_foc=MakeH1I_TPC("TPC/S2_foc","S2_X_foc",-1,1000,-100.,100.,
			"x at S2 focus [mm]",2,3);
  hTPC_Y_S2_foc=MakeH1I_TPC("TPC/S2_foc","S2_Y_foc",-1,1000,-100.,100.,
			"y at S2 focus [mm]",2,3);
  hTPC_AX_S2_foc=MakeH1I_TPC("TPC/S2_foc","S2_AX_foc",-1,1000,-100.5,100.5,
			"angl_x at S2 focus [mrad]",2,3);
  hTPC_AY_S2_foc=MakeH1I_TPC("TPC/S2_foc","S2_AY_foc",-1,1000,-100.5,100.5,
			"angl_y at S2 focus [mrad]",2,3);

  hTPC_X_S4=MakeH1I_TPC("TPC/S4","S4_X",-1,1000,-100.5,100.5,
			"x at S4 [mm]",2,3);
  hTPC_Y_S4=MakeH1I_TPC("TPC/S4","S4_Y",-1,1000,-100.5,100.5,
			"y at S4 [mm]",2,3);
  hTPC_AX_S4=MakeH1I_TPC("TPC/S4","S4_AX",-1,1000,-100.5,100.5,
			"angl_x at S4[mrad]",2,3);
  hTPC_AY_S4=MakeH1I_TPC("TPC/S4","S4_AY",-1,1000,-100.5,100.5,
			"angl_y at S4[mrad]",2,3);
  hTPC_X_S4_target1=MakeH1I_TPC("TPC/S4","S4_X_target1",-1,1000,-100.5,100.5,
			"x at S4 at H2 target [mm]",2,3);
  hTPC_Y_S4_target1=MakeH1I_TPC("TPC/S4","S4_Y_target1",-1,1000,-100.5,100.5,
			"y at S4 at H2 target [mm]",2,3);
  hTPC_X_S4_target1d=MakeH1I_TPC("TPC/S4","S4_X_target1d",-1,1000,-100.5,100.5,
			"x at S4 at H2 target [mm]",2,3);
  hTPC_Y_S4_target1d=MakeH1I_TPC("TPC/S4","S4_Y_target1d",-1,1000,-100.5,100.5,
			"y at S4 at H2 target [mm]",2,3);
  
  hTPC_XY_S4_target1=MakeH2I("TPC/S4","S4_XY_target1",1000,-100.5,100.5,1000,-100.5,100.5,
			"x-S4 at H2 target [mm]","y-S4 at H2 target [mm]",2);
  hTPC_XY_S4_target1d=MakeH2I("TPC/S4","S4_XY_target1d",1000,-100.5,100.5,1000,-100.5,100.5,
			"x-S4 at H2 target [mm]","y-S4 at H2 target [mm]",2);

  hTPC_XAX_S4=MakeH2I("TPC/S4","angle_vs_x_S4", 240,-120.,120., 240,-50.0,50.0,
                          "X [mm] ","x angle [mrad] ", 2);
  
  hTPC_XS4_AX_S2 =MakeH2I("TPC/S4","angle_s2_at vs x_S4", 240,-120.,120., 240,-50.0,50.0,
                          "X at S4 [mm] ","angl_x at S2 [mrad] ", 2);

  hTPC_X_S4_target2=MakeH1I_TPC("TPC/S4","S4_X_target2",-1,1000,-100.5,100.5,
			"x at S4 at target 2 [mm]",2,3);
  hTPC_Y_S4_target2=MakeH1I_TPC("TPC/S4","S4_Y_target2",-1,1000,-100.5,100.5,
			"y at S4 at target 2 [mm]",2,3);
  hTPC_X_S4_target2d=MakeH1I_TPC("TPC/S4","S4_X_target2d",-1,1000,-100.5,100.5,
			"x at S4 at target 2 [mm]",2,3);
  hTPC_Y_S4_target2d=MakeH1I_TPC("TPC/S4","S4_Y_target2d",-1,1000,-100.5,100.5,
			"y at S4 at target 2 [mm]",2,3);
  hTPC_AX_S4_target2=MakeH1I_TPC("TPC/S4","S4_AX_target2",-1,1000,-100.5,100.5,
			"angl_x at S4 at target 2 [mrad]",2,3);
  hTPC_AY_S4_target2=MakeH1I_TPC("TPC/S4","S4_AY_target2",-1,1000,-100.5,100.5,
			"angl_y at S4 at target 2 [mrad]",2,3);

  hTPC_XY_S4_target2=MakeH2I("TPC/S4","S4_XY_target2",1000,-100.5,100.5,1000,-100.5,100.5,
			"x-S4 at target 2 [mm]","y at S4 at target 2 [mm]",2);
  hTPC_XY_S4_target2d=MakeH2I("TPC/S4","S4_XY_target2d",1000,-100.5,100.5,1000,-100.5,100.5,
			"x-S4 at target 2 [mm]","y at S4 at target 2 [mm]",2);

   hTPC_SC21x  = MakeH1I_TPC("TPC/Detector","TPC_SC21x",-1, 221,-110.5,110.5,"X tracked at SC21 [mm]",2,3);
   hTPC_SC21y  = MakeH1I_TPC("TPC/Detector","TPC_SC21y",-1, 221,-110.5,110.5,"Y tracked at SC21 [mm]",2,3);
   hTPC_SC41x  = MakeH1I_TPC("TPC/Detector","TPC_SC41x",-1, 221,-110.5,110.5,"X tracked at SC41 [mm]",2,3);
   hTPC_SC41y  = MakeH1I_TPC("TPC/Detector","TPC_SC41y",-1, 221,-110.5,110.5,"Y tracked at SC41 [mm]",2,3);

   	for(int i=0;i<6;i++){
   		char name[100];
		   sprintf(name,"TPC/TPC%d",i+1);
		   MakePic(name,"Amplitudes",4,2,hTPC_A[i][0],hTPC_A[i][1],hTPC_A[i][2],hTPC_A[i][3],hTPC_L0[i],hTPC_R0[i],hTPC_L1[i],hTPC_R1[i]);
	}

   hTPCS2_XZ=MakeH2I("s436","Beam_tracking_TPCs_S2_XZ", 300, 1., 1178.5, 221, -110.5, 110.5, "Position Z[mm]","Position X[mm]",2);
   hTPCS2_YZ=MakeH2I("s436","Beam_tracking_TPCs_S2_YZ", 300, 1., 1178.5, 221, -110.5, 110.5, "Position Z[mm]","Position Y[mm]",2);


}


void TFRSCalibrProc::InitProcessor() {
  // MW initialization                                                                                                                                                                                                              

  fbFirstEvent = kTRUE;
  for (int i=0;i<32;i++)
    scaler_save[i] = 0;
  firstsec = 0;
  firsttenthsec = 0;
  firsthundrethsec = 0;        //mik                                                                                                                                                                                                
  firstcycle = 0;
  dtime = 0.;
  dt_last = 0.;
  dt_diff = 0.;

  // MON initialization                                                                                                                                                                                                             
}



//////////////////////////////////////////////////////////////////
/// ************ MWDC Fitting Function **************** //////////
Float_t temp_pos[8], temp_z[8], temp_theta[8]; // [i_plane_used] 
Int_t temp_num_plane_used;                     // used in myFunct. need set in MWDC_Tracking

void myFunct_1mwdc(int& nDim, double* gout, double& result, double par[], int flg){
   double ans;   /*  par[] => 0:x0, 1:y0, 2:a0, 3:b0 */
   ans=0;
   for(int i_plane_used=0; i_plane_used < temp_num_plane_used; i_plane_used++){
     double x_temp, y_temp;
     x_temp = par[0] + temp_z[i_plane_used] * par[2];
     y_temp = par[1] + temp_z[i_plane_used] * par[3];
     ans += pow(x_temp*cos(temp_theta[i_plane_used]) + y_temp*sin(temp_theta[i_plane_used]) -temp_pos[i_plane_used],2);
   }
   result = ans;
}





/////////////////////////////////////////////////////////////////////////
///  *********** ETAP S4 Profile Analysis *************************** //////////
 void TFRSCalibrProc::Process_ETAP_Profile_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
 {
 
 
   return;   
}








/////////////////////////////////////////////////////////////////////////
///  *********** ETAP MINI Analysis *************************** //////////
 void TFRSCalibrProc::Process_ETAP_MINI_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
 {
 
  
   //conversion : src to tgt
   for(int i_mini=0; i_mini<2; i_mini ++){
       tgt.mini_qdc[i_mini] = (Float_t)(src.mini_q[i_mini]);
       tgt.mini_tdc[i_mini] = (Float_t)(src.mini_t[i_mini]);
   }

   // Fill
   for(int i_mini=0; i_mini<2; i_mini++){
       hMINI_QDC[i_mini]->Fill(tgt.mini_qdc[i_mini]);   
       hMINI_TDC[i_mini]->Fill(tgt.mini_tdc[i_mini]);  
       hMINI_TDC_QDC[i_mini]->Fill(tgt.mini_tdc[i_mini],tgt.mini_qdc[i_mini] );  
   }
  
   return;   
}


/////////////////////////////////////////////////////////////////////////
///  *********** ETAP HIRAC Analysis *************************** //////////
 void TFRSCalibrProc::Process_ETAP_HIRAC_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
 {
    
   // conversion : src to tgt
   for(int i_hirac=0; i_hirac<8; i_hirac ++){
       tgt.hirac_qdc_raw[i_hirac]   = (Float_t)(src.hirac_q[i_hirac]);
       tgt.hirac_tdc_raw[i_hirac]   = (Float_t)(src.hirac_t[i_hirac]);
   }
   /*
   // calculation / calibration
   for(int i_hirac=0; i_hirac<8; i_hirac++){
       tgt.hirac_qdc_cor[i_hirac]  =  -1.0*(tgt.hirac_qdc_raw[i_hirac] - tgt.hirac_qdc_base[i_hirac])+500.0; //
       tgt.hirac_pe[i_hirac]       =  tgt.hirac_qdc_cor[i_hirac] ;
       tgt.hirac_tdc_t0cor[i_hirac]=  tgt.hirac_tdc_raw[i_hirac] ;    
       tgt.hirac_tdc_cor[i_hirac]  =  tgt.hirac_tdc_raw[i_hirac] ;
   }

 
   // calculation (pesum, numhit)
   tgt.hirac_numhit=0;
   for(int i_hirac=0; i_hirac<8; i_hirac++){
     tgt.hirac_pesum += tgt.hirac_pe[i_hirac];
     if(1){
       tgt.hirac_numhit += 1 ;
     }
   }


   // calculation (x)
   if(tgt.hirac_pesum>3.0){//calculate mean x only for #pesum > 3.0
     tgt.hirac_x     =0.0;
     for(int i_hirac=0; i_hirac<8; i_hirac++){
       tgt.hirac_x += ( 1.0 * tgt.hirac_pe[i_hirac] / tgt.hirac_pesum );
     }
   }


   // Fill
   for(int i_hirac=0; i_hirac<8; i_hirac++){
     hHIRAC_QDC_RAW[i_hirac]->Fill(tgt.hirac_qdc_raw[i_hirac]); 
     hHIRAC_QDC_BASE[i_hirac]->Fill(tgt.hirac_qdc_base[i_hirac]); 
     hHIRAC_QDC_RAW_BASE[i_hirac]->Fill(tgt.hirac_qdc_raw[i_hirac], tgt.hirac_qdc_base[i_hirac]);
     hHIRAC_QDC_COR[i_hirac]->Fill(tgt.hirac_qdc_cor[i_hirac]); 
     hHIRAC_PE[i_hirac]->Fill(tgt.hirac_pe[i_hirac]); 
     hHIRAC_TDC_RAW[i_hirac]->Fill(tgt.hirac_tdc_raw[i_hirac]); 
     hHIRAC_TDC_T0COR[i_hirac]->Fill(tgt.hirac_tdc_t0cor[i_hirac]); 
     hHIRAC_TDC_QDC[i_hirac]->Fill(tgt.hirac_tdc_t0cor[i_hirac], tgt.hirac_qdc_cor[i_hirac]);
     hHIRAC_TDC_COR[i_hirac]->Fill(tgt.hirac_tdc_cor[i_hirac]); 
   }
   hHIRAC_PESUM->Fill(tgt.hirac_pesum);
   hHIRAC_X->Fill(tgt.hirac_x);
   hHIRAC_NUMHIT->Fill(tgt.hirac_numhit); 
   */
   return;   
}


/////////////////////////////////////////////////////////////////////////
///  *********** ETAP TORCH Analysis *************************** //////////
void TFRSCalibrProc::Process_ETAP_TORCH_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
 {
   TMWDCParameter* mwdc = (TMWDCParameter*) GetParameter("MWDCPar");
   
   //conversion : src to tgt
   for(int i_torch=0; i_torch<6; i_torch ++){
     tgt.torch_qdc[i_torch] = (Float_t)(src.torch_q[i_torch]);
     tgt.torch_tdc[i_torch] = (Float_t)(src.torch_t[i_torch]);
   }
   

   // Fill
   for(int i_torch=0; i_torch<6; i_torch++){
       hTORCH_QDC[i_torch]->Fill(tgt.torch_qdc[i_torch]);   
       hTORCH_TDC[i_torch]->Fill(tgt.torch_tdc[i_torch]);  
       hTORCH_TDC_QDC[i_torch]->Fill(tgt.torch_tdc[i_torch],tgt.torch_qdc[i_torch] );  
   }
  
   return;   
 }

void TFRSCalibrProc::Process_ETAP_MWDC_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
 {
   
   TMWDCParameter* mwdc = (TMWDCParameter*) GetParameter("MWDCPar");
   Int_t numhit[16];
   // printf("%d",mwdc->i_v830_normalization);
   
   //conversion : src to tgt
   for(int i_plane=0;i_plane<16;i_plane++){
     numhit[i_plane]=src.mwdc_numhit[i_plane];
     tgt.mwdc_numhit[i_plane]=numhit[i_plane];
     for(int i_hit=0;i_hit<numhit[i_plane];i_hit++){
       tgt.mwdc_time[i_plane][i_hit]= ((float)(src.mwdc_time[i_plane][i_hit]));
       tgt.mwdc_tot[i_plane][i_hit] = ((float)(src.mwdc_tot[i_plane][i_hit]));
       tgt.mwdc_wireid[i_plane][i_hit] = (src.mwdc_wireid[i_plane][i_hit]);
       tgt.mwdc_wirepos[i_plane][i_hit] = (mwdc->plane_sign[i_plane])*(5.0)*((float)(src.mwdc_wireid[i_plane][i_hit]) - (mwdc->center_id[i_plane]) );
       //
       // drift time to drift length conversion.
       if( (mwdc->dtmin[i_plane])<(tgt.mwdc_time[i_plane][i_hit])  && (tgt.mwdc_time[i_plane][i_hit])<(mwdc->dt0[i_plane])){
	 int dt_ch = (mwdc->dt0[i_plane])-(tgt.mwdc_time[i_plane][i_hit]);  // t0 is larger!!! because of common stop mode!!!
	 tgt.mwdc_length[i_plane][i_hit] = (mwdc->dtdx_table[i_plane][dt_ch]);
       }// condition for dt-dx conversion 
     }
   }
   
   // Fill histograms before Tracking
   for(int i_plane=0;i_plane<16;i_plane++){
     hMWDC_NUMHIT[i_plane]->Fill(numhit[i_plane]);
     for(int i_hit=0;i_hit<numhit[i_plane];i_hit++){
       hMWDC_TIME[i_plane]->Fill(tgt.mwdc_time[i_plane][i_hit]);
       hMWDC_TOT[i_plane]->Fill(tgt.mwdc_tot[i_plane][i_hit]);
       hMWDC_WIREID[i_plane]->Fill(tgt.mwdc_wireid[i_plane][i_hit]);
       hMWDC_WIREPOS[i_plane]->Fill(tgt.mwdc_wirepos[i_plane][i_hit]);
       hMWDC_LENGTH[i_plane]->Fill(tgt.mwdc_length[i_plane][i_hit]);
     }
   }
   Int_t numhit_total;
   numhit_total = (numhit[0]+numhit[1]+numhit[2]+numhit[3]+numhit[4]+numhit[5]+numhit[6]+numhit[7]+numhit[8]+numhit[9]+numhit[10]+numhit[11]+numhit[12]+numhit[13]+numhit[14]+numhit[15]);
   hMWDC_NUMHITSUM->Fill(numhit_total);


   //  condition to try tracking. 
   bool condition_for_tracking ;
   condition_for_tracking = ((mwdc->tracking_level)>0);
   if(condition_for_tracking){
   //   if(condition_for_tracking && (mwdc->TrackingEnabled)){
     MWDCTracking test; 
     for(int i_plane=0; i_plane<16; i_plane++){
       for(int i_hit=0; i_hit<numhit[i_plane]; i_hit++){
	 if(-0.0 < tgt.mwdc_length[i_plane][i_hit] && tgt.mwdc_length[i_plane][i_hit]<2.5){  // cut condition on TOT, Drift time, etc.
	   test.StoreHit(i_plane, tgt.mwdc_wirepos[i_plane][i_hit], tgt.mwdc_length[i_plane][i_hit], tgt.mwdc_tot[i_plane][i_hit], tgt.mwdc_time[i_plane][i_hit], mwdc->plane_angle[i_plane],  mwdc->zpos[i_plane]);
	   //  cout <<"stored track:"<< i_plane <<",";
	   //  cout << tgt.mwdc_wirepos[i_plane][i_hit] <<", ";
	   //  cout << tgt.mwdc_length[i_plane][i_hit] << ", ";
	   //  cout << mwdc->plane_angle[i_plane] << ", "<< mwdc->zpos[i_plane]<<endl;
	 }
       }
     }
     //test.Tracking_FitCylindrical(); 
     test.Tracking_LRfixed(); 
     test.ResidualExCalc();
     test.FindTime_wMaxToT();
     //
     tgt.mwdc_x = test.GetX();
     tgt.mwdc_a = test.GetA();
     tgt.mwdc_y = test.GetY();
     tgt.mwdc_b = test.GetB();
     tgt.mwdc_chi2 = test.GetChi2();     
     for(int i_plane=0; i_plane<16; i_plane++){
       tgt.mwdc_res[i_plane] = test.GetResidual(i_plane);
       tgt.mwdc_res_ex[i_plane] = test.GetExclusiveResidual(i_plane);
       hMWDC_RES[i_plane] ->Fill(tgt.mwdc_res[i_plane]);
       hMWDC_RES_EX[i_plane] ->Fill(tgt.mwdc_res_ex[i_plane]);
       tgt.mwdc_time_wMaxToT[i_plane]= test.GetTime_wMaxToT(i_plane);
       hMWDC_TIME_wMaxToT[i_plane] ->Fill(tgt.mwdc_time_wMaxToT[i_plane]);
     }
     //
     //  cout <<"result track:"<< tgt.mwdc_chi2 <<", " << tgt.mwdc_x << endl;
     //
     hMWDC_CHI2 -> Fill(tgt.mwdc_chi2);
     hMWDC_X -> Fill(tgt.mwdc_x);
     hMWDC_Y -> Fill(tgt.mwdc_y);
     hMWDC_A -> Fill(tgt.mwdc_a);
     hMWDC_B -> Fill(tgt.mwdc_b);
     hMWDC_XY -> Fill(tgt.mwdc_x, tgt.mwdc_y);
     hMWDC_AB -> Fill(tgt.mwdc_a, tgt.mwdc_b);
     hMWDC_XA -> Fill(tgt.mwdc_x, tgt.mwdc_a);
     hMWDC_YB -> Fill(tgt.mwdc_y, tgt.mwdc_b);

     hMWDC_XA_s-> Fill(tgt.mwdc_x, tgt.mwdc_a);
     hMWDC_YB_s-> Fill(tgt.mwdc_y, tgt.mwdc_b);
   }


   if(fill_hist_s436){// JLRS 20-07-2014
   // s436
   // 19-07-2014-JLRS-Yassid
    
     float Dist_Z_MWDCs=1000.;
     float Z_p = Rannb.Rndm()*Dist_Z_MWDCs;
   
     float X_n= tgt.mwdc_x + tgt.mwdc_a*Z_p;
     float Y_n= tgt.mwdc_y + tgt.mwdc_b*Z_p;;

     // Histogram in X and Z
     hMWDC_s436_XZ->Fill(Z_p,X_n);
     // Histogram in Y and Z
     hMWDC_s436_YZ->Fill(Z_p,Y_n);

     // Positions on different planes 20-07-2014 JLRS
     hMWDC_s436_plane[0]->Fill(tgt.mwdc_x,tgt.mwdc_y);//First MWDC
     hMWDC_s436_plane[1]->Fill(tgt.mwdc_x+tgt.mwdc_a*1000.,tgt.mwdc_y+tgt.mwdc_b*1000.);//Second MWDC
     // Distance between ToF41 and MWDC1 1537mm
     hMWDC_s436_plane[2]->Fill(tgt.mwdc_x+tgt.mwdc_a*1537.,tgt.mwdc_y+tgt.mwdc_b*1537.);//ToF41

     // Focal Plane
     tgt.focal_plane = (tgt.mwdc_x - mwdc->focal_z * tgt.mwdc_a*1000 - mwdc->focal_aa * tgt.mwdc_a*1000*tgt.mwdc_a*1000) * (1 - mwdc-> focal_a * tgt.mwdc_a)
       - mwdc->focal_y*tgt.mwdc_y*tgt.mwdc_y;//added 29/Jul/2014 S. Tera
     hMWDC_s436_plane[3]->Fill(tgt.focal_plane,tgt.mwdc_a*1000.);

     hFocal_X_ToF_s4->Fill(tgt.focal_plane
			   ,0.5*((tgt.sci_tdc[7][0]+tgt.sci_tdc[7][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));
     hFocal_X->Fill(tgt.focal_plane);
     hFocal_plane_s4_init->Fill(tgt.mwdc_x,tgt.mwdc_a*1000.);

     //Histograms for angles and energy loss 19-07-2014-JLRS
     hSCI_Angle_DE[0]->Fill(tgt.mwdc_a*1000.,sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]));
     hSCI_Angle_DE[1]->Fill(tgt.mwdc_a*1000.,sqrt(tgt.sci_qdc[6][0]*tgt.sci_qdc[6][1]));
     hSCI_Angle_DE[2]->Fill(tgt.mwdc_a*1000.,sqrt(tgt.sci_qdc[7][0]*tgt.sci_qdc[7][1]));
     hSCI_Angle_DE[3]->Fill(tgt.mwdc_a*1000.,sqrt(tgt.sci_qdc[8][0]*tgt.sci_qdc[8][1]));
     // Position x on the MWDC
     hSCI_Pos_DE[0]->Fill(tgt.mwdc_x,sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]));
     hSCI_Pos_DE[1]->Fill(tgt.mwdc_x,sqrt(tgt.sci_qdc[6][0]*tgt.sci_qdc[6][1]));
     hSCI_Pos_DE[2]->Fill(tgt.mwdc_x,sqrt(tgt.sci_qdc[7][0]*tgt.sci_qdc[7][1]));
     hSCI_Pos_DE[3]->Fill(tgt.mwdc_x,sqrt(tgt.sci_qdc[8][0]*tgt.sci_qdc[8][1]));

     if(tgt.b_pi[2]||tgt.b_pi[3]){
       hFocal_X2->Fill(tgt.focal_plane);
       hFocal_XY->Fill(tgt.focal_plane,tgt.mwdc_y);
       hMWDC_NUMHITSUM0->Fill(numhit_total);
     }

   }


   return;  
 }
//



//  ***********TPC and sci Analysis to s436 ********************* // 19-07-2014-JLRS
void TFRSCalibrProc::Process_TPC_ETAP_SCI_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
{
  //Sci analisys **************************************************************
  // Energy loss -> sqrt(Q1*Q2)

  TMWDCParameter* mwdc = (TMWDCParameter*) GetParameter("MWDCPar");

   for(int i_sci=0; i_sci<11; i_sci++){
     for(int i_lr=0; i_lr<2; i_lr++){
       tgt.sci_qdc[i_sci][i_lr] = (float)(src.etapsci_q[i_sci][i_lr]);
       tgt.sci_tdc[i_sci][i_lr] = (float)(src.etapsci_t[i_sci][i_lr]);
       tgt.sci_t0_tdc[i_sci][i_lr] = (float)(src.etapsci_t0_t[i_sci][i_lr]); // 260714 YT
       tgt.sci_ml[i_sci][i_lr] = (src.etapsci_ml[i_sci][i_lr]); // 260714 YT
       tgt.sci_mt[i_sci][i_lr] = (src.etapsci_mt[i_sci][i_lr]); // 260714 YT
     }  
     if(0.0<=(tgt.sci_qdc[i_sci][0]-mwdc->sci_q0[i_sci][0])*(tgt.sci_qdc[i_sci][1]-mwdc->sci_q0[i_sci][1])){
       tgt.sci_de[i_sci] = sqrt((tgt.sci_qdc[i_sci][0]-mwdc->sci_q0[i_sci][0])*(tgt.sci_qdc[i_sci][1]-mwdc->sci_q0[i_sci][1]));
     }
   }

  // Fill ETAP_SCI
   for(int i_sci=0; i_sci<9; i_sci++){
     for(int i_lr=0; i_lr<2; i_lr++){
       hSCI_QDC[i_sci][i_lr]->Fill(tgt.sci_qdc[i_sci][i_lr]);
       hSCI_TDC_M[i_sci][i_lr]->Fill(tgt.sci_ml[i_sci][i_lr]);  
       hSCI_T0_TDC[i_sci][i_lr]->Fill(tgt.sci_t0_tdc[i_sci][i_lr]);  
       //28/07/2014
       Bool_t KSCI;
       if(i_sci==6 && i_lr==0){
	 KSCI=cTDC_SCI[0][0]->Test(tgt.sci_tdc[i_sci][i_lr]);
       }else KSCI=kTRUE;
       if(KSCI==1 && i_sci==6 && i_lr==0){
	 hSCI_TDC[i_sci][i_lr]->Fill(tgt.sci_tdc[i_sci][i_lr]);
       }else {
	 hSCI_TDC[i_sci][i_lr]->Fill(tgt.sci_tdc[i_sci][i_lr]);
       }

       hSCI_TDC_QDC[i_sci][i_lr]->Fill(tgt.sci_tdc[i_sci][i_lr],tgt.sci_qdc[i_sci][i_lr] );
     }

     //19-07-2014
     //20-07-2014 JLRS: if
     if(fill_hist_s436){
     hSCI_DE[i_sci]->Fill(sqrt(tgt.sci_qdc[i_sci][0]*tgt.sci_qdc[i_sci][1]));
     }
   }

   //------------------
   // 260714 YT
   if( (-990.<tgt.sci_t0_tdc[0][0]) && (-990.<tgt.sci_t0_tdc[4][0])){ // with hit
     tgt.tof_21l_41l =   tgt.sci_t0_tdc[0][0] -  tgt.sci_t0_tdc[4][0]  ;
   }
   if( (-990.<tgt.sci_t0_tdc[0][1]) && (-990.<tgt.sci_t0_tdc[4][1])){
     tgt.tof_21r_41r =   tgt.sci_t0_tdc[0][1] -  tgt.sci_t0_tdc[4][1]  ;
   }
   if( (-990.<tgt.sci_t0_tdc[0][0]) && (-990.<tgt.sci_t0_tdc[4][0]) && (-990.<tgt.sci_t0_tdc[0][1]) && (-990.<tgt.sci_t0_tdc[4][1]) ){
     tgt.tof_21_41=   (tgt.tof_21l_41l + tgt.tof_21r_41r)/2.0;
   }
   if( (-990.<tgt.sci_t0_tdc[4][0]) && (-990.<tgt.sci_t0_tdc[5][0]) && (-990.<tgt.sci_t0_tdc[4][1]) && (-990.<tgt.sci_t0_tdc[5][1]) ){
   
     tgt.tof_41_42=   (tgt.sci_t0_tdc[4][0] - tgt.sci_t0_tdc[5][0] + tgt.sci_t0_tdc[4][1] - tgt.sci_t0_tdc[5][1] ) /2.0;
   }

   hTOFSC21LSC41L -> Fill(  tgt.tof_21l_41l);
   hTOFSC21RSC41R -> Fill(  tgt.tof_21r_41r);
   hTOFSC21SC41 -> Fill(  tgt.tof_21_41);
   hTOFSC41SC42 -> Fill(  tgt.tof_41_42);
   hTOFSC21SC41SC42 -> Fill(  tgt.tof_21_41, tgt.tof_41_42);
   hTOFDE41SC41SC42 -> Fill(  tgt.tof_21_41, sqrt((tgt.sci_qdc[4][0]-mwdc->sci_q0[4][0])*(tgt.sci_qdc[4][1]-mwdc->sci_q0[4][1])));
   hTOFDE21SC41SC42 -> Fill(  tgt.tof_21_41, sqrt((tgt.sci_qdc[0][0]-mwdc->sci_q0[0][0])*(tgt.sci_qdc[0][1]-mwdc->sci_q0[0][1])));
   //-------------
  
   //19-07-2014
   //Histograms
   if(fill_hist_s436){
   hSCI_DE1_DE2[0]->Fill(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]), sqrt(tgt.sci_qdc[6][0]*tgt.sci_qdc[6][1]));
   hSCI_DE1_DE2[1]->Fill(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]), sqrt(tgt.sci_qdc[7][0]*tgt.sci_qdc[7][1]));
   hSCI_DE1_DE2[2]->Fill(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]), sqrt(tgt.sci_qdc[8][0]*tgt.sci_qdc[8][1]));
   // ToF calculated as 0.5(ToF_L+ToF_R)
   // 4->SC41
   // 6->ToF41
   // 7->ToF42  
   // 8->ToF43
   if(tgt.sci_tdc[7][0]>0. && tgt.sci_tdc[7][1]>0. && tgt.sci_tdc[6][0]>0. && tgt.sci_tdc[6][1]>0.)
   hSCI_DE_ToF[0]->Fill(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]),0.5*((tgt.sci_tdc[7][0]+tgt.sci_tdc[7][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));
   if(tgt.sci_tdc[8][0]>0. && tgt.sci_tdc[8][1]>0. && tgt.sci_tdc[6][0]>0. && tgt.sci_tdc[6][1]>0.)
   hSCI_DE_ToF[1]->Fill(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]),0.5*((tgt.sci_tdc[8][0]+tgt.sci_tdc[8][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));
  if(tgt.sci_tdc[7][0]>0. && tgt.sci_tdc[7][1]>0. && tgt.sci_tdc[6][0]>0. && tgt.sci_tdc[6][1]>0.)
   hSCI_DE_ToF[2]->Fill(sqrt(tgt.sci_qdc[6][0]*tgt.sci_qdc[6][1]),0.5*((tgt.sci_tdc[7][0]+tgt.sci_tdc[7][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));
   if(tgt.sci_tdc[8][0]>0. && tgt.sci_tdc[8][1]>0. && tgt.sci_tdc[6][0]>0. && tgt.sci_tdc[6][1]>0.)
   hSCI_DE_ToF[3]->Fill(sqrt(tgt.sci_qdc[6][0]*tgt.sci_qdc[6][1]),0.5*((tgt.sci_tdc[8][0]+tgt.sci_tdc[8][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));

   } 

   tgt.b_pi[0] = cPI_DE_TOF[0]->Test(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1])
                                     ,0.5*((tgt.sci_tdc[7][0]+tgt.sci_tdc[7][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));
   tgt.b_pi[1] = cPI_DE_TOF[1]->Test(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1])
                                     ,0.5*((tgt.sci_tdc[8][0]+tgt.sci_tdc[8][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));
   tgt.b_pi[2] = cPI_DE_TOF[2]->Test(sqrt(tgt.sci_qdc[6][0]*tgt.sci_qdc[6][1])
                                     ,0.5*((tgt.sci_tdc[7][0]+tgt.sci_tdc[7][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));
   tgt.b_pi[3] = cPI_DE_TOF[3]->Test(sqrt(tgt.sci_qdc[6][0]*tgt.sci_qdc[6][1])
                                     ,0.5*((tgt.sci_tdc[8][0]+tgt.sci_tdc[8][1])-(tgt.sci_tdc[6][0]+tgt.sci_tdc[6][1])));

   if( tgt.sci_tdc[4][0]>0. && tgt.sci_tdc[4][1]>0. && tgt.sci_tdc[0][0]>0. && tgt.sci_tdc[0][1]>0.)
     hToF_s2_s4->Fill(sqrt(tgt.sci_qdc[4][0]*tgt.sci_qdc[4][1]),0.5*(tgt.sci_tdc[4][0]+tgt.sci_tdc[4][1])-tgt.sci_tdc[9][0]-(0.5*(tgt.sci_tdc[0][0]+tgt.sci_tdc[0][1])-tgt.sci_tdc[10][0]));// to check


      hToF_ToF41_ToF42->Fill( (tgt.sci_tdc[4][0]+tgt.sci_tdc[4][1])/2.0 -  (tgt.sci_tdc[7][0]+tgt.sci_tdc[7][1])/2.0  ); 


  // TPC analisis ******************************************************************************
  //
  TFRSParameter* frs = (TFRSParameter*) GetParameter("FRSPar");
  TTPCParameter* tpc = (TTPCParameter*) GetParameter("TPCPar");

  bDrawHist=1;// JLRS to be sure

  for(int i=0;i<6;i++){  
		if (bDrawHist) {
	    hTPC_L0[i]->Fill(src.tpc_l[i][0]);
	    hTPC_R0[i]->Fill(src.tpc_r[i][0]);
	    hTPC_L1[i]->Fill(src.tpc_l[i][1]);
	    hTPC_R1[i]->Fill(src.tpc_r[i][1]);
	    hTPC_LT0[i]->Fill(src.tpc_lt[i][0]);
	    hTPC_RT0[i]->Fill(src.tpc_rt[i][0]);
	    hTPC_LT1[i]->Fill(src.tpc_lt[i][1]);
	    hTPC_RT1[i]->Fill(src.tpc_rt[i][1]);
	    hTPC_LTRT[i]->Fill(src.tpc_lt[i][0],src.tpc_rt[i][1]);
		}

    int count =0;
    Int_t r_y = 0;

    int countx =0;
    Int_t r_x0 = 0;
    Int_t r_x1 = 0;

    tgt.tpc_y[i] = 0;
    tgt.tpc_x[i] = 9999;

    for(int j=0;j<4;j++){
		if (bDrawHist) {
		  hTPC_DT[i][j]->Fill(src.tpc_dt[i][j]);
		  hTPC_A[i][j]->Fill(src.tpc_a[i][j]);
		}

      //// calculate control sums
      if(j<2) tgt.tpc_csum[i][j] = (src.tpc_lt[i][0] + src.tpc_rt[i][0]
				    - 2*src.tpc_dt[i][j]);
      else tgt.tpc_csum[i][j] = (src.tpc_lt[i][1] + src.tpc_rt[i][1]
				 - 2*src.tpc_dt[i][j]);


      //      if((src.de_42l>230&&src.de_42l<450)||(src.de_42r>540&&src.de_42r<750)){
			if (bDrawHist) 
		      hTPC_CSUM[i][j]->Fill(tgt.tpc_csum[i][j]);
      tgt.b_tpc_csum[i][j] = cTPC_CSUM[i][j]->Test(tgt.tpc_csum[i][j]);
      //      }
     
      if(src.tpc_lt[i][0]==0 && src.tpc_rt[i][0]==0 && j<2)
      			{tgt.b_tpc_csum[i][j]=0;}
      
      if(src.tpc_lt[i][1]==0 && src.tpc_rt[i][1]==0 && j>1)
      			{tgt.b_tpc_csum[i][j]=0;} 
      
      if (tgt.b_tpc_csum[i][j])
		{
			r_y += src.tpc_dt[i][j];
			tgt.tpc_y[i] += tpc->y_factor[i][j]*src.tpc_dt[i][j] + tpc->y_offset[i][j];
			count++;
      }
    }

    if (tgt.b_tpc_csum[i][0] || tgt.b_tpc_csum[i][1]){
       r_x0 =  src.tpc_lt[i][0]-src.tpc_rt[i][0];
       //          r_x0 =  src.tpc_lt[i][0];

      tgt.tpc_x[i]=tpc->x_factor[i][0]*r_x0 + tpc->x_offset[i][0];
      countx++;
    }
    if (tgt.b_tpc_csum[i][2] || tgt.b_tpc_csum[i][3]){
      r_x1 =  src.tpc_lt[i][1]-src.tpc_rt[i][1];
      if (countx == 0)
			tgt.tpc_x[i]=tpc->x_factor[i][1]*r_x1 + tpc->x_offset[i][1];
		else
			tgt.tpc_x[i]+=tpc->x_factor[i][1]*r_x1 + tpc->x_offset[i][1];
      countx++;
    }

    tgt.b_tpc_xy[i] = kFALSE;  // HWE

    if (countx > 0) {
      tgt.tpc_y[i] = tgt.tpc_y[i]/count;
      tgt.tpc_x[i] = tgt.tpc_x[i]/countx;
      //Int_t r_x=src.tpc_lt[i]-src.tpc_rt[i];
      //tgt.tpc_x[i]=tpc->x_factor[i]*r_x + tpc->x_offset[i];

      //      if(r_x0<-40)

		if (bDrawHist) {
   	   hTPC_XRAW0[i]->Fill(r_x0);
	      hTPC_XRAW1[i]->Fill(r_x1);
	      hTPC_YRAW[i]->Fill(r_y/count); 
//	      if(tgt.coin[15]==1){
   	   hTPC_X[i]->Fill(tgt.tpc_x[i]);
	      hTPC_Y[i]->Fill(tgt.tpc_y[i]);
   	   hcTPC_XY[i]->Fill(tgt.tpc_x[i],tgt.tpc_y[i]);
//    	 }
	    }
	   tgt.b_tpc_xy[i] = kTRUE;
    }

    if(countx>1){
      float x0=tpc->x_factor[i][0]*r_x0 + tpc->x_offset[i][0];
      float x1=tpc->x_factor[i][1]*r_x1 + tpc->x_offset[i][1];
		if (bDrawHist)
	      hTPC_DELTAX[i]->Fill(x0-x1);
    }    
  }

 // *****Relative distances for tracking (S388)
 //  Float_t dist_TPC1_TPC2 = 1.;         
  //distances at S2 for exp s388 measured 'by eye' (i.e. not very precise)! AE, 8.8.2012
  Float_t dist_TPC4_target1 = 455.;  // 8.8.12, s388: taget1 is first Si detector at S2 
                                     // using: TPC4->chamber= 150 mm, chamber->Si(1)= 305 mm
  Float_t dist_TPC3_TPC4 = 1782.5-604.; // exp s388
  Float_t dist_TPC3_focS2 = 2280-604.;//3010-2203.5 ; //exp s388
  //2125. 24-07-2014
  Float_t dist_TPC5_TPC6 = 1435.5;//25-07-2014  s437 
  Float_t dist_TPC6_focS4  = -1213.5; //25.07.14  222 mm after TPC5
  Float_t dist_TPC6_target2  = 1015.; // 8.08.12, exp s388 target2= OTPC entrance (check distance)


  //Position S2 tracked with TPCs 3 and 4 for focus
  //  if (tgt.b_tpc_xy[2]&&tgt.b_tpc_xy[3]) {
  //  tgt.tpc_angle_x_s2_foc = (tgt.tpc_x[3] - tgt.tpc_x[2])/dist_TPC3_TPC4*1000.;
  //  tgt.tpc_angle_y_s2_foc = (tgt.tpc_y[3] - tgt.tpc_y[2])/dist_TPC3_TPC4*1000.;
  //  tgt.tpc_x_s2_foc = -tgt.tpc_angle_x_s2_foc * dist_TPC3_focS2/1000. + tgt.tpc_x[2];
  //  tgt.tpc_y_s2_foc = -tgt.tpc_angle_y_s2_foc * dist_TPC3_focS2/1000. + tgt.tpc_y[2];

  //21-07-2104  for e436-e437 experiments Tracking S2 with TPC1 and TPC2

    Float_t dist_TPC1_TPC2 = 1782.5-604.;
    // Float_t dist_TPC1_focS2 = 2280-604.;
    Float_t dist_TPC2_focS2 = 2280.-1782.5;  // added  25Jul2014 (YT)


  //18-07-2014
  if (tgt.b_tpc_xy[0]&&tgt.b_tpc_xy[1]) {
    tgt.tpc_angle_x_s2_foc = (tgt.tpc_x[1] - tgt.tpc_x[0])/dist_TPC1_TPC2*1000.;
    tgt.tpc_angle_y_s2_foc = (tgt.tpc_y[1] - tgt.tpc_y[0])/dist_TPC1_TPC2*1000.;
    // tgt.tpc_x_s2_foc = tgt.tpc_angle_x_s2_foc * dist_TPC1_focS2/1000. + tgt.tpc_x[0];
    //tgt.tpc_y_s2_foc = tgt.tpc_angle_y_s2_foc * dist_TPC1_focS2/1000. + tgt.tpc_y[0];

    // added at 2:55 25/Jul/2014  (YT)
    tgt.tpc_x_s2_foc = tgt.tpc_angle_x_s2_foc * dist_TPC2_focS2/1000. + tgt.tpc_x[1];
    tgt.tpc_y_s2_foc = tgt.tpc_angle_y_s2_foc * dist_TPC2_focS2/1000. + tgt.tpc_y[1];

    //    if (bDrawHist) {
      hTPC_X_S2_foc->Fill(tgt.tpc_x_s2_foc);
      hTPC_Y_S2_foc->Fill(tgt.tpc_y_s2_foc);
      hTPC_AX_S2_foc->Fill(tgt.tpc_angle_x_s2_foc);
      hTPC_AY_S2_foc->Fill(tgt.tpc_angle_y_s2_foc);
      // }

   // JLRS 21-07-2014
   // s436 and s437
   // 19-07-2014-JLRS-Yassid
    
     float Dist_Z_TPCs=1782.5-604.;
     float Z_p = Rannb.Rndm()*Dist_Z_TPCs;
   
     float X_n= tgt.tpc_x[0] +  (tgt.tpc_x[1] - tgt.tpc_x[0])/dist_TPC1_TPC2*Z_p;
     float Y_n= tgt.tpc_y[0] +  (tgt.tpc_y[1] - tgt.tpc_y[0])/dist_TPC1_TPC2*Z_p;;

     // Histogram in X and Z
     hTPCS2_XZ->Fill(Z_p,X_n);
     // Histogram in Y and Z
     hTPCS2_YZ->Fill(Z_p,Y_n);


     // 22/07/2014
     hTPC1_TPC2_X->Fill(tgt.tpc_x[0],tgt.tpc_x[1]);
     hTPC1_TPC2_Y->Fill(tgt.tpc_y[0],tgt.tpc_y[1]);
   

  }
  else  tgt.tpc_x_s2_foc= -999 ;

  //S4 positions tracked with TPCs 5 and 6
  if (tgt.b_tpc_xy[4]&&tgt.b_tpc_xy[5]) {
    
    //S4 focus tracked with TPCs 5 and 6 
    tgt.tpc_angle_x_s4 = (tgt.tpc_x[5] - tgt.tpc_x[4])/dist_TPC5_TPC6*1000.;
    tgt.tpc_angle_y_s4 = (tgt.tpc_y[5] - tgt.tpc_y[4])/dist_TPC5_TPC6*1000.;
    tgt.tpc_x_s4 = tgt.tpc_angle_x_s4 * dist_TPC6_focS4/1000. + tgt.tpc_x[5];
    tgt.tpc_y_s4 = tgt.tpc_angle_y_s4 * dist_TPC6_focS4/1000. + tgt.tpc_y[5];
    
		if (bDrawHist) {
	    hTPC_X_S4->Fill(tgt.tpc_x_s4);
	    hTPC_Y_S4->Fill(tgt.tpc_y_s4);
	    hTPC_AX_S4->Fill(tgt.tpc_angle_x_s4);
	    hTPC_AY_S4->Fill(tgt.tpc_angle_y_s4);
	    hTPC_XAX_S4->Fill(tgt.tpc_x_s4,tgt.tpc_angle_x_s4);
	    hTPC_XS4_AX_S2->Fill(tgt.tpc_x_s4,tgt.tpc_angle_x_s2_foc);
		}

    //S4 entrance of OTPC tracked with TPCs 5 and 6 for s388
    
      tgt.tpc_x_s4_target2 = tgt.tpc_angle_x_s4 * dist_TPC6_target2/1000. + tgt.tpc_x[5];
      tgt.tpc_y_s4_target2 = tgt.tpc_angle_y_s4 * dist_TPC6_target2/1000. + tgt.tpc_y[5];

     
      if (bDrawHist) {
	hTPC_X_S4_target2->Fill(tgt.tpc_x_s4_target2);
	hTPC_Y_S4_target2->Fill(tgt.tpc_y_s4_target2);
	hTPC_XY_S4_target2->Fill(tgt.tpc_x_s4_target2,tgt.tpc_y_s4_target2);
      }
  }
   return ;
}

//--------------------------------------------------------------------------------
//

void TFRSCalibrProc::Process_ETAP_Scaler_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
{
  TMWDCParameter* mwdc = (TMWDCParameter*) GetParameter("MWDCPar");
  // printf("%d",(mwdc->maxcount_v830));
   int Nmax;
   Nmax = (mwdc->maxcount_v830);
   // 20-07-2014 JLRS
   //printf("scaler(15)=%d\n", src.etap_scaler[15]);
   for(int i=0; i<32; i++){
     // present scaler value
     tgt.etap_scaler[i] = src.etap_scaler[i];
     tgt.mh_scaler[i]=src.mh_scaler[i]; // 26072014YT
     //    printf("i=%d, etap=%d, mh=%d\n", i,  tgt.etap_scaler[i],  tgt.mh_scaler[i]);
     // check whether this is first event or not.
     
     if(-999!=etap_scaler_previous[i]){ // not first event
       tgt.etap_scaler_increase[i] = src.etap_scaler[i] - etap_scaler_previous[i];
     }else{ // for first event   
       tgt.etap_scaler_increase[i]=0;
     }
     if(-999!=mh_scaler_previous[i]){ // not first event // 26072014YT
       tgt.mh_scaler_increase[i] = src.mh_scaler[i] - mh_scaler_previous[i]; // 26072014YT
     }else{ // for first event    // 26072014YT
       tgt.mh_scaler_increase[i]=0; // 26072014YT
     } // 26072014YT
     
     // if scaler value crossed maxcount, need to add maxcount
     if(tgt.etap_scaler_increase[i]<0){ 
       tgt.etap_scaler_increase[i] += Nmax;//(mwdc->maxcount_v830);
     }

     // if scaler value crossed maxcount, need to add maxcount
     if(tgt.mh_scaler_increase[i]<0){ // 26072014YT
       tgt.mh_scaler_increase[i] += Nmax;//(mwdc->maxcount_v830); // 26072014YT
     }

     // printf("i=%d, N=%d, DeltaN=%d \n",i,  tgt.etap_scaler[i], tgt.etap_scaler_increase[i]);
     // set present value as new previous value
     etap_scaler_previous[i]=tgt.etap_scaler[i];
     mh_scaler_previous[i]=tgt.mh_scaler[i]; // 26072014YT
   } 

    
   //----Fill Total
    for(int i_scaler=0; i_scaler<(mwdc->num_ch_v830); i_scaler++){
        int imod_scaler, ich_scaler;
	//S4
        imod_scaler = (mwdc->imod_v830[i_scaler] );
        ich_scaler  = (mwdc->ich_v830[i_scaler] );
	hSCALER_TOTAL[imod_scaler][ich_scaler] -> Fill(tgt.etap_scaler[i_scaler]);
	//MH
	imod_scaler = (mwdc->imod_v830_mh[i_scaler] );// 26072014YT
	ich_scaler  = (mwdc->ich_v830_mh[i_scaler] );// 26072014YT
	hSCALER_TOTAL_MH[imod_scaler][ich_scaler] -> Fill(tgt.mh_scaler[i_scaler]); // 26072014YT
    }

    
    // rate calculation                                                                                                                                
    int i_scaler_std;
    i_scaler_std = (mwdc->i_v830_normalization);
    time_count_scaler += (tgt.etap_scaler_increase[i_scaler_std]);
    for(int i_scaler=0; i_scaler<(mwdc->num_ch_v830); i_scaler++){
      scaler_memo[i_scaler] +=  (tgt.etap_scaler_increase[i_scaler]);
      scaler_memo_mh[i_scaler] +=  (tgt.mh_scaler_increase[i_scaler]); // 26072014YT
    }
    int time_count_sec;
    time_count_sec = (time_count_scaler/100000); // 100kHz 

    // spill count
    int i_scaler_spill_on  = 28;//fixed
    int i_scaler_spill_off = 29;//fixed
    spill_on_count   += (tgt.etap_scaler_increase[i_scaler_spill_on]);
    spill_off_count   += (tgt.etap_scaler_increase[i_scaler_spill_off]);

    for(int i_scaler=0; i_scaler<(mwdc->num_ch_v830); i_scaler++){
      scaler_memo_spill[i_scaler] +=  (tgt.etap_scaler_increase[i_scaler]);
      scaler_memo_spill_mh[i_scaler] +=  (tgt.mh_scaler_increase[i_scaler]); // 26072014YT
    }
                                                                        
    //---Time vs Rate----
    if(time_count_sec != time_count_sec_last){
      int scaler_memo_std;
      scaler_memo_std = scaler_memo[i_scaler_std];
      for(int i_scaler=0; i_scaler<(mwdc->num_ch_v830); i_scaler++){
        int imod_scaler, ich_scaler;
        imod_scaler = (mwdc->imod_v830[i_scaler] );
        ich_scaler  = (mwdc->ich_v830[i_scaler] );
        int x_bin, y_set;
        x_bin = (time_count_sec % 3000); // 3000 bin in total                                                                                                            
        y_set = (int)(100000.0*((Float_t)( scaler_memo[i_scaler]  ))/((Float_t)( scaler_memo_std ))); //100kHz total                                           
        if(y_set>=0.00){
	  // printf("imod=%d, ich=%d,xbin=%d,yset=%d \n",imod_scaler,ich_scaler,x_bin,y_set);
	  hSCALER_TIME[imod_scaler][ich_scaler] -> SetBinContent(x_bin,y_set);
	  hSCALER_TIME[imod_scaler][ich_scaler] -> SetBinContent((x_bin+100)%3000,0);
        }
        scaler_memo[i_scaler] =0;
	

	//---MH scaler----
	imod_scaler = (mwdc->imod_v830_mh[i_scaler] );
        ich_scaler  = (mwdc->ich_v830_mh[i_scaler] );
        x_bin = (time_count_sec % 3000); // 3000 bin in total                                             
        y_set = (int)(100000.0*((Float_t)( scaler_memo_mh[i_scaler]  ))/((Float_t)( scaler_memo_std ))); //100kHz total      
	if(y_set>=0.00){
	  hSCALER_TIME_MH[imod_scaler][ich_scaler] -> SetBinContent(x_bin,y_set);
	  hSCALER_TIME_MH[imod_scaler][ich_scaler] -> SetBinContent((x_bin+100)%3000,0);
        }
        scaler_memo_mh[i_scaler] =0;
      }
      time_count_sec_last = time_count_sec ;
    }


    //---Spill vs Rate----
    if(spill_off_count != spill_off_count_last){
      
      for(int i_scaler=0; i_scaler<(mwdc->num_ch_v830); i_scaler++){
        int imod_scaler, ich_scaler;
        imod_scaler = (mwdc->imod_v830[i_scaler] );
        ich_scaler  = (mwdc->ich_v830[i_scaler] );
        int x_bin, y_set;
        x_bin = (spill_off_count % 200); // 200 bin in total                                                                                                            
        y_set =  scaler_memo_spill[i_scaler];
        if(y_set>=0){
	  hSCALER_SPILL[imod_scaler][ich_scaler] -> SetBinContent(x_bin,y_set);
	  hSCALER_SPILL[imod_scaler][ich_scaler] -> SetBinContent((x_bin+10)%200,0);
	  hSCALER_SPILL[imod_scaler][ich_scaler] -> SetBinContent((x_bin+9)%200,0);
	  hSCALER_SPILL[imod_scaler][ich_scaler] -> SetBinContent((x_bin+8)%200,0);
	  hSCALER_SPILL[imod_scaler][ich_scaler] -> SetBinContent((x_bin+7)%200,0);
	  hSCALER_SPILL[imod_scaler][ich_scaler] -> SetBinContent((x_bin+6)%200,0);
        }
        scaler_memo_spill[i_scaler] =0;
	

	//---MH scaler----
	imod_scaler = (mwdc->imod_v830_mh[i_scaler] );
        ich_scaler  = (mwdc->ich_v830_mh[i_scaler] );
        x_bin = (spill_off_count % 200); // 200 bin in total                                             
        y_set =  scaler_memo_spill_mh[i_scaler];
	if(y_set>=0){
	  hSCALER_SPILL_MH[imod_scaler][ich_scaler] -> SetBinContent(x_bin,y_set);
	  hSCALER_SPILL_MH[imod_scaler][ich_scaler] -> SetBinContent((x_bin+10)%200,0);
	  hSCALER_SPILL_MH[imod_scaler][ich_scaler] -> SetBinContent((x_bin+9)%200,0);
	  hSCALER_SPILL_MH[imod_scaler][ich_scaler] -> SetBinContent((x_bin+8)%200,0);
	  hSCALER_SPILL_MH[imod_scaler][ich_scaler] -> SetBinContent((x_bin+7)%200,0); 
	  hSCALER_SPILL_MH[imod_scaler][ich_scaler] -> SetBinContent((x_bin+6)%200,0);
        }
        scaler_memo_spill_mh[i_scaler] =0;
      }
      spill_off_count_last = spill_off_count;
    }
    
    //22-07-2014    
    //Int_t Start_ext=0;
    
     if(mwdc->first_event==1){ 
       Start_ext_0 = tgt.etap_scaler[28];
       mwdc->first_event=2; 
       //cout<<"first"<<endl;
     }
     Start_ext =  tgt.etap_scaler[28]; // Start spill extraction

     if(Start_ext-Start_ext_0>=1){
       Start_ext_0=Start_ext;

       Clock_aux = tgt.etap_scaler[15]  ; // Scaler clock value when extracting spill
      
     }

     Int_t  T_norm=  (tgt.etap_scaler[15] - Clock_aux)/100; //Normalized to ms
       
     // cout<<T_norm<<"     "<<tgt.etap_scaler[15]<<"     "<< tgt.etap_scaler[28]<<endl;

     if(tgt.b_pi[2]||tgt.b_pi[3]){
       hTextraction_XS4->Fill(tgt.mwdc_x-(T_norm)*0.03,T_norm);
       hTextraction_AS4->Fill(tgt.mwdc_a*1000,T_norm);
     }

   return ;
 }

void TFRSCalibrProc::Process_MW_Analysis(TFRSSortEvent& src, TFRSCalibrEvent& tgt) {
   TFRSParameter* frs = (TFRSParameter*) GetParameter("FRSPar");
   TMWParameter* mw = (TMWParameter*) GetParameter("MWPar");
   
/*   Naming conventions:  index     detector   focus #                     */
/*                         1         MW11        1                         */
/*                         2         MW21        2                         */
/*                         3         MW22                                  */
/*                         4         MW31        3                         */
////////////////////////////////////////////////////////////////////////////
  int max_index = 4; /*  up to S3 */

  for(int i=0;i<max_index;i++) {	
    /***************/
    /* Raw Spectra */
    /***************/
    hMW_AN[i]->Fill(src.mw_an[i]);
    hMW_XL[i]->Fill(src.mw_xl[i]);
    hMW_XR[i]->Fill(src.mw_xr[i]);
    hMW_YU[i]->Fill(src.mw_yu[i]);
    hMW_YD[i]->Fill(src.mw_yd[i]);

    /********************************************/
    /* Calculate the sum spectra and conditions */
    /********************************************/

    /* better test first existence of xl, xr, an before filling of xsum */
    if(src.mw_an[i]&&src.mw_xl[i]&&src.mw_xr[i]) {
      // if(src.mw_xl[i]&&src.mw_xr[i]) {
      tgt.mw_xsum[i] = 1000+(src.mw_xl[i] - src.mw_an[i]) + (src.mw_xr[i] - src.mw_an[i]);
      
      // tgt.mw_xsum[i] = (src.mw_xl[i]) + (src.mw_xr[i]); //when an doesn't work
      hMW_XSUM[i]->Fill(tgt.mw_xsum[i]);
    }

    tgt.b_mw_xsum[i] = cMW_XSUM[i]->Test(tgt.mw_xsum[i]);

    /* better test first existence of yu, yd, an before filling of ysum */
    if(src.mw_an[i]&&src.mw_yu[i]&&src.mw_yd[i]) {
      // if(src.mw_yu[i]&&src.mw_yd[i]) {
      tgt.mw_ysum[i] = 1000+(src.mw_yu[i] - src.mw_an[i]) + (src.mw_yd[i] - src.mw_an[i]);
      //	tgt.mw_ysum[i] = (src.mw_yu[i]) + (src.mw_yd[i]); //when an doesn't work			
      hMW_YSUM[i]->Fill(tgt.mw_ysum[i]);
    }
    tgt.b_mw_ysum[i] = cMW_YSUM[i]->Test(tgt.mw_ysum[i]);
    
    /*******************************************************************/
    /* If the signals in x and y are valid, calculate position spectra */
    /*******************************************************************/
    if (tgt.b_mw_xsum[i]) {
      //      Int_t r_x = src.mw_xl[i] - src.mw_xr[i];
      Float_t r_x = src.mw_xl[i] *  mw->gain_tdc[1][i] - src.mw_xr[i] *  mw->gain_tdc[2][i]; //14.09.05 CN+AM
      tgt.mw_x[i] = mw->x_factor[i] * r_x + mw->x_offset[i];
      hMW_X[i]->Fill(tgt.mw_x[i]);
    }
    
    if (tgt.b_mw_ysum[i]) {
      //      Int_t r_y = src.mw_yd[i] - src.mw_yu[i];
      Float_t r_y = src.mw_yd[i] *  mw->gain_tdc[4][i] - src.mw_yu[i] *  mw->gain_tdc[3][i]; //14.09.05 CN+AM
      tgt.mw_y[i] = mw->y_factor[i] * r_y + mw->y_offset[i];
      hMW_Y[i]->Fill(tgt.mw_y[i]);
    }

    
    if(tgt.b_mw_xsum[i] && tgt.b_mw_ysum[i]) {
      hMW_XY[i]->Fill(tgt.mw_x[i], tgt.mw_y[i]);  
    }

  }; // for(int i=0;i<max_index;i++)


  /*********************************************/
  /* S2 Angle and transformed position spectra */
  /*********************************************/

  Float_t  dist_MW21_MW22  = frs->dist_MW22  - frs->dist_MW21;
  Float_t  dist_MW22_focS2 = frs->dist_focS2 - frs->dist_MW22;
  Float_t  dist_MW22_SC21  = frs->dist_SC21  - frs->dist_MW22;
  Float_t  dist_MW22_SC22  = frs->dist_SC22  - frs->dist_MW22;
  

  if (tgt.b_mw_xsum[1] && tgt.b_mw_xsum[2]) {  /* MW21 and MW22 X okay */
    /*  X angle at S2  [mrad]:  */
    tgt.angle_x_s2 = (tgt.mw_x[2]-tgt.mw_x[1])/dist_MW21_MW22*1000.;
    hMW_xAngS2->Fill(tgt.angle_x_s2);

    /*  X at nominal S2 focus:  */
    tgt.focx_s2 = tgt.mw_x[2] + dist_MW22_focS2 * tgt.angle_x_s2/1000.;
    hMW_xFocS2->Fill(tgt.focx_s2);

    /*  X at SC21 position:    */
    tgt.sc21_x = tgt.mw_x[2] + dist_MW22_SC21 * tgt.angle_x_s2/1000.;
    hMW_SC21x->Fill(tgt.sc21_x);

    /*  X at SC22 position:    */
    tgt.sc22_x = tgt.mw_x[2] + dist_MW22_SC22 * tgt.angle_x_s2/1000.;
    hMW_SC22x->Fill(tgt.sc22_x);


    /* 'real' z-position of S2 X focus (cm) */
    Float_t rh = (tgt.angle_x_s2 - angle_x_s2m);
    if(fabs(rh)>1e-4) {
      tgt.z_x_s2 = ((focx_s2m - tgt.focx_s2)/rh)*100. + frs->dist_focS2/10.;  
      hMW_zxS2->Fill(tgt.z_x_s2);
    }
    
    /* keep values for next event */
    focx_s2m = tgt.focx_s2; 
    angle_x_s2m = tgt.angle_x_s2;
  }
  
  if (tgt.b_mw_ysum[1] && tgt.b_mw_ysum[2]) { /* MW21 and MW22 Y okay */
    /*  Y angle at S2 [mrad]:   */
    tgt.angle_y_s2 = (tgt.mw_y[2] - tgt.mw_y[1])/dist_MW21_MW22*1000.;
    hMW_yAngS2->Fill(tgt.angle_y_s2);

    /*  Y at nominal S2 focus:  */
    tgt.focy_s2 = tgt.mw_y[2] + dist_MW22_focS2 * tgt.angle_y_s2/1000.;
    hMW_yFocS2->Fill(tgt.focy_s2);

    /* 'real' z-position of S2 Y focus (cm) */
    Float_t rh = (tgt.angle_y_s2 - angle_y_s2m);
    if(fabs(rh)>1.e-4) {
      tgt.z_y_s2 = ((focy_s2m - tgt.focy_s2)/rh)*100. + frs->dist_focS2/10.;  
      hMW_zyS2->Fill(tgt.z_y_s2);
    }
    
    /* keep values for next event */
    focy_s2m = tgt.focy_s2; 
    angle_y_s2m = tgt.angle_y_s2; 
  }
  
  if (tgt.b_mw_ysum[1] && tgt.b_mw_ysum[2] && 
      tgt.b_mw_xsum[1] && tgt.b_mw_xsum[2])
    hMW_FocS2->Fill(tgt.focx_s2,tgt.focy_s2); 

}




void TFRSCalibrProc::Process_TEST(TFRSSortEvent& src, TFRSCalibrEvent& tgt)
{
  return;
}

ClassImp(TFRSCalibrProc)
