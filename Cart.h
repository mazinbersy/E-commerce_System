#ifndef CART_H
#define CART_H
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;


struct product {
    string name;
    float price;
    float quantity;
    time_t expiry;
    bool shipping;
    float weight;

};


class Cart {

private:
    float sum=0.0;
    vector<pair<product,float>> products;


public:
    void add(product, float);
    void remove(int, float);
    float getSum();
    bool empty();
    bool outOfStock(product, float);
    bool expired(product);
    void displayCart();
    vector<pair<product, float>>& getProducts();


};



#endif //CART_H
