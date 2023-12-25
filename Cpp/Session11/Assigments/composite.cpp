#include <iostream>
#include <vector>

class PageObject
{
    public: 
       // virtual void addItem(PageObject a) const = 0;
        virtual void addItem(PageObject* a) const = 0;
        virtual void removeItem() {}
        virtual void deleteItem(PageObject* a) {}
        virtual ~PageObject() {}
};

class Page : public PageObject
{
    public: 
        void addItem(PageObject* a) const override
        {
            std::cout << "Item is added to the page " << std::endl;
        }
        void removeItem() 
        {
            std::cout << "Item is removed from the page " << std::endl;
        }
        void deleteItem(PageObject* a) 
        {
            std::cout << "Item is deleted from the page " << std::endl;
        }
};

class Copy : public PageObject
{
    std::vector<PageObject*> copyPages;
    public:
        void addItem(PageObject* a) const override
        {
            std::cout << "Item is added to the copy " << std::endl;
        }
        void removeItem() 
        {
            std::cout << "Item is removed from the copy " << std::endl;
        }
        void deleteItem(PageObject* a) 
        {
            std::cout << "Item is deleted from the copy " << std::endl;
        }
        void AddElement(PageObject* a)
        {
            copyPages.push_back(a);
        }
};

int main()
{
    Page p1;
    Page p2;
    Page p3;
    Copy c1;
    Copy c2;

    c1.AddElement(&p1);
    c1.AddElement(&p2);
    c2.AddElement(&p3);

    c1.addItem(&p1);
    c1.addItem(&p2);
    c2.addItem(&p3);

    p1.addItem(&p2);
    p3.addItem(&p2);

    c2.removeItem();
    p2.removeItem();

    c1.deleteItem(&p2);

    //PageObject shp1; not allowed
}
