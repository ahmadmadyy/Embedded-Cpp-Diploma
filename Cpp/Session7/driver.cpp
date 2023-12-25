#include "employee.h"
int main()
{
    Employee e1;
    e1.setName("Ahmad");
    e1.setId(10);
    e1.setSalary(1000);
    e1.display();
    Employee e2 (20,500,"Ali");
    e2.display();
    
    Employee e3;
    e3.setName("Mohamed");
    e3.setId(30);
    e3.setSalary(7000);
    e3.display();

    /*
    In Object-Oriented Programming (OOP), when multiple 
    objects are created and they have destructors, the order 
    in which the destructors are called upon the destruction 
    of those objects is determined by the reverse order
    of their creation. The destructor of the first 
    created object is called last because of the way 
    objects are managed in memory and their lifecycles.

    When an object is created, memory is allocated 
    for it, and its constructor is called to initialize 
    its properties and resources. When an object goes 
    out of scope (for example, when a function finishes
    executing or when the program ends), its destructor
    is called to release any resources it holds and 
    perform cleanup operations.

    Since objects are created and destroyed in a 
    last-in, first-out (LIFO) manner, the destructor
    of the first created object will be called after 
    the destructors of the subsequently created objects.
    This ensures that any resources held by the 
    objects are properly released and cleaned up 
    in the reverse order of their creation.

    In summary, the order of destructor calls 
    follows a stack-like behavior, where the first 
    object created is the last one to be destroyed. 
    This ensures that resources are deallocated in 
    a consistent and orderly manner, preventing potential
    issues related to resource leaks or incorrect deallocation.
    */
}