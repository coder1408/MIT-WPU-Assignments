
#include <iostream>
using namespace std;

#define MAX 10

class Heap
{
    int marks[MAX];
    int n;

public:
    void accept();
    void display();
    void heapsort();
    void adjust(int a, int i);
};

void Heap::accept()
{
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

void Heap::display()
{
    cout << "\nMarks are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }
}

void Heap::heapsort()
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        adjust(n - 1, i);
    }

    cout << "\n\nMaximum marks are: " << marks[0];
    while (n > 0)
    {
        int t = marks[0];
        marks[0] = marks[n - 1];
        marks[n - 1] = t;
        n--;
        adjust(n - 1, 0);
        if (n == 1)
        {
            cout << "\nMinimum marks are: " << marks[0];
        }
    }
}

void Heap::adjust(int a, int i)
{
    while (2 * i + 1 <= a)
    {
        int j = 2 * i + 1;
        if ((j + 1 <= a) && (marks[j + 1] > marks[j]))
        {
            j++;
        }
        if (marks[i] >= marks[j])
        {
            break;
        }
        else
        {
            int temp = marks[i];
            marks[i] = marks[j];
            marks[j] = temp;
            i = j;
        }
    }
}

int main()
{
    Heap heap;
    heap.accept();
    heap.display();
    heap.heapsort();
    return 0;
}