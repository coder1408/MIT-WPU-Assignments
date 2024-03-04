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
    void dfs_nr();
    void bfs();
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

class queue
{
private:
    struct Node
    {
        gnode *data;
        Node *next;
        Node(gnode *value) : data(value), next(nullptr) {}
    };

    Node *front;
    Node *rear;

public:
    queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(gnode *value)
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

    gnode *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return nullptr;
        }
        else
        {
            Node *temp = front;
            gnode *value = temp->data;

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
            cout << temp->name << "->";
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
    gnode *temp;
    for (int i = 0; i < n; i++)
    {
        if (head[i]->vertex == v)
        {
            temp = head[i];
            break;
        }
    }
    cout << temp->name << " ";
    visited[v] = 1;
    temp = temp->next;
    while (temp != NULL)
    {
        if (visited[temp->vertex] != 1)
        {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
}

void graph::dfs_nr()
{
    int visited[20];
    stack s;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    cout << "\n\ndfs (non - recursive): ";
    int v;
    cout << "\nEnter starting vertex: ";
    cin >> v;
    s.push(head[v]);
    visited[v] = 1;
    gnode *temp;
    do
    {
        temp = s.pop();
        cout << temp->name << " ";
        temp = temp->next;
        while (temp != NULL)
        {
            if (visited[temp->vertex] != 1)
            {
                s.push(head[temp->vertex]);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    } while (s.isempty() == 0);
}

void graph::bfs()
{
    int visited[20];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    queue q;
    cout << "\nBFT: ";
    int v;
    cout << "\nEnter starting vertex: ";
    cin >> v;
    q.enqueue(head[v]);
    visited[v] = 1;
    gnode *temp;
    do
    {
        temp = q.dequeue();
        cout << temp->name << " ";
        temp = temp->next;
        while (temp != NULL)
        {
            if (visited[temp->vertex] != 1)
            {
                q.enqueue(head[temp->vertex]);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    } while (q.isEmpty() == 0);
}

int main()
{
    graph map;
    int choice;
    int ch;

    do
    {
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Depth First Traversal" << endl;
        cout << "4. Breadth First Traversal" << endl;
        cout << "5. Depth First Traversal (Non-Recursive)" << endl;
        cout << "6. Exit" << endl;
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
            map.bfs();
            break;
        case 5:
            map.dfs_nr();
            break;
        case 6:
            cout << "Exiting.." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (ch != 6);

    return 0;
}
