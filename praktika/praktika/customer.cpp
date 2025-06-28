#include "customer.h"
#include <iostream>
#include <fstream>
#include "utils.h"

using namespace std;

bool registerCustomer() {
    string username, password;
    cout << "Register\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream check("customers.txt");
    string u, p;
    while (check >> u >> p) {
        if (u == username) {
            cout << "Username already exists.\n";
            return false;
        }
    }
    check.close();

    ofstream file("customers.txt", ios::app);
    if (!file) {
        cout << "Cannot open customers.txt.\n";
        return false;
    }

    file << username << " " << password << "\n";
    cout << "Registered successfully!\n";
    return true;
}

std::string loginCustomer() {
    string username, password;
    cout << "Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("customers.txt");
    if (!file) {
        cout << "Cannot open customers.txt.\n";
        return "";
    }

    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful!\n";
            return username;
        }
    }

    cout << "Invalid login.\n";
    return "";
}

void customerMenu(vector<Movie>& movies, const string& username) {
    clearConsole();
    if (movies.empty()) {
        cout << "No movies to display.\n";
        return;
    }

    cout << "\n=== Available Movies ===\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title
            << " | " << movies[i].city
            << " | " << movies[i].date << endl;
        for (size_t j = 0; j < movies[i].showtimes.size(); ++j) {
            cout << "   " << j + 1 << ") " << movies[i].showtimes[j].time
                << " - Seats: " << movies[i].showtimes[j].availableSeats << endl;
        }
    }

    int m, s, tickets;
    cout << "Choose a movie: ";
    cin >> m;
    if (m < 1 || m > movies.size()) return;

    Movie& selected = movies[m - 1];

    cout << "Choose showtime: ";
    cin >> s;
    if (s < 1 || s > selected.showtimes.size()) return;

    Showtime& show = selected.showtimes[s - 1];

    cout << "How many tickets? ";
    cin >> tickets;

    if (tickets <= 0 || tickets > show.availableSeats) {
        cout << "Not enough seats.\n";
        return;
    }

    show.availableSeats -= tickets;
    cout << "Tickets booked! Enjoy the movie.\n";

    ofstream resFile("reservations.txt", ios::app);
    if (!resFile) {
        cout << "Cannot open reservations.txt.\n";
        return;
    }

    resFile << username << " "
        << selected.title << " "
        << selected.city << " "
        << selected.date << " "
        << show.time << " "
        << tickets << "\n";
}
