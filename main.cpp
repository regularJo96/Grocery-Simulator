#include <iostream>
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <vector>
#include "customer.h"

using namespace std;

// to track the number of threads
int NUMBER_OF_THREADS = 0;

string getName(int index);
int nextArrival(int currentDuration);
void work(string name, int customerNumber);

int main() {

    srand(time(NULL));
    std::vector<std::thread> workers;
    int storeClose = 20;
    int duration = 0;
    int arrival = 0;
    int customerNumber = 0;
    string customerName = "";


    while (duration < storeClose || NUMBER_OF_THREADS > 0) {
        cout << "time elapsed: " << duration << endl;

        if (duration >= arrival) {
            arrival = nextArrival(duration);
        }

        this_thread::sleep_for(chrono::milliseconds(1000));
        duration = duration + 1;
        if (duration == arrival && duration < storeClose) {
            customerNumber = customerNumber + 1;
            workers.push_back(std::thread(work, getName(customerNumber - 1), customerNumber));
        }
    }

    for (auto& th : workers) {
        th.join();
    }

    std::cout << "Grocery Store Simulator exiting..." << std::endl;
}

void work(string name, int customerNumber) {
    NUMBER_OF_THREADS++;
    using namespace std::literals::chrono_literals;
    int duration = 0;

    Customer customer(name, customerNumber);
    Cart cart;
    customer.chooseCart(&cart);

    int timeToGrab = customer.grabTime(duration);

    while (duration < customer.getShopTime()) {

        if (duration == timeToGrab) {
            // grab a random item from a soon to be implemented has-map of items key value table. [idNumber : ["name", "price"]
            customer.placeItemInCart(new Item(0.00, "apple"));
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
    int number = ((rand() % 5) + 1);
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