#include "queue.h"

template <class T>
Queue<T>::Queue(int s)
{
    size = s > 0 && s < 1000 ? s : 10 ;
    rear = front = -1;
    queuePtr = new T[size] ;
}
/*
template <class T>
int Queue<T>::enqueue(const T& item)
{
	if(!isFull())
	{
		queuePtr[++rear] = item;
		return 1;  // enqueue successful
	}
	return 0;  // enqueue unsuccessful
}

template <class T>
int Queue<T>::dequeue(T& item)
{
    if (!isEmpty())
	{
		item = queuePtr[front++];
		return 1 ;  // dequeue successful
	}
	return 0 ;  // dequeue unsuccessful
}
*/

template <class T>
int Queue<T>::enqueue(const T& item)
{
    if (!isFull())
    {
        if (isEmpty()) 
        {
            front = 0; // Initialize front if queue was empty
        }
        rear = (rear + 1) % size; // Circular queue behavior
        queuePtr[rear] = item;
        return 1; // enqueue successful
    }
    return 0; // enqueue unsuccessful
}

template <class T>
int Queue<T>::dequeue(T& item)
{
    if (!isEmpty())
    {
        item = queuePtr[front];
        if (front == rear) 
        {
            front = rear = -1; // Reset front and rear if queue becomes empty
        } 
        else 
        {
            front = (front + 1) % size; // Circular queue behavior
        }
        return 1; // dequeue successful
    }
    return 0; // dequeue unsuccessful
}