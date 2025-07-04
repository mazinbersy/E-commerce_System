#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

extern unordered_set<string> existingUsernames;

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



#endif //CUSTOMER_H
