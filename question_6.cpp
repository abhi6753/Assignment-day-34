//6. Write a C++ program that counts the total number of characters, words and lines in the file. 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int findWords(string );
int main()
{
    int characters,words,line;
    characters = words = line =0;
    string str;
    ifstream fin;
    fin.open("D:/Desktop/Abhishek.txt",ios::in);
    if(!fin)
     cout<<"File does not exist"<<endl;
    else
    {
        while (!fin.eof())
        {
           getline(fin,str);
           characters += str.length();
           words += findWords(str);
           line++;
        }
        cout<<"Total characters = "<<characters<<endl;
        cout<<"Total words = "<<words<<endl;
        cout<<"Total Lines = "<<line<<endl;
        fin.close();
    }
    return 0;
}
int findWords(string str)
{
   int word =1;
   for(int i = 0;str[i];i++)
   {
     if(str[i]==32)
      word++;
   }
   return word;
}