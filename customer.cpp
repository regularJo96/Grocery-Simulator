#include <string>

class Customer{
    public:
        Customer();
        Customer(string name, int id;)
        string getName();
        int getId();
        
        void setName(string name);
        void setId(int id);

    private:
        string name;
        int id;
}

// break out into seperate file
Customer::Customer(){
    Customer::setName("John Doe");
    Customer::setId(0);
}

Customer::Customer(string name, int id){
    Customer::setName(name);
    Customer::setId(id);
}

Customer::getName(){
    return (Customer::name);
}

Customer::getId(){
    return (Customer::id);
}

Customer::setName(string name){
    Customer::name = name;
}

Customer::setId(int id){
    Customer::id = id;
}