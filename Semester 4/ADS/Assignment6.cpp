#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define MAX 20

class Student
{
    int roll_no;
    string name;
    char grade;
    friend class HashClass;

public:
    void readFromFile(ifstream &inFile);
    void writeToFile(ofstream &outFile);
};

class HashClass
{
    Student hashtable[MAX];

public:
    HashClass()
    {
        for (int i = 0; i < MAX; i++)
        {
            hashtable[i].roll_no = -1;
        }
    }

    int insert_linear_prob_without_replacement(int key);
    void display();
    void readFromFile(string filename);
    void writeToFile(string filename);
};

void Student::readFromFile(ifstream &inFile)
{
    inFile >> roll_no >> name >> grade;
}

void Student::writeToFile(ofstream &outFile)
{
    outFile << roll_no << " " << name << " " << grade << endl;
}

void HashClass::readFromFile(string filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        hashtable[i].readFromFile(inFile);
    }

    inFile.close();
}

void HashClass::writeToFile(string filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (hashtable[i].roll_no != -1)
        {
            hashtable[i].writeToFile(outFile);
        }
    }

    outFile.close();
}

int HashClass::insert_linear_prob_without_replacement(int key)
{
    int choice;
    do
    {
        if (key < 0 || key >= MAX)
        {
            cout << "Invalid key" << endl;
            return -1;
        }

        if (hashtable[key].roll_no == -1)
        {
            cout << "Enter roll number: ";
            cin >> hashtable[key].roll_no;
            cout << "Enter name: ";
            cin >> hashtable[key].name;
            cout << "Enter grade: ";
            cin >> hashtable[key].grade;
            cout << "Record inserted successfully" << endl;
            return key;
        }

        int i = (key + 1) % MAX;
        while (i != key)
        {
            if (hashtable[i].roll_no == -1)
            {
                cout << "Enter roll number: ";
                cin >> hashtable[i].roll_no;
                cout << "Enter name: ";
                cin >> hashtable[i].name;
                cout << "Enter grade: ";
                cin >> hashtable[i].grade;
                cout << "Record inserted successfully" << endl;
                return i;
            }
            i = (i + 1) % MAX;
        }

        cout << "Hash table is full" << endl;
        cout << "Do you want to insert more records? (1 for Yes / 0 for No): ";
        cin >> choice;
    } while (choice != 0);

    return -1;
}

void HashClass::display()
{
    for (int i = 0; i < MAX; i++)
    {
        if (hashtable[i].roll_no != -1)
        {
            cout << "Roll number: " << hashtable[i].roll_no << endl;
            cout << "Name: " << hashtable[i].name << endl;
            cout << "Grade: " << hashtable[i].grade << endl;
            cout << endl;
        }
    }
}

int main()
{
    HashClass h;
    int key;
    int choice;
    string filename = "student_records.txt"; // File name to store records

    // Load records from file
    h.readFromFile(filename);

    do
    {
        cout << "1. Insert (linear probing without replacement)" << endl;
        cout << "2. Insert (linear probing with replacement)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Save to file" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            h.insert_linear_prob_without_replacement(key);
            break;

        case 2:
            break;

        case 3:
            h.display();
            break;

        case 4:
            h.writeToFile(filename);
            cout << "Records saved to file: " << filename << endl;
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}
