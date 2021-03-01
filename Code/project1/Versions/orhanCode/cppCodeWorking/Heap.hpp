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
    ElementT H; 

   HEAP()
    {
        
    }
    HEAP(int n)
    {
        capacity = n;
        size = 12;
    }

    //methods for project 1
    HEAP* initialize(int n);
    void heapPrint(HEAP* a);
    void buildHeap();

void setH(ElementT H);
void setCapacity(int capacity);
void setSize(int size);
ElementT getH();
int getCapacity();
int getSize();



};


#endif