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
	size = 0; //correct 
    //size = 12;	//wrong 

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

//parent/child methods
int getParent(int i)
{
	return (i) / 2;
}

int getLeftChild(int i)
{
	return 2*i;
}

int getRightChild(int i)
{
	return 2 * i + 1;
}

//to swap the KEYS in the array
//integer Swap
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

//builds a minHeap method
void HEAP::buildMinHeap(HEAP* a)//buildHeap(pointer to array heap?)
{
	
	//for(int i = a.size/2; i > 0; i--)
	for(int i = a->size/2; i > 0; i--)
	{
		a->minHeapify(a, i);	//this is the call to minheapify recursively
	}
	//a->minHeapify(a, )
	
}

//minHeapify function 
void HEAP::minHeapify(HEAP* a, int i)
{
	int getLeft = getLeftChild(i);
	int getRight = getRightChild(i);
	int root = i;

	//comparisions
	if (getLeft <= a->size && a->H[getLeft].key < a->H[i].key)
	{
		root = getLeft;
	}
	if (getRight <= a->size && a->H[getRight].key < a->H[root].key)
	{
		root = getRight;
	}

	if (root != i)
	{
		//swapp values
		swap(&a->H[i].key, &a->H[root].key);

		//call the function () recursively.
		minHeapify(a, root);
	}
	a->heapifyCount++;
}

void HEAP::insert(HEAP *a, int k)
{
	//if size = capacity
	if (a->size == a->capacity)
    {
		cout << "\nOverflow: Could not Insert\n";
		return;
	}

	//insert the new key at the end
	int i = a->size;
	a->size++;
	a->H[i + 1].key = k;

	//build the new heap
	buildMinHeap(a);

	// Check the min heap property if it is violated
	while (i != 1 && a->H[getParent(i)].key > a->H[i].key)
	{
		swap(&a->H[i].key, &a->H[getParent(i)].key);
		i = getParent(i);
	}

}

//decrease the key to the set value
void HEAP::decreaseKey(HEAP* a, int index, int value)
{
	if (value > a->H[index].key)
	{
		cout << "key is larger than current key";
	}
	a->H[index].key = value;
	while (index > 1 && a->H[getParent(index)].key > a->H[index].key)
	{
		swap(a->H[index].key, a->H[getParent(index)].key);
		index = getParent(index);
	}
}

//returns the minimun value and then removes it from the heap
int HEAP::extractMin(HEAP* a)
{
	int deletedKey;
	if (a->size <= 0)
	{
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


