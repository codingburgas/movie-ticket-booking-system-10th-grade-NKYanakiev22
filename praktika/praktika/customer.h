#pragma once
#include <vector>
#include <string>
#include "movie.h"

bool registerCustomer();
std::string loginCustomer();
void customerMenu(std::vector<Movie>& movies, const std::string& username);
