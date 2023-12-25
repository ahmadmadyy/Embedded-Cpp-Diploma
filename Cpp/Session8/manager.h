#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"

class Manager : public Employee //inheritance
{
    public:
    Manager(int id,int salary,std::string name) : Employee(id,salary,name)
    // delegate constructor
    {

    }
    private:
};


#endif