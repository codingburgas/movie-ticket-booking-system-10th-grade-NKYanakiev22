#include "customer.h"
#include <iostream>

using namespace std;

void customerMenu(vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies available to book.\n";
        return;
    }

    cout << "\n=== Available Movies ===\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title
            << " | " << movies[i].city
            << " | " << movies[i].date << endl;
        for (size_t j = 0; j < movies[i].showtimes.size(); ++j) {
            cout << "   " << j + 1 << ") "
                << movies[i].showtimes[j].time
                << " - Seats: " << movies[i].showtimes[j].availableSeats << endl;
        }
    }

    int movieChoice;
    cout << "\nSelect a movie number to book tickets: ";
    cin >> movieChoice;

    if (movieChoice < 1 || movieChoice > movies.size()) {
        cout << "Invalid movie selection.\n";
        return;
    }

    Movie& selectedMovie = movies[movieChoice - 1];

    int showtimeChoice;
    cout << "Select a showtime number: ";
    cin >> showtimeChoice;

    if (showtimeChoice < 1 || showtimeChoice > selectedMovie.showtimes.size()) {
        cout << "Invalid showtime selection.\n";
        return;
    }

    Showtime& selectedShowtime = selectedMovie.showtimes[showtimeChoice - 1];

    int tickets;
    cout << "Enter number of tickets to book: ";
    cin >> tickets;

    if (tickets <= 0) {
        cout << "Invalid ticket number.\n";
        return;
    }

    if (tickets > selectedShowtime.availableSeats) {
        cout << "Not enough seats available.\n";
    }
    else {
        selectedShowtime.availableSeats -= tickets;
        cout << "Booking successful! Enjoy your movie.\n";
    }
}
