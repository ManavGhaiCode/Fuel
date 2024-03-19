#! /usr/bin/bash

rm -rf Build

echo -e "-----------------CMAKE OUT-----------------\n"

cmake -S . -B Build

cd Test
cmake -S . -B ../Build/Test
cd ../

echo -e "\n-------------------------------------------"
echo -e "------------------MAKE OUT-----------------\n"

cd Build
time make

echo -e "\n-------------------------------------------"
echo -e "----------------ENGINE OUT-----------------\n"

./Test