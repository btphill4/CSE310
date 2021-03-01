#include "HEAP.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;


/*HEAP::HEAP()
{
    capacity = 0;
    size = 12;
}*/

HEAP::HEAP(int n)
{
	capacity = n;
    size = 12;

    ElementT* arr = new ElementT[n + 1];  //dynamically allocated

    H = arr;
}

HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);

    cout << "INSIDE PRINT: capcity=" << heap->getCapacity() << ", size=" 
    << heap->getSize() << endl;

    return heap;
}

void	HEAP::heapPrint(HEAP* heapPtr)
{
	cout << "INSIDE PRINT: capcity=" << heapPtr->getCapacity() << ", size=" 
    << heapPtr->getSize() << endl;

   /* //print the HEAP from size 1
    for(int i = 1; i <= heapPtr->size; i++)
    {
        cout << heapPtr->H[i]->key << ", ";
        break;
    }*/
}

int	HEAP::getSize()
{
	return this->size;
}

int	HEAP::getCapacity()
{
	return this->capacity;

}

ElementT*	HEAP::getH()
{
	return this-> H;
}

int	HEAP::setSize()
{
	
}

int	HEAP::setCapacity()
{
	
}

ElementT*	HEAP::setH()
{
	
}

int main()
{
    //HEAP cheap;
    HEAP *heapPointer;
    heapPointer->initialize(10);
    
    cout << "INSIDE main: capcity=" << heapPointer->getCapacity() << ", size=" 
    << heapPointer->size << endl;

    //heapPointer->heapPrint(heapPointer);
}




