#ifndef heap_h
#define heap_h

// ELEMENT is  a  data  type  that  contains  a  field  namedkey,  
// which  is  of  typeint.   Note  that ELEMENT should not be of typeint
typedef struct TAG_ELEMENT
{
    int key;
}ELEMENT;

//Array of pointers type, type ELEMENT Pointer
typedef ELEMENT *ElementT;  

// HEAP is a data type that contains three fields named capacity(of typeint),
// size(of typeint),and H(an array of type 
// ELEMENT with index ranging from 0 to capacity)
typedef struct TAG_HEAP
{
    
    int capacity; /* max size of the heap */
    int size = 12; /* current size of the heap */
    ElementT *H; /* points to array of n + 1 pointers(of type *Element) pointer to pointers to elements (**Element)*/
    
  
    //methods//
    HEAP* initalize(int n);  
    //void heapPrint(heap* );
    void heapPrint(HEAP*);
    HEAP* getPointer(heapPtr);
    
}HEAP;


#endif

/** 
 typedef struct {
  int n;
  boolean success;
  char s[16];
} my_struct_t; 

  my_struct_t myStruct = {10, true, "Hello!"}; 
  my_struct_t * ptr; */


/**
 * void percUp(HEAP *H, int pos);
 * Function: PercUp
 * Usage: PercUp(heap, position)
 * 
 * percUp goes to the node at the position and percolates it up the tree
 * until the heap order is satisfied
 * 
 * void percDown(HEAP *H, int pos);
 * Function: PercDown
 * Usage: PerkDown(heap, position)
 * 
 * percDown goes to the node at the position and percolates it down the tree
 * until the heap order is satisfied
 */







/** Given Code

typedef struct TAG_ELEMENT{
    int key;
}ELEMENT;

typedef ELEMENT *ElementT;

typedef struct TAG_HEAP{
    int capacity;       // max size of the heap 
    int size;           // current size of the heap 
    ElementT *H;        // pointer to pointers to elements 
}HEAP;

*/