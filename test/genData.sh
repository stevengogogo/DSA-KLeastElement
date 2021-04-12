#!/bin/bash

echo "generate data"
for i in {11..13};
do
    /home/ubuntu/.local/bin/julia test/dataGen.jl 50000 50 test/data/$i.in test/data/$i.out 

    echo "Create: test/data/$i.in test/data/$i.out"

done