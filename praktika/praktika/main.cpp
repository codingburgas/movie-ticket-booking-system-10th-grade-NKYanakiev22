#include <iostream>
#include <string>
using namespace std;

void print()
{
    string fName;
    string password;
    cout << "Please enter username: " << endl;
    cin >> fName;
    cout << "Please enter pass: " << endl;
    cin >> password;
}


int main()
{
    int n;
    cout << "Please enter: " << endl;
    cout << "1. Admin panel" << endl;
    cout << "2. Customer panel" << endl;
    cin >> n;
    switch (n)
    {
    case 1: cout << "You choose admin panel" << endl;
        print();
        break;
    case 2: cout << "You choose customer panel" << endl;
        print();
        break;
    }
}