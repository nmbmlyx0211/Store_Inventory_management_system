#include "ItemContainer.hpp"
#include <fstream>

const string delimiter="~~";

void ItemContainer::printItemCon()
{
    for(int i=0; i<Itemlst.size(); ++i)
        Itemlst[i].printItemInfo();
}

void ItemContainer:: addNewItem(Item i)
{
    Itemlst.push_back(i);
}



void ItemContainer::writetoStream(ofstream & out)
{
    for(int i=0; i<Itemlst.size(); ++i)
        out << Itemlst[i].getID() << delimiter<< Itemlst[i].getName() << delimiter<< Itemlst[i].getCost() <<delimiter<< Itemlst[i].getQuantity() <<endl;
}


int ItemContainer::findItemByID()//binary search
{
    sortItemByID();
    int mid;
    unsigned long target;
    int left=0;
    int right=Itemlst.size()-1;
    cout<< "Enter the item ID: ";
    cin >> target;
    for(;;)
    {
        mid=(left+right)/2;
        if (target==Itemlst[mid].getID())
        {
            Itemlst[mid].printItemInfo();
            return mid;
        }

        else if(left>=right)
        {
            cout <<"Item was not found! try again.";
            return -1;
        }

        else if (target < Itemlst[mid].getID())
            right=mid-1;
        else
            left=mid+1;
    }
}

void ItemContainer::findItemByName()//didn't use i, what should do without return i? just return??
{
    string name;
    cout<< "Enter the item name: ";
    getline(cin >> ws, name);
    for (int i=0; i<Itemlst.size(); ++i)
    {
        if (Itemlst[i].getName()==name)
        {
            Itemlst[i].printItemInfo();
            return;// or break?
        }
    }
    cout << "Item was not found! try again." << endl;
}

void ItemContainer::removeItem()
{
    int i;
    i = findItemByID();
    if (i!=-1)
    {
        cout << "The above item is getting deleted!" << endl;
        for (i; i<Itemlst.size()-1; ++i)
            Itemlst[i]=Itemlst[i+1];
        Itemlst.pop_back();
    }
}
void ItemContainer::sortItemByID()
{
    Item temp;
    for (int k=1; k<Itemlst.size();++k)
    {
        for (int m=k; m>0; --m)
        {
            if (Itemlst[m].getID()<Itemlst[m-1].getID())
            {
                temp=Itemlst[m];
                Itemlst[m]=Itemlst[m-1];
                Itemlst[m-1]=temp;
            }
            else
                break;
        }
    }
    cout<<"Items have been sorted by ID" << endl;
}
