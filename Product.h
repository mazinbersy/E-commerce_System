#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Product {

private:
    string name;
    float price;
    float quantity;
    time_t expiry;
    bool shipping;
    float weight;

public:
    Product(string, float, float, time_t, bool, float);
    string getName();
    float getPrice();
    float getQuantity();
    time_t getExpiry();
    bool needsShipping();
    float getWeight();
    void setQuantity(float);
    bool isExpired();
    void display();
};



#endif //PRODUCT_H
