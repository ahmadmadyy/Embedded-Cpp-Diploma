#include <iostream>

namespace mystandard
{
    template <typename T>
    class SmartPointer
    {
        public:
            explicit SmartPointer(T* ptr = NULL)
            {
                p = ptr;
            }

            ~SmartPointer()
            {
                delete (p);
            }

            T& operator*() // Overloading dereferencing operator
            {
                return *p;
            }
        private: 
            T* p;
    };
}

int main()
{
    mystandard::SmartPointer<int> pointer(new int());
    *pointer = 100;
    std::cout << "Pointer: " << *pointer << std::endl;

    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, the destructor for it is automatically
    // called and destructor does delete ptr.

}