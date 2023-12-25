#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"

class Manager : public employee
{
    public:
    Manager(int id, std::string name, int &salary) : 
                employee(id, name, salary)
    {
    }

    private:

};

#endif