#include <iostream>

template <class T>
class CountedPtr
{
    public:
        long *count;
        T* ptr;

        CountedPtr(T* p) : ptr(p) // Constructor
        {
            count = new long{1};
        }

        CountedPtr(const CountedPtr& other) // copy constructor
        {
            this->ptr = other.ptr;
            this->count = other.count;
            (*count)++;
        }

        T& operator*() // dereference operator for fundamental data types
        {
            return *ptr;
        }

        T& operator->() // dereference operator for user defined data types
        {
            return ptr;
        }

        ~CountedPtr()
        {
            (*count)--;
            if(*count == 0)
            {
                delete ptr;
                delete count;
            }
        }
};

void function(CountedPtr<int> ptr)
{
    std::cout << "Function is called, count = "  << *ptr.count << std::endl;
}

int main()
{
    CountedPtr<int> ptr1(new int(5));
    CountedPtr<int> ptr2(ptr1);
    std::cout << "count = " << *ptr2.count << std::endl; 
                                // displays the count of the shared pointer // 2
    function(ptr2);
    std::cout << "count = " << *ptr2.count << std::endl; 
                                    // displays the count of the shared pointer // 3

    return 0;
}