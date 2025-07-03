#pragma once
#include <vector>
#include <string>
#include "movie.h"

class CustomerManager {
public:
    bool registerCustomer();
    std::string loginCustomer();
    void customerMenu(std::vector<Movie>& movies, const std::string& username);
};
