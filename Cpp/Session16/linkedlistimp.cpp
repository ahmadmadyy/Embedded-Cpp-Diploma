#include <iostream>
#include <memory>
#include <functional>

/*
    std::function<void(std::shared_ptr<Node>)> callback = void (*callback)(Node*)     
*/

namespace Container
{

    struct Record
    {
        std::string name;
        std::string address;
    };

    struct Node
    {
        Record record;
        std::shared_ptr<Node> Next;
    };

    // void traverse(std::shared_ptr<Node>& Head, 
    //                          void (*callback)(std::shared_ptr<Node> Node))
    void traverse(std::shared_ptr<Node>& Head, 
                                    std::function<void(std::shared_ptr<Node>)> callback)
    {
        while(Head)
        {
            callback(Head);
            Head = Head->Next;
        }
    }
}

void print(std::shared_ptr<Container::Node> Head)
{
    std::cout << Head->record.name << " " << Head->record.address << std::endl;
}

int main()
{
    // Container::Node *Head = new Container::Node;
    // Container::Node *FirstNode = new Container::Node;
    // Container::Node *SecondNode = new Container::Node;
    // Container::Node *ThirdNode = new Container::Node;

    //std::shared_ptr<Container::Node> Head = std::make_shared<Container::Node>();

    auto Head = std::make_shared<Container::Node>();
    auto FirstNode = std::make_shared<Container::Node>();
    auto SecondNode = std::make_shared<Container::Node>();
    auto ThirdNode = std::make_shared<Container::Node>();

    Head->record.name = "Ahmed";
    Head->record.address = "Nasr City";
    Head->Next = FirstNode;

    FirstNode->record.name = "Ali";
    FirstNode->record.address = "Smart Village";
    FirstNode->Next = SecondNode;

    SecondNode->record.name = "Marwan";
    SecondNode->record.address = "Giza";
    SecondNode->Next = ThirdNode;

    ThirdNode->record.name = "Youssef";
    ThirdNode->record.address = "New Cairo";
    ThirdNode->Next = nullptr;

    Container::traverse(Head,print);

    // delete ThirdNode;
    // delete SecondNode;
    // delete FirstNode;
    // delete Head;
    
}