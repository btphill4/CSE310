/** 
 * Author: Brandon Phillips
 * Function: TThis hold the heap class methods
 * from Heap.h to be used in the main
*/


#include "Heap.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

//constructor
HEAP::HEAP(int n)
{
	capacity = n;
    size = 12;

    //element pointer array
    ELEMENT* arr = new ELEMENT[n + 1];  //dynamically allocated

    H = arr;
}

//initialize, return HEAP* ptr
HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);   //will be dynamically allocated in the constuctor

    //testing purposes
    /*cout << "INSIDE init: capcity=" << heap->getCapacity() << ", size=" 
    << heap->getSize() << endl;*/

    return heap;
}

//print the objects of the heap
void HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    cout << "capacity=" << a->capacity << ", size=" 
    << a->getSize() << endl;

    //print the HEAP from size 1
    ElementT arr = a->getH();
    for(int i = 1; i <= a->size; i++)
    {
        //if key is == 0, break the for loop
        if(arr[i].key == 0)
        {
            break;
        }

        //if we are at the end of the arr, don't print a comma
        if(i == a->size)
        {
            cout << arr[i].key << endl;
        }

        //print everything and put a commma after
        else
        {
        cout << arr[i].key << ", ";
        }
    }
    //cout << endl;
    
    
}




