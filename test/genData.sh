#!/bin/bash

echo "generate data"
for i in {22..50};
do
    /home/ubuntu/.local/bin/julia test/dataGen.jl 10 50000 test/data/$i.in test/data/$i.out 

    echo "Create: test/data/$i.in test/data/$i.out"

done