#pragma once

class BST
{
    public: 
	BST(); // Default constructor.

	BST(int); // Parameterized constructor.

	BST* Insert(BST*, int);  // Insert function.

    BST* search(BST*, int); // Search Method

    int data;
	BST *left, *right; // pointer to implementation pimpl idiom
};