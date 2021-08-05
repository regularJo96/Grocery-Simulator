#include <iostream>
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <vector>
#include "customer.h"
#include "stock.h"

using namespace std;

// to track the number of threads
int NUMBER_OF_THREADS = 0;

string getName(int index);
int nextArrival(int currentDuration);
void work(string name, int customerNumber, Stock stock);
Item* getRandomItem(Stock stock);

int main() {
    Stock stock;
    stock.readFile();

    srand(time(NULL));
    std::vector<std::thread> workers;
    int storeClose = 20;
    int duration = 1;
    int arrival = nextArrival(0);
    int customerNumber = 0;
    string customerName = "";


    while (duration < storeClose || NUMBER_OF_THREADS > 0) {
        cout << "time elapsed: " << duration << " minute(s)" << endl;

        this_thread::sleep_for(chrono::milliseconds(1000));
        if (duration == arrival && duration < storeClose) {
            customerNumber = customerNumber + 1;
            workers.push_back(std::thread(work, getName(customerNumber - 1), customerNumber, stock));
        }

        if (duration >= arrival) {
            arrival = nextArrival(duration);
        }

        duration = duration + 1;
      
        std::cout << std::endl;
    }

    for (auto& th : workers) {
        th.join();
    }

    std::cout << "Grocery Store Simulator exiting..." << std::endl;
}

void work(string name, int customerNumber, Stock stock) {
    NUMBER_OF_THREADS++;
    using namespace std::literals::chrono_literals;
    int duration = 0;

    Customer customer(name, customerNumber);
    Cart cart;
    customer.chooseCart(&cart);

    int timeToGrab = customer.grabTime(duration);

    while (duration < customer.getShopTime()) {

        if (duration == timeToGrab) {
            customer.placeItemInCart(getRandomItem(stock));
        }

        if (duration >= timeToGrab) {
            timeToGrab = customer.grabTime(duration);
        }

        this_thread::sleep_for(chrono::milliseconds(1000));
        duration = duration + 1;
    }

    std::cout << customer.getName() << " finished shopping.\n" << std::endl;
    customer.cartContent();
    NUMBER_OF_THREADS--;
}

int nextArrival(int currentDuration) {
    int number = ((rand() % 4) + 1);
    return (number + currentDuration);
}


string getName(int index) {
    string array[50] = { "Smith","Johnson","Williams","Brown","Jones",
                                         "Garcia","Miller","Davis","Rodriguez","Martinez",
                                        "Hernandez","Lopez","Gonzales","Wilson","Anderson",
                                         "Thomas","Taylor","Moore","Jackson","Martin",
                                         "Lee","Perez","Thompson","White","Harris",
                                          "Sanchez","Clark","Ramirez","Lewis","Robinson",
                                          "Walker","Young","Allen","King","Wright",
                                          "Scott","Torres","Nguyen","Hill","Flores",
                                          "Green","Adams","Nelson","Baker","Hall",
                                          "Rivera","Campbell","Mitchell","Carter","Roberts" };

    return (array[index]);
}

Item* getRandomItem(Stock stock){
    int number = ((rand() % 9));

    return(stock.getItem(number));
}