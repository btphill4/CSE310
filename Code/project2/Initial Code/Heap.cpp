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
	//size = 0; //correct I think
    size = 12;	//wrong I think

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
//==================END Project 1=========================//

// Project 2 Methods //
//to swap the KEYS in the array
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

//return the parent node value 
int HEAP::getParent(int i)
{
	return i/2;
}
//returns the left node value *BROKEN*
int HEAP::getLeft(int i)
{
	return 2*i;
	//i ;//= a->H[i/2]->key;
	//return i;

}

//returns the right node value *BROKEN*
int HEAP::getRight(int i)
{
	return ((2 * i) + 1);
	//i; //= a->H[2*i]->key;
	//int* iPtr;
	//return iPtr;
}

//builds a minHeap
void HEAP::buildMinHeap(HEAP*  a)
{
	a->getSize() == a->getCapacity();
	for(int i = (a->getCapacity()); i <= 1; i++)
	{
		//minHeapify(a, i);
	} 
}
//builds minHeap 
void minHeapify(HEAP * a, int i)
{
	int * l;
	int left;
	//left = a->H[i]->getLeft(i);
	l = &left;
	//int right = a->getRight(i);
	int root;

	//THE LOGIC IS HERE BUT THE GETLEFT AND RIGHT ARE WRONG//
	/*if(left >= a->getSize() && a->H[left] < a->H[i])
	{
		root = left;
	}
	else
	{
		root = i;
	}

	if(right <= a->getSize() && a->H[right] < a->H[root])
	{
		root = right;
	}
	if(root != i)
	{
		swap(a->H[i], a->H[root]);
		minHeapify(a, root);
	}*/
	
}

//sorts the heap(min)
void HEAP::heapSort(HEAP* a)
{
	buildMinHeap(a);
	for(int i = a->getCapacity(); i <= 2; i++)
	{
		swap(a->H[1], a->H[i]);
		a->size--;

	}
}

//returns the root element(doesn't remove)
ELEMENT HEAP::getHeapMin(HEAP * a)
{
	return a->H[1];
}


//inserts element in the array 
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

   //added element, size++ ADD TO MAIN MAYBE
   a->size++;
}

//prints and removes the root element
int extractMin(HEAP* a)
{
	if(a->getSize() < 1)
	{
		cout << "heap is empty\n";
	}

	int min;
	//int min = a->H[1]->key;
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
void decreaseKey(HEAP* a, int i, int k)
{ /*
	if (k > a->H[i]) //->key)
	{
		cout << "key is larger than current key";
	}
	a->H[i]->key = k;
	while (i > 1 && a->H[a->getParent(i)] > a->H[i])
	{
		swap(a->H[i], a->H[a->getParent(i)]);
		i = a->getParent(i);
	}
	*/
}










