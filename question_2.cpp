//2. Write a C++ program to read a text file and count the number of characters in it.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream fin;
    string str;
    int count=0;
    fin.open("D:/Desktop/Abhishek.txt",ios::in);
    if(!fin)
     cout<<"File does not exist"<<endl;
    else
    {
        while (!fin.eof())
        {
           getline(fin,str);
        }
        cout<<"Total characters = "<<str.length();
        fin.close();
    }
    return 0;
}