#!/bin/bash

set -e

if [[ $# != 1 ]]; then
    echo "[Usage] $0 NUM_RECS"
    exit 1
fi

./gensort -a $1 data.$1
./sort data.$1 data.$1.sorted
./valsort data.$1.sorted
