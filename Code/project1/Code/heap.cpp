#include "heap.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/** 
 * Creates object of type HEAP with capcity n, size 0 and 
 * H points to dynamically allocated array of n+1 pointers.
 * It then returns a pointer to this object. 
*/

void HEAP::heapInit(int n)
{
    HEAP::capacity = n + 1;

} 

/** 
 * prints ou the heap information including capacity, 
 * size, and the key fields of the element 
 * in the array with index from  to size
*/
void HEAP::heapPrint(HEAP *H)
{
    //print the capity and size
    cout << "capcity=" << HEAP::capacity << ", size=" 
    << HEAP::size << endl;

    //print the HEAP
    for(int i = 0; i <= size; i++)
    {
        
    }
}


