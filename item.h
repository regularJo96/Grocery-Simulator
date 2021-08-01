#include <string>
#pragma once

using namespace std;

class Item {
    private:
        float price;
        string name;
        
    public:
        Item(float price, string name);

        float getPrice();
        string getName();
};