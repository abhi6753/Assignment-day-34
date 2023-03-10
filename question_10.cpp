/*
10. Write a C++ program to create a file which has information Name, Account number,
Balance and perform following operations:
a. Add record
b. Display content of file
c. Display name of person having balance > 10,000
*/
#include <iostream>
#include <fstream>
using namespace std;
class Employee
{
    string name;
    long long int account_number;
    float balance;

public:
    void Addrecord();
    void DisplayAll();
    void Balance();
};
void Employee::Balance()
{
    ifstream fin;
    fin.open("D:/Desktop/Employee.txt", ios::in);
    if (!fin)
        cout << "Unable to open file" << endl;
    else
    {
        while (!fin.eof())
        {
            fin.ignore();
            getline(fin, name);
            fin >> account_number;
            fin >> balance;
            if (balance > 10000)
            {
                cout << name << endl;
                cout << account_number << endl;
                cout << balance << endl;
            }
        }
    }
    fin.close();
}
void Employee::DisplayAll()
{
    ifstream fin;
    fin.open("D:/Desktop/Employee.txt", ios::in);
    if (!fin)
        cout << "Unable to open file" << endl;
    else
    {
        while (!fin.eof())
        {
            fin.ignore();
            getline(fin, name);
            fin >> account_number;
            fin >> balance;
            cout << name << endl;
            cout << account_number << endl;
            cout << balance << endl;
        }
    }
    fin.close();
}
void Employee::Addrecord()
{
    ofstream fout;
    fout.open("D:/Desktop/Employee.txt", ios::app);
    if (!fout)
        cout << "Unable to pen File" << endl;
    else
    {
        cout << "Enter name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter A/c no. : ";
        cout << account_number;
        cout << "Enter balance : ";
        cout << balance;
        fout << endl;
        fout << name << endl;
        fout << account_number << endl;
        fout << balance;
        fout.close();
        cout << "Added successfully" << endl;
    }
}
int main()
{
    Employee e1;
    char ch;
    while (true)
    {
    choice:
        cout << "1. Add record" << endl;
        cout << "2. Display" << endl;
        cout << "3. Display name of person having balance > 10,000" << endl;
        cout << "4. Exit" << endl;
        switch (ch)
        {
        case '1':
            e1.Addrecord();
            break;
        case '2':
            e1.DisplayAll();
            break;
        case '3':
            e1.Balance();
            break;
        case '4':
            break;
        default:
            cout << "Please enter correct choice" << endl;
            goto choice;
        }
    }
    return 0;
}