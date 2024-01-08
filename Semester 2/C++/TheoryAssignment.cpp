#include <iostream>
#include <string>
using namespace std;

class Marks {
protected:
    int roll_no;
    string name;

public:
    void getdata() {
        cin.ignore();
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter name: ";
        cin >> name;
    }
};

class Physics : public Marks {
protected:
    int physics_marks;

public:
    void get_physics_marks() {
        cout << "Enter physics marks: ";
        cin >> physics_marks;
    }
    int return_physics_marks() {
        return physics_marks;
    }
};

class Chemistry : public Marks {
protected:
    int chemistry_marks;

public:
    void get_chemistry_marks() {
        cout << "Enter chemistry marks: ";
        cin >> chemistry_marks;
    }
    int return_chemistry_marks() {
        return chemistry_marks;
    }
};

class Mathematics : public Marks {
protected:
    int mathematics_marks;

public:
    void get_mathematics_marks() {
        cout << "Enter mathematics marks: ";
        cin >> mathematics_marks;
    }
    int return_mathematics_marks() {
        return mathematics_marks;
    }
};

int main() {
    int n, total_physics = 0, total_chemistry = 0, total_mathematics = 0;
    cout << "Enter the number of students: ";
    cin >> n;
    Physics** p = new Physics*[n];
    Chemistry** c = new Chemistry*[n];
    Mathematics** m = new Mathematics*[n];
    for (int i = 0; i < n; i++) {
        p[i] = new Physics;
        c[i] = new Chemistry;
        m[i] = new Mathematics;
        cout << "Enter details for student " << i + 1 << endl;
        p[i]->getdata();
        p[i]->get_physics_marks();
        c[i]->get_chemistry_marks();
        m[i]->get_mathematics_marks();
        total_physics += p[i]->return_physics_marks();
        total_chemistry += c[i]->return_chemistry_marks();
        total_mathematics += m[i]->return_mathematics_marks();
    }
    cout << "Total physics marks: " << total_physics << endl;
    cout << "Total chemistry marks: " << total_chemistry << endl;
    cout << "Total mathematics marks: " << total_mathematics << endl;
    cout << "Average physics marks: " << (float)total_physics / n << endl;
    cout << "Average chemistry marks: " << (float)total_chemistry / n << endl;
    cout << "Average mathematics marks: " << (float)total_mathematics / n << endl;
    delete[] p;
    delete[] c;
    delete[] m;
    return 0;
}
