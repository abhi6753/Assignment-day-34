/*9. A company has following details of their employees in the file 'emp.dat'
a. Emp Id
b. Emp Name
c. Emp Address
d. Emp Dept (Admin/Sales/Production/IT)
e. Emp Phone
f. Emp Age
Write a C++ program to read the above file. Create a new file such as Adm.dat,
Sal.dat, Pro.dat, IT.dat respectively to store the employee details according to their
department.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Employee
{
    int empId;
    string name;
    string address;
    string dept;
    long long int phone;
    int age;

public:
    void addEmployee()
    {
        ofstream fout;
        fout.open("D:/Desktop/Emp.dat", ios::app);
        if (!fout)
            cout << "Unable to open Emp.dat file" << endl;
        else
        {
            cout << "Enter id   : ";
            cin >> empId;
            cout << "Enter name : ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter address : ";
            getline(cin, address);
            cout << "select department : ";
            cin >> dept;
            cout << "Enter mobile number : ";
            cin >> phone;
            cout << "Enter age : " << endl;
            cin >> age;
            fout << endl;
            fout << empId << endl;
            fout << name << endl;
            fout << address << endl;
            fout << dept << endl;
            fout << phone << endl;
            fout << age << endl;
            cout << "Added successfully" << endl;
            fout.close();
            if (dept == "Admin")
            {
                ofstream fout;
                fout.open("D:/Desktop/Adm.dat", ios::app);
                if (!fout)
                    cout << "Unable to open Adm.dat file" << endl;
                else
                {
                    fout << endl;
                    fout << empId << endl;
                    fout << name << endl;
                    fout << address << endl;
                    fout << dept << endl;
                    fout << phone << endl;
                    fout << age << endl;
                    cout << "Added successfully" << endl;
                }
                fout.close();
            }
            else if (dept == "Sales")
            {
                ofstream fout;
                fout.open("D:/Desktop/Sal.dat", ios::app);
                if (!fout)
                    cout << "Unable to open Sal.dat file" << endl;
                else
                {
                    fout << endl;
                    fout << empId << endl;
                    fout << name << endl;
                    fout << address << endl;
                    fout << dept << endl;
                    fout << phone << endl;
                    fout << age << endl;
                }
                fout.close();
                cout << "Added successfully" << endl;
            }
            else if (dept == "Production")
            {
                ofstream fout;
                fout.open("D:/Desktop/Pro.dat", ios::app);
                if (!fout)
                    cout << "Unable to open Pro.dat file" << endl;
                else
                {
                    fout << endl;
                    fout << empId << endl;
                    fout << name << endl;
                    fout << address << endl;
                    fout << dept << endl;
                    fout << phone << endl;
                    fout << age << endl;
                    cout << "Added successfully" << endl;
                }
                fout.close();
            }
            else if (dept == "IT")
            {
                ofstream fout;
                fout.open("D:/Desktop/IT.dat", ios::app);
                if (!fout)
                    cout << "Unable to open IT.dat file" << endl;
                else
                {
                    fout << endl;
                    fout << empId << endl;
                    fout << name << endl;
                    fout << address << endl;
                    fout << dept << endl;
                    fout << phone << endl;
                    fout << age << endl;
                    cout << "Added successfully" << endl;
                }
                fout.close();
            }
        }
    }
};
int main()
{
    Employee e1;
    e1.addEmployee();
    return 0;
}