#include <iostream>
using namespace std;

int GetValue()
{
    return 10;
}

int& GetValueRef() // the & makes it possible to make the fcn a rvalue, 
                                                        // static makes it possible
{
    static int value = 10; // Data segment
    return value;
}

void printName(string &name)
{
    cout <<"Left Value Reference " << name << endl;
}

void printName(string&& name) //rvalue reference
{
    cout <<"Right Value Reference " << name << endl; 
}

int main()
{
    // var is lvalue , 10 is rvalue means it has no location
    int i = 10; 

    i = GetValue(); //OK
    // 10 = i; //you can't do that
    GetValueRef() = 5; // Works Fine!, baceause of the return (&) type
    
    string firstName = "Robotics"; //temp
    string lastName = "Corner"; //temp

    string fullName = firstName + lastName; // will be stored in memory, so has address
 
    printName(fullName);
    printName(firstName + lastName); // no storage in memory, so has no address, temp
                                                        //RoboticsCorner

    return 0;
}