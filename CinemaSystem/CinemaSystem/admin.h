#pragma once
#include <vector>
#include "movie.h"

class Admin {
public:
    bool login(std::vector<Movie>& movies);
    void menu(std::vector<Movie>& movies);
};
