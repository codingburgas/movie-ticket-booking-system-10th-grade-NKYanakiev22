#include <iostream>
#include <vector>
#include <string>
#include "movie.h"

using namespace std;

void addMovie(vector<Movie>& movies) {
    Movie m;
    cout << "Enter movie title: ";
    cin.ignore();
    getline(cin, m.title);

    cout << "Enter city: ";
    getline(cin, m.city);

    int showtimeCount;
    cout << "How many showtimes to add? ";
    cin >> showtimeCount;

    for (int i = 0; i < showtimeCount; ++i) {
        Showtime s;
        cout << "Enter showtime (e.g., 18:00): ";
        cin >> s.time;

        cout << "Enter date for this showtime (YYYY-MM-DD): ";
        cin >> s.date;

        cout << "Enter number of available seats: ";
        cin >> s.availableSeats;

        m.showtimes.push_back(s);
    }

    movies.push_back(m);
    cout << "Movie added successfully!\n";
}

void viewMovies(const vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies available.\n";
        return;
    }

    for (size_t i = 0; i < movies.size(); ++i) {
        cout << "\nMovie " << i + 1 << ": " << movies[i].title << endl;
        for (const auto& show : movies[i].showtimes) {
            cout << "  Time: " << show.time << ", Seats: " << show.availableSeats
