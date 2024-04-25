#include <iostream>
#include <string>
using namespace std;

class avl_node
{
public:
    string word, meaning;
    avl_node *left, *right;
    friend class avlTree;
};

class avlTree
{
private:
    avl_node *root;

public:
    int height(avl_node *);
    int diff(avl_node *);
    avl_node *rr_rotation(avl_node *);
    avl_node *ll_rotation(avl_node *);
    avl_node *lr_rotation(avl_node *);
    avl_node *rl_rotation(avl_node *);
    avl_node *balance(avl_node *);
    avl_node *insert();
    avl_node *insert(avl_node *, avl_node *);
    void display(avl_node *, int);
    void inorder(avl_node *);
    void preorder(avl_node *);
    void postorder(avl_node *);
    avlTree()
    {
        root = NULL;
    }
};

avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avlTree::insert()
{
    char ch;
    do
    {
        string word, meaning;
        cout << "Enter word: ";
        cin >> word;
        cout << "Enter meaning: ";
        cin >> meaning;
        avl_node *temp = new avl_node;
        temp->word = word;
        temp->meaning = meaning;
        temp->left = NULL;
        temp->right = NULL;
        root = insert(root, temp);
        cout << "Do you want to enter more words? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return nullptr;
}

avl_node *avlTree::insert(avl_node *root, avl_node *temp)
{
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    else if (temp->word < root->word)
    {
        root->left = insert(root->left, temp);
        root = balance(root);
    }
    else if (temp->word >= root->word)
    {
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    return root;
}

avl_node *avlTree::balance()


int main()
{
    avlTree tree;
    tree.insert();
    return 0;
}
