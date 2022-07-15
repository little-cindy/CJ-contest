#!/bin/bash                         
if diff -b -B -q liu.out std.out;then       
    echo "Wonderful!"                             
else
    echo "Fake!Wrong Answer!"
fi                                          
