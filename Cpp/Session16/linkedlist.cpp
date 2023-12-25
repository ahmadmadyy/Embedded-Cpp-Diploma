#include <iostream>
#include <memory>
#include <functional>

/*
Changed all raw pointers to smart pointers, included search using traverse and callback
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
        std::shared_ptr<Node> Next;  // Node *Next;
    };

    // void (*callback)(Container::Node*)
    void Traverse(std::shared_ptr<Node> Head, 
                                    std::function<void(std::shared_ptr<Node>)> callback)
    {
        while(Head)
        {
            callback(Head);
            Head = Head->Next;
        }
    }

    void Traverse(std::shared_ptr<Node> Head, 
        std::function<void(std::shared_ptr<Node>, std::string key, std::string&)> callback, 
                                                std::string key, std::string &result)
        {
            while(Head)
            {
                callback(Head,key,result);
                Head = Head->Next;
            }
        }

}

void print(std::shared_ptr<Container::Node> Head) 
{
    std::cout << Head->record.name << " " << Head->record.address << std::endl;        
}

void search(std::shared_ptr<Container::Node> Head, std::string key, std::string &result)
{
    if(Head->record.name == key)
    {
        result = Head->record.address;
    }
}

void searching(std::shared_ptr<Container::Node> Head, std::string key, std::string &result)
{
    Container::Traverse(Head, search, key, result);
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

    Container::Traverse(Head,print);

    // delete ThirdNode;
    // delete SecondNode;
    // delete FirstNode;
    // delete Head;

    return 0;
}