#include <iostream>
#include <vector>
#include <string>
#include "movie.h"

using namespace std;

void addMovie(vector<Movie>& movies) {
    Movie m;

    // Flush any leftover input before getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter movie title: ";
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

        if (i == 0) {
            m.date = s.date;
        }
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
            cout << "  Time: " << show.time << ", Seats: " << show.availableSeats;
        }
    }
}

void editShowtimes(vector<Movie>& movies) {
    viewMovies(movies);
    int index;
    cout << "Enter movie number to edit: ";
    cin >> index;
    if (index < 1 || index > movies.size()) {
        cout << "Invalid index.\n";
        return;
    }

    Movie& movie = movies[index - 1];
    int choice;
    cout << "Editing: " << movie.title << "\n";
    cout << "1. Change a showtime\n2. Change available seats\n";
    cin >> choice;

    if (choice == 1) {
        for (size_t i = 0; i < movie.showtimes.size(); ++i)
            cout << i + 1 << ". " << movie.showtimes[i].time << endl;

        int stIndex;
        cout << "Which showtime to edit? ";
        cin >> stIndex;
        if (stIndex >= 1 && stIndex <= movie.showtimes.size()) {
            cout << "Enter new time: ";
            cin >> movie.showtimes[stIndex - 1].time;
        }
    }
    else if (choice == 2) {
        for (size_t i = 0; i < movie.showtimes.size(); ++i)
            cout << i + 1 << ". " << movie.showtimes[i].time << " (" << movie.showtimes[i].availableSeats << " seats)\n";

        int stIndex;
        cout << "Which showtime's seats to change? ";
        cin >> stIndex;
        if (stIndex >= 1 && stIndex <= movie.showtimes.size()) {
            cout << "Enter new number of seats: ";
            cin >> movie.showtimes[stIndex - 1].availableSeats;
        }
    }
    else {
        cout << "Invalid choice.\n";
    }
}
