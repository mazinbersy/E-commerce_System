#include "Cart.h"

void Cart::add(product p, float quantity) {

    if(expired(p)) {
        cout<<"Sorry, Product "<<p.name<<" has Expired."<<endl;
        return;
    }
    if(outOfStock(p,quantity)) {
        cout<<"Sorry, The Requested Quantity is Not Available at the Moment"<<endl;
        return;
    }
    products.push_back({p,quantity});
    sum += quantity * p.price;
    cout<<"Product Added Successfully."<<endl;
}

void Cart::remove(int index, float quantity) {
    if(!empty()) {
        if(products[index].second <= quantity) {
            sum -= products[index].first.price * products[index].second;
            products.erase(products.begin() + index);
            cout<<"Product Removed Successfully."<<endl;
        }
        else {
            sum -= products[index].first.price * quantity;
            products[index].second -= quantity;
            cout<<"Quantity Decreased Successfully."<<endl;

        }
    }
    else
        cout<<"Cart is Already Empty."<<endl;
}

float Cart::getSum() {
    return sum;
}


bool Cart::empty() {
    if(products.empty())
        return true;
    return false;
}


bool Cart::outOfStock(product p, float quantity) {
    if(p.quantity < quantity)
        return true;
    return false;
}

bool Cart::expired(product p) {
    if(p.expiry < time(0))
        return true;
    return false;
}

void Cart::displayCart() {
    if (products.empty()) {
        cout << "Cart is empty." << endl;
        return;
    }

    cout << "\nCart Contents:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        const auto& item = products[i];
        cout << i << ". " << item.first.name
             << " | Quantity: " << item.second
             << " | Unit Price: $" << item.first.price
             << " | Subtotal: $" << item.second * item.first.price << endl;
    }
    cout << "Total: $" << sum << endl;
}
vector<pair<product, float>>& Cart::getProducts() {
    return products;
}

