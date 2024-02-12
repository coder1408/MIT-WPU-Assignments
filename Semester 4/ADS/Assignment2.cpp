#include <iostream>
#include <string>
using namespace std;

class treenode
{
    string word;
    string meaning;
    treenode *right, *left;
    friend class tree;
};

class queue
{
private:
    struct Node
    {
        treenode *data;
        Node *next;
        Node(treenode *value) : data(value), next(nullptr) {}
    };

    Node *front;
    Node *rear;

public:
    queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(treenode *value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    treenode *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return nullptr;
        }
        else
        {
            Node *temp = front;
            treenode *value = temp->data;

            if (front == rear)
            {
                front = rear = nullptr;
            }
            else
            {
                front = front->next;
            }

            delete temp;
            return value;
        }
    }
};

class tree
{
    treenode *root;
    queue q;

public:
    tree()
    {
        root = nullptr;
    }
    void create_dictionary();
    void search_word();
    void display_dictionary();
    string search_word_r(treenode *temp, const string &word);
    treenode *copy_dictionary(treenode *root);
    void copy_dictionary();
    void mirror_r(treenode *root);
    void mirror_r()
    {
        mirror_r(root);
        display_dictionary();
    }
    void delete_node();
    void mirror_nr();
};

void tree::create_dictionary()
{
    root = new treenode;
    cout << "Enter Word for root" << endl;
    cin >> root->word;
    cout << "Enter Meaning for " << root->word << endl;
    cin.ignore();
    getline(cin, root->meaning);
    root->left = nullptr;
    root->right = nullptr;

    char choice = 'y';
    do
    {
        treenode *temp, *curr;
        temp = root;
        int flag = 0;

        curr = new treenode;
        curr->left = nullptr;
        curr->right = nullptr;
        cout << "Enter Word: " << endl;
        cin >> curr->word;

        while (flag == 0)
        {
            if (curr->word == temp->word)
            {
                cout << "Word already exists in the dictionary." << endl;
                flag = -1;
                delete curr;
            }
            else if (curr->word < temp->word)
            {
                if (temp->left == nullptr)
                {
                    cout << "Enter Meaning for " << curr->word << endl;
                    cin.ignore();
                    getline(cin, curr->meaning);
                    temp->left = curr;
                    flag = 1;
                }
                else
                    temp = temp->left;
            }
            else if (curr->word > temp->word)
            {
                if (temp->right == nullptr)
                {
                    cout << "Enter Meaning for " << curr->word << endl;
                    cin.ignore();
                    getline(cin, curr->meaning);
                    temp->right = curr;
                    flag = 1;
                }
                else
                    temp = temp->right;
            }
        }
        cout << "Do you want to add another word?(y or n)" << endl;
        cin >> choice;
    } while (choice == 'y');
}

void tree::display_dictionary()
{
    treenode *temp = nullptr;
    if (root == nullptr)
    {
        cout << "Dictionary is empty" << endl;
        return;
    }
    else
    {
        int p = 1, r = 0; // Initialize p to 1
        temp = root;
        q.enqueue(temp);
        while (!q.isEmpty())
        {
            for (int i = 0; i < p && !q.isEmpty(); i++) // Adjust loop condition
            {
                temp = q.dequeue();
                cout << temp->word << ": " << temp->meaning << " "; // Separate word and meaning with space

                if (temp->left != nullptr)
                {
                    q.enqueue(temp->left);
                    r++;
                }
                if (temp->right != NULL)
                {
                    q.enqueue(temp->right);
                    r++;
                }
            }

            cout << endl;
            p = r;
            r = 0;
        }
    }
}

void tree::search_word()
{
    char choice = 'y';
    do
    {
        string word;
        cout << "Enter word to be searched: " << endl;
        cin >> word;
        string meaning = search_word_r(root, word);
        if (!meaning.empty())
            cout << "Meaning: " << meaning << endl;
        else
            cout << "Word not found in the dictionary" << endl;
        cout << "Do you want to search another word?" << endl;
        cin >> choice;
    } while (choice == 'y');
}

string tree::search_word_r(treenode *temp, const string &word)
{
    if (temp == nullptr)
        return ""; // Not found
    else if (temp->word == word)
        return temp->meaning; // Found
    else if (word < temp->word)
        return search_word_r(temp->left, word);
    else
        return search_word_r(temp->right, word);
}

treenode *tree::copy_dictionary(treenode *root)
{
    treenode *temp = nullptr;
    if (root != NULL)
    {
        temp = new treenode;
        temp->word = root->word;
        temp->meaning = root->meaning;
        temp->left = copy_dictionary(root->left);
        temp->right = copy_dictionary(root->right);
    }
    return temp;
}

void tree::copy_dictionary()
{
    tree copyDict;
    copyDict.root = copy_dictionary(root);
    cout << "Copied Dictionary: " << endl;
    copyDict.display_dictionary();
}

void tree::mirror_r(treenode *root)
{
    if (root == nullptr)
        return;

    // Swap left and right subtrees
    treenode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirror_r(root->left);
    mirror_r(root->right);
}

void tree::mirror_nr()
{
    if (root == nullptr)
    {
        cout << "Dictionary is empty" << endl;
        return;
    }

    queue q;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        treenode *current = q.dequeue();

        // Swap left and right pointers of the current node
        treenode *temp = current->left;
        current->left = current->right;
        current->right = temp;

        // Enqueue the left child if it exists
        if (current->left != nullptr)
        {
            q.enqueue(current->left);
        }

        // Enqueue the right child if it exists
        if (current->right != nullptr)
        {
            q.enqueue(current->right);
        }
    }

    cout << "Mirrored Dictionary:" << endl;
    display_dictionary();
}

void tree::delete_node()
{
    string word;
    cout << "Enter word to be deleted: " << endl;
    cin >> word;

    treenode *temp = root;
    treenode *parent = nullptr;
    treenode *curr = nullptr;

    while (temp != nullptr && temp->word != word)
    {
        parent = temp;
        if (word < temp->word)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == nullptr)
    {
        cout << "Word not found in the dictionary" << endl;
        return;
    }

    curr = temp;

    if (curr == root)
    {
        // Handle case when the node to be deleted is the root
        if (curr->left == nullptr)
        {
            root = curr->right;
        }
        else if (curr->right == nullptr)
        {
            root = curr->left;
        }
        else
        {
            treenode *s = curr->right;
            while (s->left != nullptr)
            {
                s = s->left;
            }
            s->left = curr->left;
            root = curr->right;
        }
    }
    else
    {
        // Handle other cases
        if (curr->left == nullptr && curr->right == nullptr)
        {
            // Node has no children
            if (parent->left == curr)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        else if (curr->left == nullptr)
        {
            // Node has only right child
            if (parent->left == curr)
            {
                parent->left = curr->right;
            }
            else
            {
                parent->right = curr->right;
            }
        }
        else if (curr->right == nullptr)
        {
            // Node has only left child
            if (parent->left == curr)
            {
                parent->left = curr->left;
            }
            else
            {
                parent->right = curr->left;
            }
        }
        else
        {
            // Node has both left and right children
            treenode *s = curr->right;
            while (s->left != nullptr)
            {
                s = s->left;
            }
            s->left = curr->left;

            if (parent->left == curr)
            {
                parent->left = curr->right;
            }
            else
            {
                parent->right = curr->right;
            }
        }
    }

    curr->right = nullptr;
    curr->left = nullptr;
    delete curr;
}

int main()
{
    tree dictionary;
    int choice;
    do
    {
        cout << "1. Create Dictionary" << endl;
        cout << "2. Search Word" << endl;
        cout << "3. Display Dictionary" << endl;
        cout << "4. Copy Dictionary" << endl;
        cout << "5. Mirror Dictionary (Recursive)" << endl;
        cout << "6. Mirror Dictionary (Non-Recursive)" << endl; // Added "Non-Recursive" to the option "Mirror Dictionary
        cout << "7. Delete word" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            dictionary.create_dictionary();
            break;
        case 2:
            dictionary.search_word();
            break;
        case 3:
            dictionary.display_dictionary();
            break;
        case 4:
            dictionary.copy_dictionary();
            break;
        case 5:
            dictionary.mirror_r();
            break;
        case 6:
            dictionary.mirror_nr();
            break;
        case 7:
            dictionary.delete_node();
            break;
        case 8:
            cout << "Exiting.." << endl;
            break;
        default:
            cout << "Invalid Choice.." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}
