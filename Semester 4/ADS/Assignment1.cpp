#include <iostream>

using namespace std;

class treenode
{
    int data;
    treenode *left, *right;
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
    void create_nr();
    void inorder_r(treenode *root);
    void inorder_r();
    void preorder_r(treenode *root);
    void preorder_r();
    void postorder_r(treenode *root);
    void postorder_r();
};

void tree::create_nr()
{
    if (root == NULL)
    {
        root = new treenode;
        cout << "Enter data for root node: " << endl;
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
    }

    char choice1;
    char choice;

    do
    {
        treenode *temp, *curr;
        temp = root;
        int flag = 0;

        curr = new treenode;
        curr->left = NULL;
        curr->right = NULL;
        cout << "Enter data for node: " << endl;
        cin >> curr->data;

        

        while (flag == 0)
        {
            cout << "Do you want to enter the node to the left or to the right of " << temp->data << "? (l or r)" << endl;
            cin >> choice;

            if (choice == 'l')
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        cout << "Do you want to enter new node? (y or n)" << endl;
        cin >> choice1;
    } while (choice1 == 'y');
}

void tree::inorder_r()
{
    inorder_r(root);
}
void tree::inorder_r(treenode *root)
{
    if(root != NULL)
    {
        inorder_r(root->left);
        cout << root->data << " " << endl;
        inorder_r(root->right);
    }
}

void tree::preorder_r()
{
    preorder_r(root);
}
void tree::preorder_r(treenode *root)
{
    if(root != NULL)
    {
        cout << root->data << " " << endl;
        preorder_r(root->left);
        preorder_r(root->right);
    }
}

void tree::postorder_r()
{
    postorder_r(root);
}
void tree::postorder_r(treenode *root)
{
    if(root != NULL)
    {
        postorder_r(root->left);
        postorder_r(root->right);
        cout << root->data << " " << endl;
    }
}

int main()
{
    tree bt;
    char choice;
    do
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Create a binary tree" << endl;
        cout << "2. Display the tree in inorder" << endl;
        cout << "3. Display the tree in preorder" << endl;
        cout << "4. Display the tree in postorder" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
            bt.create_nr();
            break;
        case '2':
            bt.inorder_r();
            break;
        case '3':
            bt.preorder_r();
            break;
        case '4':
            bt.postorder_r();
            break;
        case '5':
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != '5');
}