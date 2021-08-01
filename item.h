#include <string>
#pragma once

using namespace std;

class Item {
private:
    float price;
    string name;
    Item* nextItem;

public:
    Item(float price, string name);

    float getPrice();
    string getName();
    Item* getNext();
    void setNext(Item* item);
};
