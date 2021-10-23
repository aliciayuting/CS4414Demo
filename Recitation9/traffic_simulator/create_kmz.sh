#!/bin/bash

cd Release/bin
zip -r myfile.zip myfile.kml files
mv myfile.zip myfile.kmz
mv myfile.kmz ../../data
