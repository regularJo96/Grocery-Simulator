#include "item.h"

#pragma once

class Cart {
private:
    int id;
    Item* item;
    int size;

public:
    Cart();

    int getId();
    void setId(int id);
    void addItem(Item* item);
    void getContent();
};
