#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "admin.h"
#include "movie.h"
#include "customer.h"
#include "utils.h"

using namespace std;

int main() {
    vector<Movie> movies;
    int choice;

    while (true) {
        clearConsole();
        cout << "\n=== Movie Booking System ===\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            adminLogin(movies);
            break;
        case 2: {
            int customerChoice;
            clearConsole();
            cout << "\n=== Customer Menu ===\n";
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "Choose: ";
            cin >> customerChoice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (customerChoice == 1) {
                registerCustomer();
                cout << "Now log in to continue.\n";
            }
            else if (customerChoice == 2) {
                string loggedInUser = loginCustomer();
                if (!loggedInUser.empty()) {
                    customerMenu(movies, loggedInUser);
                }
            }
            else {
                cout << "Invalid option.\n";
            }
            break;
        }
        case 3:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
