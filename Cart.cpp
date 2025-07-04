#include "Cart.h"

void Cart::add(Product& p, float quantity) {

    if(p.isExpired()) {
        cout<<"Sorry, Product "<<p.getName()<<" has Expired."<<endl;
        return;
    }
    if(outOfStock(p,quantity)) {
        cout<<"Sorry, The Requested Quantity is Not Available at the Moment"<<endl;
        return;
    }
    products.push_back({p,quantity});
    sum += quantity * p.getPrice();
    float newQ = p.getQuantity() - quantity;
    p.setQuantity(newQ);
    cout<<"Product Added Successfully."<<endl;
}

void Cart::remove(int index, float quantity, Product& p) {
    if(!empty()) {
        if(products[index].second <= quantity) {
            sum -= p.getPrice() * products[index].second;
            products.erase(products.begin() + index);
            p.setQuantity(p.getQuantity() + products[index].second);
            cout<<"Product Removed Successfully."<<endl;
        }
        else {
            sum -= p.getPrice() * quantity;
            products[index].second -= quantity;
            p.setQuantity(p.getQuantity() + quantity);
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


bool Cart::outOfStock(Product p, float quantity) {
    if(p.getQuantity() < quantity)
        return true;
    return false;
}


void Cart::displayCart() {
    if (products.empty()) {
        cout << "Cart is empty." << endl;
        return;
    }

    cout << "Cart Contents:"<<endl;
    for (int i = 0; i < products.size(); ++i) {
        auto item = products[i];
        cout << i << ". " << item.first.getName()
             << " | Quantity: " << item.second
             << " | Unit Price: $" << item.first.getPrice()
             << " | Subtotal: $" << item.second * item.first.getPrice() << endl;
    }
    cout << "Total: $" << sum << endl;
}
vector<pair<Product, float>>& Cart::getProducts() {
    return products;
}

void Cart::clearCart() {
    products.clear();
    sum =0.0;
}

