#!/bin/bash

mkdir -p Release
cd Release
cmake -DCMAKE_BUILD_TYPE=Release ..
make

cd bin
mkdir files
cd ..

cd ..
cp data/Traffic_Signals_SF.csv Release/bin
