/** 
 * Author: Brandon Phillips
 * Function: TThis hold the heap class methods
 * from Heap.h to be used in the main
*/


#include "Heap.hpp"
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

// Project 2 Methods //
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

//inserts element 
void HEAP::insert(HEAP* a, ElementT obj)
{
    /*
    if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	// First insert the new key at the end 
	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	// Fix the min heap property if it is violated 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	swap(&harr[i], &harr[parent(i)]); 
	i = parent(i); 
	} 
    */
}
void extractMin(HEAP* a)
{
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
}
void decreaseKey(HEAP* a, int index, int value)
{
    /*
    harr[i] = new_val; 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	swap(&harr[i], &harr[parent(i)]); 
	i = parent(i); 
	} 
    */
}

int HEAP::getLeft(int i)
{
	return 2*i;
}

int HEAP::getRight(int i)
{
	return (2*i) + 1;
}

void minHeapify(int size, HEAP * a, int i)
{
	/*int left = a->H->key->getLeft(i);
	int right = a->getRight(i);
	int floor;

	if(left <= a->getSize() && a->H[left] < a->H[i])
	{
		floor = left;
	}
	else
	{
		floor = i;
	}

	if(right <= a->getSize() && a[right] < a[i])
	{
		swap(a[floor],a[i]);
		minHeapify(size, a, floor)
	}*/


    /*
    int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l] < harr[i]) 
		smallest = l; 
	if (r < heap_size && harr[r] < harr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
		MinHeapify(smallest); 
	} 
    */
}






