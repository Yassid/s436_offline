#!/bin/bash

#Processes a lmd or lml file with go4.
#Go4 Sort, Calibr, Analysis steps are written to root trees


if [ "$1" == "" ] || [ "$2" == "" ]; then
	echo ""
	echo "Usage: $0 [input lmd,lml] [output prefix]"
	echo ""
	echo "Creates ROOT trees for Sort, Calibr and Analysis steps in Go4"
	echo "Creates files that start with the prefix provided and the code SRT, CAL, and ANL for each tree."
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

if [ -e "$2SRT.root" ] || [ -e "$2CAL.root" ] || [ -e "$2ANL.root" ]; then
	echo "ERROR: Output files already exists!"
	exit 4
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

#go4analysis -lib $DIR/libGo4UserAnalysis.so -name $DIR/MainUserAnalysis -file $1 -disable-asf -step Sort -enable-step -store go4.root -enable-store -step Calibr -enable-step -store go4.root -enable-store -step Analysis -enable-step -store go4.root -enable-store
go4analysis -lib $DIR/libGo4UserAnalysis.so -name $DIR/MainUserAnalysis -file $1 -disable-asf -step Sort -enable-step -store $2SRT.root -enable-store -step Calibr -enable-step -store $2CAL.root -enable-store -step Analysis -enable-step -store $2ANL.root -enable-store

if [ $? != 0 ]; then 
	echo "ERROR in go4analysis!"
	exit $?
fi


echo "Processing Complete"

exit 0

