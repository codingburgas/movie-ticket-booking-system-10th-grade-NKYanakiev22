#pragma once
#include <vector>
#include <string>

struct Customer {
    std::string username;
    std::string password;
};

bool customerLogin(const std::vector<Customer>& customers);
void customerRegister(std::vector<Customer>& customers);
void customerLoginOrRegister(std::vector<Customer>& customers);
