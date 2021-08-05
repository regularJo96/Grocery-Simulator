#include <string>
#pragma once

using namespace std;

class Item {
private:
    float price;
    string name;
    Item* nextItem;

public:
    Item(string name, float price);

    float getPrice();
    string getName();
    Item* getNext();
    void setNext(Item* item);
};
