#include <iostream>
using namespace std;
int top;

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
    void search_nr();
    void depth();
    int depth_r(treenode *temp);
    void depth_nr();
};

class stack
{
    treenode *data_stack[30];
    
public:
    stack()
    {
        top = -1;
    };
    void push(treenode *temp);
    treenode *pop();
    int isempty();
    friend class tree;
};

int stack::isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
treenode *stack::pop()
{
    treenode *temp;
    temp = data_stack[top];
    top--;
    return temp;
}
void stack::push(treenode *temp)
{
    top++;
    data_stack[top] = temp;
}

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

void tree::search_nr()
{
    int flag = 0;
    treenode *temp;
    temp = root;
    int num;

    cout <<"Enter number to be searched: " << endl;
    cin >> num;
    while(temp != NULL)
    {
        if(temp->data == num)
        {
            flag = 1;
            break;
        }
        else if(num < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
        if(flag == 1)
        {
            cout << "Number found!" << endl;
        }
        else
        {
            cout << "Number not found" << endl;
        }
    }
}

void tree::depth()
{
    int d = depth_r(root);
    cout << "Depth of the tree is: " << d << endl;
}
int tree::depth_r(treenode *temp)
{
    int t1=0, t2=0;
    if(temp == NULL)
    {
        return 0;
    }
    else
    {
        t1 = depth_r(temp->left);
        t2 = depth_r(temp->right);
    }
    if(t1 > t2)
        return ++t1;
    else
        return ++t2;
}

void tree::depth_nr()
{
    stack s;
    treenode *temp = root;
    int d = 0;

    while (1)
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
            if (s.isempty())
                break;
            else if (d < top)
                d = top;
        }

        if (s.isempty())
            break;
        else
        {
            temp = s.pop();
            temp = temp->right;
        }
    }

    cout << "Depth of the tree is: " << d+1 << endl;
}

int main()
{
    tree bt;
    int choice;
    do
    {
        cout << "1. Create Binary Search Tree" << endl;
        cout << "2. Search Brinary Tree (Recursive)" << endl;
        cout << "3. Search Binary Tree (Non-Recursive)" << endl;
        cout << "4. Depth of the Tree (Recursive)" << endl;
        cout << "5. Depth of the Tree (Non-Recursive)" << endl; 
        cout << "6. Exit" << endl;
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
            bt.search_nr();
            break;
        case 4:
            bt.depth();
            break;
        case 5:
            bt.depth_nr();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice.." << endl;
            break;
        }
    } while (choice != 6);
}