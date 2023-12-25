#include <iostream>
#include <vector>


class PageObject 
{
   public:
      virtual void addItem(PageObject a) { }
      virtual void removeItem() { }
      virtual void deleteItem(PageObject a) { }
};

class Page : public PageObject 
{
   public:
      void addItem(PageObject a) {
      std::cout << "Item added into the page" << std::endl;
   }
   void removeItem() {
      std::cout << "Item Removed from page" << std::endl;
   }
   void deleteItem(PageObject a) {
      std::cout << "Item Deleted from Page" << std::endl;
   }
};

//combining inheritance and composition
class Copy : public PageObject 
{
   std::vector<PageObject> copyPages;
   public:
      void AddElement(PageObject a) {
         copyPages.push_back(a);
      }
      void addItem(PageObject a) {
         std::cout << "Item added to the copy" << std::endl;
      }
      void removeItem() {
         std::cout << "Item removed from the copy" << std::endl;
      }
      void deleteItem(PageObject a) {
         std::cout << "Item deleted from the copy";
      }
};

int main() {
   Page p1;
   Page p2;

   Copy myCopy;

   myCopy.AddElement(p1);
   myCopy.AddElement(p2);

   myCopy.addItem(p1);

   p1.addItem(p2);
   
   myCopy.removeItem();
   p2.removeItem();
}