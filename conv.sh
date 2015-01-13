runnum=$178
data_head="/d/frs03/s437/14Jul/pd14Jul"
out_head="/d/frs03/s437/ROOT/run"
aaaaa=$data_head$runnum
bbbbb=$out_head$runnum
if test -f $bbbbb.root; then
    echo "$bbbbb.root already exist"
else    
    echo "start to create $bbbbb.root"
    go4analysis -file ${aaaaa}.lmd -step Unpack -enable-step -step Sort -enable-step -step Calibr -enable-step -enable-store -store ${bbbbb}.root 
fi
