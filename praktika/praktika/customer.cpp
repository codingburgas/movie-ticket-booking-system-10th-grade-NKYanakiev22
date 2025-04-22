#include <iostream>
#include "customer.h"
#include "movie.h"

using namespace std;

void customerBookTicket(const vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies available.\n";
        return;
    }

    // Step 1: Select City
    vector<string> cities;
    for (const auto& movie : movies) {
        if (find(cities.begin(), cities.end(), movie.city) == cities.end()) {
            cities.push_back(movie.city);
        }
    }

    clearScreen(); // Clear screen after city selection
    cout << "\nAvailable Cities:\n";
    for (size_t i = 0; i < cities.size(); ++i)
        cout << i + 1 << ". " << cities[i] << endl;

    int cityChoice;
    cout << "Select city: ";
    cin >> cityChoice;
    if (cityChoice < 1 || cityChoice > cities.size()) return;
    string selectedCity = cities[cityChoice - 1];

    // Step 2: Select Date
    vector<string> dates;
    for (const auto& movie : movies) {
        if (movie.city == selectedCity && find(dates.begin(), dates.end(), movie.date) == dates.end()) {
            dates.push_back(movie.date);
        }
    }

    clearScreen(); // Clear screen after date selection
    cout << "\nAvailable Dates in " << selectedCity << ":\n";
    for (size_t i = 0; i < dates.size(); ++i)
        cout << i + 1 << ". " << dates[i] << endl;

    int dateChoice;
    cout << "Select date: ";
    cin >> dateChoice;
    if (dateChoice < 1 || dateChoice > dates.size()) return;
    string selectedDate = dates[dateChoice - 1];

    // Step 3: Select Movie
    vector<const Movie*> filteredMovies;
    clearScreen(); // Clear screen after date selection
    cout << "\nAvailable Movies on " << selectedDate << " in " << selectedCity << ":\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i].city == selectedCity && movies[i].date == selectedDate) {
            cout << filteredMovies.size() + 1 << ". " << movies[i].title << endl;
            filteredMovies.push_back(&movies[i]);
        }
    }

    int movieChoice;
    cout << "Select movie: ";
    cin >> movieChoice;
    if (movieChoice < 1 || movieChoice > filteredMovies.size()) return;

    const Movie* selectedMovie = filteredMovies[movieChoice - 1];

    clearScreen();
    cout << "\nShowtimes for " << selectedMovie->title << ":\n";
    for (size_t i = 0; i < selectedMovie->showtimes.size(); ++i) {
        cout << i + 1 << ". " << selectedMovie->showtimes[i].time
            << " (" << selectedMovie->showtimes[i].availableSeats << " seats)\n";
    }

    int showtimeChoice;
    cout << "Select showtime: ";
    cin >> showtimeChoice;
    if (showtimeChoice < 1 || showtimeChoice > selectedMovie->showtimes.size()) return;

    cout << "\n?? You selected:\n";
    cout << "City: " << selectedCity << endl;
    cout << "Date: " << selectedDate << endl;
    cout << "Movie: " << selectedMovie->title << endl;
    cout << "Time: " << selectedMovie->showtimes[showtimeChoice - 1].time << endl;
    cout << "Enjoy your show!\n";
}
