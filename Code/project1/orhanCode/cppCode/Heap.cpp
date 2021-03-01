#include "Heap.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

/*
//HEAP *heapPointer;

HEAP* HEAP::initialize(int n)
{
    //create an array that hold pointers of type ElementT
    //n + 1 because we dont want ElementA[0]
	ELEMENT ElementA[n+1];

    //create HEAP object tempH, pass n to capacity and size = 12
    HEAP *tempH;
    tempH = new HEAP;
    //tempH.capacity = n;
    tempH->setCapacity(n);
    
    tempH->setSize(12);

    //set tempH's *H value to ElementA
    tempH->setH(ElementA);

   
    return tempH;
}
*/
HEAP::HEAP(int n)
{
	capacity = n;
    size = 12;

    ELEMENT* arr = new ELEMENT[n + 1];  //dynamically allocated

    H = arr;
}

HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);

    cout << "INSIDE init: capcity=" << heap->getCapacity() << ", size=" 
    << heap->getSize() << endl;

    return heap;
}



void HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    cout << "capacity = " << a->capacity << ", size = " 
    << a->getSize() << endl;

    //print the HEAP from size 1
    ElementT arr = a->getH();
    for(int i = 1; i <= a->size; i++)
    {
        cout << arr[i].key << endl;
    }
}




//testing main


