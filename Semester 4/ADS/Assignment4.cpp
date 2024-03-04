#include <iostream>
#include <string>

using namespace std;
int top;

class gnode
{
    int vertex;
    string name;
    gnode *next;
    friend class graph;
};

class graph
{
private:
    gnode *head[20];
    int n;

public:
    graph();
    void create();
    void display();
    void dfs();
    void dfs(int v);
};

class stack
{
    gnode *data_stack[30];

public:
    stack()
    {
        top = -1;
    };
    void push(gnode *temp);
    gnode *pop();
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

gnode *stack::pop()
{
    gnode *temp;
    temp = data_stack[top];
    top--;
    return temp;
}

void stack::push(gnode *temp)
{
    top++;
    data_stack[top] = temp;
}

graph::graph()
{
    cout << "Enter number of persons:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        head[i] = new gnode;
        cout << "Enter name of friend " << i << " :" << endl;
        cin >> head[i]->name;
        head[i]->next = NULL;
        head[i]->vertex = i;
    }
}

void graph::create()
{
    for (int i = 0; i < n - 1; i++)
    {
        gnode *temp = head[i];
        int adj;
        char choice;
        do
        {
            cout << "Enter friend of " << head[i]->name << " (Enter vertex):" << endl;
            cin >> adj;
            if (adj == head[i]->vertex)
            {
                cout << "Self loop not allowed" << endl;
            }
            else
            {
                gnode *curr = new gnode;
                curr->vertex = adj;
                for (int j = 0; j < n; j++)
                {
                    if (head[j]->vertex == adj)
                    {
                        curr->name = head[j]->name;
                    }
                }
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Do you want to add more friends? (y/n)" << endl;
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
};

void graph::display()
{
    for (int i = 0; i < n; i++)
    {
        gnode *temp = head[i];
        cout << "Friends of " << head[i]->name << " are:" << endl;
        while (temp != NULL)
        {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void graph::dfs()
{
    int visited[20];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    cout << "Enter starting vertex:" << endl;
    int v;
    cin >> v;
    dfs(v);
}

void graph::dfs(int v)
{
    int visited[20];
    cout << head[v]->name << " ";
    visited[v] = 1;
    for(int w = 0; w < n; w++)
    {
        if(visited[w] == 0)
        {
            dfs(w);
        }
    }
}

int main()
{
    graph map;
    int choice;
    char ch;

    do
    {
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Depth First Traversal" << endl;
        cout << "4. Breadth First Traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            map.create();
            break;
        case 2:
            map.display();
            break;
        case 3:
            map.dfs();
            break;
        case 4:
            break;
        case 5:
            cout << "Exiting.." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << "Do you want to continue? (y/n)" << endl;
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
