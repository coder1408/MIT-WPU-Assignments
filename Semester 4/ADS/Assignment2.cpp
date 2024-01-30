#include<iostream>
using namespace std;

class treenode
{
    int data;
    treenode *right, *left;
    friend class tree;
};

class tree
{
    treenode *root;
    public:
        tree()
        {
            root = NULL;
        }
};
