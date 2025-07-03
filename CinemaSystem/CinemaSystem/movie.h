#pragma once
#include <string>
#include <vector>

struct Showtime {
    std::string time;
    std::string date;
    int availableSeats;
};

class Movie {
private:
    std::string title;
    std::string city;
    std::vector<Showtime> showtimes;

public:
    Movie() = default;
    Movie(const std::string& title, const std::string& city);

    void addShowtime(const Showtime& showtime);
    void editShowtime(int index, const std::string& newTime);
    void editSeats(int index, int newSeats);

    const std::string& getTitle() const;
    const std::string& getCity() const;
    std::vector<Showtime>& getShowtimes();
    const std::vector<Showtime>& getShowtimes() const;

    void display(int index) const;
};

void addMovie(std::vector<Movie>& movies);
void viewMovies(const std::vector<Movie>& movies);
void editShowtimes(std::vector<Movie>& movies);
