#include <iostream.h>
#include <string.h>
#include <fstream.h>


void setup() {
   // look up analysis object and all parameters 
    
   TFRSAnalysis* an = dynamic_cast<TFRSAnalysis*> (TGo4Analysis::Instance());
   if (an==0) {
      cout << "!!!  Script should be run in FRS analysis" << endl;
      return;
   }

   TMWDCParameter* mwdc = dynamic_cast<TMWDCParameter*> (an->GetParameter("MWDCPar"));
   if (mwdc==0) {
      cout << "!!!  Parameter MWDCPar not found" << endl;
      return;
   }

   TMWParameter* mw = dynamic_cast<TMWParameter*> (an->GetParameter("MWPar"));
   if (mw==0) {
      cout << "!!!  Parameter MWPar not found" << endl;
      return;
   }
   
   TFRSParameter* frs = dynamic_cast<TFRSParameter*> (an->GetParameter("FRSPar"));
   if (frs==0) {
      cout << "!!!  Parameter FRSPar not found" << endl;
      return;
   }

   TMUSICParameter* music = dynamic_cast<TMUSICParameter*> (an->GetParameter("MUSICPar"));
   if (music==0) {
      cout << "!!!  Parameter MUSICPar not found" << endl;
      return;
   }

   TSCIParameter* sci = dynamic_cast<TSCIParameter*> (an->GetParameter("SCIPar"));
   if (sci==0) {
      cout << "!!!  Parameter SCIPar not found" << endl;
      return;
   }

   TIDParameter* id = dynamic_cast<TIDParameter*> (an->GetParameter("IDPar"));
   if (id==0) {
      cout << "!!!  Parameter IDPar not found" << endl;
      return;
   }
   
   TTPCParameter* tpc = dynamic_cast<TTPCParameter*> (an->GetParameter("TPCPar"));
   if (tpc==0) {
      cout << "!!!  Parameter TPCPar not found" << endl;
      return;
   }

   TSIParameter* si = dynamic_cast<TSIParameter*> (an->GetParameter("SIPar"));
   if (si==0) {
      cout << "!!!  Parameter ITAGPar not found" << endl;
      return;
   }
   
   
   cout << endl << "setup script started" << endl;
   


   mwdc->test=2.0;

   //focal plane information
   //mwdc->focal_z=0.0;  //mm/mrad
   //mwdc->focal_a=0.;0; //tilt tan(Theta)
   //mwdc->focal_aa=0.0;//mm/(mrad)^2
   //
   //mwdc->focal_z=1.0;  //mm/mrad
   //mwdc->focal_a=10.; // tilt
   //mwdc->focal_aa=0.083;//mm/(mrad)^2
   // for 900 MeV/u
   //mwdc->focal_z=-0.1;  //mm/mrad
   //mwdc->focal_z=-0.3;  //mm/mrad //900 MeV
   mwdc->focal_z=0.8;  //mm/mrad
   mwdc->focal_a=8.; // tilt
   mwdc->focal_aa=0.09;//mm/(mrad)^2
   mwdc->focal_y=-0.01;//

   // V1742 
   mwdc->v1742cellcorrection_enable = 1; ////  1=on, other=off
   sprintf(mwdc->filename_v1742cellcorrectiontable,"v1742cellcorrection_20140215_run1550.txt"); //// give a file name
   V1742ReadCellCorrectionTable(mwdc, mwdc->filename_v1742cellcorrectiontable);
   mwdc->v1742cellcorrection_offset = 3600; ////  1=on, other=off
   

   
   ////////////////////////////////////////////
   ///////      ETAP SCI Parameters     ///////   
   ////////////////////////////////////////////

   // sci_name
   mwdc->num_sci = 11;
   mwdc->sci_num_channel[0]=2; sprintf(mwdc->sci_name[0],"SC21"); sprintf(mwdc->sci_channel_name[0][0],"SC21L"); sprintf(mwdc->sci_channel_name[0][1],"SC21R");
   mwdc->sci_num_channel[1]=2; sprintf(mwdc->sci_name[1],"SC2H"); sprintf(mwdc->sci_channel_name[1][0],"SC2HL"); sprintf(mwdc->sci_channel_name[1][1],"SC2HR");
   mwdc->sci_num_channel[2]=2; sprintf(mwdc->sci_name[2],"SC2V"); sprintf(mwdc->sci_channel_name[2][0],"SC2VU"); sprintf(mwdc->sci_channel_name[2][1],"SC2VD");
   mwdc->sci_num_channel[3]=2; sprintf(mwdc->sci_name[3],"SC31"); sprintf(mwdc->sci_channel_name[3][0],"SC31L"); sprintf(mwdc->sci_channel_name[3][1],"SC31R");
   mwdc->sci_num_channel[4]=2; sprintf(mwdc->sci_name[4],"SC41"); sprintf(mwdc->sci_channel_name[4][0],"SC41L"); sprintf(mwdc->sci_channel_name[4][1],"SC41R");
   mwdc->sci_num_channel[5]=2; sprintf(mwdc->sci_name[5],"SC42"); sprintf(mwdc->sci_channel_name[5][0],"SC42L"); sprintf(mwdc->sci_channel_name[5][1],"SC42R");
   mwdc->sci_num_channel[6]=2; sprintf(mwdc->sci_name[6],"TOF41"); sprintf(mwdc->sci_channel_name[6][0],"TOF41L"); sprintf(mwdc->sci_channel_name[6][1],"TOF41R");
   mwdc->sci_num_channel[7]=2; sprintf(mwdc->sci_name[7],"TOF42"); sprintf(mwdc->sci_channel_name[7][0],"TOF42L"); sprintf(mwdc->sci_channel_name[7][1],"TOF42R");
   mwdc->sci_num_channel[8]=2; sprintf(mwdc->sci_name[8],"TOF43"); sprintf(mwdc->sci_channel_name[8][0],"TOF43L"); sprintf(mwdc->sci_channel_name[8][1],"TOF43R");

   //Common
   mwdc->sci_num_channel[9]=1; sprintf(mwdc->sci_name[9],"COM0"); sprintf(mwdc->sci_channel_name[9][0],"COM0");
   mwdc->sci_num_channel[10]=1; sprintf(mwdc->sci_name[10],"COM1"); sprintf(mwdc->sci_channel_name[10][0],"COM1");



  //
   mwdc->sci_q0[0][0]=277.4;  mwdc->sci_q0[0][1]=418.2; //21L  21R
   mwdc->sci_q0[1][0]=0.0;  mwdc->sci_q0[1][1]=0.0; //2HL  2HR
   mwdc->sci_q0[2][0]=0.0;  mwdc->sci_q0[2][1]=0.0; //2VU  2VD
   mwdc->sci_q0[3][0]=0.0;  mwdc->sci_q0[3][1]=0.0; //31L  31R
   mwdc->sci_q0[4][0]=1114;  mwdc->sci_q0[4][1]=1236; //41L  41R
   mwdc->sci_q0[5][0]=1322;  mwdc->sci_q0[5][1]=858.1; //42L  42R
   mwdc->sci_q0[6][0]=216.9;  mwdc->sci_q0[6][1]=176.4; //TOF41L  TOF41R
   mwdc->sci_q0[7][0]=213.6;  mwdc->sci_q0[7][1]=186.0; //TOF42L  TOF42R
   mwdc->sci_q0[8][0]=218.7;  mwdc->sci_q0[8][1]=140.1; //TOF43L  TOF43R


   ////////////////////////////////////////////
   ///////     mini HIRAC Parameters    ///////   
   ////////////////////////////////////////////

   // name
   sprintf(mwdc->mini_channel_name[0],"1U") ;
   sprintf(mwdc->mini_channel_name[1],"1D") ;


   ////////////////////////////////////////////
   /////////      HIRAC Parameters    /////////   
   ////////////////////////////////////////////

   // name
   sprintf(mwdc->hirac_channel_name[0],"1U") ;
   sprintf(mwdc->hirac_channel_name[1],"2U") ;
   sprintf(mwdc->hirac_channel_name[2],"3U") ;
   sprintf(mwdc->hirac_channel_name[3],"4U") ;
   sprintf(mwdc->hirac_channel_name[4],"1D") ;
   sprintf(mwdc->hirac_channel_name[5],"2D") ;
   sprintf(mwdc->hirac_channel_name[6],"3D") ;
   sprintf(mwdc->hirac_channel_name[7],"4D") ;


   ////////////////////////////////////////////
   /////////      TORCH Parameters    /////////   
   ////////////////////////////////////////////

   // name
   sprintf(mwdc->torch_channel_name[0],"1") ;
   sprintf(mwdc->torch_channel_name[1],"2") ;
   sprintf(mwdc->torch_channel_name[2],"3") ;
   sprintf(mwdc->torch_channel_name[3],"4") ;
   sprintf(mwdc->torch_channel_name[4],"5") ;
   sprintf(mwdc->torch_channel_name[5],"6") ;



   ////////////////////////////////////////////
   /////////      MWDC Parameters     /////////   
   ////////////////////////////////////////////

   //---S437 S4 focus parameter---
   mwdc->l_mwdc_s4foc = 100.0 ;// mm
   mwdc->angle_s4foc  = 85.0 ; // deg  
   mwdc->l_mwdc_sc41 = 1100.0 ;// mm
   mwdc->l_mwdc_hirac= 1500.0 ;// mm
   mwdc->l_mwdc_torch= 2000.0 ;// mm
   mwdc->l_mwdc_sc42 = 5000.0 ;// mm

   //---fadc-plot-cut----
   mwdc->min_t2141 = -14500;
   mwdc->max_t2141 = -13500;
   mwdc->min_t4142 = 800;
   mwdc->max_t4142 = 1200;
   mwdc->plot_factor = 1;

   ////---- About MWDC Setup  ----//// 
   mwdc->tracking_level = 1;


   // setup // !!! COSY 2014/Jan.!!!
   // Float_t z_pos_A = -500.0;// in mm (see definition in )
   //Float_t z_pos_B = 500.0; // in mm (see definition in )
   // setup // !!! cosmic test for B
   Float_t z_pos_A = 1000.0;// MWDC-42! in mm (see definition in )
   Float_t z_pos_B = 0.0; // MWDC-41! in mm (see definition in )

   // 
   Float_t z_shift_VP = 0.0;
   Float_t z_shift_V  = -4.8;
   Float_t z_shift_UP = -24.4;
   Float_t z_shift_U  = -29.2;
   Float_t z_shift_XP = -48.8;
   Float_t z_shift_X  = -53.6;
   Float_t z_shift_XPN= -73.2;
   Float_t z_shift_XN = -78.0;
  
   //---------plane offset ---------//
   double plane_offset[16] = {
     //MWDC41
     -0.07967 ,//Xn
     -0.1416 + 0.02426 -0.005117,//Xpn
     0.01607 ,//X
     0.04133 ,//Xp
     0.04569 - 0.01594 +0.006 - 0.0055,//U
     0.02612 - 0.0046,//Up
     0.0043 + 0.0069 -0.0069 + 0.015,//V
     0.07118 - 0.02919 +0.012 - 0.015,//Vp
     //MWDC42
     -0.08263 +0.01592,//Xn
     -0.127 + 0.0219, //Xpn
     -0.001929 + 0.00835,//X
     0.02847 + 0.0043,//Xp
     0.07562 - 0.0025 - 0.0013 - 0.008968,//U
     0.04649 - 0.0092 + 0.0014 + 0.01194,//Up
     0.07935 - 0.02821 + 0.007,//V
     0.03978 - 0.0051 - 0.006 + 0.007851//Vp
   };
   double distance_wires = 5.0;//mm
   // plane information: name, zpos, center_id ([i_order] from upstream) // !!! COSY 2014/Jan. !!!
   /*
   sprintf(mwdc->plane_name[0] ,"A_Vp") ; mwdc->zpos[0] = z_pos_A + z_shift_VP;  mwdc->center_id[0] = 23.5-0.015-0.003;//+
   sprintf(mwdc->plane_name[1] ,"A_V")  ; mwdc->zpos[1] = z_pos_A + z_shift_V;   mwdc->center_id[1] = 24.0+0.004-0.003;//-
   sprintf(mwdc->plane_name[2] ,"A_Up") ; mwdc->zpos[2] = z_pos_A + z_shift_UP;  mwdc->center_id[2] = 23.5-0.015;//+
   sprintf(mwdc->plane_name[3] ,"A_U")  ; mwdc->zpos[3] = z_pos_A + z_shift_U;   mwdc->center_id[3] = 23.0-0.005;//- //mwdc->center_id[3] = 24.0;
   sprintf(mwdc->plane_name[4] ,"A_Xp") ; mwdc->zpos[4] = z_pos_A + z_shift_XP;  mwdc->center_id[4] = 23.5+0.018;//+
   sprintf(mwdc->plane_name[5] ,"A_X")  ; mwdc->zpos[5] = z_pos_A + z_shift_X;   mwdc->center_id[5] = 24.0-0.003;//-
   sprintf(mwdc->plane_name[6] ,"A_Xpn"); mwdc->zpos[6] = z_pos_A + z_shift_XPN; mwdc->center_id[6] = 23.5;
   sprintf(mwdc->plane_name[7] ,"A_Xn") ; mwdc->zpos[7] = z_pos_A + z_shift_XN;  mwdc->center_id[7] = 24.0;
   sprintf(mwdc->plane_name[8] ,"B_Vp") ; mwdc->zpos[8] = z_pos_B + z_shift_VP;  mwdc->center_id[8] = 23.5-0.001;//+
   sprintf(mwdc->plane_name[9] ,"B_V")  ; mwdc->zpos[9] = z_pos_B + z_shift_V;   mwdc->center_id[9] = 24.0+0.031;//-
   sprintf(mwdc->plane_name[10],"B_Up") ; mwdc->zpos[10]= z_pos_B + z_shift_UP;  mwdc->center_id[10]= 23.5-0.021;//+
   sprintf(mwdc->plane_name[11],"B_U")  ; mwdc->zpos[11]= z_pos_B + z_shift_U;   mwdc->center_id[11]= 23.0+0.005;//-// mwdc->center_id[11]= 24.0;
   sprintf(mwdc->plane_name[12],"B_Xp") ; mwdc->zpos[12]= z_pos_B + z_shift_XP;  mwdc->center_id[12]= 23.5+0.031;//+
   sprintf(mwdc->plane_name[13],"B_X")  ; mwdc->zpos[13]= z_pos_B + z_shift_X;   mwdc->center_id[13]= 24.0-0.026;//-
   sprintf(mwdc->plane_name[14],"B_Xpn"); mwdc->zpos[14]= z_pos_B + z_shift_XPN; mwdc->center_id[14]= 23.5;
   sprintf(mwdc->plane_name[15],"B_Xn") ; mwdc->zpos[15]= z_pos_B + z_shift_XN;  mwdc->center_id[15]= 24.0;
   */
   // --- MWDC-A = MWDC-42, MWDC-B = MWDC-41 in S436/S437 July 2014 ---
   sprintf(mwdc->plane_name[15] ,"42_Vp") ; mwdc->zpos[15] = z_pos_A + z_shift_VP;  mwdc->center_id[15] = 23.5-0.015-0.003;//+
   sprintf(mwdc->plane_name[14] ,"42_V")  ; mwdc->zpos[14] = z_pos_A + z_shift_V;   mwdc->center_id[14] = 24.0+0.004-0.003;//-
   sprintf(mwdc->plane_name[13] ,"42_Up") ; mwdc->zpos[13] = z_pos_A + z_shift_UP;  mwdc->center_id[13] = 23.5-0.015;//+
   sprintf(mwdc->plane_name[12] ,"42_U")  ; mwdc->zpos[12] = z_pos_A + z_shift_U;   mwdc->center_id[12] = 23.0-0.005;//- //mwdc->center_id[3] = 24.0;
   sprintf(mwdc->plane_name[11] ,"42_Xp") ; mwdc->zpos[11] = z_pos_A + z_shift_XP;  mwdc->center_id[11] = 23.5+0.018;//+
   sprintf(mwdc->plane_name[10] ,"42_X")  ; mwdc->zpos[10] = z_pos_A + z_shift_X;   mwdc->center_id[10] = 24.0-0.003;//-
   sprintf(mwdc->plane_name[9] ,"42_Xpn"); mwdc->zpos[9] = z_pos_A + z_shift_XPN; mwdc->center_id[9] = 23.5;
   sprintf(mwdc->plane_name[8] ,"42_Xn") ; mwdc->zpos[8] = z_pos_A + z_shift_XN;  mwdc->center_id[8] = 24.0;
   sprintf(mwdc->plane_name[7] ,"41_Vp") ; mwdc->zpos[7] = z_pos_B + z_shift_VP;  mwdc->center_id[7] = 23.5-0.001;//+
   sprintf(mwdc->plane_name[6] ,"41_V")  ; mwdc->zpos[6] = z_pos_B + z_shift_V;   mwdc->center_id[6] = 24.0+0.031;//-
   sprintf(mwdc->plane_name[5],"41_Up") ; mwdc->zpos[5]= z_pos_B + z_shift_UP;  mwdc->center_id[5]= 23.5-0.021;//+
   sprintf(mwdc->plane_name[4],"41_U")  ; mwdc->zpos[4]= z_pos_B + z_shift_U;   mwdc->center_id[4]= 23.0+0.005;//-// mwdc->center_id[11]= 24.0;
   sprintf(mwdc->plane_name[3],"41_Xp") ; mwdc->zpos[3]= z_pos_B + z_shift_XP;  mwdc->center_id[3]= 23.5+0.031;//+
   sprintf(mwdc->plane_name[2],"41_X")  ; mwdc->zpos[2]= z_pos_B + z_shift_X;   mwdc->center_id[2]= 24.0-0.026;//-
   sprintf(mwdc->plane_name[1],"41_Xpn"); mwdc->zpos[1]= z_pos_B + z_shift_XPN; mwdc->center_id[1]= 23.5;
   sprintf(mwdc->plane_name[0],"41_Xn") ; mwdc->zpos[0]= z_pos_B + z_shift_XN;  mwdc->center_id[0]= 24.0;
   
   // plane information: angle, sign ([i_order] from upstream) // !!! COSY 2014/Jan. with xy plane seeing from upstream side (Left-handed-xyz) !!!
   Float_t angle_X =   0.0;  // unit is rad.
   Float_t angle_V = -15.0*3.14159265/180.0; // sign of angle is depending on the MWDC direction. (+ for COSY, - for FRS)
   Float_t angle_U = +15.0*3.14159265/180.0; //  (- for COSY, + for FRS)
   mwdc->plane_angle[15]  = angle_V ;  mwdc->plane_sign[15] = +1.0; // - for cosy
   mwdc->plane_angle[14]  = angle_V ;  mwdc->plane_sign[14] = -1.0;
   mwdc->plane_angle[13]  = angle_U ;  mwdc->plane_sign[13] = +1.0; 
   mwdc->plane_angle[12]  = angle_U ;  mwdc->plane_sign[12] = -1.0;
   mwdc->plane_angle[11]  = angle_X ;  mwdc->plane_sign[11] = +1.0;
   mwdc->plane_angle[10]  = angle_X ;  mwdc->plane_sign[10] = -1.0;
   mwdc->plane_angle[9]  = angle_X ;  mwdc->plane_sign[9] =  +1.0;
   mwdc->plane_angle[8]  = angle_X ;  mwdc->plane_sign[8] =  -1.0;
   mwdc->plane_angle[7]  = angle_V ;  mwdc->plane_sign[7] =  +1.0;
   mwdc->plane_angle[6]  = angle_V ;  mwdc->plane_sign[6] =  -1.0;
   mwdc->plane_angle[5] = angle_U ;  mwdc->plane_sign[5]=   +1.0;
   mwdc->plane_angle[4] = angle_U ;  mwdc->plane_sign[4]=   -1.0;
   mwdc->plane_angle[3] = angle_X ;  mwdc->plane_sign[3]=   +1.0;
   mwdc->plane_angle[2] = angle_X ;  mwdc->plane_sign[2]=   -1.0;
   mwdc->plane_angle[1] = angle_X ;  mwdc->plane_sign[1]=   +1.0;
   mwdc->plane_angle[0] = angle_X ;  mwdc->plane_sign[0]=   -1.0;

   for(int i=0;i<16;i++)mwdc->center_id[i]-= mwdc->plane_sign[i]*plane_offset[i]/distance_wires; 

   ////---- Read AMSC Configuration  ----////
   sprintf(mwdc->filename_etap_setting,"daqconfig.txt");
   ReadAMSCSetting(mwdc,mwdc->filename_etap_setting); 
   ReadV830Setting(mwdc,mwdc->filename_etap_setting);
   ReadV830MHSetting(mwdc,mwdc->filename_etap_setting);
   ReadSCISetting(mwdc,mwdc->filename_etap_setting);
   ReadV1290Setting(mwdc,mwdc->filename_etap_setting);

   ////---- dt-dx coefficient ----///
   sprintf(mwdc->filename_dtdx_table,"dtdx.txt"); //symolic link to newest version
   ReadDTDXTable(mwdc,mwdc->filename_dtdx_table); 
     

   //  End of MWDC Parameter
   //------------------------------


   //-----------------------------------
//   an->SetupH1("ID_AoQ", 2000, 1., 3., "A/Q in current setup");   
   an->SetupH2("ID_x2AoQ", 500, 2.2, 2.8, 1000, -100, +100, "A/Q", "X2 [mm]");   
   //   an->SetupH2("ID_x4AoQ", 500, 1.5, 3.0, 500, -100, +100, "A/Q", "X4 [mm]");  
   an->SetupH2("ID_Z_AoQ", 600, 2.1, 2.7, 450, 40, 99, "A/Q", "Z"); 
   an->SetupH2("ID_Z_AoQ_corr", 600, 2.1, 2.7, 450, 50, 95, "A/Q (a2 corr)", "Z"); 
   an->SetupH2("ID_x4z", 450, 70., 95.0, 500, -100, 100, "Z", "X4 [mm]"); 
//   an->SetupWinCond("cID_x2", -75.0, 75.0);
      

   Float_t cID_dEToF_points[4][2] = 
     {{    0.,    0.},
      {    0., 4000.},
      {40000., 4000.},
      {40000.,    0.}}; 
   an->SetupPolyCond("cID_dEToF", 4, cID_dEToF_points);
   

   // setup FRS parameter

   mw->x_factor[0] = 0.25; // MW11 [mm/ns] 14.09.05 CN+AM 2ns/mm delay line 
   mw->x_factor[1] = 0.25; // MW21
   mw->x_factor[2] = 0.25; // MW22
   mw->x_factor[3] = 0.25; // MW31
   mw->x_factor[4] = 0.25; // MW41 
   mw->x_factor[5] = 0.25; // MW42
   mw->x_factor[8] = 0.25; // MW71
   mw->x_factor[9] = 0.25; // MW81   
   mw->x_factor[10] = 0.125; // MW82 [mm/ns] 11.05.06  CN 4ns/mm delay line

   //27-MAY-2007 TESTED VALUE WITH SLITS
   mw->x_offset[0] = -0.4; //  MW11  17.01.09 TESTED VALUE WITH SLITS
   mw->x_offset[1] = 2.0;  //  MW21  17.01.09 TESTED VALUE WITH SLITS
   mw->x_offset[2] = -1.0; //  MW22  17.01.09 TESTED VALUE WITH SLITS
   mw->x_offset[3] = -0.205; // MW31 //10/05/06, ok also 20.01.09
   mw->x_offset[4] = 0.;  // MW41
   mw->x_offset[5] = -9.; // MW42 20.01.09 TESTED VALUE WITH SLITS
   mw->x_offset[8] = 1.642; // MW71 //15/05/06
   mw->x_offset[9] = 1.;   // MW81 //11/05/06
   mw->x_offset[10] = -5.; // MW82 //27-MAY-2007

   mw->y_factor[0] = 0.25; // MW11 [mm/ns] 14.09.05 CN+AM 2ns/mm delay line 
   mw->y_factor[1] = 0.25; // MW21
   mw->y_factor[2] = 0.25; // MW22
   mw->y_factor[3] = 0.25; // MW31
   mw->y_factor[4] = 0.25; // MW41
   mw->y_factor[5] = 0.25; // MW42
   mw->y_factor[8] = 0.25; // MW71
   mw->y_factor[9] = 0.25; // MW81
   mw->y_factor[10] = 0.125; // MW82  [mm/ns] 11.05.06  CN 4ns/mm delay line

   //27-MAY-2007 TESTED VALUE WITH SLITS
   mw->y_offset[0] = -14.0; // MW11 27-MAY-2007 TESTED VALUE WITH SLITS
   mw->y_offset[1] = -5.0;  // MW21 27-MAY-2007 TESTED VALUE WITH SLITS
   mw->y_offset[2] = -1.0;  // MW22 27-MAY-2007 TESTED VALUE WITH SLITS
   mw->y_offset[3] = 0.0;   // MW31 18-MAY-2007
   mw->y_offset[4] = 0.;  // MW41
   mw->y_offset[5] = 0.;  // MW42
   mw->y_offset[8] = -2.736;  // MW71 //15/05/06
   mw->y_offset[9] = 3.2;     // MW81 //11/05/06
   mw->y_offset[10] = 0.764;  // MW82 //11/05/06


   mw->gain_tdc[0][0] = 0.302929; //  MW11 Anode (#ch  0 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][0] = 0.303253; //  MW11 XL    (#ch 17 TDC V775a)
   mw->gain_tdc[2][0] = 0.303975; //  MW11 XR    (#ch 16 TDC V775a)
   mw->gain_tdc[3][0] = 0.308414; //  MW11 YU    (#ch 18 TDC V775a)
   mw->gain_tdc[4][0] = 0.309826; //  MW11 YD    (#ch 19 TDC V775a)

   mw->gain_tdc[0][1] = 0.306064; //  MW21 Anode (#ch  1 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][1] = 0.306958; //  MW21 XL    (#ch 21 TDC V775a)
   mw->gain_tdc[2][1] = 0.307799; //  MW21 XR    (#ch 20 TDC V775a)
   mw->gain_tdc[3][1] = 0.297774; //  MW21 YU    (#ch 22 TDC V775a)
   mw->gain_tdc[4][1] = 0.310235; //  MW21 YD    (#ch 23 TDC V775a)

   mw->gain_tdc[0][2] = 0.301179;  // MW22 Anode (#ch  2 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][2] = 0.311121; //  MW22 XL    (#ch 25 TDC V775a)
   mw->gain_tdc[2][2] = 0.303233; //  MW22 XR    (#ch 24 TDC V775a)
   mw->gain_tdc[3][2] = 0.300558; //  MW22 YU    (#ch 26 TDC V775a)
   mw->gain_tdc[4][2] = 0.301105; //  MW22 YD    (#ch 27 TDC V775a)

   mw->gain_tdc[0][3] = 0.304426; //  MW31 Anode (#ch  3 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][3] = 0.312163; //  MW31 XL    (#ch 29 TDC V775a)
   mw->gain_tdc[2][3] = 0.305609; //  MW31 XR    (#ch 28 TDC V775a)
   mw->gain_tdc[3][3] = 0.304716; //  MW31 YU    (#ch 30 TDC V775a)
   mw->gain_tdc[4][3] = 0.293695; //  MW31 YD    (#ch 31 TDC V775a)

   mw->gain_tdc[0][4] = 0.298871; //  MW41 Anode (#ch  4 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][4] = 0.284086; //  MW41 XL    (#ch 1 TDC V775b)
   mw->gain_tdc[2][4] = 0.288656; //  MW41 XR    (#ch 0 TDC V775b)
   mw->gain_tdc[3][4] = 0.286589; //  MW41 YU    (#ch 2 TDC V775b)
   mw->gain_tdc[4][4] = 0.29269;  //  MW41 YD    (#ch 3 TDC V775b)

   mw->gain_tdc[0][5] = 0.297881; //  MW42 Anode (#ch  5 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][5] = 0.287364; //  MW42 XL    (#ch 5 TDC V775b)
   mw->gain_tdc[2][5] = 0.289636; //  MW42 XR    (#ch 4 TDC V775b)
   mw->gain_tdc[3][5] = 0.291135; //  MW42 YU    (#ch 6 TDC V775b)
   mw->gain_tdc[4][5] = 0.289867; //  MW42 YD    (#ch 7 TDC V775b)

   mw->gain_tdc[0][6] = 0.307892; //  MW51 Anode (#ch  6 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][6] = 0.289894; //  MW51 XL    (#ch  9 TDC V775b)
   mw->gain_tdc[2][6] = 0.292366; //  MW51 XR    (#ch  8 TDC V775b)
   mw->gain_tdc[3][6] = 0.284708; //  MW51 YU    (#ch 10 TDC V775b)
   mw->gain_tdc[4][6] = 0.28186;  //  MW51 YD    (#ch 11 TDC V775b)

   mw->gain_tdc[0][7] = 0.298266; //  MW61 Anode (#ch  7 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][7] = 0.311; //  MW61 XL    (#ch ? TDC V775b)
   mw->gain_tdc[2][7] = 0.305; //  MW61 XR    (#ch ? TDC V775b)
   mw->gain_tdc[3][7] = 0.337; //  MW61 YU    (#ch ? TDC V775b)
   mw->gain_tdc[4][7] = 0.289; //  MW61 YD    (#ch ? TDC V775b)

   mw->gain_tdc[0][8] = 0.303602; //  MW71 Anode (#ch  8 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][8] = 0.300082; //  MW71 XL    (#ch 13 TDC V775b)
   mw->gain_tdc[2][8] = 0.286092; //  MW71 XR    (#ch 12 TDC V775b)
   mw->gain_tdc[3][8] = 0.294287; //  MW71 YU    (#ch 14 TDC V775b)
   mw->gain_tdc[4][8] = 0.291341; //  MW71 YD    (#ch 15 TDC V775b)

   mw->gain_tdc[0][9] = 0.306041; //  MW81 Anode (#ch  9 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][9] = 0.288468; //  MW81 XL    (#ch 17 TDC V775b)
   mw->gain_tdc[2][9] = 0.293831; //  MW81 XR    (#ch 16 TDC V775b)
   mw->gain_tdc[3][9] = 0.281296; //  MW81 YU    (#ch 18 TDC V775b)
   mw->gain_tdc[4][9] = 0.279099; //  MW81 YD    (#ch 19 TDC V775b)

   mw->gain_tdc[0][10] = 0.31314;  //  MW82 Anode (#ch 10 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][10] = 0.287279; //  MW82 XL    (#ch 21 TDC V775b)
   mw->gain_tdc[2][10] = 0.284028; //  MW82 XR    (#ch 20 TDC V775b)
   mw->gain_tdc[3][10] = 0.28051;  //  MW82 YU    (#ch 22 TDC V775b)
   mw->gain_tdc[4][10] = 0.28743;  //  MW82 YD    (#ch 23 TDC V775b)

   mw->gain_tdc[0][11] = 0.299973; //  MWB21 Anode (#ch 11 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][11] = 0.311; //  MWB21 XL    (#ch ? TDC V775b)
   mw->gain_tdc[2][11] = 0.305; //  MWB21 XR    (#ch ? TDC V775b)
   mw->gain_tdc[3][11] = 0.337; //  MWB21 YU    (#ch ? TDC V775b)
   mw->gain_tdc[4][11] = 0.289; //  MWB21 YD    (#ch ? TDC V775b)

   mw->gain_tdc[0][12] = 0.306923; //  MWB22 Anode (#ch 12 TDC V775a) // 13.01.2008
   mw->gain_tdc[1][12] = 0.311; //  MWB22 XL    (#ch ? TDC V775b)
   mw->gain_tdc[2][12] = 0.305; //  MWB22 XR    (#ch ? TDC V775b)
   mw->gain_tdc[3][12] = 0.337; //  MWB22 YU    (#ch ? TDC V775b)
   mw->gain_tdc[4][12] = 0.289; //  MWB22 YD    (#ch ? TDC V775b)


   frs->dist_focS2   = 2280.0; // [mm]
   frs->dist_MW21    =  604.0; // 
   frs->dist_MW22    = 1782.5; // 
   frs->dist_SC21    = 1554.5; // 
   //   frs->dist_MW41    = 1140.0; // ok on air
   //   frs->dist_MW42    = 2600.0; // ok on air


   //**S323,410 exp.
   frs->dist_SC41    = 2180.0; // 8.09.11
   //frs->dist_focS4   = 2330.0; // from exp s410
   frs->dist_focS4   = 4300.0; // from new theory setting
   
   //**S323,410 exp.
   frs->dist_MUSIC1  = 690.0;  // 8.09.11
   frs->dist_MUSIC2  = 1205.0; // 8.09.11
   frs->dist_MUSIC3  = 3065.0; // 8.09.11 

 
   frs->dist_MUSICa1 = 52.5;  // do not change
   frs->dist_MUSICa2 = 157.5; // do not change
   frs->dist_MUSICa3 = 262.5; // do not change
   frs->dist_MUSICa4 = 367.5; // do not change

   frs->dist_itag_42 = 6660.;      //updated 18.03.10
   frs->dist_itag_stopper = 6880.; 
   frs->dist_itag_43 = 7035.;

         music->e1_off[0]   = 0.; //MUSIC1 offsets
         music->e1_off[1]   = 0.; 
         music->e1_off[2]   = 0.;
         music->e1_off[3]   = 0.;
         music->e1_off[4]   = 0.;
         music->e1_off[5]   = 0.;
         music->e1_off[6]   = 0.;
         music->e1_off[7]   = 0.;


         music->e1_gain[0]   = 1.27; // MUSIC1 gains
         music->e1_gain[1]   = 1.27; 
         music->e1_gain[2]   = 1.27;
         music->e1_gain[3]   = 1.27;
         music->e1_gain[4]   = 1.27;
         music->e1_gain[5]   = 1.27;
         music->e1_gain[6]   = 1.27;
         music->e1_gain[7]   = 1.27;

         music->e2_off[0]   = 0.; //MUSIC2 offsets
         music->e2_off[1]   = 0.; 
         music->e2_off[2]   = 0.;
         music->e2_off[3]   = 0.;
         music->e2_off[4]   = 0.;
         music->e2_off[5]   = 0.;
         music->e2_off[6]   = 0.;
         music->e2_off[7]   = 0.;


         music->e2_gain[0]   = 1.; // MUSIC2 gains
         music->e2_gain[1]   = 1.; 
         music->e2_gain[2]   = 1.;
         music->e2_gain[3]   = 1.;
         music->e2_gain[4]   = 1.;
         music->e2_gain[5]   = 1.;
         music->e2_gain[6]   = 1.;
         music->e2_gain[7]   = 1.;

         music->e3_off[0]   = 0.; //MUSIC3 offsets
         music->e3_off[1]   = 0.; 
         music->e3_off[2]   = 0.;
         music->e3_off[3]   = 0.;


         music->e3_gain[0]   = 1.; // MUSIC3 gains
         music->e3_gain[1]   = 1.; 
         music->e3_gain[2]   = 1.;
         music->e3_gain[3]   = 1.;


   music->pos_a1[0]   = 1.0;   // C0...Cn position correction not used
   music->pos_a1[1]   = 0.0;
   music->pos_a1[2]   = 0.0;
   music->pos_a1[3]   = 0.0;
   music->pos_a1[4]   = 0.0;
   music->pos_a1[5]   = 0.0;
   music->pos_a1[6]   = 0.0;


   //TPC3   //23/04/08 VALUE SET ACCORDING TO CALIBRATION
   tpc->x_factor[2][0] = 0.0719;  //L-R time 0
   tpc->x_factor[2][1] = 0.0714;  //L-R time 1
   tpc->y_factor[2][0] = -0.0352; //drift time 0
   tpc->y_factor[2][1] = -0.0354; //drift time 1
   tpc->y_factor[2][2] = -0.0350; //drift time 2
   tpc->y_factor[2][3] = -0.0348; //drift time 3

   tpc->x_offset[2][0] = -1.6;
   tpc->x_offset[2][1] = 0.4;
   tpc->y_offset[2][0] = 48.5;
   tpc->y_offset[2][1] = 48.4;
   tpc->y_offset[2][2] = 47.9;
   tpc->y_offset[2][3] = 47.8;

   // TPC4
  tpc->x_factor[3][0] = 0.0759;
  tpc->x_factor[3][1] = 0.0755;
  tpc->y_factor[3][0] = -0.0361;
  tpc->y_factor[3][1] = -0.0357;
  tpc->y_factor[3][2] = -0.0355;
  tpc->y_factor[3][3] = -0.0363; 
	
  tpc->x_offset[3][0] = -0.9;
  tpc->x_offset[3][1] = 4.6;
  tpc->y_offset[3][0] = 57.8;
  tpc->y_offset[3][1] = 57.6;
  tpc->y_offset[3][2] = 57.1;
  tpc->y_offset[3][3] = 57.2;
  

  // TPC5
  
  tpc->x_factor[4][0] = 0.0750;
  tpc->x_factor[4][1] = 0.0771;
  tpc->y_factor[4][0] =-0.0375;
  tpc->y_factor[4][1] =-0.0374;
  tpc->y_factor[4][2] =-0.0377;
  tpc->y_factor[4][3] =-0.0374; 
  
  tpc->x_offset[4][0] = 1.4-1.4-1.7; // -1.7 was added  25Jul2014 (YT)
  tpc->x_offset[4][1] =-2.6-1.4-1.7;
  tpc->y_offset[4][0] = 41.0+6.4; // +6.4 was added  25Jul2014 (YT)
  tpc->y_offset[4][1] = 41.0+6.4;
  tpc->y_offset[4][2] = 39.7+6.4;
  tpc->y_offset[4][3] = 39.8+6.4;   

   // TPC6
 
  //   tpc->x_factor[5][0] = 0.07755;
   //   tpc->x_factor[5][1] = 0.07683;
   //   tpc->y_factor[5][0] = 0.04040;
   //   tpc->y_factor[5][1] = 0.04700;
   //   tpc->y_factor[5][2] = 0.0409;
   //   tpc->y_factor[5][3] = 0.0392;  

   //   tpc->x_offset[5][0] = -0.15221;
   //   tpc->x_offset[5][1] = 1.5;
   //   tpc->y_offset[5][0] = 38;
   //   tpc->y_offset[5][1] = 37.96;
   //   tpc->y_offset[5][2] = 37.25;
   //   tpc->y_offset[5][3] = 36.67; 
 
      tpc->x_factor[5][0] = 0.0786;
      tpc->x_factor[5][1] = 0.0805;
      tpc->y_factor[5][0] =-0.0377;
      tpc->y_factor[5][1] =-0.0380;
      tpc->y_factor[5][2] =-0.0375;
      tpc->y_factor[5][3] =-0.0375;  

      tpc->x_offset[5][0] = -2.07-1.2+5.2; // +5.2 was added  25Jul2014 (YT)
      tpc->x_offset[5][1] = -0.9-1.2+5.2;
      tpc->y_offset[5][0] = 42.1-10.7;// -10.7 was added  25Jul2014 (YT)
      tpc->y_offset[5][1] =42.3-10.7;
      tpc->y_offset[5][2] =42.7-10.7;
      tpc->y_offset[5][3] =43.0-10.7; 

   // TPC1
   tpc->x_factor[0][0] = 0.070623;
   tpc->x_factor[0][1] = 0.07248;
   tpc->y_factor[0][0] =-0.035723; 
   tpc->y_factor[0][1] =-0.034725;
   tpc->y_factor[0][2] =-0.0364399;
   tpc->y_factor[0][3] =-0.035037; 
	 
   tpc->x_offset[0][0] =-0.5;
   tpc->x_offset[0][1] =-1.058;
   tpc->y_offset[0][0] = 38.1838 -1.3; // -1.3 was added  25Jul2014 (YT)
   tpc->y_offset[0][1] = 38.37   -1.3;
   tpc->y_offset[0][2] = 39.1557 -1.3;
   tpc->y_offset[0][3] = 39.097  -1.3; 

   // TPC2
   tpc->x_factor[1][0] = 0.0716;
   tpc->x_factor[1][1] = 0.070329;
   tpc->y_factor[1][0] = -0.0362752;
   tpc->y_factor[1][1] = -0.0365182;
   tpc->y_factor[1][2] = -0.0357276;
   tpc->y_factor[1][3] = -0.0360721;  

   tpc->x_offset[1][0] = -0.81  -0.8;   // -0.8 was added  25Jul2014 (YT)
   tpc->x_offset[1][1] =  1.9   -0.8;
   tpc->y_offset[1][0] =  36.77 -13.1;  // -13.1 was added  25Jul2014 (YT)
   tpc->y_offset[1][1] =  38.0  -13.1;
   tpc->y_offset[1][2] =  36.123-13.1;
   tpc->y_offset[1][3] =  37.13 -13.1; 

   // index 2 for Sc21  
   sci->x_a[0][2] = -6021;  //  SC21 calibration ch->mm 
   sci->x_a[1][2] =  5.82772; //  s323 Cd126 Fragments
   sci->x_a[2][2] = -0.0014115;  // 
   sci->x_a[3][2] =  0.000000;  //                            
   sci->x_a[4][2] =  0.000000;  //                             
   sci->x_a[5][2] =  0.000000;  //                             
   sci->x_a[6][2] =  0.000000;  //    
	/*
   // index 2 for Sc21  
   sci->x_a[0][2] = 1184.51;  //  SC21 calibration ch->mm 
   sci->x_a[1][2] =  -0.5206; //  s323 test run: Xe fragments run
   sci->x_a[2][2] =  0.000000;  // 
   sci->x_a[3][2] =  0.000000;  //                            
   sci->x_a[4][2] =  0.000000;  //                             
   sci->x_a[5][2] =  0.000000;  //                             
   sci->x_a[6][2] =  0.000000;  //    
	*/
  	/* 
   sci->x_a[0][2] = 741.18;  //  SC21 calibration ch->mm 
   sci->x_a[1][2] =  -0.2952; //  linear fit parameters from TPC3/4 extrapolation to Sc21, 25.03.10
   sci->x_a[2][2] =  0.000000;  // 
   sci->x_a[3][2] =  0.000000;  //                            
   sci->x_a[4][2] =  0.000000;  //                             
   sci->x_a[5][2] =  0.000000;  //                             
   sci->x_a[6][2] =  0.000000;  //                             
   */
   //sci->x_a[0][2] = -10765.35;  //  SC21 calibration ch->mm 
   //sci->x_a[1][2] =  14.85664; //  fit to file 559 from TPC3/4 extrapolation to Sc21, 30.03.10
   //sci->x_a[2][2] = -0.00709;  // 
   //sci->x_a[3][2] =  1.3485E-6;  //                            
   //sci->x_a[4][2] = -8.0222E-11; //                             
   //sci->x_a[5][2] =  0.000000;  //                             
   //sci->x_a[6][2] =  0.000000;  //        

   // index 5 for Sc41
   sci->x_a[0][5] = 0.;  //  SC41 calibration ch->mm 
   sci->x_a[1][5] = 1.;  //
   sci->x_a[2][5] = 0.000000;   //
   sci->x_a[3][5] = 0.000000;   //                            
   sci->x_a[4][5] = 0.000000;   //                             
   sci->x_a[5][5] = 0.000000;   //                             
   sci->x_a[6][5] = 0.000000;   //    

   // index 6 for Sc42
   sci->x_a[0][6] = 0.; //   SC42 calibration ch->mm 
   sci->x_a[1][6] = 1.; // 
   sci->x_a[2][6] = 0.000000;  // 
   sci->x_a[3][6] = 0.000000;  //                            
   sci->x_a[4][6] = 0.000000;  //                             
   sci->x_a[5][6] = 0.000000;  //                             
   sci->x_a[6][6] = 0.000000;  //    


   // TOF 
   sci->tac_off[0] = 0.;  //SC21L-R  // not used online
   sci->tac_off[1] = 0.;  //SC41L-R 
   sci->tac_off[2] = 0.;  //SC41L-SC21L
   sci->tac_off[3] = 0.;  //SC41R-SC21R
   sci->tac_off[4] = 0.;  //SC42L-SC42R
   sci->tac_off[5] = 0.;  //SC42L-SC21L
   sci->tac_off[6] = 0.;  //SC42R-SC21R

   sci->tac_factor[0] = 5.387;   //SC21L-R [ps/ch]  12.08.2011, range 25 ns
   sci->tac_factor[1] = 5.510;   //SC41L-R [ps/ch]  12.08.2011, range 25 ns  
   sci->tac_factor[4] = 0.;   //SC42L-SC42R [ps/ch] 12.08.2011, not used

   sci->tac_factor[2] = 17.151;   //SC41L-SC21L [ps/ch] 12.08.2011, range 70ns (adc full range)
   sci->tac_factor[3] = 17.060;   //SC41R-SC21R [ps/ch] 12.08.2011, range 70ns (adc full range)
   sci->tac_factor[5] = 17.287;   //SC41L-SC21L_raw 12.08.2011, TAC range 70 ns (adc full range)
   sci->tac_factor[6] = 16.883;   //SC41R-SC21R_raw 12.08.2011, TAC range 70 ns (adc full range)
   

   sci->tof_bll2  = 1.;    // not used online [ps/ch]
   sci->tof_brr2  = 1.;    // not used online
   sci->tof_bll3  = 1.;    // not used online 
   sci->tof_brr3  = 1.;    // not used online

   sci->tof_a2 = 0.; // [ps] offset   Tof S41-S21
   sci->tof_a3 = 0.; // [ps] offset   Tof S41-S21_raw


   //for s323/s410 test run. 13/08/2010
   //id->id_tofoff2  = 201763.2; // [ps]  S41-S21
   //id->id_path2    = 122296.8; // path/c [ps]   S41-S21_raw


   //for s410 isomer setting. 23/09/2011
   //   id->id_tofoff2  = 201184.0; // [ps]  S41-S21
   //   id->id_path2    = 122448;

   //adjusted for s411 (1 tof point)
   id->id_tofoff2  = 200935.0; // [ps]  S41-S21
   id->id_path2    = 122321. ; // 122627.0;



   // adjusted id_path2 after change of the sci voltages:
   //id->id_path2    = 122143; // path/c [ps]   S41-S21_raw  jk 16.09.11



   id->id_tofoff3  = 202532.5;   // [ps]  S41-S21_raw
   id->id_path3    = 122257.3;   // path/c [ps]  S41-S21_raw 


   // to be changed according to S323 optics
   // B-rho values : change according to the FRS settings

   // s411 238U
      frs->bfield[0] = 1.19075;       // FRS D3 field [Tesla] 
      frs->bfield[1] = 1.18614;       // FRS D4 field [Tesla] 
      frs->bfield[2] = 0.8514;        // FRS D3 field [Tesla] 
      frs->bfield[3] = 0.8514;        // FRS D4 field [Tesla] 

   // s411 223Th
   //frs->bfield[0] = 1.13855;       // FRS D3 field [Tesla] 
   //frs->bfield[1] = 1.13394;       // FRS D4 field [Tesla] 
   //frs->bfield[2] = 0.8054;        // FRS D3 field [Tesla] 
   //frs->bfield[3] = 0.8053;        // FRS D4 field [Tesla] 

   
   frs->dispersion[0] = -6.474266;     // FRS dispersion TA-S2     (TA2B-Rising optics: TA-S2)
   frs->dispersion[1] =  7.2202681;    // FRS dispersion S2-S4     (TA2B-Rising optics: TA-S4) 
   frs->magnification[1] = 1.115225;   // FRS magnification S2-S4  (TA2B-Rising optics: TA-S4)


   frs->rho0[0]   = 11.203 ;   // FRS (D1+D2)/2 radius [m]    
   frs->rho0[1]   = 11.2641 ;   // FRS (D3+D4)/2 radius [m]   16.09.11


   //frs->primary_z = 83;  // old Bi calib.
   frs->primary_z = 92.2;  // new U calib.,
   frs->offset_z  =  0.0;
   frs->offset_z2  = 0.0;
   frs->offset_z3  = 0.0;

        //s410
	frs->a2AoQCorr = 0.0009;
	frs->a4AoQCorr = 0.0010;

	// s323:
	//	frs->a2AoQCorr = 0.00165;
	//	frs->a4AoQCorr = 0.00196;
	
   // MUSIC 1 velocity correction 
   //   id->vel_a[0] =   9777.9;
   //   id->vel_a[1] = -13932.0; 
   //   id->vel_a[2] =   5744.2;
   //   id->vel_a[3] =      0.0;  
   //      id->vel_a[0] =   12491.2;
   //      id->vel_a[1] = -23994.4; 
   //      id->vel_a[2] =   13239.6;
   //      id->vel_a[3] =      0.0;

   //id->vel_a[0] =  7788.3;  // update 14.08.11
   //id->vel_a[1] = -5993.5; 
   //id->vel_a[2] =  0.0;
   //id->vel_a[3] =  0.0; 

   id->vel_a[0] =  17223.11;  // alternative based on ATIMA only for Z_0=92.2, 8.10.2011
   id->vel_a[1] = -28435.8; 
   id->vel_a[2] =  14472.5;
   id->vel_a[3] =  0.0; 


   // MUSIC 2 velocity correction 
      //      id->vel_a2[0] =  15215.0;
      //      id->vel_a2[1] = -27423.0; 
      //      id->vel_a2[2] =  13903.0;
   //   id->vel_a2[3] =      0.0;  
   //   id->vel_a2[0] =  20066.2; // old
   //   id->vel_a2[1] = -46292.9; 
   //  id->vel_a2[2] =  29357.6;
   //  id->vel_a2[3] =      0.0;
   //
   id->vel_a2[0] =  7788.3;  // copy from MUSIC41 16.09.11
   id->vel_a2[1] = -5993.5; 
   id->vel_a2[2] =  0.0;
   id->vel_a2[3] =  0.0; 
   // MUSIC 3 velocity correction 
   //   id->vel_a3[0] =  10316.0;
   //   id->vel_a3[1] = -21710.0; 
   //   id->vel_a3[2] =  12283.0;
   //   id->vel_a3[3] =      0.0;  
   //      id->vel_a3[0] =  12568;
   //      id->vel_a3[1] = -32076.5; 
   //      id->vel_a3[2] =  21729.8;
   //      id->vel_a3[3] =      0.0;  
   id->vel_a3[0] =  7199.5; // update 14.08.11
   id->vel_a3[1] = -4921.3; 
   id->vel_a3[2] =  0.0;
   id->vel_a3[3] =  0.0;     


   //Si
	si->si_factor1=1.;
	si->si_offset1=0.;
	si->si_factor2=1.;
	si->si_offset2=0.;
	
	//DSSD from quick calibration at 3AM the 
	//8-10-2011 no dead layer of complex fit
	//considered
si->dssd_factor[0]=5.948748738;
si->dssd_factor[1]=5.840863356;
si->dssd_factor[2]=5.841564766;
si->dssd_factor[3]=5.841564766;
si->dssd_factor[4]=6.11687233;
si->dssd_factor[5]=5.686452672;
si->dssd_factor[6]=6.003051341;
si->dssd_factor[7]=5.894468929;
si->dssd_factor[8]=5.88325057;
si->dssd_factor[9]=5.77742419;
si->dssd_factor[10]=5.667636417;
si->dssd_factor[11]=6.031290555;
si->dssd_factor[12]=6.031169649;
si->dssd_factor[13]=5.878108431;
si->dssd_factor[14]=5.748337043;
si->dssd_factor[15]=5.90527091;


si->dssd_factor[16]=5.599428485;
si->dssd_factor[17]=5.738174794;
si->dssd_factor[18]=5.814969305;
si->dssd_factor[19]=5.768465172;
si->dssd_factor[20]=5.789223084;
si->dssd_factor[21]=5.637205262;
si->dssd_factor[22]=6.059133776;
si->dssd_factor[23]=5.810083112;
si->dssd_factor[24]=5.878316526;
si->dssd_factor[25]=5.824912923;
si->dssd_factor[26]=6.059133776;
si->dssd_factor[27]=6.076085315;
si->dssd_factor[28]=5.851748088;
si->dssd_factor[29]=6.00921249;
si->dssd_factor[30]=6.342133463;
si->dssd_factor[31]=5.773846386; 

	
si->dssd_offset[0]=-345.2575132;
si->dssd_offset[1]=-422.5795196;
si->dssd_offset[2]=-403.8167623;
si->dssd_offset[3]=-339.5595498;
si->dssd_offset[4]=-269.3656146;
si->dssd_offset[5]=-463.6006769;
si->dssd_offset[6]=-313.4127368;
si->dssd_offset[7]=-502.3174526;
si->dssd_offset[8]=-359.5344824;
si->dssd_offset[9]=-396.5735229;
si->dssd_offset[10]=-339.2627942;
si->dssd_offset[11]=-513.5746936;
si->dssd_offset[12]=-383.9853844;
si->dssd_offset[13]=-334.4427696;
si->dssd_offset[14]=-292.2460598;
si->dssd_offset[15]=-336.5206218;
	
si->dssd_offset[16]=-344.6052435;
si->dssd_offset[17]=-202.0851624;
si->dssd_offset[18]=-455.519489;
si->dssd_offset[19]=-517.8241382;
si->dssd_offset[20]=-366.5117228;
si->dssd_offset[21]=-437.2838188;
si->dssd_offset[22]=-340.2942252;
si->dssd_offset[23]=-513.8597776;
si->dssd_offset[24]=-473.5729145;
si->dssd_offset[25]=-405.8711404;
si->dssd_offset[26]=-328.1759576;
si->dssd_offset[27]=-360.0277692;
si->dssd_offset[28]=-344.6374124;
si->dssd_offset[29]=-460.978433;
si->dssd_offset[30]=-965.3023538;
si->dssd_offset[31]=-501.6735231;




    cout << "Focus distance S4: " << frs->dist_focS4 << endl;
    cout << "Setup done " << endl;


}
    


void ReadDTDXTable(TMWDCParameter* mwdc, char* name_settingfile){
  // Pupose : read dtdx tables 
  cout << endl;
  cout << "------- Read DT-DX Table --------" <<endl;
  
  // file open
  ifstream ifs(name_settingfile);
  string str;
  if(ifs.fail()) {
    cerr << "Input file does not exist. \n";
    exit(0);
  }

  // read
  int i_plane,n_point,tdc_max,tdc_min;
  for(int i=0; i<16; i++){
    // 
    ifs >> i_plane >>  n_point >> tdc_max >> tdc_min ;
    cout << "Plane(i="<< i_plane<< ") : n_point="<< n_point <<", tdc_max="<< tdc_max << ", tdc_min="<< tdc_min;
    (mwdc->dt0[i_plane])   = tdc_max;
    (mwdc->dtmin[i_plane]) = tdc_min;
    //
    for(int j=0; j<n_point; j++){
      ifs >> (mwdc->dtdx_table[i_plane][j]) ;
      if(0==j){cout << ", first_x=" << (mwdc->dtdx_table[i_plane][j]); }
      if(j==n_point-1){ cout << ", .... last_x=" <<(mwdc->dtdx_table[i_plane][j]) << endl; }
    }
    if(0==n_point){
      cout << ", No value in this plane..." << endl;
    }
  }
  cout << endl;
  cout << "------- Read DT-DX Table done !  --------" << endl <<endl;;
 
  return;
}



void ReadAMSCSetting(TMWDCParameter* mwdc, char* name_settingfile){
  // Pupose : fill these values 
  //  mwdc->plane_num[i_amsc_daq][i_amsc_group]
  //  mwdc->wire_group[i_amsc_daq][i_amsc_group]

  // 
  for(int i_amsc_daq=0;i_amsc_daq<16;i_amsc_daq++){
    for(int i_amsc_group=0;i_amsc_group<4;i_amsc_group++){
      mwdc->plane_num[i_amsc_daq][i_amsc_group]=-999;//
      mwdc->wire_group[i_amsc_daq][i_amsc_group]=-999;//
    }
  }

  string str;
  string str_begin = "AMSC_SETTING_BEGIN";
  string str_end   = "AMSC_SETTING_END";
  cout << endl;
  cout << "------- Read AMSC setting --------" <<endl;

  // file open
  ifstream ifs(name_settingfile);
  if(ifs.fail()) {
    cerr << "Input file does not exist. \n";
	exit(0);
  }

  // search BEGIN word
  getline(ifs, str);
  while(string::npos == str.find(str_begin,0) && (!ifs.eof())){ // npos== >> found 
    getline(ifs, str);
    printf(".");
  }
  if(ifs.eof()){
     cout << " BEGIN position not found. exiting..."<< endl;
     exit(0);
  }else{
    cout << "BEGIN position found. OK!"<< endl;  
  }

  // Read contents
  getline(ifs, str);// ignore 1st line.
  getline(ifs, str);// ignore 2nd line.
  for(int i_line=0;i_line<48;i_line++){
    int i_plane_order, i_wire_group, i_amsc_daq, i_amsc_geo, i_amsc_group;
    char c_mwdc[16], c_plane[64];
	ifs >> i_plane_order >> c_mwdc >> c_plane >> i_wire_group >> i_amsc_daq >> i_amsc_geo >> i_amsc_group ;
	//
	if(0 <= i_amsc_daq && i_amsc_daq<16 && 0<= i_amsc_group && i_amsc_group <4){
	  mwdc->plane_num[i_amsc_daq][i_amsc_group] = i_plane_order;
	  mwdc->wire_group[i_amsc_daq][i_amsc_group]= i_wire_group ;
	  cout  << i_plane_order << "\t" << c_mwdc << "\t" << c_plane<< "\t"  <<  i_wire_group<< "\t"  << i_amsc_daq << "\t" << i_amsc_geo << "\t" << i_amsc_group <<endl ;
	}else{
	  cout <<"("<< i_plane_order <<"\t"<< c_mwdc <<"\t"<< c_plane<<"\t"<< i_wire_group<<"\t"<< i_amsc_daq <<"\t"<< i_amsc_geo << "\t" << i_amsc_group << ")"<<endl ;
	}
  }
  
  // Check END word
  getline(ifs, str); // 
  getline(ifs, str);
  if(string::npos == str.find(str_end,0)){
	cout << "could not reach END position. exiting..."<< endl;
	exit(0);
  }else{
	cout << "reached END position. OK!"<< endl;
	cout << "------- Read AMSC setting done !  --------" << endl <<endl;;
  }
 
  return;
}


void ReadV830Setting(TMWDCParameter* mwdc, char* name_settingfile){
 
  string str;
  string str_begin = "V830_SETTING_BEGIN";
  string str_end   = "V830_SETTING_END";
  cout << endl;
  cout << "------- Read V830 setting --------" <<endl;

  // file open
  ifstream ifs(name_settingfile);
  if(ifs.fail()) {
    cerr << "Input file does not exist. \n";
	exit(0);
  }

  // search BEGIN word
  getline(ifs, str);
  while(string::npos == str.find(str_begin,0) && (!ifs.eof())){ // npos== >> found 
    getline(ifs, str);
  }
  if(ifs.eof()){
     cout << " BEGIN position not found. exiting..."<< endl;
     exit(0);
  }else{
    cout << "BEGIN position found. OK! : "<< str << endl;  
  }

  cout <<"   i   :   name   :  imod_rpv100 :  ich_rpv100 : check_normalization  " << endl;

  // maxcount (exactly speaking, max+1)
  // mwdc->maxcount_v830 = 0x100000000;

  // Read contents
  getline(ifs, str);// ignore 1st line.
  getline(ifs, str);// ignore 2nd line.
  mwdc->num_ch_v830 = 32;
  for(int i_line=0;i_line<32;i_line++){
    int i_v830, imod_v830_daq, ich_v830_daq, check_normalization;
    char c_name[16];
    ifs >> i_v830 >> c_name >> imod_v830_daq >> ich_v830_daq >> check_normalization;
	//
	if(0 <= i_v830 && i_v830 < 32){
	   mwdc->imod_v830[i_v830] =  imod_v830_daq;
	   mwdc->ich_v830[i_v830]  =  ich_v830_daq;
	   sprintf( mwdc->name_v830[i_v830], "%s", c_name);
	   if(1==check_normalization){
	     mwdc->i_v830_normalization = i_v830;
	   }
	   //
	   cout  << i_v830 << "\t" << c_name << "\t" << imod_v830_daq << "\t"  <<  ich_v830_daq << "\t" ;
	   cout  << check_normalization << endl;
	}else{
	  cout << " wrong!!!: " << endl;
	   exit(-1);
	}
  }
  // Check END word
  getline(ifs, str); // 
  getline(ifs, str);
  if(string::npos == str.find(str_end,0)){ // == >> not found
	cout << "could not reach END position. exiting..."<< endl;
	exit(0);
  }else{
        cout << "reached END position. OK! : "<< str <<endl;
   	cout << "------- Read V830 setting done !  --------" << endl <<endl;;
  }
 
  return;
}




void ReadV830MHSetting(TMWDCParameter* mwdc, char* name_settingfile){
 
  string str;
  string str_begin = "V830MH_SETTING_BEGIN";
  string str_end   = "V830MH_SETTING_END";
  cout << endl;
  cout << "------- Read V830MH setting --------" <<endl;

  // file open
  ifstream ifs(name_settingfile);
  if(ifs.fail()) {
    cerr << "Input file does not exist. \n";
	exit(0);
  }

  // search BEGIN word
  getline(ifs, str);
  while(string::npos == str.find(str_begin,0) && (!ifs.eof())){ // npos== >> found 
    getline(ifs, str);
  }
  if(ifs.eof()){
     cout << " BEGIN position not found. exiting..."<< endl;
     exit(0);
  }else{
    cout << "BEGIN position found. OK! : "<< str << endl;  
  }

  cout <<"   i   :   name   :  imod_rpv100 :  ich_rpv100 : check_normalization  " << endl;

  // Read contents
  getline(ifs, str);// ignore 1st line.
  getline(ifs, str);// ignore 2nd line.
  mwdc->num_ch_v830 = 32;
  for(int i_line=0;i_line<32;i_line++){
    int i_v830, imod_v830_daq, ich_v830_daq, check_normalization;
    char c_name[16];
    ifs >> i_v830 >> c_name >> imod_v830_daq >> ich_v830_daq >> check_normalization;
	//
	if(0 <= i_v830 && i_v830 < 32){
	   mwdc->imod_v830_mh[i_v830] =  imod_v830_daq;
	   mwdc->ich_v830_mh[i_v830]  =  ich_v830_daq;
	   sprintf( mwdc->name_v830_mh[i_v830], "%s", c_name);
	   //
	   cout  << i_v830 << "\t" << c_name << "\t" << imod_v830_daq << "\t"  <<  ich_v830_daq << "\t" ;
	   cout  << check_normalization << endl;
	}else{
	  cout << " wrong!!!: " << endl;
	   exit(-1);
	}
  }
  // Check END word
  getline(ifs, str); // 
  getline(ifs, str);
  if(string::npos == str.find(str_end,0)){ // == >> not found
	cout << "could not reach END position. exiting..."<< endl;
	exit(0);
  }else{
        cout << "reached END position. OK! : "<< str <<endl;
   	cout << "------- Read V830MH setting done !  --------" << endl <<endl;;
  }
 
  return;
}




void ReadSCISetting(TMWDCParameter* mwdc, char* name_settingfile){
 
  string str;
  string str_begin = "SCI_SETTING_BEGIN";
  string str_end   = "SCI_SETTING_END";
  cout << endl;
  cout << "------- Read SCI setting --------" <<endl;

  // file open
  ifstream ifs(name_settingfile);
  if(ifs.fail()) {
    cerr << "Input file does not exist. \n";
	exit(0);
  }

  // search BEGIN word
  getline(ifs, str);
  while(string::npos == str.find(str_begin,0) && (!ifs.eof())){ // npos== >> found 
    getline(ifs, str);
  }
  if(ifs.eof()){
     cout << " BEGIN position not found. exiting..."<< endl;
     exit(0);
  }else{
    cout << "BEGIN position found. OK! : "<< str << endl;  
  }

  cout <<"i_sci :  i_lr_sci  :  name : imod_v1742 : ich_v1742 : imod_v792 : ich_v792 : imod_v1290 : ich_v1290 " << endl;

  // Read contents
  getline(ifs, str);// ignore 1st line.
  getline(ifs, str);// ignore 2nd line.
  for(int i_line=0;i_line<20;i_line++){
    int i_sci, i_lr_sci, imod_v1742_daq, ich_v1742, imod_v792_daq, ich_v792, imod_v1290_daq, ich_v1290, imod_v775_daq, ich_v775;
    int imod_v830_daq, ich_v830, imod_v820_daq, ich_v820;
    char c_name[16];
    ifs >> i_sci >> i_lr_sci >> c_name >> imod_v1742_daq >> ich_v1742 >>  imod_v792_daq >> ich_v792 >>  imod_v1290_daq >> ich_v1290;
	//
	if(0 <= i_sci && i_sci < 16 && 0 <= i_lr_sci && i_lr_sci <2){
	   mwdc->imod_v1742_sci[i_sci][i_lr_sci] =  imod_v1742_daq;
	   mwdc->ich_v1742_sci[i_sci][i_lr_sci]  =  ich_v1742;
	   mwdc->imod_v792_sci[i_sci][i_lr_sci]  =  imod_v792_daq;
	   mwdc->ich_v792_sci[i_sci][i_lr_sci]   =  ich_v792;
	   mwdc->imod_v1290_sci[i_sci][i_lr_sci] =  imod_v1290_daq;
	   mwdc->ich_v1290_sci[i_sci][i_lr_sci]  =  ich_v1290;
	   //
	   cout  << i_sci << "\t" << i_lr_sci << "\t" << c_name << "\t" << imod_v1742_daq << "\t"  <<  ich_v1742 << "\t" ;
	   cout  << imod_v792_daq << "\t" << ich_v792 << "\t" << imod_v1290_daq << "\t" << ich_v1290  <<endl ;
	}else{
	  cout << "i_sci, i_lr_sci wrong!!!: " << i_sci << i_lr_sci << endl;
	   exit(-1);
	}
  }
  // Check END word
  getline(ifs, str); // 
  getline(ifs, str);
  if(string::npos == str.find(str_end,0)){ // == >> not found
	cout << "could not reach END position. exiting..."<< endl;
	exit(0);
  }else{
        cout << "reached END position. OK! : "<< str <<endl;
   	cout << "------- Read SCI setting done !  --------" << endl <<endl;;
  }
 
  return;
}




void ReadV1290Setting(TMWDCParameter* mwdc, char* name_settingfile){
 
  string str;
  string str_begin = "V1290_OTHER_SETTING_BEGIN";
  string str_end   = "V1290_OTHER_SETTING_END";
  cout << endl;
  cout << "------- Read V1290 Other setting --------" <<endl;

  // file open
  ifstream ifs(name_settingfile);
  if(ifs.fail()) {
    cerr << "Input file does not exist. \n";
	exit(0);
  }

  // search BEGIN word
  getline(ifs, str);
  while(string::npos == str.find(str_begin,0) && (!ifs.eof())){ // npos== >> found 
    getline(ifs, str);
  }
  if(ifs.eof()){
     cout << " BEGIN position not found. exiting..."<< endl;
     exit(0);
  }else{
    cout << "BEGIN position found. OK! : "<< str << endl;  
  }

  cout <<"   i   :   name   :  imod_v1290 : ich_v1290 : check_T0  " << endl;

  // Read contents
  getline(ifs, str);// ignore 1st line.
  getline(ifs, str);// ignore 2nd line.
  mwdc->num_ch_v1290_other =0;
  // mwdc->num_ch_v1290_other = 8;
  for(int i_line=0;i_line<8;i_line++){
    int i_v1290_other, imod_v1290_other_daq, ich_v1290_other_daq, check_t0;
    char c_name[16];
    ifs >> i_v1290_other >> c_name >> imod_v1290_other_daq >> ich_v1290_other_daq >> check_t0;
	//
	if(0 <= i_v1290_other && i_v1290_other < 16){
	   mwdc->imod_v1290_other[i_v1290_other] =  imod_v1290_other_daq;
	   mwdc->ich_v1290_other[i_v1290_other]  =  ich_v1290_other_daq;
	   sprintf((mwdc->name_v1290_other[i_v1290_other]),"%s",c_name);
	   if(1==check_t0){ // T0 for imod=1
	     mwdc->i_T0_v1290[1] = i_v1290_other;
	   }
	   if(0==check_t0){ // T0 for imod=0
	     mwdc->i_T0_v1290[0] = i_v1290_other;
	   }
	   //
	   cout  << i_v1290_other << "\t" << c_name << "\t" << imod_v1290_other_daq << "\t"  <<  ich_v1290_other_daq << "\t" ;
	   cout  << check_t0 << endl;
	}else{
	  cout << " wrong!!!: " << endl;
	   exit(-1);
	}
  }
  // Check END word
  getline(ifs, str); // 
  getline(ifs, str);
  if(string::npos == str.find(str_end,0)){ // == >> not found
	cout << "could not reach END position. exiting..."<< endl;
	exit(0);
  }else{
        cout << "reached END position. OK! : "<< str <<endl;
   	cout << "------- Read V1290 other setting done !  --------" << endl <<endl;;
  }
 
  return;
}


void V1742ReadCellCorrectionTable(TMWDCParameter* mwdc, char* name_settingfile){
  
 // Pupose : read cellcorrection tables 
  cout << endl;
  cout << "------- Read V1742 Cell Cellcorrection Table --------" <<endl;
  
  // file open
  ifstream ifs(name_settingfile);
  string str;
  if(ifs.fail()) {
    cerr << "Input file does not exist. \n";
    exit(0);
  }
  
  // read
  for(int i_ch=0; i_ch <32 ; i_ch ++){
    for(int i_cell=0; i_cell <1024; i_cell++){
      int value;
      if(!ifs.eof()){
	ifs >> value;
	mwdc->v1742cellcorrection[i_ch][i_cell]  = value;
        cout << "i_ch, i_cell, value = " << i_ch <<", "<< i_cell <<", "<<value << endl;
      }else{
	cout << "V1742: read cell correction table fialed...." << endl;
	exit(0);
      }
    } 
  }
  cout << "------- Read V1742 Cell Correction Table done !  --------" << endl <<endl;
  return ;
}


void V1742ParameterInit(TMWDCParameter* mwdc){
  for(int i_ch=0; i_ch<32; i_ch++){
    mwdc->v1742q_begin[i_ch] = -1;
    mwdc->v1742q_end[i_ch]   = -1;
    mwdc->v1742baseline_begin[i_ch] = -1;
    mwdc->v1742baseline_end[i_ch]   = -1;
    mwdc->v1742t_threshold[i_ch] = -1;
    mwdc->v1742valid_threshold[i_ch] =-1;
  }
  return ;
}
