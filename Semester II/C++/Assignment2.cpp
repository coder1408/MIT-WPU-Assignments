#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
  string name;
  int emp_num;
  string qualification;
  string address;
  long long contact_num;
  float basic_salary;
  float DA;
  float TA;
  float net_salary;

public:
  // Default constructor
  Employee() {
    name = "";
    emp_num = 0;
    qualification = "";
    address = "";
    contact_num = 0;
    basic_salary = 0;
    DA = 0;
    TA = 0;
    net_salary = 0;
  }

  // Parameterized constructor
  Employee(string n, int en, string q, string a, long long cn, float bs, float d, float t) {
    name = n;
    emp_num = en;
    qualification = q;
    address = a;
    contact_num = cn;
    basic_salary = bs;
    DA = d;
    TA = t;
    net_salary = bs + d + t;
  }

  // Copy constructor
  Employee(const Employee &obj) {
    name = obj.name;
    emp_num = obj.emp_num;
    qualification = obj.qualification;
    address = obj.address;
    contact_num = obj.contact_num;
    basic_salary = obj.basic_salary;
    DA = obj.DA;
    TA = obj.TA;
    net_salary = obj.net_salary;
  }

  // Function to display employee information
  void display() {
    cout << "Name: " << name << endl;
    cout << "Employee Number: " << emp_num << endl;
    cout << "Qualification: " << qualification << endl;
    cout << "Address: " << address << endl;
    cout << "Contact Number: " << contact_num << endl;
    cout << "Basic Salary: " << basic_salary << endl;
    cout << "DA: " << DA << endl;
    cout << "TA: " << TA << endl;
    cout << "Net Salary: " << net_salary << endl;
  }
};

int main() {
  Employee emp1;
  cout << "Default Constructor:\n";
  emp1.display();

  Employee emp2("John Doe", 123, "Bachelor's", "123 Main St", 1234567890, 1000, 200, 300);
  cout << "\nParameterized Constructor:\n";
  emp2.display();

  Employee emp3 = emp2;
  cout << "\nCopy Constructor:\n";
  emp3.display();

  return 0;
}
