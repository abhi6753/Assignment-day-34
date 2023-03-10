//3. Write a C++ program to open an output file 'a.txt' and append data to it.
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    string str;
    ofstream fout;
    fout.open("D:/Desktop/a.txt",ios::app);
    if(!fout)
     cout<<"Unable to create or open file"<<endl;
    else
    {
        cout<<"If you want to save then enter -1"<<endl;
        while(1)
        {
           getline(cin,str);
           if(str == "-1")
            break;
           fout<<str<<endl;
        }
        fout.close(); 
    }
    return 0;
}