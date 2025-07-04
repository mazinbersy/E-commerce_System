#include "Cart.h"
#include "Customer.h"
#include "Product.h"
#include "ShippingService.h"
#include <iostream>
using namespace std;

// Simulate product database
vector<Product> productDatabase = {
    Product("Milk", 2.5, 10, time(0) + 86400, true, 1.0),
    Product("Bread", 1.5, 20, time(0) + 172800, true, 0.5),
    Product("Cheese", 4.0, 5, time(0) - 10000, true, 0.8),
    Product("Laptop", 1000.0, 2, time(0) + 864000, false, 2.5)
};

bool insufficientBalance(Customer& customer, float total) {
    return customer.getBalance() < total;
}

void checkout(Customer& customer, Cart& cart, ShippingService& shipService) {
    if (cart.empty()) {
        cout << "Your cart is empty!" << endl;
        return;
    }

    float subtotal = 0;
    float shippingFee = 0;


    for (auto& item : cart.getProducts()) {
        Product& p = item.first;
        float qty = item.second;
        if (p.needsShipping()) {
            shipService.addItem(p.getName(), qty * p.getWeight());
        }
    }

    shipService.displayItems();
    shippingFee = shipService.getCost();

    cout << "** Checkout receipt **" << endl;
    for (auto& item : cart.getProducts()) {
        Product& p = item.first;
        float qty = item.second;
        float cost = qty * p.getPrice();
        cout << qty << "x " << p.getName() << " $" << cost << endl;
        subtotal += cost;
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
    cart.clearCart();
    shipService.clear();
}

int main() {
    Customer customer;
    Cart cart;
    ShippingService shipService;
    int choice;

    cout << "Welcome to the Shopping System!" << endl;
    cout << "1. Create Account" << endl << "2. Login" << endl << "OR Enter Anything Else to Exit " << endl << "Choose: ";
    cin >> choice;

    if (choice == 1) {
        if (!customer.createAccount()) return 0;
    } else if (choice == 2) {
        if (!customer.login()) return 0;
    } else {
        return 0;
    }

    while (true) {
        cout << "----- Menu -----" << endl;
        cout << "1. View Products" << endl
             << "2. Add to Cart" << endl
             << "3. Remove from Cart" << endl
             << "4. View Cart Total" << endl
             << "5. Recharge Balance" << endl
             << "6. Checkout" << endl
             << "7. View Cart" << endl
             << "8. Logout" << endl
             << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < productDatabase.size(); i++) {
                cout<<i<<". ";
                productDatabase[i].display();
            }
        } else if (choice == 2) {
            cout << "Available Products:" << endl;
            for (int i = 0; i < productDatabase.size(); i++) {
                cout<<i<<". ";
                productDatabase[i].display();
            }
            int index;
            float qty;
            cout << "Enter product index: ";
            cin >> index;
            if (index >= 0 && index < productDatabase.size()) {
                cout << "Enter quantity: ";
                cin >> qty;
                cart.add(productDatabase[index], qty);
            } else {
                cout << "Invalid product index." << endl;
            }
        } else if (choice == 3) {
            cart.displayCart();
            int index;
            float qty;
            cout << "Enter index of item in cart to remove: ";
            cin >> index;
            cout << "Enter quantity to remove: ";
            cin >> qty;
            cart.remove(index, qty, productDatabase[index]);
        } else if (choice == 4) {
            cout << "Cart total: $" << cart.getSum() << endl;
        } else if (choice == 5) {
            float amount;
            cout << "Enter amount to recharge: ";
            cin >> amount;
            customer.rechargeBalance(amount);
            cout << "New balance: $" << customer.getBalance() << endl;
        } else if (choice == 6) {
            checkout(customer, cart, shipService);
        } else if (choice == 7) {
            cart.displayCart();
        } else if (choice == 8) {
            cout << "Logged out successfully!" << endl;
            cout << "1. Create Account" << endl << "2. Login" << endl << "OR Enter Anything Else to Exit " << endl << "Choose: ";
            cin >> choice;

            if (choice == 1) {
                if (!customer.createAccount()) return 0;
            } else if (choice == 2) {
                if (!customer.login()) return 0;
            } else {
                cout << "THANK YOU FOR SHOPPING WITH US!" << endl;
                return 0;
            }
        } else {
            cout << "Invalid option." << endl;
        }
    }
}
