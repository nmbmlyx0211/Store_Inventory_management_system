#include <iostream>
#include <fstream>

#include "ItemContainer.hpp"

using namespace std;
const char * menu[]={"1. Add new item",
                        "2. Print item list",
                        "3. Find item by ID",
                        "4. Find item by name",
                        "5. Remove an item",
                        "6. Sort item by ID",
                        "7. Quit"
                    };
void registerNewItem(ItemContainer & con);
int menuSel();
void writeItem(ItemContainer & con);
void readItemInfo(ItemContainer & con);


int main () {
    ItemContainer con;
    readItemInfo(con);
    int sel;
    do
    {
        sel=menuSel();
        switch(sel)
        {
            case 1:
                registerNewItem(con);
                break;
            case 2:
                con.printItemCon();
                break;
            case 3:
                con.findItemByID();//binary search
                break;
            case 4:
                con.findItemByName();
                break;
            case 5:
                con.removeItem();
                break;
            case 6:
                con.sortItemByID();
                break;
            case 7:
                cout << "Good bye!" << endl;
                break;
            default:
                cout << "Error: invalid value"<<endl;
        }
    }while (sel!=7);
    writeItem(con);
    return 0;
}



void registerNewItem(ItemContainer & con)
{
    unsigned long Id;
    string name;
    float cost;
    int quantity;
    cout << "Enter item ID: ";
    cin >> Id;
    cout << "Enter item name: ";
    getline(cin >>ws, name);
    cout << "Enter item cost: ";
    cin >> cost;
    cout <<"Enter item quantity: ";
    cin >> quantity;
    Item temp(Id, name, cost, quantity);
    con.addNewItem(temp);

}



int menuSel()
{
    int sel;
    cout<<"\n\t\tInventory Management System Menu"<<endl;
    for (int i=0; i<sizeof(menu)/sizeof(menu[0]); ++i)
        cout << menu[i] << endl;
    cout << "Select:";
    cin >> sel;
    return sel;

}


void readItemInfo(ItemContainer & con)
{
    ifstream in ("Item.txt");
    unsigned long Id;
    string name;
    float cost;
    int quantity;
    if(in.is_open())
    {
        for(;;){

            in >> Id;
            in.ignore(2);
            getline(in>>ws, name, '~');
            in.ignore(1);
            in >> cost;
            in.ignore(2);
            in >> quantity;
            if (in.good())
            {
                Item temp(Id, name, cost, quantity);
                con.addNewItem(temp);
            }
            else if(in.eof())
                break;
            else
            {
                in.clear();
                string temp;
                getline(in, temp);
                cout << "Corrupted record: " << temp << endl;
            }
        }
    }
    in.close();
}


void writeItem(ItemContainer & con)
{
    ofstream out ("Item.txt");
    if(out.is_open())
    {
        con.writetoStream(out);
    }
    out.close();
}










