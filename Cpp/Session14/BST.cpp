#include "BST.h"
#include <iostream>

BST::BST() : data(0), left(NULL), right(NULL) 
{

}

BST::BST(int x) 
{
    data=x;
    left = right = NULL;
}

BST* BST::Insert(BST* root, int value)
{
    if(!root)
    {
        return new BST(value);
    }

    if(root->data>value)
    {
        root->left = Insert(root->left,value);
    }
    else 
    {
        root->right = Insert(root->right,value);
    }
    return root;
}

BST* BST::search(BST* root, int key)
{
    if(root==NULL || root->data==key)
    {
        return root;
    }
    if(root->data>key)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}