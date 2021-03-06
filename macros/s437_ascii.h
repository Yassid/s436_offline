//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul 30 12:40:39 2014 by ROOT version 5.34/03
// from TTree CalibrxTree/Go4FileStore
// found on file: pd14Jul0230_CAL.root
//////////////////////////////////////////////////////////

#ifndef s437_ascii_h
#define s437_ascii_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "/home/daq/Desktop/s436/offline/s437_pro_30072014/TFRSCalibrEvent.h"
#include <TObject.h>
#include <TNamed.h>
//#include "./Go4Event/TGo4EventElement.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxFRSCalibrEvent = 1;

class s437_ascii {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //TFRSCalibrEvent *FRSCalibrEvent_;
   UInt_t          FRSCalibrEvent_TGo4EventElement_fUniqueID;
   UInt_t          FRSCalibrEvent_TGo4EventElement_fBits;
   TString         FRSCalibrEvent_TGo4EventElement_fName;
   TString         FRSCalibrEvent_TGo4EventElement_fTitle;
   Bool_t          FRSCalibrEvent_TGo4EventElement_fbIsValid;
   Short_t         FRSCalibrEvent_TGo4EventElement_fIdentifier;
   UInt_t          FRSCalibrEvent_freeTrig;
   UInt_t          FRSCalibrEvent_acptTrig;
   UInt_t          FRSCalibrEvent_mon_inc[64];
   Int_t           FRSCalibrEvent_seconds;
   Int_t           FRSCalibrEvent_tenthsecs;
   Int_t           FRSCalibrEvent_hundrethsecs;
   Int_t           FRSCalibrEvent_extraction_cycle;
   Int_t           FRSCalibrEvent_coin[16];
   Float_t         FRSCalibrEvent_seetram;
   Float_t         FRSCalibrEvent_mw_xsum[13];
   Float_t         FRSCalibrEvent_mw_ysum[13];
   Float_t         FRSCalibrEvent_mw_x[13];
   Float_t         FRSCalibrEvent_mw_y[13];
   Float_t         FRSCalibrEvent_mw_wire[13];
   Float_t         FRSCalibrEvent_z_x_s2;
   Float_t         FRSCalibrEvent_z_y_s2;
   Float_t         FRSCalibrEvent_z_x_s4;
   Float_t         FRSCalibrEvent_z_y_s4;
   Float_t         FRSCalibrEvent_z_x_s8;
   Float_t         FRSCalibrEvent_z_y_s8;
   Bool_t          FRSCalibrEvent_b_mw_xsum[13];
   Bool_t          FRSCalibrEvent_b_mw_ysum[13];
   Float_t         FRSCalibrEvent_focx_s2;
   Float_t         FRSCalibrEvent_focy_s2;
   Float_t         FRSCalibrEvent_focx_s4;
   Float_t         FRSCalibrEvent_focy_s4;
   Float_t         FRSCalibrEvent_focx_s8;
   Float_t         FRSCalibrEvent_focy_s8;
   Float_t         FRSCalibrEvent_angle_x_s2;
   Float_t         FRSCalibrEvent_angle_y_s2;
   Float_t         FRSCalibrEvent_angle_x_s4;
   Float_t         FRSCalibrEvent_angle_y_s4;
   Float_t         FRSCalibrEvent_angle_x_s8;
   Float_t         FRSCalibrEvent_angle_y_s8;
   Int_t           FRSCalibrEvent_tpc_csum[6][4];
   Float_t         FRSCalibrEvent_tpc_x[6];
   Float_t         FRSCalibrEvent_tpc_y[6];
   Bool_t          FRSCalibrEvent_b_tpc_csum[6][4];
   Bool_t          FRSCalibrEvent_b_tpc_xy[6];
   Float_t         FRSCalibrEvent_tpc_x_s2_foc;
   Float_t         FRSCalibrEvent_tpc_y_s2_foc;
   Float_t         FRSCalibrEvent_tpc_angle_x_s2_foc;
   Float_t         FRSCalibrEvent_tpc_angle_y_s2_foc;
   Float_t         FRSCalibrEvent_tpc_x_s4;
   Float_t         FRSCalibrEvent_tpc_y_s4;
   Float_t         FRSCalibrEvent_tpc_angle_x_s4;
   Float_t         FRSCalibrEvent_tpc_angle_y_s4;
   Float_t         FRSCalibrEvent_tpc_x_s4_target1;
   Float_t         FRSCalibrEvent_tpc_y_s4_target1;
   Float_t         FRSCalibrEvent_tpc_x_s4_target2;
   Float_t         FRSCalibrEvent_tpc_y_s4_target2;
   Float_t         FRSCalibrEvent_tpc_angle_x_s4_target2;
   Float_t         FRSCalibrEvent_tpc_angle_y_s4_target2;
   Float_t         FRSCalibrEvent_tpc_sc21_x;
   Float_t         FRSCalibrEvent_tpc_sc41_x;
   Float_t         FRSCalibrEvent_tpc_sc21_y;
   Float_t         FRSCalibrEvent_tpc_sc41_y;
   Float_t         FRSCalibrEvent_sc21_x;
   Float_t         FRSCalibrEvent_sc22_x;
   Float_t         FRSCalibrEvent_sc41_x;
   Float_t         FRSCalibrEvent_itag_stopper_x;
   Float_t         FRSCalibrEvent_sc42_x;
   Float_t         FRSCalibrEvent_sc43_x;
   Float_t         FRSCalibrEvent_sc21_y;
   Float_t         FRSCalibrEvent_sc41_y;
   Float_t         FRSCalibrEvent_sc42_y;
   Float_t         FRSCalibrEvent_sc43_y;
   Float_t         FRSCalibrEvent_sc81_x;
   Float_t         FRSCalibrEvent_music1_x1;
   Float_t         FRSCalibrEvent_music1_x2;
   Float_t         FRSCalibrEvent_music1_x3;
   Float_t         FRSCalibrEvent_music1_x4;
   Float_t         FRSCalibrEvent_music2_x;
   Int_t           FRSCalibrEvent_etap_scaler[64];
   Int_t           FRSCalibrEvent_etap_scaler_increase[64];
   Float_t         FRSCalibrEvent_etap_scaler_normalized[64];
   Int_t           FRSCalibrEvent_mh_scaler[64];
   Int_t           FRSCalibrEvent_mh_scaler_increase[64];
   Float_t         FRSCalibrEvent_mh_scaler_normalized[64];
   Int_t           FRSCalibrEvent_mwdc_numhit[16];
   Float_t         FRSCalibrEvent_mwdc_tot[16][64];
   Float_t         FRSCalibrEvent_mwdc_time[16][64];
   Float_t         FRSCalibrEvent_mwdc_time_wMaxToT[16];
   Int_t           FRSCalibrEvent_mwdc_wireid[16][64];
   Float_t         FRSCalibrEvent_mwdc_wirepos[16][64];
   Float_t         FRSCalibrEvent_mwdc_length[16][64];
   Int_t           FRSCalibrEvent_mwdc_numtrack;
   Int_t           FRSCalibrEvent_mwdc_numtrack_estimate[2];
   Float_t         FRSCalibrEvent_mwdc_chi2;
   Float_t         FRSCalibrEvent_mwdc_x;
   Float_t         FRSCalibrEvent_mwdc_y;
   Float_t         FRSCalibrEvent_mwdc_a;
   Float_t         FRSCalibrEvent_mwdc_b;
   Float_t         FRSCalibrEvent_mwdc_res[16];
   Float_t         FRSCalibrEvent_mwdc_res_ex[16];
   Float_t         FRSCalibrEvent_mwdc_chi2_test[2];
   Float_t         FRSCalibrEvent_mwdc_x_test[2];
   Float_t         FRSCalibrEvent_mwdc_y_test[2];
   Float_t         FRSCalibrEvent_mwdc_a_test[2];
   Float_t         FRSCalibrEvent_mwdc_b_test[2];
   Float_t         FRSCalibrEvent_mwdc_res_test[2][8];
   Float_t         FRSCalibrEvent_focal_plane;
   Int_t           FRSCalibrEvent_qdcvalid;
   Float_t         FRSCalibrEvent_sci_qdc[16][2];
   Float_t         FRSCalibrEvent_sci_tdc[16][2];
   Int_t           FRSCalibrEvent_sci_ml[16][2];
   Int_t           FRSCalibrEvent_sci_mt[16][2];
   Float_t         FRSCalibrEvent_sci_t0_tdc[16][2];
   Float_t         FRSCalibrEvent_sci_time[16][2];
   Float_t         FRSCalibrEvent_sci_timeave[16];
   Float_t         FRSCalibrEvent_sci_timedif[16];
   Float_t         FRSCalibrEvent_sci_de[16];
   Float_t         FRSCalibrEvent_tof_21l_41l;
   Float_t         FRSCalibrEvent_tof_21r_41r;
   Float_t         FRSCalibrEvent_tof_21_41;
   Float_t         FRSCalibrEvent_tof_41l_42l;
   Float_t         FRSCalibrEvent_tof_41r_42r;
   Float_t         FRSCalibrEvent_tof_41_42;
   Float_t         FRSCalibrEvent_mini_qdc[2];
   Float_t         FRSCalibrEvent_mini_tdc[2];
   Float_t         FRSCalibrEvent_mini_time[2];
   Float_t         FRSCalibrEvent_mini_pe[2];
   Float_t         FRSCalibrEvent_mini_pesum;
   Int_t           FRSCalibrEvent_mini_numhit;
   Float_t         FRSCalibrEvent_hirac_qdc_raw[8];
   Float_t         FRSCalibrEvent_hirac_qdc_base[8];
   Float_t         FRSCalibrEvent_hirac_qdc_cor[8];
   Float_t         FRSCalibrEvent_hirac_pe[8];
   Float_t         FRSCalibrEvent_hirac_tdc_raw[8];
   Float_t         FRSCalibrEvent_hirac_tdc_t0cor[8];
   Float_t         FRSCalibrEvent_hirac_tdc_cor[8];
   Float_t         FRSCalibrEvent_hirac_pesum;
   Float_t         FRSCalibrEvent_hirac_x;
   Int_t           FRSCalibrEvent_hirac_numhit;
   Float_t         FRSCalibrEvent_torch_qdc[6];
   Float_t         FRSCalibrEvent_torch_tdc[6];
   Float_t         FRSCalibrEvent_torch_time[6];
   Float_t         FRSCalibrEvent_torch_pe[6];
   Float_t         FRSCalibrEvent_torch_pesum;
   Float_t         FRSCalibrEvent_torch_x;
   Int_t           FRSCalibrEvent_torch_numhit;
   Bool_t          FRSCalibrEvent_b_pi[5];

   // List of branches
   TBranch        *b_FRSCalibrEvent_TGo4EventElement_fUniqueID;   //!
   TBranch        *b_FRSCalibrEvent_TGo4EventElement_fBits;   //!
   TBranch        *b_FRSCalibrEvent_TGo4EventElement_fName;   //!
   TBranch        *b_FRSCalibrEvent_TGo4EventElement_fTitle;   //!
   TBranch        *b_FRSCalibrEvent_TGo4EventElement_fbIsValid;   //!
   TBranch        *b_FRSCalibrEvent_TGo4EventElement_fIdentifier;   //!
   TBranch        *b_FRSCalibrEvent_freeTrig;   //!
   TBranch        *b_FRSCalibrEvent_acptTrig;   //!
   TBranch        *b_FRSCalibrEvent_mon_inc;   //!
   TBranch        *b_FRSCalibrEvent_seconds;   //!
   TBranch        *b_FRSCalibrEvent_tenthsecs;   //!
   TBranch        *b_FRSCalibrEvent_hundrethsecs;   //!
   TBranch        *b_FRSCalibrEvent_extraction_cycle;   //!
   TBranch        *b_FRSCalibrEvent_coin;   //!
   TBranch        *b_FRSCalibrEvent_seetram;   //!
   TBranch        *b_FRSCalibrEvent_mw_xsum;   //!
   TBranch        *b_FRSCalibrEvent_mw_ysum;   //!
   TBranch        *b_FRSCalibrEvent_mw_x;   //!
   TBranch        *b_FRSCalibrEvent_mw_y;   //!
   TBranch        *b_FRSCalibrEvent_mw_wire;   //!
   TBranch        *b_FRSCalibrEvent_z_x_s2;   //!
   TBranch        *b_FRSCalibrEvent_z_y_s2;   //!
   TBranch        *b_FRSCalibrEvent_z_x_s4;   //!
   TBranch        *b_FRSCalibrEvent_z_y_s4;   //!
   TBranch        *b_FRSCalibrEvent_z_x_s8;   //!
   TBranch        *b_FRSCalibrEvent_z_y_s8;   //!
   TBranch        *b_FRSCalibrEvent_b_mw_xsum;   //!
   TBranch        *b_FRSCalibrEvent_b_mw_ysum;   //!
   TBranch        *b_FRSCalibrEvent_focx_s2;   //!
   TBranch        *b_FRSCalibrEvent_focy_s2;   //!
   TBranch        *b_FRSCalibrEvent_focx_s4;   //!
   TBranch        *b_FRSCalibrEvent_focy_s4;   //!
   TBranch        *b_FRSCalibrEvent_focx_s8;   //!
   TBranch        *b_FRSCalibrEvent_focy_s8;   //!
   TBranch        *b_FRSCalibrEvent_angle_x_s2;   //!
   TBranch        *b_FRSCalibrEvent_angle_y_s2;   //!
   TBranch        *b_FRSCalibrEvent_angle_x_s4;   //!
   TBranch        *b_FRSCalibrEvent_angle_y_s4;   //!
   TBranch        *b_FRSCalibrEvent_angle_x_s8;   //!
   TBranch        *b_FRSCalibrEvent_angle_y_s8;   //!
   TBranch        *b_FRSCalibrEvent_tpc_csum;   //!
   TBranch        *b_FRSCalibrEvent_tpc_x;   //!
   TBranch        *b_FRSCalibrEvent_tpc_y;   //!
   TBranch        *b_FRSCalibrEvent_b_tpc_csum;   //!
   TBranch        *b_FRSCalibrEvent_b_tpc_xy;   //!
   TBranch        *b_FRSCalibrEvent_tpc_x_s2_foc;   //!
   TBranch        *b_FRSCalibrEvent_tpc_y_s2_foc;   //!
   TBranch        *b_FRSCalibrEvent_tpc_angle_x_s2_foc;   //!
   TBranch        *b_FRSCalibrEvent_tpc_angle_y_s2_foc;   //!
   TBranch        *b_FRSCalibrEvent_tpc_x_s4;   //!
   TBranch        *b_FRSCalibrEvent_tpc_y_s4;   //!
   TBranch        *b_FRSCalibrEvent_tpc_angle_x_s4;   //!
   TBranch        *b_FRSCalibrEvent_tpc_angle_y_s4;   //!
   TBranch        *b_FRSCalibrEvent_tpc_x_s4_target1;   //!
   TBranch        *b_FRSCalibrEvent_tpc_y_s4_target1;   //!
   TBranch        *b_FRSCalibrEvent_tpc_x_s4_target2;   //!
   TBranch        *b_FRSCalibrEvent_tpc_y_s4_target2;   //!
   TBranch        *b_FRSCalibrEvent_tpc_angle_x_s4_target2;   //!
   TBranch        *b_FRSCalibrEvent_tpc_angle_y_s4_target2;   //!
   TBranch        *b_FRSCalibrEvent_tpc_sc21_x;   //!
   TBranch        *b_FRSCalibrEvent_tpc_sc41_x;   //!
   TBranch        *b_FRSCalibrEvent_tpc_sc21_y;   //!
   TBranch        *b_FRSCalibrEvent_tpc_sc41_y;   //!
   TBranch        *b_FRSCalibrEvent_sc21_x;   //!
   TBranch        *b_FRSCalibrEvent_sc22_x;   //!
   TBranch        *b_FRSCalibrEvent_sc41_x;   //!
   TBranch        *b_FRSCalibrEvent_itag_stopper_x;   //!
   TBranch        *b_FRSCalibrEvent_sc42_x;   //!
   TBranch        *b_FRSCalibrEvent_sc43_x;   //!
   TBranch        *b_FRSCalibrEvent_sc21_y;   //!
   TBranch        *b_FRSCalibrEvent_sc41_y;   //!
   TBranch        *b_FRSCalibrEvent_sc42_y;   //!
   TBranch        *b_FRSCalibrEvent_sc43_y;   //!
   TBranch        *b_FRSCalibrEvent_sc81_x;   //!
   TBranch        *b_FRSCalibrEvent_music1_x1;   //!
   TBranch        *b_FRSCalibrEvent_music1_x2;   //!
   TBranch        *b_FRSCalibrEvent_music1_x3;   //!
   TBranch        *b_FRSCalibrEvent_music1_x4;   //!
   TBranch        *b_FRSCalibrEvent_music2_x;   //!
   TBranch        *b_FRSCalibrEvent_etap_scaler;   //!
   TBranch        *b_FRSCalibrEvent_etap_scaler_increase;   //!
   TBranch        *b_FRSCalibrEvent_etap_scaler_normalized;   //!
   TBranch        *b_FRSCalibrEvent_mh_scaler;   //!
   TBranch        *b_FRSCalibrEvent_mh_scaler_increase;   //!
   TBranch        *b_FRSCalibrEvent_mh_scaler_normalized;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_numhit;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_tot;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_time;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_time_wMaxToT;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_wireid;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_wirepos;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_length;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_numtrack;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_numtrack_estimate;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_chi2;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_x;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_y;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_a;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_b;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_res;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_res_ex;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_chi2_test;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_x_test;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_y_test;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_a_test;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_b_test;   //!
   TBranch        *b_FRSCalibrEvent_mwdc_res_test;   //!
   TBranch        *b_FRSCalibrEvent_focal_plane;   //!
   TBranch        *b_FRSCalibrEvent_qdcvalid;   //!
   TBranch        *b_FRSCalibrEvent_sci_qdc;   //!
   TBranch        *b_FRSCalibrEvent_sci_tdc;   //!
   TBranch        *b_FRSCalibrEvent_sci_ml;   //!
   TBranch        *b_FRSCalibrEvent_sci_mt;   //!
   TBranch        *b_FRSCalibrEvent_sci_t0_tdc;   //!
   TBranch        *b_FRSCalibrEvent_sci_time;   //!
   TBranch        *b_FRSCalibrEvent_sci_timeave;   //!
   TBranch        *b_FRSCalibrEvent_sci_timedif;   //!
   TBranch        *b_FRSCalibrEvent_sci_de;   //!
   TBranch        *b_FRSCalibrEvent_tof_21l_41l;   //!
   TBranch        *b_FRSCalibrEvent_tof_21r_41r;   //!
   TBranch        *b_FRSCalibrEvent_tof_21_41;   //!
   TBranch        *b_FRSCalibrEvent_tof_41l_42l;   //!
   TBranch        *b_FRSCalibrEvent_tof_41r_42r;   //!
   TBranch        *b_FRSCalibrEvent_tof_41_42;   //!
   TBranch        *b_FRSCalibrEvent_mini_qdc;   //!
   TBranch        *b_FRSCalibrEvent_mini_tdc;   //!
   TBranch        *b_FRSCalibrEvent_mini_time;   //!
   TBranch        *b_FRSCalibrEvent_mini_pe;   //!
   TBranch        *b_FRSCalibrEvent_mini_pesum;   //!
   TBranch        *b_FRSCalibrEvent_mini_numhit;   //!
   TBranch        *b_FRSCalibrEvent_hirac_qdc_raw;   //!
   TBranch        *b_FRSCalibrEvent_hirac_qdc_base;   //!
   TBranch        *b_FRSCalibrEvent_hirac_qdc_cor;   //!
   TBranch        *b_FRSCalibrEvent_hirac_pe;   //!
   TBranch        *b_FRSCalibrEvent_hirac_tdc_raw;   //!
   TBranch        *b_FRSCalibrEvent_hirac_tdc_t0cor;   //!
   TBranch        *b_FRSCalibrEvent_hirac_tdc_cor;   //!
   TBranch        *b_FRSCalibrEvent_hirac_pesum;   //!
   TBranch        *b_FRSCalibrEvent_hirac_x;   //!
   TBranch        *b_FRSCalibrEvent_hirac_numhit;   //!
   TBranch        *b_FRSCalibrEvent_torch_qdc;   //!
   TBranch        *b_FRSCalibrEvent_torch_tdc;   //!
   TBranch        *b_FRSCalibrEvent_torch_time;   //!
   TBranch        *b_FRSCalibrEvent_torch_pe;   //!
   TBranch        *b_FRSCalibrEvent_torch_pesum;   //!
   TBranch        *b_FRSCalibrEvent_torch_x;   //!
   TBranch        *b_FRSCalibrEvent_torch_numhit;   //!
   TBranch        *b_FRSCalibrEvent_b_pi;   //!

   s437_ascii(TTree *tree=0);
   virtual ~s437_ascii();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef s437_ascii_cxx
s437_ascii::s437_ascii(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("pd14Jul0369_CAL.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("pd14Jul0369_CAL.root");
      }
      f->GetObject("CalibrxTree",tree);

   }
   Init(tree);
}

s437_ascii::~s437_ascii()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t s437_ascii::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t s437_ascii::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void s437_ascii::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("FRSCalibrEvent.TGo4EventElement.fUniqueID", &FRSCalibrEvent_TGo4EventElement_fUniqueID, &b_FRSCalibrEvent_TGo4EventElement_fUniqueID);
   fChain->SetBranchAddress("FRSCalibrEvent.TGo4EventElement.fBits", &FRSCalibrEvent_TGo4EventElement_fBits, &b_FRSCalibrEvent_TGo4EventElement_fBits);
   fChain->SetBranchAddress("FRSCalibrEvent.TGo4EventElement.fName", &FRSCalibrEvent_TGo4EventElement_fName, &b_FRSCalibrEvent_TGo4EventElement_fName);
   fChain->SetBranchAddress("FRSCalibrEvent.TGo4EventElement.fTitle", &FRSCalibrEvent_TGo4EventElement_fTitle, &b_FRSCalibrEvent_TGo4EventElement_fTitle);
   fChain->SetBranchAddress("FRSCalibrEvent.TGo4EventElement.fbIsValid", &FRSCalibrEvent_TGo4EventElement_fbIsValid, &b_FRSCalibrEvent_TGo4EventElement_fbIsValid);
   fChain->SetBranchAddress("FRSCalibrEvent.TGo4EventElement.fIdentifier", &FRSCalibrEvent_TGo4EventElement_fIdentifier, &b_FRSCalibrEvent_TGo4EventElement_fIdentifier);
   fChain->SetBranchAddress("FRSCalibrEvent.freeTrig", &FRSCalibrEvent_freeTrig, &b_FRSCalibrEvent_freeTrig);
   fChain->SetBranchAddress("FRSCalibrEvent.acptTrig", &FRSCalibrEvent_acptTrig, &b_FRSCalibrEvent_acptTrig);
   fChain->SetBranchAddress("FRSCalibrEvent.mon_inc[64]", FRSCalibrEvent_mon_inc, &b_FRSCalibrEvent_mon_inc);
   fChain->SetBranchAddress("FRSCalibrEvent.seconds", &FRSCalibrEvent_seconds, &b_FRSCalibrEvent_seconds);
   fChain->SetBranchAddress("FRSCalibrEvent.tenthsecs", &FRSCalibrEvent_tenthsecs, &b_FRSCalibrEvent_tenthsecs);
   fChain->SetBranchAddress("FRSCalibrEvent.hundrethsecs", &FRSCalibrEvent_hundrethsecs, &b_FRSCalibrEvent_hundrethsecs);
   fChain->SetBranchAddress("FRSCalibrEvent.extraction_cycle", &FRSCalibrEvent_extraction_cycle, &b_FRSCalibrEvent_extraction_cycle);
   fChain->SetBranchAddress("FRSCalibrEvent.coin[16]", FRSCalibrEvent_coin, &b_FRSCalibrEvent_coin);
   fChain->SetBranchAddress("FRSCalibrEvent.seetram", &FRSCalibrEvent_seetram, &b_FRSCalibrEvent_seetram);
   fChain->SetBranchAddress("FRSCalibrEvent.mw_xsum[13]", FRSCalibrEvent_mw_xsum, &b_FRSCalibrEvent_mw_xsum);
   fChain->SetBranchAddress("FRSCalibrEvent.mw_ysum[13]", FRSCalibrEvent_mw_ysum, &b_FRSCalibrEvent_mw_ysum);
   fChain->SetBranchAddress("FRSCalibrEvent.mw_x[13]", FRSCalibrEvent_mw_x, &b_FRSCalibrEvent_mw_x);
   fChain->SetBranchAddress("FRSCalibrEvent.mw_y[13]", FRSCalibrEvent_mw_y, &b_FRSCalibrEvent_mw_y);
   fChain->SetBranchAddress("FRSCalibrEvent.mw_wire[13]", FRSCalibrEvent_mw_wire, &b_FRSCalibrEvent_mw_wire);
   fChain->SetBranchAddress("FRSCalibrEvent.z_x_s2", &FRSCalibrEvent_z_x_s2, &b_FRSCalibrEvent_z_x_s2);
   fChain->SetBranchAddress("FRSCalibrEvent.z_y_s2", &FRSCalibrEvent_z_y_s2, &b_FRSCalibrEvent_z_y_s2);
   fChain->SetBranchAddress("FRSCalibrEvent.z_x_s4", &FRSCalibrEvent_z_x_s4, &b_FRSCalibrEvent_z_x_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.z_y_s4", &FRSCalibrEvent_z_y_s4, &b_FRSCalibrEvent_z_y_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.z_x_s8", &FRSCalibrEvent_z_x_s8, &b_FRSCalibrEvent_z_x_s8);
   fChain->SetBranchAddress("FRSCalibrEvent.z_y_s8", &FRSCalibrEvent_z_y_s8, &b_FRSCalibrEvent_z_y_s8);
   fChain->SetBranchAddress("FRSCalibrEvent.b_mw_xsum[13]", FRSCalibrEvent_b_mw_xsum, &b_FRSCalibrEvent_b_mw_xsum);
   fChain->SetBranchAddress("FRSCalibrEvent.b_mw_ysum[13]", FRSCalibrEvent_b_mw_ysum, &b_FRSCalibrEvent_b_mw_ysum);
   fChain->SetBranchAddress("FRSCalibrEvent.focx_s2", &FRSCalibrEvent_focx_s2, &b_FRSCalibrEvent_focx_s2);
   fChain->SetBranchAddress("FRSCalibrEvent.focy_s2", &FRSCalibrEvent_focy_s2, &b_FRSCalibrEvent_focy_s2);
   fChain->SetBranchAddress("FRSCalibrEvent.focx_s4", &FRSCalibrEvent_focx_s4, &b_FRSCalibrEvent_focx_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.focy_s4", &FRSCalibrEvent_focy_s4, &b_FRSCalibrEvent_focy_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.focx_s8", &FRSCalibrEvent_focx_s8, &b_FRSCalibrEvent_focx_s8);
   fChain->SetBranchAddress("FRSCalibrEvent.focy_s8", &FRSCalibrEvent_focy_s8, &b_FRSCalibrEvent_focy_s8);
   fChain->SetBranchAddress("FRSCalibrEvent.angle_x_s2", &FRSCalibrEvent_angle_x_s2, &b_FRSCalibrEvent_angle_x_s2);
   fChain->SetBranchAddress("FRSCalibrEvent.angle_y_s2", &FRSCalibrEvent_angle_y_s2, &b_FRSCalibrEvent_angle_y_s2);
   fChain->SetBranchAddress("FRSCalibrEvent.angle_x_s4", &FRSCalibrEvent_angle_x_s4, &b_FRSCalibrEvent_angle_x_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.angle_y_s4", &FRSCalibrEvent_angle_y_s4, &b_FRSCalibrEvent_angle_y_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.angle_x_s8", &FRSCalibrEvent_angle_x_s8, &b_FRSCalibrEvent_angle_x_s8);
   fChain->SetBranchAddress("FRSCalibrEvent.angle_y_s8", &FRSCalibrEvent_angle_y_s8, &b_FRSCalibrEvent_angle_y_s8);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_csum[6][4]", FRSCalibrEvent_tpc_csum, &b_FRSCalibrEvent_tpc_csum);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_x[6]", FRSCalibrEvent_tpc_x, &b_FRSCalibrEvent_tpc_x);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_y[6]", FRSCalibrEvent_tpc_y, &b_FRSCalibrEvent_tpc_y);
   fChain->SetBranchAddress("FRSCalibrEvent.b_tpc_csum[6][4]", FRSCalibrEvent_b_tpc_csum, &b_FRSCalibrEvent_b_tpc_csum);
   fChain->SetBranchAddress("FRSCalibrEvent.b_tpc_xy[6]", FRSCalibrEvent_b_tpc_xy, &b_FRSCalibrEvent_b_tpc_xy);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_x_s2_foc", &FRSCalibrEvent_tpc_x_s2_foc, &b_FRSCalibrEvent_tpc_x_s2_foc);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_y_s2_foc", &FRSCalibrEvent_tpc_y_s2_foc, &b_FRSCalibrEvent_tpc_y_s2_foc);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_angle_x_s2_foc", &FRSCalibrEvent_tpc_angle_x_s2_foc, &b_FRSCalibrEvent_tpc_angle_x_s2_foc);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_angle_y_s2_foc", &FRSCalibrEvent_tpc_angle_y_s2_foc, &b_FRSCalibrEvent_tpc_angle_y_s2_foc);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_x_s4", &FRSCalibrEvent_tpc_x_s4, &b_FRSCalibrEvent_tpc_x_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_y_s4", &FRSCalibrEvent_tpc_y_s4, &b_FRSCalibrEvent_tpc_y_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_angle_x_s4", &FRSCalibrEvent_tpc_angle_x_s4, &b_FRSCalibrEvent_tpc_angle_x_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_angle_y_s4", &FRSCalibrEvent_tpc_angle_y_s4, &b_FRSCalibrEvent_tpc_angle_y_s4);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_x_s4_target1", &FRSCalibrEvent_tpc_x_s4_target1, &b_FRSCalibrEvent_tpc_x_s4_target1);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_y_s4_target1", &FRSCalibrEvent_tpc_y_s4_target1, &b_FRSCalibrEvent_tpc_y_s4_target1);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_x_s4_target2", &FRSCalibrEvent_tpc_x_s4_target2, &b_FRSCalibrEvent_tpc_x_s4_target2);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_y_s4_target2", &FRSCalibrEvent_tpc_y_s4_target2, &b_FRSCalibrEvent_tpc_y_s4_target2);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_angle_x_s4_target2", &FRSCalibrEvent_tpc_angle_x_s4_target2, &b_FRSCalibrEvent_tpc_angle_x_s4_target2);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_angle_y_s4_target2", &FRSCalibrEvent_tpc_angle_y_s4_target2, &b_FRSCalibrEvent_tpc_angle_y_s4_target2);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_sc21_x", &FRSCalibrEvent_tpc_sc21_x, &b_FRSCalibrEvent_tpc_sc21_x);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_sc41_x", &FRSCalibrEvent_tpc_sc41_x, &b_FRSCalibrEvent_tpc_sc41_x);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_sc21_y", &FRSCalibrEvent_tpc_sc21_y, &b_FRSCalibrEvent_tpc_sc21_y);
   fChain->SetBranchAddress("FRSCalibrEvent.tpc_sc41_y", &FRSCalibrEvent_tpc_sc41_y, &b_FRSCalibrEvent_tpc_sc41_y);
   fChain->SetBranchAddress("FRSCalibrEvent.sc21_x", &FRSCalibrEvent_sc21_x, &b_FRSCalibrEvent_sc21_x);
   fChain->SetBranchAddress("FRSCalibrEvent.sc22_x", &FRSCalibrEvent_sc22_x, &b_FRSCalibrEvent_sc22_x);
   fChain->SetBranchAddress("FRSCalibrEvent.sc41_x", &FRSCalibrEvent_sc41_x, &b_FRSCalibrEvent_sc41_x);
   fChain->SetBranchAddress("FRSCalibrEvent.itag_stopper_x", &FRSCalibrEvent_itag_stopper_x, &b_FRSCalibrEvent_itag_stopper_x);
   fChain->SetBranchAddress("FRSCalibrEvent.sc42_x", &FRSCalibrEvent_sc42_x, &b_FRSCalibrEvent_sc42_x);
   fChain->SetBranchAddress("FRSCalibrEvent.sc43_x", &FRSCalibrEvent_sc43_x, &b_FRSCalibrEvent_sc43_x);
   fChain->SetBranchAddress("FRSCalibrEvent.sc21_y", &FRSCalibrEvent_sc21_y, &b_FRSCalibrEvent_sc21_y);
   fChain->SetBranchAddress("FRSCalibrEvent.sc41_y", &FRSCalibrEvent_sc41_y, &b_FRSCalibrEvent_sc41_y);
   fChain->SetBranchAddress("FRSCalibrEvent.sc42_y", &FRSCalibrEvent_sc42_y, &b_FRSCalibrEvent_sc42_y);
   fChain->SetBranchAddress("FRSCalibrEvent.sc43_y", &FRSCalibrEvent_sc43_y, &b_FRSCalibrEvent_sc43_y);
   fChain->SetBranchAddress("FRSCalibrEvent.sc81_x", &FRSCalibrEvent_sc81_x, &b_FRSCalibrEvent_sc81_x);
   fChain->SetBranchAddress("FRSCalibrEvent.music1_x1", &FRSCalibrEvent_music1_x1, &b_FRSCalibrEvent_music1_x1);
   fChain->SetBranchAddress("FRSCalibrEvent.music1_x2", &FRSCalibrEvent_music1_x2, &b_FRSCalibrEvent_music1_x2);
   fChain->SetBranchAddress("FRSCalibrEvent.music1_x3", &FRSCalibrEvent_music1_x3, &b_FRSCalibrEvent_music1_x3);
   fChain->SetBranchAddress("FRSCalibrEvent.music1_x4", &FRSCalibrEvent_music1_x4, &b_FRSCalibrEvent_music1_x4);
   fChain->SetBranchAddress("FRSCalibrEvent.music2_x", &FRSCalibrEvent_music2_x, &b_FRSCalibrEvent_music2_x);
   fChain->SetBranchAddress("FRSCalibrEvent.etap_scaler[64]", FRSCalibrEvent_etap_scaler, &b_FRSCalibrEvent_etap_scaler);
   fChain->SetBranchAddress("FRSCalibrEvent.etap_scaler_increase[64]", FRSCalibrEvent_etap_scaler_increase, &b_FRSCalibrEvent_etap_scaler_increase);
   fChain->SetBranchAddress("FRSCalibrEvent.etap_scaler_normalized[64]", FRSCalibrEvent_etap_scaler_normalized, &b_FRSCalibrEvent_etap_scaler_normalized);
   fChain->SetBranchAddress("FRSCalibrEvent.mh_scaler[64]", FRSCalibrEvent_mh_scaler, &b_FRSCalibrEvent_mh_scaler);
   fChain->SetBranchAddress("FRSCalibrEvent.mh_scaler_increase[64]", FRSCalibrEvent_mh_scaler_increase, &b_FRSCalibrEvent_mh_scaler_increase);
   fChain->SetBranchAddress("FRSCalibrEvent.mh_scaler_normalized[64]", FRSCalibrEvent_mh_scaler_normalized, &b_FRSCalibrEvent_mh_scaler_normalized);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_numhit[16]", FRSCalibrEvent_mwdc_numhit, &b_FRSCalibrEvent_mwdc_numhit);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_tot[16][64]", FRSCalibrEvent_mwdc_tot, &b_FRSCalibrEvent_mwdc_tot);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_time[16][64]", FRSCalibrEvent_mwdc_time, &b_FRSCalibrEvent_mwdc_time);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_time_wMaxToT[16]", FRSCalibrEvent_mwdc_time_wMaxToT, &b_FRSCalibrEvent_mwdc_time_wMaxToT);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_wireid[16][64]", FRSCalibrEvent_mwdc_wireid, &b_FRSCalibrEvent_mwdc_wireid);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_wirepos[16][64]", FRSCalibrEvent_mwdc_wirepos, &b_FRSCalibrEvent_mwdc_wirepos);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_length[16][64]", FRSCalibrEvent_mwdc_length, &b_FRSCalibrEvent_mwdc_length);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_numtrack", &FRSCalibrEvent_mwdc_numtrack, &b_FRSCalibrEvent_mwdc_numtrack);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_numtrack_estimate[2]", FRSCalibrEvent_mwdc_numtrack_estimate, &b_FRSCalibrEvent_mwdc_numtrack_estimate);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_chi2", &FRSCalibrEvent_mwdc_chi2, &b_FRSCalibrEvent_mwdc_chi2);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_x", &FRSCalibrEvent_mwdc_x, &b_FRSCalibrEvent_mwdc_x);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_y", &FRSCalibrEvent_mwdc_y, &b_FRSCalibrEvent_mwdc_y);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_a", &FRSCalibrEvent_mwdc_a, &b_FRSCalibrEvent_mwdc_a);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_b", &FRSCalibrEvent_mwdc_b, &b_FRSCalibrEvent_mwdc_b);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_res[16]", FRSCalibrEvent_mwdc_res, &b_FRSCalibrEvent_mwdc_res);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_res_ex[16]", FRSCalibrEvent_mwdc_res_ex, &b_FRSCalibrEvent_mwdc_res_ex);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_chi2_test[2]", FRSCalibrEvent_mwdc_chi2_test, &b_FRSCalibrEvent_mwdc_chi2_test);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_x_test[2]", FRSCalibrEvent_mwdc_x_test, &b_FRSCalibrEvent_mwdc_x_test);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_y_test[2]", FRSCalibrEvent_mwdc_y_test, &b_FRSCalibrEvent_mwdc_y_test);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_a_test[2]", FRSCalibrEvent_mwdc_a_test, &b_FRSCalibrEvent_mwdc_a_test);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_b_test[2]", FRSCalibrEvent_mwdc_b_test, &b_FRSCalibrEvent_mwdc_b_test);
   fChain->SetBranchAddress("FRSCalibrEvent.mwdc_res_test[2][8]", FRSCalibrEvent_mwdc_res_test, &b_FRSCalibrEvent_mwdc_res_test);
   fChain->SetBranchAddress("FRSCalibrEvent.focal_plane", &FRSCalibrEvent_focal_plane, &b_FRSCalibrEvent_focal_plane);
   fChain->SetBranchAddress("FRSCalibrEvent.qdcvalid", &FRSCalibrEvent_qdcvalid, &b_FRSCalibrEvent_qdcvalid);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_qdc[16][2]", FRSCalibrEvent_sci_qdc, &b_FRSCalibrEvent_sci_qdc);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_tdc[16][2]", FRSCalibrEvent_sci_tdc, &b_FRSCalibrEvent_sci_tdc);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_ml[16][2]", FRSCalibrEvent_sci_ml, &b_FRSCalibrEvent_sci_ml);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_mt[16][2]", FRSCalibrEvent_sci_mt, &b_FRSCalibrEvent_sci_mt);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_t0_tdc[16][2]", FRSCalibrEvent_sci_t0_tdc, &b_FRSCalibrEvent_sci_t0_tdc);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_time[16][2]", FRSCalibrEvent_sci_time, &b_FRSCalibrEvent_sci_time);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_timeave[16]", FRSCalibrEvent_sci_timeave, &b_FRSCalibrEvent_sci_timeave);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_timedif[16]", FRSCalibrEvent_sci_timedif, &b_FRSCalibrEvent_sci_timedif);
   fChain->SetBranchAddress("FRSCalibrEvent.sci_de[16]", FRSCalibrEvent_sci_de, &b_FRSCalibrEvent_sci_de);
   fChain->SetBranchAddress("FRSCalibrEvent.tof_21l_41l", &FRSCalibrEvent_tof_21l_41l, &b_FRSCalibrEvent_tof_21l_41l);
   fChain->SetBranchAddress("FRSCalibrEvent.tof_21r_41r", &FRSCalibrEvent_tof_21r_41r, &b_FRSCalibrEvent_tof_21r_41r);
   fChain->SetBranchAddress("FRSCalibrEvent.tof_21_41", &FRSCalibrEvent_tof_21_41, &b_FRSCalibrEvent_tof_21_41);
   fChain->SetBranchAddress("FRSCalibrEvent.tof_41l_42l", &FRSCalibrEvent_tof_41l_42l, &b_FRSCalibrEvent_tof_41l_42l);
   fChain->SetBranchAddress("FRSCalibrEvent.tof_41r_42r", &FRSCalibrEvent_tof_41r_42r, &b_FRSCalibrEvent_tof_41r_42r);
   fChain->SetBranchAddress("FRSCalibrEvent.tof_41_42", &FRSCalibrEvent_tof_41_42, &b_FRSCalibrEvent_tof_41_42);
   fChain->SetBranchAddress("FRSCalibrEvent.mini_qdc[2]", FRSCalibrEvent_mini_qdc, &b_FRSCalibrEvent_mini_qdc);
   fChain->SetBranchAddress("FRSCalibrEvent.mini_tdc[2]", FRSCalibrEvent_mini_tdc, &b_FRSCalibrEvent_mini_tdc);
   fChain->SetBranchAddress("FRSCalibrEvent.mini_time[2]", FRSCalibrEvent_mini_time, &b_FRSCalibrEvent_mini_time);
   fChain->SetBranchAddress("FRSCalibrEvent.mini_pe[2]", FRSCalibrEvent_mini_pe, &b_FRSCalibrEvent_mini_pe);
   fChain->SetBranchAddress("FRSCalibrEvent.mini_pesum", &FRSCalibrEvent_mini_pesum, &b_FRSCalibrEvent_mini_pesum);
   fChain->SetBranchAddress("FRSCalibrEvent.mini_numhit", &FRSCalibrEvent_mini_numhit, &b_FRSCalibrEvent_mini_numhit);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_qdc_raw[8]", FRSCalibrEvent_hirac_qdc_raw, &b_FRSCalibrEvent_hirac_qdc_raw);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_qdc_base[8]", FRSCalibrEvent_hirac_qdc_base, &b_FRSCalibrEvent_hirac_qdc_base);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_qdc_cor[8]", FRSCalibrEvent_hirac_qdc_cor, &b_FRSCalibrEvent_hirac_qdc_cor);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_pe[8]", FRSCalibrEvent_hirac_pe, &b_FRSCalibrEvent_hirac_pe);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_tdc_raw[8]", FRSCalibrEvent_hirac_tdc_raw, &b_FRSCalibrEvent_hirac_tdc_raw);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_tdc_t0cor[8]", FRSCalibrEvent_hirac_tdc_t0cor, &b_FRSCalibrEvent_hirac_tdc_t0cor);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_tdc_cor[8]", FRSCalibrEvent_hirac_tdc_cor, &b_FRSCalibrEvent_hirac_tdc_cor);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_pesum", &FRSCalibrEvent_hirac_pesum, &b_FRSCalibrEvent_hirac_pesum);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_x", &FRSCalibrEvent_hirac_x, &b_FRSCalibrEvent_hirac_x);
   fChain->SetBranchAddress("FRSCalibrEvent.hirac_numhit", &FRSCalibrEvent_hirac_numhit, &b_FRSCalibrEvent_hirac_numhit);
   fChain->SetBranchAddress("FRSCalibrEvent.torch_qdc[6]", FRSCalibrEvent_torch_qdc, &b_FRSCalibrEvent_torch_qdc);
   fChain->SetBranchAddress("FRSCalibrEvent.torch_tdc[6]", FRSCalibrEvent_torch_tdc, &b_FRSCalibrEvent_torch_tdc);
   fChain->SetBranchAddress("FRSCalibrEvent.torch_time[6]", FRSCalibrEvent_torch_time, &b_FRSCalibrEvent_torch_time);
   fChain->SetBranchAddress("FRSCalibrEvent.torch_pe[6]", FRSCalibrEvent_torch_pe, &b_FRSCalibrEvent_torch_pe);
   fChain->SetBranchAddress("FRSCalibrEvent.torch_pesum", &FRSCalibrEvent_torch_pesum, &b_FRSCalibrEvent_torch_pesum);
   fChain->SetBranchAddress("FRSCalibrEvent.torch_x", &FRSCalibrEvent_torch_x, &b_FRSCalibrEvent_torch_x);
   fChain->SetBranchAddress("FRSCalibrEvent.torch_numhit", &FRSCalibrEvent_torch_numhit, &b_FRSCalibrEvent_torch_numhit);
   fChain->SetBranchAddress("FRSCalibrEvent.b_pi[5]", FRSCalibrEvent_b_pi, &b_FRSCalibrEvent_b_pi);
   Notify();
}

Bool_t s437_ascii::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void s437_ascii::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t s437_ascii::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef s437_ascii_cxx
