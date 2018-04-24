#ifndef ITEMCONTAINER_HPP_INCLUDED
#define ITEMCONTAINER_HPP_INCLUDED
#include <vector>

#include "Item.hpp"
//ItemContainer
class ItemContainer
{
    private:
        vector <Item> Itemlst;

    public:

        void addNewItem(Item i);
        void printItemCon(void);
        int findItemByID();
        void findItemByName();
        void removeItem();
        void sortItemByID();
        void writetoStream(ofstream & out);

};

#endif // ITEMCONTAINER_HPP_INCLUDED
