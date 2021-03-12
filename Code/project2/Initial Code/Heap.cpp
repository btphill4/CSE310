/** 
 * Author: Brandon Phillips
 * Function: TThis hold the heap class methods
 * from Heap.h to be used in the main
*/


#include "Heap.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


//constructor
HEAP::HEAP(int n)
{
	capacity = n;
	size = 0; //correct I think
    //size = 12;	//wrong I think

    //element pointer array
    ELEMENT* arr = new ELEMENT[n + 1];  //dynamically allocated

    H = arr;
}

//initialize, return HEAP* ptr
HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);   //will be dynamically allocated in the constuctor

    //testing purposes
   /* cout << "INSIDE init: capcity=" << heap->getCapacity() << ", size=" 
    << heap->getSize() << endl; */

    return heap;
}

//print the objects of the heap
void HEAP::heapPrint(HEAP* a)
{
	//print the capity and size
    cout << "capacity=" << a->capacity << ", size=" 
    << a->size << endl;

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
        if(i == a->getSize())
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
//==================END Project 1=========================//

//=================Project 2 Methods=================//

//to swap the KEYS in the array
//integer Swap
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

//elementSwap 
void eSwap(ElementT *x, ElementT *y) 
{ 
	ElementT temp = *x; 
	*x = *y; 
	*y = temp; 
} 


//Return Node value (NOT IN HEAP.H)
int gParent(int i)
{
	return i/2;
}
int gLeft(int i)
{
	return 2*i;
}
int gRight(int i)
{
	return ((2 * i) + 1);
}

//builds a minHeap
void HEAP::buildMinHeap(HEAP* a)//buildHeap(pointer to array heap?)
{
	int counter = 0;
	//a->getSize() == a->getCapacity();
	/*for(int i = (a->getCapacity()); i <= 1; i++)
	{
		//minHeapify(a, i);		//minHeapBroken
		counter++;
		a->heapifyCount++;
	} */

	for(int i = a->size/2; i >= 1; i--)
	{
		//accessing elements
		//heap->H[i]->key
		

		minHeapify(a, i);
		a->heapifyCount++;
		counter++;
	}
	
}
//builds minHeap 
void minHeapify(HEAP * a, int i)
{
	//ElementT arr = a->getH();

	int left = gLeft(i);
	int right = gRight(i);
	int root;

	
	ELEMENT *keyPtr = new ELEMENT();
	keyPtr->key = a->H->key;
	//Logic should be right but the pointer issue
	if(left <= a->getSize() && a->H[left]->key <= a->H[i]->key)
	{
		a->H[root] = a->H[left];
		//root = left;
	}
	else
	{
		a->H[root] = a->H[i];
		//root = i;
	}

	if(right <= a->getSize() && a->H[right]->key <= a->H[i]->key)
	{
		a->H[root] = a->H[right];
		//root = right;
	}
	if(root != i)
	{
		a->H->key = swap(a->H[root]->keyPtr, a->H[i]->keyPtr);
		minHeapify(a, root);
	}
	
}

//sorts the heap(min) (I think uneeded but ye)
void HEAP::heapSort(HEAP* a)
{
	buildMinHeap(a);
	for(int i = a->getCapacity(); i <= 2; i++)
	{
		swap(a->H[1], a->H[i]);
		a->size--;

	}
}

//returns the root element(doesn't remove element)
ELEMENT HEAP::getHeapMin(HEAP * a)
{
	return a->H[1];
}


//inserts an object of type ELEMENT pointed to by 
//element into the heap pointed to by heap
void HEAP::insert(HEAP* a, int obj)
{

    //This will be in main
    if (a->size== capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 
	
	// First insert the new key at the end 
	a->size++; 
	int i = a->size - 1; 
	//a->H[i].key = obj; 
	ELEMENT *keyPtr = new ELEMENT();
	keyPtr->key = obj;
	a->H[i] = *keyPtr;

	/*// Fix the min heap property if it is violated 
	while (i != 0 && a->H[getParent(i)]->key > a->H[i]->key) 
	{ 
	eSwap(a->H[i], a->H[getParent(i)]); 
	i = getParent(i); 
	} */
    

   //added element, size++ ADD TO MAIN MAYBE
   /*
	Xue Slides
	heap-size[a]++; //a->size++;
	i = heap-size[a]; //i = a->size;
	a[i] = (negative inifity);
	heap-decrease-key(A,i,key(OBJ))
   */
}

//deletes the minimum element from the 
//heap pointed to by heapand prints them
int extractMin(HEAP* a)
{	
	

	//will be in main
	if(a->getSize() < 1)
	{
		cout << "heap is empty\n";
	}

	//print deleted key
	ELEMENT *keyPtr = new ELEMENT();
	keyPtr->key = a->H[1]->key;
	a->H[1]->key = *keyPtr;
	cout << "Deleted key: " << keyPtr << endl;

	int min;
	int min = a->H[1]->keyPtr;
	a->H[1] = a->H[a->size];
	a->size = a->size - 1;
	//minHeapify(a,1);
	return min;

    /* 
    if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root;
    */

   //removes the element, size--
   a->size--;
}

//right method but pointers are rough
//decreases the key of heap->H[index] to value
void decreaseKey(HEAP* a, int index, int value)
{ 	//main call: mainHeap->decreaseKey(mainHeap, n, f);
	

	if (value > a->H[index-1]->key)
	{
		cout << "key is larger than current key";
	}
	a->H[i]->key = k;
	while (i > 1 && a->H[a->getParent(i)] > a->H[i])
	{
		eSwap(a->H[i], a->H[a->getParent(i)]);
		i = a->getParent(i);
	}
	
	/*
	Xue Slides
	if key < a[i]
	{
		cout << "Error";
	}
	else
	a[i] = key;
		while(i > 1 and a[getParent(i) < a[i]])
		{
			eSwap(a[i], a[getParent(i)]);
			i = getParent(i);
		}
	 */
}










