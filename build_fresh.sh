#! /bin/bash

rm -rf build
mkdir build
cd build
cmake .. && cmake --build . --config Debug --target all --
cd ..
