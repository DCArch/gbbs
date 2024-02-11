#!/bin/sh
wget -c https://snap.stanford.edu/data/bigdata/communities/com-orkut.ungraph.txt.gz
gzip --decompress com-orkut.ungraph.txt.gz
bazel run //utils:snap_converter -- -s -i ${PWD}/com-orkut.ungraph.txt -o ${PWD}/orkut.input
rm com-orkut.ungraph.txt
wget -c https://snap.stanford.edu/data/bigdata/communities/com-friendster.ungraph.txt.gz
gzip --decompress com-friendster.ungraph.txt.gz
bazel run //utils:snap_converter -- -s -i ${PWD}/com-friendster.ungraph.txt -o ${PWD}/friendster.input
rm com-friendster.ungraph.txt
