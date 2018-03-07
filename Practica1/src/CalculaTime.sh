#!/bin/bash
COUNTER=65536
while [ $COUNTER -lt 67108865 ]; do
time ./SumaVectoresCOMPfor $COUNTER >> salida.dat
let COUNTER=COUNTER*2
done
