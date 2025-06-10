#include <iostream>
#include "admin.h"
#include "movie.h"

using namespace std;

int main() {
    system("cls");
    vector<Movie> movies;
    int n;

    while (true) {
        cout << "\n=== Movie Booking System ===\n";
        cout << "What are you?:\n";
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
            cout << "Exiting the program...\n";
            return 0;
        default:
            cout << "Invalid choice! Please choose again.\n";
        }
    }

    return 0;
}
