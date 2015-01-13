//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 10 15:05:05 2014 by ROOT version 5.34/21
// from TTree UnpackxTree/Go4FileStore
// found on file: pd14Jul0186_UPA.root
//////////////////////////////////////////////////////////

#ifndef s436_analyzer_h
#define s436_analyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TObject.h>
#include <TNamed.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxFRSUnpackEvent = 1;

class s436_analyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //TFRSUnpackEvent *FRSUnpackEvent_;
   UInt_t          FRSUnpackEvent_TGo4EventElement_fUniqueID;
   UInt_t          FRSUnpackEvent_TGo4EventElement_fBits;
   TString         FRSUnpackEvent_TGo4EventElement_fName;
   TString         FRSUnpackEvent_TGo4EventElement_fTitle;
   Bool_t          FRSUnpackEvent_TGo4EventElement_fbIsValid;
   Short_t         FRSUnpackEvent_TGo4EventElement_fIdentifier;
   Int_t           FRSUnpackEvent_amscl[16][64];
   Int_t           FRSUnpackEvent_amsct[16][64];
   Int_t           FRSUnpackEvent_amsc_length[16];
   Int_t           FRSUnpackEvent_amsc_error[16];
   Int_t           FRSUnpackEvent_amsc_itry[16];
   Int_t           FRSUnpackEvent_v830n[32];
   Int_t           FRSUnpackEvent_v830_length;
   Int_t           FRSUnpackEvent_v830_itry;
   Int_t           FRSUnpackEvent_v830n_mh[32];
   Int_t           FRSUnpackEvent_v830_length_mh;
   Int_t           FRSUnpackEvent_v830_itry_mh;
   Int_t           FRSUnpackEvent_v1290l[2][32];
   Int_t           FRSUnpackEvent_v1290t[2][32];
   Int_t           FRSUnpackEvent_v1290ml[2][32];
   Int_t           FRSUnpackEvent_v1290mt[2][32];
   Int_t           FRSUnpackEvent_v1290_length[2];
   Int_t           FRSUnpackEvent_v1290_itry[2];
   Int_t           FRSUnpackEvent_v792q[2][16];
   Int_t           FRSUnpackEvent_v792_length[2];
   Int_t           FRSUnpackEvent_v792_itry[2];
   Int_t           FRSUnpackEvent_v775t[32];
   Int_t           FRSUnpackEvent_v775_length;
   Int_t           FRSUnpackEvent_v775_itry;
   Float_t         FRSUnpackEvent_v1742q[32];
   Float_t         FRSUnpackEvent_v1742baseline[32];
   Float_t         FRSUnpackEvent_v1742t[32];
   Int_t           FRSUnpackEvent_v1742valid[32];
   Int_t           FRSUnpackEvent_v1742_length;
   Int_t           FRSUnpackEvent_v1742_itry;
   UInt_t          FRSUnpackEvent_vme0[21][32];
   UInt_t          FRSUnpackEvent_vme1[21][32];
   Int_t           FRSUnpackEvent_qlength;
   Int_t           FRSUnpackEvent_qtype;
   Int_t           FRSUnpackEvent_qsubtype;
   Int_t           FRSUnpackEvent_qdummy;
   Int_t           FRSUnpackEvent_qtrigger;
   Int_t           FRSUnpackEvent_qevent_nr;

   // List of branches
   TBranch        *b_FRSUnpackEvent_TGo4EventElement_fUniqueID;   //!
   TBranch        *b_FRSUnpackEvent_TGo4EventElement_fBits;   //!
   TBranch        *b_FRSUnpackEvent_TGo4EventElement_fName;   //!
   TBranch        *b_FRSUnpackEvent_TGo4EventElement_fTitle;   //!
   TBranch        *b_FRSUnpackEvent_TGo4EventElement_fbIsValid;   //!
   TBranch        *b_FRSUnpackEvent_TGo4EventElement_fIdentifier;   //!
   TBranch        *b_FRSUnpackEvent_amscl;   //!
   TBranch        *b_FRSUnpackEvent_amsct;   //!
   TBranch        *b_FRSUnpackEvent_amsc_length;   //!
   TBranch        *b_FRSUnpackEvent_amsc_error;   //!
   TBranch        *b_FRSUnpackEvent_amsc_itry;   //!
   TBranch        *b_FRSUnpackEvent_v830n;   //!
   TBranch        *b_FRSUnpackEvent_v830_length;   //!
   TBranch        *b_FRSUnpackEvent_v830_itry;   //!
   TBranch        *b_FRSUnpackEvent_v830n_mh;   //!
   TBranch        *b_FRSUnpackEvent_v830_length_mh;   //!
   TBranch        *b_FRSUnpackEvent_v830_itry_mh;   //!
   TBranch        *b_FRSUnpackEvent_v1290l;   //!
   TBranch        *b_FRSUnpackEvent_v1290t;   //!
   TBranch        *b_FRSUnpackEvent_v1290ml;   //!
   TBranch        *b_FRSUnpackEvent_v1290mt;   //!
   TBranch        *b_FRSUnpackEvent_v1290_length;   //!
   TBranch        *b_FRSUnpackEvent_v1290_itry;   //!
   TBranch        *b_FRSUnpackEvent_v792q;   //!
   TBranch        *b_FRSUnpackEvent_v792_length;   //!
   TBranch        *b_FRSUnpackEvent_v792_itry;   //!
   TBranch        *b_FRSUnpackEvent_v775t;   //!
   TBranch        *b_FRSUnpackEvent_v775_length;   //!
   TBranch        *b_FRSUnpackEvent_v775_itry;   //!
   TBranch        *b_FRSUnpackEvent_v1742q;   //!
   TBranch        *b_FRSUnpackEvent_v1742baseline;   //!
   TBranch        *b_FRSUnpackEvent_v1742t;   //!
   TBranch        *b_FRSUnpackEvent_v1742valid;   //!
   TBranch        *b_FRSUnpackEvent_v1742_length;   //!
   TBranch        *b_FRSUnpackEvent_v1742_itry;   //!
   TBranch        *b_FRSUnpackEvent_vme0;   //!
   TBranch        *b_FRSUnpackEvent_vme1;   //!
   TBranch        *b_FRSUnpackEvent_qlength;   //!
   TBranch        *b_FRSUnpackEvent_qtype;   //!
   TBranch        *b_FRSUnpackEvent_qsubtype;   //!
   TBranch        *b_FRSUnpackEvent_qdummy;   //!
   TBranch        *b_FRSUnpackEvent_qtrigger;   //!
   TBranch        *b_FRSUnpackEvent_qevent_nr;   //!

   s436_analyzer(TTree *tree=0);
   virtual ~s436_analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef s436_analyzer_cxx
s436_analyzer::s436_analyzer(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("pd14Jul0186_UPA.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("pd14Jul0186_UPA.root");
      }
      f->GetObject("UnpackxTree",tree);

   }
   Init(tree);
}

s436_analyzer::~s436_analyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t s436_analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t s436_analyzer::LoadTree(Long64_t entry)
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

void s436_analyzer::Init(TTree *tree)
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

   fChain->SetBranchAddress("FRSUnpackEvent.TGo4EventElement.fUniqueID", &FRSUnpackEvent_TGo4EventElement_fUniqueID, &b_FRSUnpackEvent_TGo4EventElement_fUniqueID);
   fChain->SetBranchAddress("FRSUnpackEvent.TGo4EventElement.fBits", &FRSUnpackEvent_TGo4EventElement_fBits, &b_FRSUnpackEvent_TGo4EventElement_fBits);
   fChain->SetBranchAddress("FRSUnpackEvent.TGo4EventElement.fName", &FRSUnpackEvent_TGo4EventElement_fName, &b_FRSUnpackEvent_TGo4EventElement_fName);
   fChain->SetBranchAddress("FRSUnpackEvent.TGo4EventElement.fTitle", &FRSUnpackEvent_TGo4EventElement_fTitle, &b_FRSUnpackEvent_TGo4EventElement_fTitle);
   fChain->SetBranchAddress("FRSUnpackEvent.TGo4EventElement.fbIsValid", &FRSUnpackEvent_TGo4EventElement_fbIsValid, &b_FRSUnpackEvent_TGo4EventElement_fbIsValid);
   fChain->SetBranchAddress("FRSUnpackEvent.TGo4EventElement.fIdentifier", &FRSUnpackEvent_TGo4EventElement_fIdentifier, &b_FRSUnpackEvent_TGo4EventElement_fIdentifier);
   fChain->SetBranchAddress("FRSUnpackEvent.amscl[16][64]", FRSUnpackEvent_amscl, &b_FRSUnpackEvent_amscl);
   fChain->SetBranchAddress("FRSUnpackEvent.amsct[16][64]", FRSUnpackEvent_amsct, &b_FRSUnpackEvent_amsct);
   fChain->SetBranchAddress("FRSUnpackEvent.amsc_length[16]", FRSUnpackEvent_amsc_length, &b_FRSUnpackEvent_amsc_length);
   fChain->SetBranchAddress("FRSUnpackEvent.amsc_error[16]", FRSUnpackEvent_amsc_error, &b_FRSUnpackEvent_amsc_error);
   fChain->SetBranchAddress("FRSUnpackEvent.amsc_itry[16]", FRSUnpackEvent_amsc_itry, &b_FRSUnpackEvent_amsc_itry);
   fChain->SetBranchAddress("FRSUnpackEvent.v830n[32]", FRSUnpackEvent_v830n, &b_FRSUnpackEvent_v830n);
   fChain->SetBranchAddress("FRSUnpackEvent.v830_length", &FRSUnpackEvent_v830_length, &b_FRSUnpackEvent_v830_length);
   fChain->SetBranchAddress("FRSUnpackEvent.v830_itry", &FRSUnpackEvent_v830_itry, &b_FRSUnpackEvent_v830_itry);
   fChain->SetBranchAddress("FRSUnpackEvent.v830n_mh[32]", FRSUnpackEvent_v830n_mh, &b_FRSUnpackEvent_v830n_mh);
   fChain->SetBranchAddress("FRSUnpackEvent.v830_length_mh", &FRSUnpackEvent_v830_length_mh, &b_FRSUnpackEvent_v830_length_mh);
   fChain->SetBranchAddress("FRSUnpackEvent.v830_itry_mh", &FRSUnpackEvent_v830_itry_mh, &b_FRSUnpackEvent_v830_itry_mh);
   fChain->SetBranchAddress("FRSUnpackEvent.v1290l[2][32]", FRSUnpackEvent_v1290l, &b_FRSUnpackEvent_v1290l);
   fChain->SetBranchAddress("FRSUnpackEvent.v1290t[2][32]", FRSUnpackEvent_v1290t, &b_FRSUnpackEvent_v1290t);
   fChain->SetBranchAddress("FRSUnpackEvent.v1290ml[2][32]", FRSUnpackEvent_v1290ml, &b_FRSUnpackEvent_v1290ml);
   fChain->SetBranchAddress("FRSUnpackEvent.v1290mt[2][32]", FRSUnpackEvent_v1290mt, &b_FRSUnpackEvent_v1290mt);
   fChain->SetBranchAddress("FRSUnpackEvent.v1290_length[2]", FRSUnpackEvent_v1290_length, &b_FRSUnpackEvent_v1290_length);
   fChain->SetBranchAddress("FRSUnpackEvent.v1290_itry[2]", FRSUnpackEvent_v1290_itry, &b_FRSUnpackEvent_v1290_itry);
   fChain->SetBranchAddress("FRSUnpackEvent.v792q[2][16]", FRSUnpackEvent_v792q, &b_FRSUnpackEvent_v792q);
   fChain->SetBranchAddress("FRSUnpackEvent.v792_length[2]", FRSUnpackEvent_v792_length, &b_FRSUnpackEvent_v792_length);
   fChain->SetBranchAddress("FRSUnpackEvent.v792_itry[2]", FRSUnpackEvent_v792_itry, &b_FRSUnpackEvent_v792_itry);
   fChain->SetBranchAddress("FRSUnpackEvent.v775t[32]", FRSUnpackEvent_v775t, &b_FRSUnpackEvent_v775t);
   fChain->SetBranchAddress("FRSUnpackEvent.v775_length", &FRSUnpackEvent_v775_length, &b_FRSUnpackEvent_v775_length);
   fChain->SetBranchAddress("FRSUnpackEvent.v775_itry", &FRSUnpackEvent_v775_itry, &b_FRSUnpackEvent_v775_itry);
   fChain->SetBranchAddress("FRSUnpackEvent.v1742q[32]", FRSUnpackEvent_v1742q, &b_FRSUnpackEvent_v1742q);
   fChain->SetBranchAddress("FRSUnpackEvent.v1742baseline[32]", FRSUnpackEvent_v1742baseline, &b_FRSUnpackEvent_v1742baseline);
   fChain->SetBranchAddress("FRSUnpackEvent.v1742t[32]", FRSUnpackEvent_v1742t, &b_FRSUnpackEvent_v1742t);
   fChain->SetBranchAddress("FRSUnpackEvent.v1742valid[32]", FRSUnpackEvent_v1742valid, &b_FRSUnpackEvent_v1742valid);
   fChain->SetBranchAddress("FRSUnpackEvent.v1742_length", &FRSUnpackEvent_v1742_length, &b_FRSUnpackEvent_v1742_length);
   fChain->SetBranchAddress("FRSUnpackEvent.v1742_itry", &FRSUnpackEvent_v1742_itry, &b_FRSUnpackEvent_v1742_itry);
   fChain->SetBranchAddress("FRSUnpackEvent.vme0[21][32]", FRSUnpackEvent_vme0, &b_FRSUnpackEvent_vme0);
   fChain->SetBranchAddress("FRSUnpackEvent.vme1[21][32]", FRSUnpackEvent_vme1, &b_FRSUnpackEvent_vme1);
   fChain->SetBranchAddress("FRSUnpackEvent.qlength", &FRSUnpackEvent_qlength, &b_FRSUnpackEvent_qlength);
   fChain->SetBranchAddress("FRSUnpackEvent.qtype", &FRSUnpackEvent_qtype, &b_FRSUnpackEvent_qtype);
   fChain->SetBranchAddress("FRSUnpackEvent.qsubtype", &FRSUnpackEvent_qsubtype, &b_FRSUnpackEvent_qsubtype);
   fChain->SetBranchAddress("FRSUnpackEvent.qdummy", &FRSUnpackEvent_qdummy, &b_FRSUnpackEvent_qdummy);
   fChain->SetBranchAddress("FRSUnpackEvent.qtrigger", &FRSUnpackEvent_qtrigger, &b_FRSUnpackEvent_qtrigger);
   fChain->SetBranchAddress("FRSUnpackEvent.qevent_nr", &FRSUnpackEvent_qevent_nr, &b_FRSUnpackEvent_qevent_nr);
   Notify();
}

Bool_t s436_analyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void s436_analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t s436_analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef s436_analyzer_cxx
