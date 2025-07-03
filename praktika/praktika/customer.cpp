#include "customer.h"
#include <iostream>
#include <fstream>

using namespace std;

bool CustomerManager::registerCustomer() {
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

string CustomerManager::loginCustomer() {
    string username, password;
    string fileUsername, filePassword;

    while (true) {
        cout << "Login\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        ifstream inFile("customers.txt");
        if (!inFile) {
            cout << "Cannot open customers.txt.\n";
            return "";
        }

        bool found = false;
        while (inFile >> fileUsername >> filePassword) {
            if (username == fileUsername && password == filePassword) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Login successful!\n";
            return username;
        }
        else {
            char retry;
            cout << "Incorrect username or password. Try again? (y/n): ";
            cin >> retry;
            if (retry == 'n' || retry == 'N') {
                return "";
            }
        }
    }
}

void CustomerManager::customerMenu(vector<Movie>& movies, const string& username) {
    system("cls");

    if (movies.empty()) {
        cout << "No movies at the moment.\n";
        system("pause");
        return;
    }

    cout << "\n=== Available Movies ===\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].title
            << " | " << movies[i].city << endl;
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

    string cardNumber;
    string cardHolderFirstName;
    string cardHolderLastName;
    string expiryDate;
    string cvv;


    cout << "Enter your 16-digit credit card number: ";
    cin >> cardNumber;
    cout << "Enter the name on the card: ";
    cin >> cardHolderFirstName >> cardHolderLastName;
    cout << "Enter expiry date (MM/YY): ";
    cin >> expiryDate;
    cout << "Enter the 3-digit CVV: ";
    cin >> cvv;

    show.availableSeats -= tickets;

    ofstream resFile("reservations.txt", ios::app);
    if (!resFile) {
        cout << "Cannot open reservations.txt.\n";
        return;
    }

    resFile << "Username: " << username
        << "Movie: " << selected.title
        << ", City: " << selected.city
        << ", Date: " << show.date
        << ", Showtime: " << show.time
        << ", Tickets: " << tickets << "\n";

    cout << "Tickets booked! Enjoy the movie.\n";
    system("pause");
}
