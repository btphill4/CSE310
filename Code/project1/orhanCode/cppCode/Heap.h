#ifndef heap_hpp
#define heap_hpp

class ELEMENT
{
    public:
    int key;
};

typedef ELEMENT *ElementT;

class HEAP
{
    public: 
    int capacity;
    int size = 12;
    ElementT H; 

   HEAP()
    {
        
    }
    HEAP(int n);
    /*{
        capacity = n;
        size = 12;
    }*/

    //methods for project 1
    HEAP* initialize(int n);
    void heapPrint(HEAP* a);
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
    
    //setters
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