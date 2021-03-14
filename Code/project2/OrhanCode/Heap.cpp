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

	//heapifyCount = 0;
    //element pointer array
    ELEMENT* arr = new ELEMENT[n + 1];  //dynamically allocated

    H = arr;
}

//initialize, return HEAP* ptr
HEAP*	HEAP::initialize(int n)
{
	HEAP* heap = new HEAP(n);   //will be dynamically allocated in the constuctor
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
        /*if(arr[i].key == NULL)
        {
			cout << "breaks in print" << endl;
            break;
        }*/
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




//builds a minHeap
void HEAP::buildMinHeap(HEAP* a)//buildHeap(pointer to array heap?)
{
	
	//for(int i = a.size/2; i > 0; i--)
	for(int i = a->size/2; i > 0; i--)
	{
		a->minHeapify(a, i);	//this is the call to minheapify recursively
	}
	//a->minHeapify(a, )
	
}

int parent(int i)
{
	return (i) / 2;
}

//definition of the function leftChild()

// to get index of left child of node at index i

int leftChild(int i)
{
	return 2*i;
}

//definition of the function rightChild()
// to get index of right child of node at index i

int rightChild(int i)
{
	return 2 * i + 1;
}


void HEAP::minHeapify(HEAP* heap, int i)
{
	//call the function leftChild()
	int left = leftChild(i);
	//call the function rightChild()
	int right = rightChild(i);
	int smallest = i;


	if (left <= heap->size && heap->H[left].key < heap->H[i].key)
	{
	smallest = left;
	}
	if (right <= heap->size && heap->H[right].key < heap->H[smallest].key)
	{
	smallest = right;
	}

	if (smallest != i)
	{
	swap(&heap->H[i].key, &heap->H[smallest].key);
	//call the function () recursively.
	minHeapify(heap, smallest);
	}
	heap->heapifyCount++;
	}

int HEAP::extractMin(HEAP* a)
{
	int deletedKey;
	if (a->size <= 0)
	{
		//return INT_MAX;
	}

	//if the size is 1 then return that element
	if (a->size == 1)
	{
	a->size--;
	deletedKey = a->H[1].key;
	return deletedKey;
	}

	// Store the minimum value, and remove it from heap
	int min = a->H[1].key;
	a->size--;
	a->H[1].key = a->H[a->size + 1].key;

	//call the MinHeapify() function.
	minHeapify(a, 1);
	return min;

}


void HEAP::insert(HEAP *heap, int k)
{

	if (heap->size == heap->capacity)
    {
		cout << "\nOverflow: Could not Insert\n";
		return;
	}

	//insert the new key at the end

	int i = heap->size;
	heap->size++;
	heap->H[i + 1].key = k;

	buildMinHeap(heap);

	// Check the min heap property if it is violated
	while (i != 1 && heap->H[parent(i)].key > heap->H[i].key)
	{
	swap(&heap->H[i].key, &heap->H[parent(i)].key);
	i = parent(i);
	}

}

void HEAP::decreaseKey(HEAP* a, int index, int value)
{
	if (value > a->H[index].key)
	{
		cout << "key is larger than current key";
	}
	a->H[index].key = value;
	while (index > 1 && a->H[parent(index)].key > a->H[index].key)
	{
		swap(a->H[index].key, a->H[parent(index)].key);
		index = parent(index);
	}
}




