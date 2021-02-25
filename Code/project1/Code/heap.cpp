#include "heap.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


// my_struct_t myStruct = {10, true, "Hello!"}; 
// my_struct_t * ptr;

 /*Creates object of type heap
    int Capacity = int n, int size = 12?, **Element H
    H is pointing to an array of n + 1 pointers 
    Returns a pointer to H*/
ELEMENT*::intialize(int n)
{
    ElementT ElementA[n+1];  //points to an ELEMENT struct array called ElementA

    //intialize
    HEAP tempH = {n,12,ElementA};   //*H = ElementA[n+1] 

    //ElementT = ElementA;

    return  *ElementA;
} 


/** 
 * prints out the heap information including capacity, 
 * size, and the key fields of the element 
 * in the array with index from  to size
*/
void HEAP::heapPrint()
{
    //print the capity and size
    cout << "capcity=" << HEAP::capacity << ", size=" 
    << HEAP::size << endl;

    //print the HEAP from size 1
    for(int i = 0; i <= size; i++)
    {
        
    }
}



