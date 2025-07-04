cmake_minimum_required(VERSION 3.28)
project(E_commerce)

set(CMAKE_CXX_STANDARD 17)

add_executable(E_commerce main.cpp
        Cart.cpp
        Customer.cpp
        Product.cpp
        ShippingService.cpp
)
