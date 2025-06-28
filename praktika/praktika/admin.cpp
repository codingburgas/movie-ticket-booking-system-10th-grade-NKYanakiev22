#include <iostream>
#include <vector>
#include <string>
#include "admin.h"
#include "movie.h"
#include "utils.h"

using namespace std;

bool adminLogin(vector<Movie>& movies) {
    clearConsole();
    string username, password;
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (username == "opel" && password == "astra-h-opc") {
        cout << "Login successful!\n";
        adminMenu(movies);
        return true;
    }
    else {
        cout << "Invalid credentials.\n";
        return false;
    }
}

void adminMenu(vector<Movie>& movies) {
    int choice;
    do {
        clearConsole();
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Add Movie\n";
        cout << "2. View Movies\n";
        cout << "3. Edit Showtimes\n";
        cout << "4. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            addMovie(movies);
            break;
        case 2:
            viewMovies(movies);
            break;
        case 3:
            editShowtimes(movies);
            break;
        case 4:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}
