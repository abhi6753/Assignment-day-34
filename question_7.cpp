/*7. There are 50 records in a file. Each record contains 6-character item-code, 20
characters for item-name and an integer price. Write a program to read these
records, arrange them in the descending order of price and write them in the same
file, overwriting the earlier records.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int total;
class Item
{
  string item_code;
  string item_name;
  float item_price;

public:
  void addItem();
  friend void DeleteItem(string);
  friend void printAllItems();
  friend void InputinArray(Item[]);
  friend void ascendingOrder(Item[]);
  friend void searchItem(string);
  friend void shortByIPrice(Item[]); // sort by increasing price
  friend void shortByDPrice(Item[]); // sort by decreasing price
};
void printAllItems()
{
  Item i1;
  ifstream fin;
  fin.open("D:/Desktop/Item.txt", ios::in);
  if (!fin)
    cout << "Unable to open the Item file" << endl;
  else
  {
    cout << "Total Items = " << total << endl
         << endl;
    while (!fin.eof())
    {
      fin >> i1.item_code;
      fin.ignore();
      getline(fin, i1.item_name);
      fin >> i1.item_price;
      cout << "Item-code  = " << i1.item_code << endl;
      cout << "Item-name  = " << i1.item_name << endl;
      cout << "Item-Price = " << i1.item_price << endl
           << endl;
    }
  }
  fin.close();
}
void searchItem(string Itemcode)
{
  bool flag = false;
  Item i1;
  ifstream fin;
  fin.open("D:/Desktop/Item.txt", ios::in);
  if (!fin)
    cout << "unable to open the Item.txt file" << endl;
  else
  {
    while (!fin.eof())
    {
      fin >> i1.item_code;
      fin.ignore();
      getline(fin, i1.item_name);
      fin >> i1.item_price;
      if (Itemcode == i1.item_code)
      {
        flag = true;
        cout << i1.item_code << endl;
        cout << i1.item_name << endl;
        cout << i1.item_price << endl;
      }
      if (Itemcode == i1.item_name)
      {
        flag = true;
        cout << i1.item_code << endl;
        cout << i1.item_name << endl;
        cout << i1.item_price << endl;
      }
    }
  }
  fin.close();
  if (flag)
    cout << endl
         << "Searching completed" << endl;
  else
    cout << endl
         << "Item not found" << endl;
}
void InputinArray(Item item[])
{
  ifstream fin;
  int k = 0;
  fin.open("D:/Desktop/Item.txt", ios::out);
  if (!fin)
    cout << "Unable to open file" << endl;
  else
  {
    while (!fin.eof())
    {
      fin >> item[k].item_code;
      fin.ignore();
      getline(fin, item[k].item_name);
      fin >> item[k].item_price;
      k++;
      if (k == 2)
        break;
    }
    fin.close();
  }
}
void shortByDPrice(Item item[])
{
  for (int i = 0; i < total - 1; i++)
  {
    for (int j = i + 1; j < total; j++)
    {
      if (item[i].item_price < item[j].item_price)
      {
        Item i2; // temporay item object
        i2 = item[i];
        item[i] = item[j];
        item[j] = i2;
      }
    }
  }
  ofstream fout;
  fout.open("D:/Desktop/Item.txt", ios::in);
  if (!fout)
    cout << "Unable to open the file" << endl;
  else
  {
    fout.clear();
    for (int i = 0; i < total; i++)
    {
      fout << endl;
      fout << item[i].item_code << endl;
      fout << item[i].item_name << endl;
      fout << item[i].item_price;
    }
    fout.close();
  }
  cout << endl
       << "Sorting completed" << endl;
}
void shortByIPrice(Item item[])
{
  for (int i = 0; i < total - 1; i++)
  {
    for (int j = i + 1; j < total; j++)
    {
      if (item[i].item_price > item[j].item_price)
      {
        Item i2; // temporay item object
        i2 = item[i];
        item[i] = item[j];
        item[j] = i2;
      }
    }
  }
  ofstream fout;
  fout.open("D:/Desktop/Item.txt", ios::in);
  if (!fout)
    cout << "Unable to open the file" << endl;
  else
  {
    fout.clear();
    for (int i = 0; i < total; i++)
    {
      fout << endl;
      fout << item[i].item_code << endl;
      fout << item[i].item_name << endl;
      fout << item[i].item_price;
    }
    fout.close();
  }
  cout << endl
       << "Sorting completed" << endl;
}
void Item::addItem()
{
  ofstream fout;
  fout.open("D:/Desktop/Item.txt", ios::app);
  if (!fout)
    cout << "Unable to open the Item.txt file" << endl;
  else
  {

    Item i;
    // Take input in temporary Item object
  item_code:
    cout << "Enter Item-code : ";
    cin >> i.item_code;
    if (i.item_code.length() != 6)
    {
      cout << "Item code must be of 6 digit" << endl;
      goto item_code;
    }
  item_name:
    cout << "Enter Item-name : ";
    cin.ignore();
    getline(cin, i.item_name);
    if (i.item_code.length() > 20)
    {
      cout << "Item name can have maximum 20 characters" << endl;
      goto item_name;
    }
    cout << "Enter Item Price : ";
    cin >> i.item_price;
    // output in file
    fout << endl;
    fout << i.item_code << endl;
    fout << i.item_name << endl;
    fout << i.item_price;
    fout.close();
    total++;
    cout << endl
         << "Addded successfully" << endl
         << endl;
  }
}
void DeleteItem(string itemCode)
{
  bool flag = false;
  Item i;
  ifstream fin;
  fin.open("D:/Desktop/Item.txt", ios::in);
  if (!fin)
    cout << "Unable to open the Item.txt file" << endl;
  else
  {
    ofstream fout;
    fout.open("D:/Desktop/TempItem.txt", ios::app);
    if (!fout)
      cout << "Unable to open the TempItem.txt file" << endl;
    else
    {

      while (!fin.eof())
      {
        fin >> i.item_code;
        fin.ignore();
        getline(fin, i.item_name);
        fin >> i.item_price;
        if (itemCode == i.item_code)
        {
          flag = true;
          continue;
        }
        else if(itemCode == i.item_name)
        {
          flag = true;
          continue;
        }
        else
        {
          fout << endl;
          fout << i.item_code << endl;
          fout << i.item_name << endl;
          fout << i.item_price ;
          
        }
      }
      fout.close();
      fin.close();
    }
    remove("D:/Desktop/Item.txt");
    rename("D:/Desktop/TempItem.txt", "D:/Desktop/Item.txt");
  }
  if (flag)
    cout << endl
         << "Deleted successfully" << endl
         << endl;
  else
    cout << endl
         << "Item not found" << endl
         << endl;
}
int main()
{
  Item i1;
  Item item[total];
  char ch;
  string itemcode;
  ifstream fin;
    fin.open("D:/Desktop/Item.txt", ios::in); // file se input lena hai
    if (!fin)
      cout << "Unable to open Item.txt file" << endl;
    else
    {
      float price;
      while (!fin.eof())
      {
        fin >> itemcode;
        fin >> itemcode; // yha pe hum total ko count krne k liye temporary file se sb ko read kr rhe hai
        fin >> price;
        total++;
      }
    }
    fin.close();
  while (true)
  {
   
  menu:
    cout << "1.Add item" << endl;
    cout << "2.Delete item" << endl;
    cout << "3.Search Item" << endl;
    cout << "4.print all item" << endl;
    cout << "5.SORT BY" << endl;
    cout << "6.Exit" << endl;
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case '1':
      i1.addItem();
      break;
    case '2':
    Delete:
      cout << "Delete By" << endl;
      cout << "1. delete by item-code" << endl;
      cout << "2. delete by item-name" << endl;
      cout << "Enter your choice : ";
      cin >> ch;
      switch (ch)
      {
      case '1':
      code:
        cout << "Enter item-code : " << endl;
        cin >> itemcode;
        if (itemcode.length() != 6)
        {
          cout << "Item-code length should be 6 digit" << endl;
          goto code;
        }
        else
          DeleteItem(itemcode);
        break;
      case '2':
      name:
        cout << "Enter item-name : " << endl;
        cin >> itemcode;
        if (itemcode.length() > 20)
        {
          cout << "Item-name length should be <=20 characters" << endl;
          goto name;
        }
        else
          DeleteItem(itemcode);
        break;
      default:
        cout << "Please enter correct choice" << endl;
        goto Delete;
      }
      break;
      ;

    case '3':
    search:
      cout << "Search By" << endl;
      cout << "1. search by item-code" << endl;
      cout << "2. search by item-name" << endl;
      cout << "Enter your choice : ";
      cin >> ch;
      switch (ch)
      {
      case '1':
      itemcode:
        cout << "Enter item-code : " << endl;
        cin >> itemcode;
        if (itemcode.length() != 6)
        {
          cout << "Item-code length should be 6 digit" << endl;
          goto itemcode;
        }
        else
          searchItem(itemcode); // isme item ka code hai
        break;
      case '2':
      itemname:
        cout << "Enter item-name : " << endl;
        cin.ignore();
        getline(cin, itemcode); // item k name ko hum itemcode me contain kra le rhe;
        if (itemcode.length() > 20)
        {
          cout << "Item-name length should be <=20" << endl;
          goto itemname;
        }
        else
          searchItem(itemcode); // is waale me item ka name hai
        break;
      default:
        cout << "Please enter correct choice" << endl;
        goto search;
      }
      break;
    case '4':
      printAllItems();
      break;
    case '5':
    sortBy:
      cout << "4.SORT BY" << endl;
      cout << "1. Price -- Low to High" << endl;
      cout << "2. Price -- High to Low" << endl;
      cout << "Enter your choice :" << endl;
      cin >> ch;
      switch (ch)
      {
      case '1':
        shortByDPrice(item);
        break;
      case '2':
        shortByIPrice(item);
        break;
      default:
        cout << "please enter correct choice" << endl;
        goto sortBy;
        break;
      }
      break;
    case '6':
      break;
    default:
      cout << "please enter correct choice" << endl;
      goto menu;
      break;
    }
  }
  return 0;
}