#include "Heap.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

//HEAP tempH = new HEAP();
HEAP *heapPointer;


HEAP*	HEAP::intialize(int n)
{
    //create an array that hold pointers of type ElementT
    //n + 1 because we dont want ElementA[0]
	ElementT ElementA[n+1];

    //create HEAP object tempH, pass n to capacity and size = 12
    HEAP tempH;
    //tempH.capacity = n;
    tempH.setCapacity(n);
    tempH.size = 12;

    //set tempH's *H value to ElementA
    tempH.setH(ElementA);

    //set a HEAP pointer to point to the tempH
    heapPointer = &tempH;

    return heapPointer;
}

void	HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    cout << "capcity=" << a->getCapacity() << ", size=" 
    << a->getSize() << endl;

    //print the HEAP from size 1
    for(int i = 1; i <= size; i++)
    {
        break;
    }
}


//testing main

int main()
{
    HEAP mainH;
    HEAP* mainPtr;

    mainPtr = mainH.intialize(3);
    mainH.setCapacity(3);

    mainPtr = &mainH;
    mainH.heapPrint(mainPtr);

    //free(mainPtr);
}


