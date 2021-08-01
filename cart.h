#include "item.h"

#pragma once

class Cart {
    private:
        int id;
        Item* item;

    public:
        Cart(int id);

        int getId();
        void setId(int id);

        void addItem(Item* item);
};