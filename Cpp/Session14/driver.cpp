#include "BST.h"
#include <iostream>

int main()
{
    BST b, *root = NULL;

	root = b.Insert(root, 50);
	b.Insert(root, 20);
	b.Insert(root, 60);
	b.Insert(root, 27);
	b.Insert(root, 33);
	b.Insert(root, 90);
	b.Insert(root, 45);
    b.Insert(root, 100);
    b.Insert(root, 50);
    BST* keyChild = b.search(root,90);

    if(keyChild->data == 90)
    {
        std::cout <<"Found key" << std::endl;
    }

	return 0;
}