/*8. A file 'Employee.txt' contains empno and empname. Write a C++ program to add and
read contents of this file and search for an employee whose name is 'XYZ'.*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Employee
{
    int empno;
    string empname;

public:
    void addEmployee();
    void showallEmployee();
    void searchEmployee(string);
    friend ostream &operator<<(ostream &, Employee);
    void Employee::searchEmployee(string empname)
    {
        ifstream fin;
        fin.open("D:/Desktop/Employee.txt", ios::in);
        if (!fin)
            cout << "Unable to open the file" << endl;
        else
        {
            while (!fin.eof())
            {
                fin >> empno;
                fin.ignore();
                getline(fin, empname);
                if (this->empname == empname)
                {
                    cout << this;
                    break;
                }
            }
        }
        fin.close();
    }
    void Employee::addEmployee()
    {
        ofstream fout;
        fout.open("D:/Desktop/Employee.txt", ios::app);
        if (!fout)
            cout << "unable to open file" << endl;
        else
        {
            cout << "Enter employee number: " << endl;
            cin >> empno;
            cout << "Enter employee name: " << endl;
            cin.ignore();
            getline(cin, empname);
            fout << endl;
            fout << empno << endl;
            fout << empname << endl;
            cout << "Added successfully" << endl;
        }
        fout.close();
    }
    void Employee::showallEmployee()
    {
        ifstream fin;
        fin.open("D:/Desktop/Employee.txt", ios::in);
        if (!fin)
            cout << "Unable to open file" << endl;
        else
        {
            while (!fin.eof())
            {
                fin >> empno;
                fin.ignore();
                getline(fin, empname);
                cout << empno << endl;
                cout << empname << endl;
            }
            fin.close();
        }
    }
};
ostream &operator<<(ostream &cout, Employee emp)
{
    cout << "Employee id   = " << emp.empno << endl;
    cout << "Employee name = " << emp.empname << endl;
    return cout;
}
int main()
{
    Employee emp;
    char ch;
    string empname;
    while (true)
    {
    menu:
        cout << "1. Add Employee" << endl;
        cout << "2. Print All Employee" << endl;
        cout << "3. Search" << endl;
        cout << "4. Exit" << endl;
        switch (ch)
        {
        case '1':
            emp.addEmployee();
            break;
        case '2':
            emp.showallEmployee();
            break;
        case '3':
            cout << "Enter employee name : " << endl;
            cin.ignore();
            getline(cin,empname);
            emp.searchEmployee(empname);
            break;
        case '4':
            break;
        default:
            cout << "Please enter correct choice" << endl;
            goto menu;
        }
    }
    return 0;
}
