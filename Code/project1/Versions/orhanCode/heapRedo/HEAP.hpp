#ifndef HEAP_HPP
# define HEAP_HPP


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
        ElementT *H;

        //constructor
        HEAP();
        HEAP(int n);

        HEAP* initialize(int n);
        void heapPrint(HEAP* heapPtr);

        //getter methods
        /*int getCapacity()
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
        }*/

        int getSize();
        int getCapacity();
        ElementT* getH();

        int setSize();
        int setCapacity();
        ElementT* setH();

	private:;

};

#endif