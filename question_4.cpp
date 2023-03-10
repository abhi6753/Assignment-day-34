//4. Write a program to copy the contents of one text file to another while changing the\
case of every alphabet.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void copy(string);
int main()
{
    string str;
    ofstream fout;
    fout.open("D:/Desktop/file1.txt", ios::app);
    if (!fout)
        cout << "Unable to open or create file1.txt" << endl;
    else
    {
        cout<<"Enter your string : "<<endl;
        
        while (true)
        {
            getline(cin, str);
            if (str == "-1")
                break;
            fout << str << endl;
        }
        fout.close();
    }
    ifstream fin;
    fin.open("D:/Desktop/file1.txt", ios::out);
    if (!fin)
    {
        cout << "File does not exist" << endl;
    }
    else
    {
        while (!fin.eof())
        {
            getline(fin, str);
            copy(str);
        }
        cout<<"Copy successfully"<<endl;
        fout.close();
    }
    return 0;
}
void copy(string str)
{
    ofstream fout;
    fout.open("D:/Desktop/file2.txt", ios::app);
    if (!fout)
        cout << "Unable to open or create file2.txt" << endl;
    else
    {
        for (int i = 0; str[i]; i++)
        {
            if(str[i]>='a'&& str[i]<='z')
            {
                str[i]=(char)str[i]-32;
            }
            else if(str[i]>='A'&& str[i]<='Z')
            {
                str[i]=(char)str[i]+32;
            }
        }
        fout << str << endl;
        fout.close();
    }
}
