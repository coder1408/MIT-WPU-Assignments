#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    T* data; // array to hold stack elements
    int size; // maximum size of stack
    int top; // index of top element

public:
    // constructor to create a stack of given size
    Stack(int s) {
        size = s;
        data = new T[size];
        top = -1;
    }

    // destructor to free dynamically allocated memory
    ~Stack() {
        delete[] data;
    }

    // function to push element onto stack
    void push(T element) {
        if (top == size - 1) {
            throw overflow_error("Stack Overflow");
        }
        data[++top] = element;
    }

    // function to pop element from stack
    T pop() {
        if (top == -1) {
            throw underflow_error("Stack Underflow");
        }
        return data[top--];
    }

    // function to display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter maximum size of stack: ";
    cin >> size;

    Stack<int> stack(size);

    int choice, element;
    do {
        cout << "\nChoose operation:\n1. Create Stack\n2. Push on Stack\n3. Display Stack\n4. Pop from Stack\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Stack created with size " << size << endl;
                break;
            case 2:
                cout << "Enter element to push onto stack: ";
                cin >> element;
                stack.push(element);
                cout << element << " pushed onto stack" << endl;
                break;
            case 3:
                stack.display();
                break;
            case 4:
                try {
                    element = stack.pop();
                    cout << element << " popped from stack" << endl;
                }
                catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 0:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
