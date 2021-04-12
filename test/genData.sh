#!/bin/bash

echo "generate data"
for i in {8..10};
do
    /home/ubuntu/.local/bin/julia test/dataGen.jl 340 60 test/data/$i.in test/data/$i.out

    echo "Create: test/data/$i.in test/data/$i.out"

done