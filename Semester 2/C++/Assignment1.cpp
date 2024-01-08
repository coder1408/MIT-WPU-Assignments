#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    string name;
    int roll_no;
    float marks;
    static int student_council;

public:
    void get_data() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter marks: ";
        cin >> marks;
    }

    friend void put_data(Student obj);

};

int Student::student_council = 0;

void put_data(Student obj) {
    cout << "Name: " << obj.name << endl;
    cout << "Roll number: " << obj.roll_no << endl;
    cout << "Marks: " << obj.marks << endl;
}

int main() {
    Student s;
    s.get_data();
    put_data(s);
    return 0;
}
