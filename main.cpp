#include <iostream>
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <vector>
#include "customer.h"

using namespace std;

string getName(int index);
int nextArrival(int currentDuration);
void work(string name, int customerNumber);

int main() {

  srand(time(NULL));
  std::vector<std::thread> workers;

  int duration = 0;
  int arrival = 0;
  int customerNumber = 0;
  string customerName = "";


  while (duration < 120) {
    cout << "time elapsed: " << duration << endl;

    if (duration >= arrival) {
      arrival = nextArrival(duration);
    }
    
    this_thread::sleep_for(chrono::milliseconds(1000));
    duration = duration + 1;
    if (duration == arrival) {
      customerNumber = customerNumber + 1;
      workers.push_back(std::thread(work, getName(customerNumber-1), customerNumber));
    }
  }

  for (auto& th : workers) {
    th.join();
  }
}

void work(string name, int customerNumber) {
  using namespace std::literals::chrono_literals;
  int duration = 0;
  
  Customer customer(name, customerNumber);

  while (duration < customer.getShopTime()) {
    std::cout <<  customer.getName() << std::this_thread::get_id() << " shopping" << std::endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    duration = duration + 1;
  }
  
  std::cout << customer.getName() << " finished shopping.\n" << std::endl;

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