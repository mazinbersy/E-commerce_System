#include "Product.h"

Product::Product(string name, float price, float quantity, time_t expiry, bool shipping, float weight)
    : name(name), price(price), quantity(quantity), expiry(expiry), shipping(shipping), weight(weight) {}

string Product::getName() {
    return name;
}

float Product::getPrice() {
    return price;
}

float Product::getQuantity() {
    return quantity;
}

time_t Product::getExpiry() {
    return expiry;
}

bool Product::needsShipping() {
    return shipping;
}

float Product::getWeight() {
    return weight;
}

void Product::setQuantity(float newQty) {
    quantity = newQty;
}

bool Product::isExpired() {
    if(expiry==-1) return false; //product doesn't expire
    return expiry < time(0);
}

void Product::display() {
    cout << name << " - $" << price
         << " | Stock: " << quantity
         << (isExpired() ? " [EXPIRED]" : "")
         << (shipping ? " | Shippable" : " | Pickup only")
         << endl;
}
