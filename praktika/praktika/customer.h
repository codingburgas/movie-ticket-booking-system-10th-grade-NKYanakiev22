#pragma once
#include <vector>
#include <string>
#include "movie.h"

bool registerCustomer();
string loginCustomer();
void customerMenu(vector<Movie>& movies, const string& username);
