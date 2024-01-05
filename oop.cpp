#include <iostream>
#include <vector>
#include <algorithm>

class ConsumerOrder  {
private:
    static int orderCount;
    std::string customer_name;
   std::vector<std::string> dishes_name;
   std::vector <double> dishes_prices;
   unsigned int orderID;
public:
    ConsumerOrder(std::string _name_c): customer_name(_name_c) { orderID = orderCount++;};
    ConsumerOrder(ConsumerOrder & _a): customer_name(_a.customer_name), dishes_name(_a.dishes_name),
    dishes_prices(_a.dishes_prices),  orderID(_a.orderID){};
    ConsumerOrder  &operator=(const ConsumerOrder &other)
    {
        if(this == &other)
        {
            customer_name = other.customer_name;
            dishes_name = other.dishes_name;
            dishes_prices = other.dishes_prices;
            orderID = other.orderID;
        }

    return *this;
    }
    ~ConsumerOrder(){
        std::cout<<"Order ID "<<orderID<<" is being destroyed" <<std::endl;
    }

   void setCustomer(std::string value);
    std::string getCustomer();
    int getID();
    void setID(int value);
    void addDish(std::string value, double price);
    void remove_dishes(std::string value_found);
    int length();
    friend bool operator>(const ConsumerOrder &v1, const ConsumerOrder &v2);
    double &operator[](int);
     friend std::ostream &operator<<(std::ostream &os , const ConsumerOrder &ca);
    static int getOrderCount();
};

void ConsumerOrder::setCustomer(std::string value) {
     customer_name = value; //std::move;
}

std::string ConsumerOrder::getCustomer() {
    return customer_name;
}

void ConsumerOrder::setID(int value) {
    orderID  = value;
}
int ConsumerOrder::getID() {
    return orderID;
}

void ConsumerOrder::addDish(std::string value, double price) {
    dishes_name.push_back(value);
    dishes_prices.push_back(price);

}

void ConsumerOrder::remove_dishes(std::string value_found) {

   bool dishes = true;

   for(int i =0; i<dishes_name.size(); i++)
   {
       if(dishes_name[i] == value_found)
       {
           dishes = false;
           dishes_name.erase(dishes_name.begin() + i);
           dishes_prices.erase(dishes_prices.begin() + i);
       }

   }
   if(dishes == true)
   {
       throw std::logic_error("dishes_name not found");
   }
}
int ConsumerOrder::length() {
    return dishes_name.size();
}

bool operator>(const ConsumerOrder &v1, const ConsumerOrder &v2){
    return v1.dishes_prices > v2.dishes_prices;
};

double &ConsumerOrder::operator[](int index)  {
    if(index >= 1 && index < dishes_prices.size())
    {
        return dishes_prices[index - 1];
    }

    else{
        throw std::logic_error("value given is greater than the length of the order");
    }
}

std::ostream &operator<<(std::ostream &os , const ConsumerOrder &ca) {
    size_t temp = 0;
    for (int i = 0; i < ca.dishes_name.size(); i++) {
        os << i + 1 << ": Dish name " << ca.dishes_name[i]
           << " / Dishes Price " << ca.dishes_prices[i] << " $ " << std::endl;
        temp += ca.dishes_prices[i];
    }
    os << "Total price is " << temp << std::endl;

    return os;

}
int ConsumerOrder::getOrderCount() {
    return orderCount;
}
int ConsumerOrder::orderCount = 0;
int main()
{

    std::cout << ConsumerOrder::getOrderCount()<<std::endl; // should be 0

    ConsumerOrder o1("John Smith");
    std::cout << o1.getCustomer()<<std::endl; // should be John Smith
    o1.addDish("vegetable soup", 20);
    o1.addDish("apple pie", 19);
    std::cout << o1.length()<<std::endl; // should be 2
    o1[1] = 21; // changes the price of the first dish
    std::cout << o1; // should print, for example:
    // Order no. 1; customer: John Smith
    // 1. vegetable soup, 21
    // 2. apple pie, 19
    // Total cost: 40

    ConsumerOrder oo("Andrew Taylor");
    oo.addDish("tomato soup", 20);
    oo.addDish("grilled chicken", 45);
    oo.addDish("tomato soup", 20);
    oo.addDish("ice cream", 15);
    if (oo > o1)
        std::cout << "order " << oo.getID() << " is more expensive than " << o1.getID()<<std::endl;
    // the message 'order 2 is more expensive than 1' should be printed

    oo.remove_dishes("tomato soup");
    std::cout << oo; // should print, for example:
    // Order no. 2; customer: Andrew Taylor
    // 1. grilled chicken, 45
    // 2. ice cream, 15
    // Total cost: 60

    std::cout << ConsumerOrder::getOrderCount()<<std::endl; // should be 2
    return 0;
}