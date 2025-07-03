#include "movie.h"
#include <iostream>
#include <limits>

using namespace std;

Movie::Movie(const string& t, const string& c) : title(t), city(c) {}

void Movie::addShowtime(const Showtime& s) {
    showtimes.push_back(s);
}

void Movie::editShowtime(int index, const string& newTime) {
    if (index >= 0 && index < showtimes.size())
        showtimes[index].time = newTime;
}

void Movie::editSeats(int index, int newSeats) {
    if (index >= 0 && index < showtimes.size())
        showtimes[index].availableSeats = newSeats;
}

const string& Movie::getTitle() const { return title; }
const string& Movie::getCity() const { return city; }
vector<Showtime>& Movie::getShowtimes() { return showtimes; }
const vector<Showtime>& Movie::getShowtimes() const { return showtimes; }

void Movie::display(int index) const {
    cout << "\nMovie " << index + 1 << ": " << title << endl;
    cout << "  City: " << city << endl;
    for (const auto& show : showtimes) {
        cout << "  Date: " << show.date
            << ", Time: " << show.time
            << ", Seats: " << show.availableSeats << endl;
    }
}

void addMovie(vector<Movie>& movies) {
    string title, city;
    int showtimeCount;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter movie title: ";
    getline(cin, title);
    cout << "Enter city: ";
    getline(cin, city);

    Movie m(title, city);

    cout << "How many showtimes to add? ";
    cin >> showtimeCount;

    for (int i = 0; i < showtimeCount; ++i) {
        Showtime s;
        cout << "Enter showtime (e.g., 18:00): ";
        cin >> s.time;
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> s.date;
        cout << "Available seats: ";
        cin >> s.availableSeats;
        m.addShowtime(s);
    }

    movies.push_back(m);
    cout << "Movie added successfully!\n";
    system("pause");
}

void viewMovies(const vector<Movie>& movies) {
    if (movies.empty()) {
        cout << "No movies available.\n";
    }
    else {
        for (size_t i = 0; i < movies.size(); ++i)
            movies[i].display(i);
    }
    system("pause");
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
    cout << "Editing: " << movie.getTitle() << "\n1. Change a showtime\n2. Change available seats\n";
    cin >> choice;

    const auto& showtimes = movie.getShowtimes();
    for (size_t i = 0; i < showtimes.size(); ++i)
        cout << i + 1 << ". " << showtimes[i].time << " (" << showtimes[i].availableSeats << " seats)\n";

    int stIndex;
    cout << "Select showtime: ";
    cin >> stIndex;

    if (choice == 1) {
        string newTime;
        cout << "New time: ";
        cin >> newTime;
        movie.editShowtime(stIndex - 1, newTime);
    }
    else if (choice == 2) {
        int newSeats;
        cout << "New seat count: ";
        cin >> newSeats;
        movie.editSeats(stIndex - 1, newSeats);
    }
    else {
        cout << "Invalid option.\n";
    }
}
