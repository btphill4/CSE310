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
    //ElementT ElementA[n+1]
	ElementT ElementA[n+1];

    //create HEAP object tempH, pass n to capacity and size = 12
    HEAP tempH;
    tempH.capacity = n;
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
    cout << "capcity=" << HEAP::capacity << ", size=" 
    << HEAP::size << endl;

    //print the HEAP from size 1
    for(int i = 1; i <= size; i++)
    {
        break;
    }
}




