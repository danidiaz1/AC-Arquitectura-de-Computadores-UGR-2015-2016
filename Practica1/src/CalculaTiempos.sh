#!/bin/sh
COUNTER=16384
while [ $COUNTER -lt 67108865 ]; do
./SumaVectoresCSections $COUNTER
let COUNTER=COUNTER*2
done
