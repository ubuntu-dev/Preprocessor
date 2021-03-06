#!/bin/bash

CLANG_VERSION=3.8
RELEASE=true

# Preprocessor
WARNINGS="-Wno-unused-function -Wno-unused-variable -Wno-c++11-compat-deprecated-writable-strings -Wno-switch -Wno-sign-compare -Wno-unused-parameter -Wno-writable-strings -Wno-unknown-escape-sequence"

FILES=""preprocessor/main.cpp" "preprocessor/utils.cpp" "preprocessor/lexer.cpp" "preprocessor/platform.cpp" "preprocessor/write_file.cpp""

echo "Building preprocessor"
if [ "$RELEASE" = "true" ]; then
    clang++-"$CLANG_VERSION" -Wall -Wextra $FILES -std=c++1z -fno-exceptions -fno-rtti -o preprocessor_exe -DERROR_LOGGING=0 -DRUN_TESTS=0 -DINTERNAL=0 -DMEM_CHECK=0 -DWIN32=0 -DLINUX=1 $WARNINGS -g -ldl
else
    clang++-"$CLANG_VERSION" -Wall -Wextra $FILES "preprocessor/test.cpp" "preprocessor/google_test/gtest-all.cc" -std=c++1z -fno-exceptions -fno-rtti -o preprocessor_exe -DERROR_LOGGING=1 -DRUN_TESTS=1 -DINTERNAL=1 -DMEM_CHECK=1 -DWIN32=0 -DLINUX=1 $WARNINGS -g -ldl -pthread
fi
mv "./preprocessor_exe" "build/preprocessor"

# Run test code after building.
if [ "$GTEST" = "true" ]; then
    if [ "$RELEASE" = "false" ]; then      
        echo "Running Preprocessor tests"
        ./build/preprocessor -t
    fi
fi