#ifndef CART_H
#define CART_H
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Product.h"
using namespace std;



class Cart {

private:
    float sum=0.0;
    vector<pair<Product, float>> products;

public:
    void add(Product&, float);
    void remove(int, float, Product&);
    float getSum();
    bool empty();
    bool outOfStock(Product, float);
    void displayCart();
    vector<pair<Product, float>>& getProducts();
    void clearCart();


};



#endif //CART_H
