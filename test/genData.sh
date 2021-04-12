#!/bin/bash

echo "generate data"
for i in {5..7};
do
    /home/ubuntu/.local/bin/julia test/dataGen.jl 340 6 test/data/$i.in test/data/$i.out

    echo "Create: test/data/$i.in test/data/$i.out"

done