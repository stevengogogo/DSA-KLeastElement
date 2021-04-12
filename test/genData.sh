#!/bin/bash

echo "generate data"
for i in {14..15};
do
    /home/ubuntu/.local/bin/julia test/dataGen.jl 200 5000 test/data/$i.in test/data/$i.out 

    echo "Create: test/data/$i.in test/data/$i.out"

done