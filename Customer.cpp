    #include "Customer.h"

unordered_set<string> existingUsernames;

    float Customer::getBalance() {
        return balance;
    }

    void Customer::rechargeBalance(float amount) {
        balance+= amount;
    }

    void Customer::changePassword() {
        string oldPassword, newPassword;
        cout<<"Please Enter Your Old Password: ";
        cin>>oldPassword;
        if(oldPassword == password) {
            cout<<"Please Enter New Password: ";
            cin >> newPassword;
            password=newPassword;
        }
        else {
            cout<<"Password Incorrect."<<endl;
        }
    }

    void Customer::changeUsername() {
        string newUsername;
        cout<<"Please Enter New Username: ";
        cin>>newUsername;
        if(existingUsernames.find(newUsername)!=existingUsernames.end()) {
            cout<<"Username Already Taken."<<endl;
        }
        else {
            existingUsernames.erase(username);
            username = newUsername;
            existingUsernames.insert(username);

        }
    }

    bool Customer::login() {
        string uname, pass;
        cout << "Enter username: ";
        cin >> uname;
        cout << "Enter password: ";
        cin >> pass;

        if(uname == username && pass==password) {
            cout << "Login successful. Welcome, " << username << "!" << endl;
            return true;
        }
        cout << "Login failed. Incorrect username or password." << endl;
        return false;
    }


    bool Customer::createAccount() {
        string uname, pass;
        cout << "Enter a username: ";
        cin >> uname;

        if (existingUsernames.find(uname) != existingUsernames.end()) {
            cout << "Username already exists. Please choose another." << endl;
            return false;
        }
        cout << "Enter a password: ";
        cin >> pass;

        username = uname;
        password = pass;
        balance = 0.0;
        existingUsernames.insert(uname);

        cout << "Account created successfully!" << endl;
        return true;
    }
