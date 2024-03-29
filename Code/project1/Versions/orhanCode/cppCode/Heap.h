/** 
 * Author: Brandon Phillips
 * Function: Header file for Heap.cpp which holds
 * all the methods and variables for classes ELEMENT, ElementT, and HEAP
*/


#ifndef heap_hpp
#define heap_hpp

/** Element class that holds keys of type integer*/
class ELEMENT
{
    public:
    int key;
};

//pointer to element class to be used with an array
typedef ELEMENT *ElementT;


//heap class
class HEAP
{
    //values to be set at construction
    public: 
    int capacity;
    int size = 12;
    ElementT H; 

    //~~~constructors~~~~//
    //default
    HEAP()
    {
        
    }
    //for initalize(n)
    HEAP(int n);
    /*{
        capacity = n;
        size = 12;
    }*/


    //methods for project 1
    HEAP* initialize(int n);
    void heapPrint(HEAP* a);

    //later implementations
    void buildHeap();


    //getter methods
    int getCapacity()
    {
	    return this->capacity;
    }
    int getSize()
    {
        return 12;
        //return this->size;
    }
    ElementT getH()
    {
        return this->H;
    } 
    
    //setters methods
    void setH(ElementT sH)
    {
        H = sH;
    }

    void setCapacity(int c)
    {
        capacity = c;
    }

    void setSize(int s)
    {
        size = s;
    }

};


#endif