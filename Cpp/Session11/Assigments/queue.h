#pragma once
#include <vector>
template <typename T>
class Queue
{
    public:
        Queue(int = 10); 

        ~Queue() 
        { 
            delete [] queuePtr; 
        }

        int enqueue(const T&); 

        int dequeue(T&); 

        int isEmpty() const 
        { 
            return rear == -1 ; 
        } 

        int isFull()  const
        { 
            return rear == size-1; 
        }

    private:
        int size;
        int front;
        int rear;  
        T* queuePtr; 
};

template class Queue<float>;
template class Queue<int>;