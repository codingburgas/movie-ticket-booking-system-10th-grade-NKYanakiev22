#pragma once
#include <string>
#include <vector>
#include "movie.h"

class CustomerManager {
private:
    std::string customerFile = "customers.txt";
    std::string reservationFile = "reservations.txt";

    bool isUsernameTaken(const std::string& username);
    bool validateCredentials(const std::string& username, const std::string& password);
    void bookTickets(std::vector<Movie>& movies, const std::string& username);

public:
    bool registerCustomer();
    std::string loginCustomer();
    void customerMenu(std::vector<Movie>& movies, const std::string& username);
};
