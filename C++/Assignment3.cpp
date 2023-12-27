#include <iostream>
#include <string>

using namespace std;

// base class for employee information
class EmpInfo {
protected:
    string name;
    int id;
    string designation;

public:
    void setEmpInfo(string n, int i, string d) {
        name = n;
        id = i;
        designation = d;
    }

    void displayEmpInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Designation: " << designation << endl;
    }
};

// base class for department information
class Department {
protected:
    string deptName;
    string location;

public:
    void setDepartment(string d, string l) {
        deptName = d;
        location = l;
    }

    void displayDepartment() {
        cout << "Department: " << deptName << endl;
        cout << "Location: " << location << endl;
    }
};

// derived class from EmpInfo and Department
class Employee : public EmpInfo, private Department {
private:
    int salary;

public:
    void setSalary(int s) {
        salary = s;
    }

    void setEmpDepartment(string d, string l) {
        setDepartment(d, l);
    }

    void displayEmployee() {
        displayEmpInfo();
        displayDepartment();
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    string empName, department;
    int empNumber, salary;

    cout << "Enter employee name: ";
    getline(cin, empName);

    cout << "Enter employee number: ";
    cin >> empNumber;

    cin.ignore(); // ignore the newline character left in the input buffer

    cout << "Enter department: ";
    getline(cin, department);

    cout << "Enter salary: ";
    cin >> salary;

    Employee emp;
    emp.setEmpInfo(empName, empNumber, "Manager"); // hardcoded designation as "Manager"
    emp.setEmpDepartment(department, "New York"); // hardcoded location as "New York"
    emp.setSalary(salary);

    emp.displayEmployee();

    return 0;
}
