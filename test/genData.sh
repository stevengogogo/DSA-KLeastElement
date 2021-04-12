#!/bin/bash

echo "generate data"
for i in {16..18};
do
    /home/ubuntu/.local/bin/julia test/dataGen.jl 50000 20000 test/data/$i.in test/data/$i.out 

    echo "Create: test/data/$i.in test/data/$i.out"

done