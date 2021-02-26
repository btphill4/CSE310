#ifndef heap_hpp
#define heap_hpp

typedef class ELEMENT
{
    public:
    int key;
};

typedef ELEMENT *ElementT;

typedef class HEAP
{
    public: 
    int capacity;
    int size;
    ElementT *H; 

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
    HEAP* intialize(int n);
    void heapPrint(HEAP* a);
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