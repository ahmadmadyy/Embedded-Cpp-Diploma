#include <iostream>
#include <memory>
 
class Rectangle {
    int length;
    int breadth;
public:
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
 
    int area(){
        return length * breadth;
    }
};
 
int main(){
   
    // std::unique_ptr<Rectangle> P1(new Rectangle(10, 5)); 
                                        // 1st way to create unique pointer
    // std::unique_ptr<int> intPTR(new int[10]);
    auto P1 = std::make_unique<Rectangle>(10,5); // 2nd way to create unique pointer
    //make_unique
    std::cout << P1->area() << std::endl; // This'll print 50

    //std::unique_ptr<Rectangle> P2(P1); 
                    //ERROR, not possible since the copy or move constructor is made delete
    
    std::unique_ptr<Rectangle> P2;
    P2 = std::move(P1); // will work normally
 
    // This'll print 50
    std::cout << P2->area() << std::endl;
      
    return 0;
}