#include <iostream>
#include <vector>
#include <limits>
#include "admin.h"
#include "movie.h"
#include "customer.h"

using namespace std;

int main() {
    vector<Movie> movies;
    Admin admin;
    CustomerManager cm;
    int choice;

    while (true) {
        system("cls");
        cout << "\n=== Movie Booking System ===\n";
        cout << "1. Admin\n2. Customer\n3. Exit\nChoose: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            admin.login(movies);
            break;
        case 2: {
            int cChoice;
            cout << "\n1. Register\n2. Login\nChoose: ";
            cin >> cChoice;

            if (cChoice == 1) {
                cm.registerCustomer();
            }
            else if (cChoice == 2) {
                string user = cm.loginCustomer();
                if (!user.empty()) cm.customerMenu(movies, user);
            }
            else {
                cout << "Invalid choice.\n";
            }
            break;
        }
        case 3:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
