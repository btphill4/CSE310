#include "Heap.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;


//HEAP *heapPointer;


//getter methods
    int HEAP::getCapacity()
    {
	    return this->capacity;
    }
    int HEAP::getSize()
    {
        return this->size;
    }
    ElementT HEAP::getH()
    {
        return this->H;
    } 
    

    //setters
    void HEAP::setH(ElementT _H)
    {
        H = _H;
    }

    void HEAP::setCapacity(int _capacity)
    {
        capacity = _capacity;
    }

    void HEAP::setSize(int _size)
    {
        size = _size;
    }

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
    
    tempH->size = 12;

    //set tempH's *H value to ElementA
    tempH->setH(ElementA);

   
    return tempH;
}


void HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    cout << "capacity = " << a->capacity << ", size = " 
    << a->size << endl;

    //print the HEAP from size 1
    ElementT arr = a->getH();
    for(int i = 1; i <= a->size; i++)
    {
        cout << arr[i].key << endl;
    }
}


//testing main


