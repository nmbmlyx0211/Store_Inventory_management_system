
#include <iostream>
#include "Item.hpp"

Item::Item(unsigned long i, string n, float c, int q)
{
    ID=i;
    name=n;
    cost=c;
    quantity=q;
}
void Item::printItemInfo()
{
    cout <<"Item ID: "<< ID << ", " << "Item name: " << name << ", " << "Item cost: " << cost << ", "<< "Item quantity: " <<quantity << endl;
}
