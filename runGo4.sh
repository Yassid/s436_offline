#!/bin/bash

#Processes a lmd or lml file with go4.
#Go4 User step is written to a root file
#User Tree is then convereted to new trees based on go4ToROOT.C

if [ "$1" == "" ] || [ "$2" == "" ]; then
	echo ""
	echo "Usage: $0 [input lmd,lml] [output.root]"
	echo ""
	echo "Runs go4 from the command line withthe User step enabled."
	echo "The go4 User step creates a ROOT file with a specific structure used in beta-n_analysis"
	echo "(This is not equivalent to the ROOT file generated when enable-store is sepcified for the User step)"
	echo ""
	exit 1
fi

if [ "$GO4SYS" == "" ]; then
	. go4login
fi
if [ "$GO4SYS" == "" ]; then
	echo "ERROR: Go4 System files not found!"
	exit 2
fi

if [ ! -f "$1" ]; then
	echo "ERROR: Input file $1 not found!"
	exit 3
fi

if [ -e "$2" ]; then
	echo "WARNING: Output file $2 already exists."
	echo "Remove $2?"
	rm -i $2
	if [ -e "$2" ]; then
		echo "ERROR: Output file $2 already exists!"
		exit 4
	fi
fi

if [ -e "go4Out.root" ]; then
	echo "Remove temporary ROOT output file?"
	rm -i go4Out.root
	if [ -e "go4Out.root" ]; then
		echo "ERROR: Need to remove go4Out.root to process events!"
		exit 5
	fi
fi

DIR="$( cd -P "$( dirname "$(readlink -f "$0")" )" && pwd )"
if [ ! -e "$DIR/MainUserAnalysis" ]; then
	echo "ERROR: $DIR/MainUserAnalysis not found!"
	exit 6
fi
if [ ! -e "$DIR/libGo4UserAnalysis.so" ]; then
	echo "ERROR: $DIR/libGo4UserAnalysis.so not found!"
	exit 6
fi

#go4analysis -lib $DIR/libGo4UserAnalysis.so -name $DIR/MainUserAnalysis -file "$1" -disable-asf -step Sort -enable-step -store SRT.root -enable-store -step Calibr -enable-step -store CAL.root -enable-store -step Analysis -enable-step -store ANL.root -enable-store
go4analysis -lib $DIR/libGo4UserAnalysis.so -name $DIR/MainUserAnalysis -file "$1" -disable-asf -step User -enable-step

if [ $? != 0 ]; then 
	echo "ERROR in go4analysis!"
	exit $?
else
	mv go4Out.root "$2"
fi


echo "Processing Complete"

exit 0

