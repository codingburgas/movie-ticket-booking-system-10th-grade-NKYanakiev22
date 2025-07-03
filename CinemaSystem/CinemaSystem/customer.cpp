#include "customer.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

bool CustomerManager::isUsernameTaken(const string& username) {
    ifstream file(customerFile);
    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

bool CustomerManager::validateCredentials(const string& username, const string& password) {
    ifstream file(customerFile);
    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) return true;
    }
    return false;
}

bool CustomerManager::registerCustomer() {
    string username, password;
    cout << "Register\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (isUsernameTaken(username)) {
        cout << "Username already exists.\n";
        return false;
    }

    ofstream file(customerFile, ios::app);
    if (!file) {
        cout << "Cannot open file.\n";
        return false;
    }

    file << username << " " << password << "\n";
    cout << "Registered successfully!\n";
    return true;
}

string CustomerManager::loginCustomer() {
    string username, password;

    while (true) {
        cout << "Login\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (validateCredentials(username, password)) {
            cout << "Login successful!\n";
            return username;
        }
        else {
            char retry;
            cout << "Incorrect credentials. Try again? (y/n): ";
            cin >> retry;
            if (retry == 'n' || retry == 'N') return "";
        }
    }
}

void CustomerManager::customerMenu(vector<Movie>& movies, const string& username) {
    system("cls");

    if (movies.empty()) {
        cout << "No movies available.\n";
        system("pause");
        return;
    }

    cout << "\n=== Available Movies ===\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].getTitle()
            << " | " << movies[i].getCity() << endl;
        const auto& showtimes = movies[i].getShowtimes();
        for (size_t j = 0; j < showtimes.size(); ++j) {
            cout << "   " << j + 1 << ") " << showtimes[j].time
                << " - Seats: " << showtimes[j].availableSeats << endl;
        }
    }

    bookTickets(movies, username);
}

void CustomerManager::bookTickets(vector<Movie>& movies, const string& username) {
    int m, s, tickets;
    cout << "Choose a movie: ";
    cin >> m;
    if (m < 1 || m > movies.size()) return;

    Movie& selected = movies[m - 1];
    auto& showtimes = selected.getShowtimes();

    cout << "Choose showtime: ";
    cin >> s;
    if (s < 1 || s > showtimes.size()) return;

    Showtime& show = showtimes[s - 1];

    cout << "How many tickets? ";
    cin >> tickets;

    if (tickets <= 0 || tickets > show.availableSeats) {
        cout << "Not enough seats.\n";
        return;
    }

    string cardNumber, cardFirst, cardLast, expiry, cvv;
    cout << "Enter card number: ";
    cin >> cardNumber;
    cout << "Cardholder name: ";
    cin >> cardFirst >> cardLast;
    cout << "Expiry date (MM/YY): ";
    cin >> expiry;
    cout << "CVV: ";
    cin >> cvv;

    show.availableSeats -= tickets;

    ofstream resFile(reservationFile, ios::app);
    if (!resFile) {
        cout << "Cannot open reservation file.\n";
        return;
    }

    resFile << "Username: " << username
        << ", Movie: " << selected.getTitle()
        << ", City: " << selected.getCity()
        << ", Date: " << show.date
        << ", Time: " << show.time
        << ", Tickets: " << tickets << "\n";

    cout << "Thank you for booking your tickets!\n";
    system("pause");
}
