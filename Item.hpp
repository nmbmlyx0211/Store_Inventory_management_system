#include <iostream>
#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

using namespace std;

class Item{
    private:
        unsigned long ID;
        string name;
        float cost;
        int quantity;
    public:
        Item(){};
        Item(unsigned long i, string n, float c, int q);
        unsigned long getID(){return ID;};
        string getName(){return name;};
        float getCost(){return cost;};
        int getQuantity(){return quantity;};
        void printItemInfo();
};


#endif // ITEM_HPP_INCLUDED
