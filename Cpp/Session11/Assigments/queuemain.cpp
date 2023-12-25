#include <iostream>
#include "queue.h"

int main()
{
    // Float:
    Queue<float> floatqueue(5);
    float f = 1.82;
    std::cout << "Adding elements onto floatqueue" << std::endl;
    //floatqueue.enqueue(5.5);
	//floatqueue.dequeue(f);
	//std::cout << f << std::endl;

    while (floatqueue.enqueue(f))
	{
		std::cout << f << ' ';
		f += 2.55;
	}
    std::cout << std::endl << "Queue Full." << std::endl << std::endl 
                                    << "Removing elements from floatqueue" << std::endl;

    while (floatqueue.dequeue(f))
    {
		std::cout << f << ' ';
    }
	std::cout << std::endl << "Queue Empty" << std::endl;
	std::cout << std::endl;

    // Int:
    Queue<int> intqueue(3);
    int i = 1;
	std::cout << "Adding elements onto intqueue" << std::endl;

    while (intqueue.enqueue(i))
	{
		std::cout << i << ' ';
		i += 1;
	}

    std::cout << std::endl << "Queue Full" << std::endl << std::endl 
                                        << "Popping elements from intqueue" << std::endl;

    while (intqueue.dequeue(i))
    {
		std::cout << i << ' ' ;
    }
	std::cout << std::endl << "Queue Empty" << std::endl;
}