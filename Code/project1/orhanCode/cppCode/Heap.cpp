#include "Heap.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

//HEAP tempH = new HEAP();
HEAP *heapPointer;


HEAP* HEAP::initialize(int n)
{
    //create an array that hold pointers of type ElementT
    //n + 1 because we dont want ElementA[0]
	ElementT ElementA[n+1];

    //create HEAP object tempH, pass n to capacity and size = 12
    HEAP tempH;
    //tempH.capacity = n;
    tempH.setCapacity(n);
    tempH.setSize(12);

    //set tempH's *H value to ElementA
    tempH.setH(ElementA);

    //set a HEAP pointer to point to the tempH
    heapPointer = &tempH;

    cout << "capcity=" << heapPointer->capacity << ", size=" 
    << heapPointer->size << endl;

    return heapPointer;
}

HEAP* HEAP::heapPrint(HEAP* heapPointer)
{
    //print the capity and size
    cout << "capcity=" << heapPointer->capacity << ", size=" 
    << heapPointer->size << endl;

    //print the HEAP from size 1
    for(int i = 1; i <= heapPointer->capacity; i++)
    {
       // cout << heapPointer->H[i] << ", ";
        //cout << endl << endl;
    }
}
/*void HEAP::heapPrint(HEAP* heapPtr)
{
	//print the capity and size
    cout << "capcity=" << heapPointer->capacity << ", size=" 
    << heapPointer->size << endl;

    //print the HEAP from size 1
    for(int i = 1; i <= heapPointer->size; i++)
    {
        break;
    }
}*/


//testing main
/*
int main()
{
    HEAP cheap;
    HEAP* heapPtr; 

    cheap.initialize(5);
    //heapPointer = 
    //cheap.heapPrint()
}*/
