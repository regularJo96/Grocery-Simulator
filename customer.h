#include "cart.h"
#include "item.h"
#include <string>
#pragma once

using namespace std;

class Customer {
private:
    string name;
    int id;
    int shopTime;
    Cart* cart;

public:
    Customer();
    Customer(string name, int id);
    string getName();
    int getId();
    int getShopTime();

    void setShopTime();
    // void shop();
    void placeItemInCart(Cart* cart, Item* item);
    // void chooseCart(Cart* cart);
    void setName(string name);
    void setId(int id);
  
};