include <iostream>
#include <string>
#include <queue>

using namespace std;

class avl_node {
    int value;
    string word;
    avl_node *left, *right;

public:
    friend class avlTree;
};

class avlTree {
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
    void bfs_display(avl_node *);

    avlTree() {
        root = NULL;
    }

    void insertWrapper() {
        char ch;
        do {
            avl_node *temp = new avl_node;
            cout << "Enter word: ";
            cin >> temp->word;
            root = insert(root, temp);
            cout << "Enter 'Y' to continue inserting: ";
            cin >> ch;
        } while (ch == 'Y');
    }

    avl_node* getRoot() {
        return root;
    }
};

int avlTree::height(avl_node *temp) {
    int h = 0;
    if (temp != nullptr) {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int avlTree::diff(avl_node *temp) {
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int balance_factor = l_height - r_height;
    return balance_factor;
}

avl_node *avlTree::rr_rotation(avl_node *parent) {
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node *avlTree::ll_rotation(avl_node *parent) {
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node *avlTree::lr_rotation(avl_node *parent) {
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

avl_node *avlTree::rl_rotation(avl_node *parent) {
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

avl_node *avlTree::balance(avl_node *temp) {
    int bal_factor = diff(temp);
    if (bal_factor > 1) {
        if (diff(temp->left) > 0)
            return ll_rotation(temp);
        else
            return lr_rotation(temp);
    } else if (bal_factor < -1) {
        if (diff(temp->right) > 0)
            return rl_rotation(temp);
        else
            return rr_rotation(temp);
    }
    return temp;
}

avl_node *avlTree::insert(avl_node *root, avl_node *temp) {
    if (root == NULL) {
        root = new avl_node;
        root->word = temp->word;
        root->left = NULL;
        root->right = NULL;
    } else if (temp->word < root->word) {
        root->left = insert(root->left, temp);
        root = balance(root);
    } else if (temp->word >= root->word) {
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    return root;
}

void avlTree::display(avl_node *ptr, int level) {
    if (ptr != NULL) {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
            cout << "Root -> ";
        for (int i = 0; i < level && ptr != root; i++)
            cout << " ";
        cout << ptr->word;
        if (ptr->left && ptr->right) {
            string rotation = diff(ptr) > 1 ? "Left " : "Right ";
            rotation += diff(ptr->left) > 0 ? "Left" : "Right";
            cout << " (Balanced by " << rotation << " rotation)";
        }
        display(ptr->left, level + 1);
    }
}

void avlTree::bfs_display(avl_node *root) {
    if (root == NULL)
        return;

    queue<avl_node *> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();
        while (nodeCount > 0) {
            avl_node *node = q.front();
            q.pop();
            cout << node->word << " ";
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

int main() {
    avlTree tree;
    tree.insertWrapper();
    cout << "BFS Display:" << endl;
    tree.bfs_display(tree.getRoot());