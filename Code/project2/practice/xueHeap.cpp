#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

class xueHeap
{
    public:
    int capacity;
    int size;

    xueHeap()
    {

    }

    int getParent(int i)
    {
        return i/2;
    }

    int getLeft(int i)
    {
        return 2*i;
    }

    int getRight(int i)
    {
        
    }
};