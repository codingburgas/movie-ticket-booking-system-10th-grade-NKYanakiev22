#include <iostream>
#include "admin.h"
#include "customer.h"
#include "movie.h"

using namespace std;

int main() {
    vector<Customer> customers;
    vector<Movie> movies;
    int n;

    while (true) {
        clearScreen();
        cout << "\n=== Movie Booking System ===\n";
        cout << "What are you?:"
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> n;

        switch (n) {
        case 1:
            adminLogin(movies);
            break;
        case 2:
            customerLoginOrRegister(customers);
            customerBookTicket(movies);
            break;
        case 3:
            cout << "Exiting the program...\n";
            return 0;
        default:
            cout << "Invalid choice! Please choose again.\n";
            break;
        }
    }

    return 0;
}
