# 🛒 Console-Based Shopping System

This is a C++ console application simulating a basic e-commerce system. It allows users to create accounts, login, browse products, manage their cart, and checkout with shipping and balance deduction functionalities.

---

## 📦 Features

- 🧾 **Account Creation & Login**
- 🛍️ **Product Browsing** with expiry info
- 🛒 **Cart Management** (add, remove, view items)
- 💰 **Balance Recharge** and checkout
- 🚚 **Shipping Fee Calculation** for shippable items
- 🧮 **Subtotal & Total Calculation**
- ❌ **Product Expiry Handling**
- 🔐 **Username and Password Changes**

⚠️ **Note**
Login works only if an account is created during the same runtime. All user data is stored in memory and will be lost once the program terminates. Persistent storage (e.g., file or database) is not implemented.

---

## 📂 File Structure

- `main.cpp`: Application entry point and main loop
- `Customer.h/.cpp`: Customer class with account features
- `Product.h/.cpp`: Product class with info and shipping data
- `Cart.h/.cpp`: Cart class to manage product selections
- `ShippingService.h/.cpp`: Handles shipment logic and cost

---

## 🛠️ How to Run

1. **Compile** all `.cpp` files:
   ```bash
   g++ main.cpp Customer.cpp Product.cpp Cart.cpp ShippingService.cpp -o shop
2. **Run** the executable: 

```bash
./shop

