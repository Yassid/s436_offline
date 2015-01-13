#include "Riostream.h"
#include "TString.h"
#include "TROOT.h"
#include "TApplication.h"
#include "TFRSAnalysis.h"
#include "Go4AnalysisClient/TGo4AnalysisClient.h"
#include <stdlib.h>

#define kGUI   2
#define kBatch 1

//================== FRS analysis main program ============================
int main(int argc, char **argv)
{
// argv[0] program 
// argv[1] "-gui" when started by GUI.
//         In this case the following args are:
// argv[2] analysis name as specified in GUI
// argv[3] hostname of GUI
// argv[4] connector port of GUI
//         if not GUI the args are:
// argv[1] LMD filename
// argv[2] optional number of events

   cout << argv[0] << endl << "Started with args" << endl;
   for(int i=1;i<argc;i++) cout << "   " << i << ": " << argv[i] << endl;
 
   if(argc < 2) {
      cout << endl;
      cout << "****************************************************" << endl;
      cout << "*     GO4 FRS online analysis. Usage:              *" << endl;
      cout << "* ./MainUserAnalysis file [events]                 *" << endl;
      cout << "* ./MainUserAnalysis -server name localhost 5000   *" << endl;
      cout << "* ./MainUserAnalysis -gui name 'guihost' 'guiport' *" << endl;
      cout << "****************************************************" << endl;
      return 0;
   } 
   
   TApplication theApp("App", 0, 0); // init root application loop
   
   Int_t runningMode = kGUI;             // runningMode of analysis, kGUI or kBatch 
   Bool_t servermode=kFALSE;             // run analysis task as client or as server
   TString analysisname = "FRSanalysis"; // symbolic name of analysis as specified in go4
   Bool_t useHServer = kFALSE;           // set kTRUE to activate HServer

   if(strstr(argv[1],"-gui")) {
      runningMode = kGUI;
      servermode = kFALSE;
      if (argc>2) analysisname = argv[2];
   } else 
   
   if(strstr(argv[1],"-server")) {
      runningMode = kGUI;
      servermode = kTRUE;
      if (argc>2) analysisname = argv[2];
   } else {
      runningMode = kBatch; // no GUI
   }

   TString lmdfile, outputbase;

   Int_t maxevents = 999999999;          // number of events processed in batch mode
   if (runningMode == kBatch) {
      lmdfile = argv[1];
      if (argc>2) maxevents=atoi(argv[2]); 
      
      outputbase = lmdfile;
      Int_t slash = outputbase.Index("/");
      
      while (slash>=0) {
         outputbase.Remove(0, slash+1);
         slash = outputbase.Index("/");
      }
      
      Int_t lmdexten = outputbase.Index(".lmd");
      if (lmdexten>0) outputbase.Resize(lmdexten);
      
      if (outputbase.Length()==0) {
         cout << "Error with input file " <<  lmdfile << endl;
         return 0;
      }
      
   } else {
      lmdfile.Form("%s.lmd", analysisname.Data());
      outputbase = analysisname;
   }
   
   TString asffile = outputbase + "_ASF"; // autosave file
   TString unpackfile = outputbase + "_UPA"; // unpacked events
   TString sortfile = outputbase + "_SRT"; // sorted events
   TString calibrfile = outputbase + "_CAL"; // calibrated events
   TString anlfile = outputbase + "_ANL"; // analyzed events
   TString userfile = outputbase + "_USR"; // user events
   
   cout << "Files configured:" << endl
        << "  Input:      " << lmdfile << endl
        << "  Autosave:   " << asffile << endl 
        << "  Unpacked:   " << unpackfile << endl
        << "  Sorted:     " << sortfile << endl 
        << "  Calibrated: " << calibrfile << endl
        << "  Analyzed:   " << anlfile << endl
        << "  User:       " << userfile << endl;

// Now setup the FRS analysis itself
   TFRSAnalysis* analysis = new TFRSAnalysis(lmdfile,asffile,unpackfile,sortfile,calibrfile,anlfile,userfile);

   if(runningMode == kBatch) {
      cout << "****  Starting analysis in batch mode ...  " << endl;
      if (analysis->InitEventClasses()) {
         analysis->RunImplicitLoop(maxevents);
         delete analysis;
         cout << "**** Batch run done **** " << endl;
      } else {
         cout << "Init event classes failed, aborting!"<<endl;
      }
      gApplication->Terminate();
   }
         
   //==================== password settings for gui login (for analysis server only)
   if(servermode) {
      // note: do not change go4 default passwords for analysis in client mode
      // autoconnect to gui server will not work then!!!
      analysis->SetAdministratorPassword("FRSadmin");
      analysis->SetControllerPassword("FRSctrl");
      analysis->SetObserverPassword("FRSview");
   }

   if(runningMode == kGUI) {
      cout << "****  Starting analysis in " << (servermode ? "SERVER" : "CLIENT") << " mode ..." << endl;
      TGo4AnalysisClient* client = new TGo4AnalysisClient(argc,argv,analysis,
                                                         useHServer,"FRS","work",
                                                         servermode, kFALSE);
      cout << "Created AnalysisClient Instance: "<<client->GetName()<<endl;
   }
	if (runningMode == kGUI && !servermode) analysis->SetRunningMode(1);
	else if (runningMode == kGUI && servermode) analysis->SetRunningMode(2);
	else analysis->SetRunningMode(0);
   theApp.Run();
   return 0;
}
