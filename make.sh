#!/bin/bash
echo "=== Compiling agent ==="
mkdir -p agent/build
cd agent/build
cmake ..
make

echo "=== Compiling grid ==="
cd ../../
pwd
mkdir -p grid/build
cd grid/build
cmake ..
make

echo "=== Compiling experiment ==="
cd ../../
mkdir -p experiment/build
cd experiment/build
cmake ..
make

echo "=== Executing experiment ==="
./experiment

echo "=== Cleaning up experiment ==="
rm -rf agent/build grid/build experiment/build
