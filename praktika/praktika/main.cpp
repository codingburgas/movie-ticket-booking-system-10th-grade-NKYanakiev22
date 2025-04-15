#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Customer
{
    string username;
    string password;
};

void adminLogin()
{
    string adminUsername = "kolyo";
    string adminPassword = "121212";

    string username, password;
    cout << "Please enter admin username: ";
    cin >> username;
    cout << "Please enter admin password: ";
    cin >> password;

    if (username == adminUsername && password == adminPassword)
    {
        cout << "Admin logged in successfully!" << endl;
    }
    else
    {
        cout << "Invalid admin credentials!" << endl;
    }
}

bool customerLogin(const vector<Customer>& customers)
{
    string username, password;
    cout << "Please enter username: ";
    cin >> username;
    cout << "Please enter password: ";
    cin >> password;

    for (const auto& customer : customers)
    {
        if (customer.username == username && customer.password == password)
        {
            cout << "Customer logged in successfully!" << endl;
            return true;
        }
    }

    cout << "Invalid username or password!" << endl;
    return false;
}

void customerRegister(vector<Customer>& customers)
{
    string username, password;
    cout << "Please enter a username for registration: ";
    cin >> username;
    cout << "Please enter a password for registration: ";
    cin >> password;

    customers.push_back({ username, password });
    cout << "Customer registered successfully!" << endl;
}

void customerLoginOrRegister(vector<Customer>& customers)
{
    int choice;
    cout << "1. Log in" << endl;
    cout << "2. Register" << endl;
    cout << "Please select an option: ";
    cin >> choice;

    if (choice == 1)
    {
        customerLogin(customers);
    }
    else if (choice == 2)
    {
        customerRegister(customers);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}

int main()
{
    vector<Customer> customers;
    int n;

    while (true)
    {
        cout << "\nPlease enter: " << endl;
        cout << "1. Admin panel" << endl;
        cout << "2. Customer panel" << endl;
        cout << "3. Exit" << endl;
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "You chose the admin panel" << endl;
            adminLogin();
            break;
        case 2:
            cout << "You chose the customer panel" << endl;
            customerLoginOrRegister(customers);
            break;
        case 3:
            cout << "Exiting the program..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please choose again." << endl;
            break;
        }
    }

    return 0;
}
