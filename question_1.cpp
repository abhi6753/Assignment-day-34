//1. Write a C++ program to create a file and print “File created successfully” and throw\
an error if file is not created.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("D:/Desktop/Abhishek.txt",ios::out);
    try
    {
        if(!fout)
         throw "File not created or open";
        else
        {
          fout<<"File created successfully";
          cout<<"Print successfully"<<endl;
          fout.close();
        }
    }
    catch(const char* str)
    {
        cout<<str<<endl;
    }
    return 0;
}
