#include "ShippingService.h"

float ShippingService::getWeight() {
    return totalWeight;
}

float ShippingService::getCost() {
    return shippingCost;
}

void ShippingService::addItem(string p, float w) {
    items.push_back({p,w});
    totalWeight +=w;
    shippingCost += w * 2; //Every Kilogram is 2$ to Ship
}

void ShippingService::displayItems() {
    if (items.empty()) {
    cout << "No items scheduled for shipping." << endl;
    return;
}

cout << "** Shipment Notice **" << endl;
float totalWeight = 0;

for (auto& item : items) {
    cout << "- " << item.first << ": " << item.second << "kg" << endl;
    totalWeight += item.second;
}

cout << "-------------------------" << endl;
cout << "Total package weight: " << totalWeight << "kg" << endl;
cout << "Shipping cost: $" << shippingCost << endl;
}

void ShippingService::clear() {
    items.clear();
    totalWeight = 0.0;
    shippingCost = 0.0;
}
