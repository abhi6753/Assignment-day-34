//5. Write a C++ program to merge the two files.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string str;
    ofstream fout;
    ifstream fin;
    fin.open("D:/Desktop/file1.txt",ios::out);
    if(!fin)
    cout<<"Unable to open file"<<endl;
    else
    {
        fout.open("D:/Desktop/file2.txt",ios::app);
        if(!fin)
        cout<<"Unable to open file"<<endl;
        else
        {
          while(!fin.eof())
          {
            getline(fin,str);
            fout<<str<<endl;
          }
          cout<<"Merging completed"<<endl;
        }
        fout.close();
        fin.close();
        remove("D:/Desktop/file1.txt");
    }

    return 0;
}
