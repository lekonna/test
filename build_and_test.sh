#!/bin/bash


mkdir _test
cd _test
cmake ../
if [ $? -ne 0 ]; then
    echo "CMAKE failed"
    cd ..
    rm -rf _test
    exit 1
fi
echo "CMAKE passed"
make
if [ $? -ne 0 ]; then
    echo "BUILD failed"
    cd ..
    rm -rf _test
    exit 1
fi
echo "BUILD passed"
./bin/runTests

if [ $? -ne 0 ]; then
    echo "TEST failed"
    cd ..
    rm -rf _test
    exit 1
fi
echo "TEST passed"

cd ..
rm -rf _test

echo "Done!"

exit 0
