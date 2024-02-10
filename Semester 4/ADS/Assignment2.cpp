#include <iostream>
#include <string>
using namespace std;

class treenode
{
public:
    string word;
    string meaning;
    treenode *right, *left;
    friend class tree;
};

class tree
{
    treenode *root;

public:
    tree()
    {
        root = nullptr;
    }
    void create_dictionary();
    void display_dictionary();
    void search_word();
    void display_dictionary();
    void display_dictionary(treenode *temp);
    string search_word_r(treenode *temp, const string &word);
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

void tree::display_dictionary(treenode *temp)
{
    if (temp != nullptr)
    {
        display_dictionary(temp->left);
        cout << temp->word << ": " << temp->meaning << endl;
        display_dictionary(temp->right);
    }
}

void tree::display_dictionary()
{
    cout << "Dictionary Entries (Inorder Traversal):" << endl;
    display_dictionary(root);
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

int main()
{
    tree dictionary;
    int choice;
    do
    {
        cout << "1. Create Dictionary" << endl;
        cout << "2. Search Word" << endl;
        cout << "3. Display Dictionary" << endl;
        cout << "4. Exit" << endl;
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
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice.." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
