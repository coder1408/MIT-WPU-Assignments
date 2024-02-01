#include <iostream>
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
    void create_bst();
    void search();
    int search_r(treenode *temp, int num);

};

void tree::create_bst()
{
    root = new treenode;
    cout << "Enter Data for root" << endl;
    cin >> root->data;
    root->left = NULL;
    root->right = NULL;

    char choice = 'y';
    do
    {
        treenode *temp, *curr;
        temp = root;
        int flag = 0;

        curr = new treenode;
        curr->left = NULL;
        curr->right = NULL;
        cout << "Enter data: " << endl;
        cin >> curr->data;

        while (flag == 0)
        {
            if(curr->data == temp->data)
            {
                cout << "Every node in BST should contain a unique value" << endl;
                flag = -1;
                delete curr;
            }
            else if (curr->data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                else
                    temp = temp->left;
            }
            else if (curr->data > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                else
                    temp = temp->right;
            }
        }
        cout << "Do you want to add another node?(y or n)" << endl;
        cin >> choice;
    } while (choice == 'y');
}

void tree::search()
{
    char choice = 'y';
    do
    {
        int flag = 0;
        int num;
        cout << "Enter number to be searched: " << endl;
        cin >> num;
        flag = search_r(root, num);
        if (flag == 1)
            cout << "Number found!" << endl;
        else
            cout << "Number not found" << endl;
        cout << "Do you want to search another number?" << endl;
        cin >> choice;
    }
    while(choice == 'y');
}
int tree::search_r(treenode *temp, int num)
{
    if (temp == NULL)
        return 0; // Not found
    else if (temp->data == num)
        return 1; // Found
    else if (num < temp->data)
        return search_r(temp->left, num);
    else
        return search_r(temp->right, num);
}

int main()
{
    tree bt;
    int choice;
    do
    {
        cout << "1. Create Binary Search Tree" << endl;
        cout << "2. Search Brinary Tree" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            bt.create_bst();
            break;
        case 2:
            bt.search();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice.." << endl;
            break;
        }
    } while (choice != 2);
}