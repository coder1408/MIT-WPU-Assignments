#include <iostream>

using namespace std;

class gnode
{
    int vertex;
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
    void prims(int startVertex);
};

graph::graph()
{
    for (int i = 0; i < 20; i++)
    {
        head[i] = new gnode;
        head[i]->vertex = i;
        head[i]->next = NULL;
    }
}

void graph::create()
{
    int n;
    cout << "Enter no. of vertices:" << endl;
    cin >> n;
    int adjMatrix[20][20]; // Fix: Declare adjMatrix as a two-dimensional array with a fixed size
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        gnode *temp = head[i];
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                gnode *newNode = new gnode;
                newNode->vertex = j;
                newNode->next = NULL;
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }
}

void graph::display()
{
    int adjMatrix[20][20];
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        gnode *temp = head[i]->next;
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
        while (temp != NULL)
        {
            adjMatrix[i][temp->vertex] = 1;
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void graph::prims(int startVertex)
{
    int cost[20][20];
    int nearest[20];
    int t[19][2];
    int mincost = 0;

    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

        nearest[startVertex] = -1;
    for (int i = 0; i < n; i++)
    {
        if (i != startVertex)
            nearest[i] = startVertex;
    }

    int r = 0;
    for (int i = 1; i < n; i++)
    {
        int min = INT_MAX;
        int j;

        // Find the minimum edge
        for (int k = 0; k < n; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]] < min)
            {
                j = k;
                min = cost[k][nearest[k]];
            }
        }

        // Update tree and total cost
        t[r][0] = j;
        t[r][1] = nearest[j];
        r = r + 1;
        mincost = mincost + cost[j][nearest[j]];
        nearest[j] = -1;

        // Update nearest for remaining vertices
        for (int k = 0; k < n; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j])
                nearest[k] = j;
        }
    }

    // Display the minimum spanning tree edges
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cout << "(" << t[i][0] << ", " << t[i][1] << ")" << endl;
    }

    // Display the minimum cost
    cout << "Minimum Cost: " << mincost << endl;
}

int main()
{
    graph g;
    int choice;
    do
    {
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Prim's algorithm" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.create();
            break;
        case 2:
            g.display();
            break;
        case 3:
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 3);
}