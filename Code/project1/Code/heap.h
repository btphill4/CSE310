#ifndef heap_h
#define heap_h

/** 
    Example (C++ style):
	class contact { 
	  char name[30];
	  int phone;
	};
	p = new contact;
*/



// ELEMENT is  a  data  type  that  contains  a  field  namedkey,  
// which  is  of  typeint.   Note  that ELEMENT should not be of typeint
typedef struct TAG_ELEMENT
{
    int key;
}ELEMENT;


typedef ELEMENT *ElementT;  //points to an ELEMENT struct called ElementT

// HEAP is a data type that contains three fields named capacity(of typeint),
// size(of typeint),and H(an array of type 
// ELEMENT with index ranging from 0 to capacity)
typedef struct TAG_HEAP
{
    
    int capacity; /* max size of the heap */
    int size; /* current size of the heap */
    ElementT *H; /* pointer to pointers to elements (**Element)*/
    int n;

    //methods//
    ELEMENT* initalize(int n);  
    void heapPrint(HEAP *H);
    //void percUp(HEAP *H, int pos);
    //void percDown(HEAP *H, int pos);
    //int getSize();

}HEAP;

    
/** 
 typedef struct {
  int n;
  boolean success;
  char s[16];
} my_struct_t; 

  my_struct_t myStruct = {10, true, "Hello!"}; 
  my_struct_t * ptr;*/


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

#endif





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