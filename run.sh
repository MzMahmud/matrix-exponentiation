#!/bin/bash
echo 'compiling ' $1 '....'
g++ -std=c++14 $1

echo 'running a.exe ....'
time ./a.exe