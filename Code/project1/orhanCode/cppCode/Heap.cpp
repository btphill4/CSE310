#include "Heap.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;


HEAP::HEAP(int n)
{
	capacity = n;
    size = 12;

    ELEMENT* arr = new ELEMENT[n + 1];  //dynamically allocated

    H = arr;
}

HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);   //will be dynamically allocated in the constuctor

    /*cout << "INSIDE init: capcity=" << heap->getCapacity() << ", size=" 
    << heap->getSize() << endl;*/

    return heap;
}


void HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    cout << "capacity=" << a->capacity << ", size=" 
    << a->getSize() << endl;

    //print the HEAP from size 1
    ElementT arr = a->getH();
    for(int i = 1; i <= a->size; i++)
    {
        if(i == a->size)
        {
            cout << arr[i].key;
        }
        else
        {
        cout << arr[i].key << ", ";
        }
    }
    cout << endl;
}




//testing main


