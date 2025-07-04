#include "Cart.h"
#include "Customer.h"
#include <iostream>
using namespace std;

// Simulate product database
vector<product> productDatabase = {
    {"Milk", 2.5, 10, time(0) + 86400, true, 1.0},
    {"Bread", 1.5, 20, time(0) + 172800, true, 0.5},
    {"Cheese", 4.0, 5, time(0) - 10000, true, 0.8}, // expired
    {"Laptop", 1000.0, 2, time(0) + 864000, false, 2.5}
};

bool insufficientBalance(Customer& customer, float total) {
    return customer.getBalance() < total;
}

void checkout(Customer& customer, Cart& cart) {
    if (cart.empty()) {
        cout << "Your cart is empty!" << endl;
        return;
    }

    float totalWeight = 0;
    float subtotal = 0;
    float shippingFee = 0;

    cout << "\n** Shipment notice **" << endl;

    // Calculate subtotal and weight
    for (auto& item : cart.getProducts()) {
        const product& p = item.first;
        float qty = item.second;
        if (p.shipping) {
            cout << qty << "x " << p.name << " " << (qty * p.weight) << "kg" << endl;
            totalWeight += qty * p.weight;
        }
    }

    cout << "Total package weight: " << totalWeight << "kg" << endl;

    cout << "\n** Checkout receipt **" << endl;
    for (auto& item : cart.getProducts()) {
        const product& p = item.first;
        float qty = item.second;
        float cost = qty * p.price;
        cout << qty << "x " << p.name << " $" << cost << endl;
        subtotal += cost;
    }

    // Flat shipping fee if any shipping-required item exists
    if (totalWeight > 0) {
        shippingFee = 30.0; // fixed for this example
    }

    float total = subtotal + shippingFee;

    cout << "----------------------" << endl;
    cout << "Subtotal $" << subtotal << endl;
    cout << "Shipping $" << shippingFee << endl;
    cout << "Amount $" << total << endl;

    if (insufficientBalance(customer, total)) {
        cout << "Insufficient balance! Please recharge." << endl;
        return;
    }

    customer.rechargeBalance(-total);
    cout << "Checkout successful. Remaining balance: $" << customer.getBalance() << endl;
}


int main() {
    Customer customer;
    Cart cart;
    int choice;

    cout << "Welcome to the Shopping System!" << endl;


        cout << "1. Create Account" <<endl <<"2. Login"<<endl <<"OR Enter Anything Else to Exit "<<endl <<"Choose: ";
        cin >> choice;

        if(choice == 1) {
            if(customer.createAccount());
        }
        else if(choice == 2) {
            if(customer.login());
        }
        else {
            return 0;
        }


    while(true) {
        cout << "----- Menu -----" << endl;
        cout << "1. View Products"<<endl<<"2. Add to Cart"<<endl<<"3. Remove from Cart"<<
            endl<<"4. View Cart Total"<<endl<<"5. Recharge Balance"<<endl<<"6. Checkout"<<endl
            <<"7. View Cart "<<endl<<"8. Logout"<<endl<<"Choose: ";
        cin >> choice;

        if(choice == 1) {
            for(size_t i = 0; i < productDatabase.size(); ++i) {
                product& p = productDatabase[i];
                cout << i << ". " << p.name << " - $" << p.price << " | Stock: " << p.quantity
                     << (cart.expired(p) ? " [EXPIRED]" : "") << endl;
            }
        }
        else if(choice == 2) {
            cout << "Available Products:"<<endl;
            for(int i = 0; i < productDatabase.size(); i++) {
                product p = productDatabase[i];
                cout << i << ". " << p.name << " - $" << p.price << " | Stock: " << p.quantity
                     << (cart.expired(p) ? " [EXPIRED]" : "") << endl;
            }

            int index;
            float qty;
            cout << "Enter product index: ";
            cin >> index;
            if(index >= 0 && index < productDatabase.size()) {
                cout << "Enter quantity: ";
                cin >> qty;
                cart.add(productDatabase[index], qty);
            } else {
                cout << "Invalid product index." << endl;
            }
        }
        else if(choice == 3) {
            cart.displayCart();

            int index;
            float qty;
            cout << "Enter index of item in cart to remove: ";
            cin >> index;
            cout << "Enter quantity to remove: ";
            cin >> qty;
            cart.remove(index, qty);
        }
        else if(choice == 4) {
            cout << "Cart total: $" << cart.getSum() << endl;
        }
        else if(choice == 5) {
            float amount;
            cout << "Enter amount to recharge: ";
            cin >> amount;
            customer.rechargeBalance(amount);
            cout << "New balance: $" << customer.getBalance() << endl;
        }
        else if(choice == 6) {
            checkout(customer, cart);
        }
        else if(choice == 7) {
            cart.displayCart();
        }
        else if(choice == 8) {
            cout << "Logged out successfully!" << endl;
            cout << "1. Create Account" <<endl <<"2. Login"<<endl <<"OR Enter Anything Else to Exit "<<endl <<"Choose: ";
            cin >> choice;

            if(choice == 1) {
                if(customer.createAccount());
            }
            else if(choice == 2) {
                if(customer.login());
            }
            else {
                return 0;
            }
        }
        else {
            cout << "Invalid option." << endl;
        }
    }

}
