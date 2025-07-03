#include "admin.h"
#include <iostream>
#include <limits>

using namespace std;

bool Admin::login(vector<Movie>& movies) {
    system("cls");
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username == "kolyo" && password == "121212") {
        cout << "Login successful!\n";
        menu(movies);
        return true;
    }
    else {
        cout << "Invalid credentials.\n";
        return false;
    }
}

void Admin::menu(vector<Movie>& movies) {
    int choice;
    do {
        system("cls");
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Add Movie\n2. View Movies\n3. Edit Showtimes\n4. Logout\nChoose: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: addMovie(movies); break;
        case 2: viewMovies(movies); break;
        case 3: editShowtimes(movies); break;
        case 4: cout << "Logging out...\n"; break;
        default: cout << "Invalid option.\n";
        }
    } while (choice != 4);
}
