#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


class Customer {

private:
    string username;
    string password;
    float balance;

public:
    float getBalance();
    void rechargeBalance(float);
    void changePassword();
    void changeUsername();
    bool login();
    bool createAccount();
};

extern unordered_map<string,Customer> existingCustomers;


#endif //CUSTOMER_H
