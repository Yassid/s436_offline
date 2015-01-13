#!/bin/sh

# converts all event files corresponding to the rule in expression f1*BELEN*.lmd into root files using the version of go4 where the script is copied to
# run the script (be sure that it is executable) from the folder where the MainUserAnalysis file is

count=0
for name in /d/frs03/s323/calib/f196*Cf*lmd    #test/S4/110810_3TRG*	#f161_*BKG.lmd
do

#awk -v str=$name '
#END {
#lmdFolder=substr(str,1,19)
#filename=substr(str,21)
#printf "%s%s\n","lmdFolder=",lmdFolder
#gsub(".lmd","-curr-sh.root",filename)
#printf "%s%s\n","filename=",filename
#printf "%s\n","echo $lmdFolder/root/$filename"
#} 
#' convert_all.sh	# just dummy file: it is not actually needed

let count=$count+1
#echo $name
length=${#name}
lmdFolder=${name:0:19}
filename=${name:20:($length-20-4)}
#echo $filename
#echo $lmdFolder/$filename.lmd
#echo $lmdFolder/root/$filename-sh.root
go4analysis -name MainUserAnalysis -file $lmdFolder/$filename.lmd -asf $lmdFolder/root/$filename-tdc.root
echo "---------------------------------------------------------------"
echo

done

echo $count "event files converted into root files"
