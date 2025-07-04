    #include "Customer.h"

unordered_map<string,Customer> existingCustomers;

    float Customer::getBalance() {
        return balance;
    }

    void Customer::rechargeBalance(float amount) {
        balance+= amount;
        existingCustomers[username] = *this;
    }

    void Customer::changePassword() {
        string oldPassword, newPassword;
        cout<<"Please Enter Your Old Password: ";
        cin>>oldPassword;
        if(oldPassword == password) {
            cout<<"Please Enter New Password: ";
            cin >> newPassword;
            password=newPassword;
            existingCustomers[username] = *this;
        }
        else {
            cout<<"Password Incorrect."<<endl;
        }
    }

    void Customer::changeUsername() {
        string newUsername;
        cout<<"Please Enter New Username: ";
        cin>>newUsername;
        if(existingCustomers.find(newUsername)!=existingCustomers.end()) {
            cout<<"Username Already Taken."<<endl;
        }
        else {
            existingCustomers.erase(username);
            username = newUsername;
            existingCustomers[username] = *this;

        }
    }

    bool Customer::login() {
        string uname, pass;
        cout << "Enter username: ";
        cin >> uname;
        cout << "Enter password: ";
        cin >> pass;

        if(existingCustomers.find(uname)!= existingCustomers.end() && existingCustomers[uname].password == pass) {
            cout << "Login successful. Welcome, " << uname << "!" << endl;
            *this = existingCustomers[uname];
            return true;
        }
        cout << "Login failed. Incorrect username or password." << endl;
        return false;
    }


    bool Customer::createAccount() {
        string uname, pass;
        cout << "Enter a username: ";
        cin >> uname;

        if (existingCustomers.find(uname) != existingCustomers.end()) {
            cout << "Username already exists. Please choose another." << endl;
            return false;
        }
        cout << "Enter a password: ";
        cin >> pass;

        username = uname;
        password = pass;
        balance = 0.0;
        existingCustomers[uname] = *this;

        cout << "Account created successfully!" << endl;
        return true;
    }
