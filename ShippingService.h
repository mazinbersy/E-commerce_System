#ifndef SHIPPINGSERVICE_H
#define SHIPPINGSERVICE_H
#include "Product.h"
#include <vector>
using namespace std;


class ShippingService {
private:
    vector<pair<string,float>> items;
    float totalWeight =0.0;
    float shippingCost =0.0;

public:
    float getWeight();
    float getCost();
    void addItem(string, float);
    void displayItems();
    void clear();

};



#endif //SHIPPINGSERVICE_H
