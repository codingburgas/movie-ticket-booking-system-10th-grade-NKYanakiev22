#pragma once
#include <vector>
#include <string>

struct Showtime {
    std::string time;
    std::string date;
    int availableSeats;
};

struct Movie {
    std::string title;
    std::string city;
    std::string date;
    std::vector<Showtime> showtimes;
};

void addMovie(std::vector<Movie>& movies);
void viewMovies(const std::vector<Movie>& movies);
void editShowtimes(std::vector<Movie>& movies);
