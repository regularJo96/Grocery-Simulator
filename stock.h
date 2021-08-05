#include "item.h"
#include <vector>
#include <unordered_map>

class Stock{
    public:
        Item* getItem(int key);
        void readFile();
    private:
        unordered_map<int, Item*> items;
        

};