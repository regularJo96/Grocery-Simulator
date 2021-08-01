#include <string>
#pragma once

using namespace std;

class Item {
    private:
        int id;
        string name;

    public:
        Item(int id, string name);

        int getId();
        string getName();
};