#include "stock.h"
#include "item.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void Stock::readFile(){
    ifstream file("stock.txt");
    int count = 0;
    int mapIndex = 0;
    float price = 0.00;

    if(file.is_open()){
        string sPrice = "";
        string name = "";
        char letter;
        bool isName = true;
        
        while (file) {
            letter = file.get();
            while (letter != '\n' && letter != '$') {
                if (letter != ' ' && isName) {
                    name = name + letter;
                }
                else if (letter != ' ' && !isName) {
                    sPrice = sPrice + letter;
                }
                else {
                    isName = false;
                }
                letter = file.get();
            }
            if (sPrice == "") {
                break;
            }

            price = stof(sPrice);
            Stock::items[mapIndex] = new Item(name, price);

            //reset all variables for next iteration
            isName = true;
            name = "";
            sPrice = "";

            ++mapIndex;
        }
        file.close();
    }
    else {
        cout << "file not open" << endl;
    }
}

Item* Stock::getItem(int key) {
    
    return(items[key]);
}
