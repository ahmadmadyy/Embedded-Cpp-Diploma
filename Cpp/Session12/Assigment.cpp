#include <iostream>
#include <string.h>

class String
{
    public:
        String(const char* string) // Parametrized Constructor
        {
            std::cout << "Created" << std::endl;
            mSize = strlen(string);
            m_data = new char[mSize];
            memcpy(m_data,string,mSize); // copy data from string to m_data
        }

        String(const String& other) // Copy Constructor
        {
            std::cout << "Copied" << std::endl;
            mSize = other.mSize;
            m_data = new char[mSize];
            memcpy(m_data,other.m_data,mSize); 
        }

        String(String&& other) //rvalue reference, Move Constructor
        {
            std::cout << "Moved" << std::endl;
            mSize = other.mSize;
            m_data = other.m_data;
            other.mSize = 0;
            other.m_data = nullptr;
        }

        void print()
        {
            for(int i=0;i<mSize;i++)
            {
                std::cout << m_data[i];
            }
            std::cout << std::endl;
        }

    ~String() // Destructor
    {
        delete m_data;
    }

    private:
        char *m_data;
        uint32_t mSize;
};

class Entity
{
    public:
        Entity(const String& name) : mName(name)
        {

        }

        Entity(String&& name) : mName(std::move(name))
        {

        }

        void printName()
        {
            mName.print();
        }

    private:
        String mName;
};

int main()
{
    String str1("Embedded Systems");
    String str2("Autonomous Systems");
    Entity entity1(std::move(str1));
    Entity entity2(str2);
    entity1.printName();
    entity2.printName();
}