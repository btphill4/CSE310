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
    int size;
    ElementT *H; //

   HEAP()
    {
        /*capacity = 0;
        size = 12; */
    }
    HEAP(int n)
    {
        capacity = n;
        size = 12;
    }

    //methods for project 1
    HEAP* initialize(int n);
    HEAP* heapPrint(HEAP* heapPointer);
    void buildHeap();

    //getter methods
    int getCapacity()
    {
	    return this->capacity;
    }
    int getSize()
    {
        return this->size;
    }
    ElementT* getH()
    {
        return this-> H;
    } 
    

    //setters
    void setH(ElementT *H)
    {
        this -> H = H;
    }

    void setCapacity(int capacity)
    {
        this -> capacity = capacity;
    }

    void setSize(int size)
    {
        this -> size = size;
    }


};


#endif