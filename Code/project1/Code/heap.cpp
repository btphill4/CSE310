#include "heap.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//Variables accessible outside of methods
HEAP tempH;
HEAP *heapPointer;

//Pointer notes
// my_struct_t myStruct = {10, true, "Hello!"}; 
// my_struct_t * ptr;
// ptr = &myStruct;




 /*Creates object of type heap
    int Capacity = int n, int size = 12?, **Element H
    H is pointing to an array of n + 1 pointers 
    Returns a pointer to H (HEAP* heapPointer) */
HEAP*::intialize(int n)
{
    /*points to an ELEMENT struct array called ElementA
      ElementT points at ElEMENT, ELEMENT A is a type pointer to Element* */

    ElementT ElementA[n+1];  //ElementA will hold pointer to ELEMENT.key values
    
    /* intialize the HEAP tempH */
    //tempH = {n,12,ElementA};   //*H = ElementT* ElementA[n+1] 

    tempH.capacity = n;
    tempH.size = 12;
    tempH.H = ElementA;

    //dynamically adjust the HEAP *heapPointer to capcity(n) + 1
    heapPointer = (HEAP*) malloc(n+1);
    heapPointer = &tempH;

    return heapPointer;    //pointer to type object
} 

//method to return the pointer to use for other methods
HEAP*::getPointer(heapPointer)
{
    return heapPointer;
}

/** 
 * prints out the heap information including capacity, 
 * size, and the key fields of the element 
 * in the array with index from  to size
*/
void heapPrint(heapPointer)
{

    //print the capity and size
    cout << "capcity=" << HEAP::capacity << ", size=" 
    << HEAP::size << endl;

    //print the HEAP from size 1
    for(int i = 0; i <= size; i++)
    {
        
    }
}




