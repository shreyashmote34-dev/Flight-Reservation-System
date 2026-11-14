
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Flight {
    int id;
    string name;
    string source;
    string destination;
    float price;
    int seats;
};

vector<Flight> flights;

// Add Flight
void addFlight() {
    Flight f;

    cout << "\nEnter Flight ID: ";
    cin >> f.id;

    cin.ignore();

    cout << "Enter Flight Name: ";
    getline(cin, f.name);

    cout << "Enter Source: ";
    getline(cin, f.source);

    cout << "Enter Destination: ";
    getline(cin, f.destination);

    cout << "Enter Ticket Price: ";
    cin >> f.price;

    cout << "Enter Available Seats: ";
    cin >> f.seats;

    flights.push_back(f);

    cout << "\nFlight Added Successfully!\n";
}

// Display Flights
void displayFlights() {
    if (flights.empty()) {
        cout << "\nNo Flights Available!\n";
        return;
    }

    cout << "\n------ Available Flights ------\n";

    for (const Flight &f : flights) {
        cout << "\nFlight ID: " << f.id;
        cout << "\nFlight Name: " << f.name;
        cout << "\nSource: " << f.source;
        cout << "\nDestination: " << f.destination;
        cout << "\nTicket Price: Rs. " << f.price;
        cout << "\nAvailable Seats: " << f.seats;
        cout << "\n-----------------------------\n";
    }
}

// Search Flight using Linear Search
void searchFlight() {
    int id;
    bool found = false;

    cout << "\nEnter Flight ID to Search: ";
    cin >> id;

    for (const Flight &f : flights) {
        if (f.id == id) {
            cout << "\nFlight Found!\n";
            cout << "Flight Name: " << f.name << endl;
            cout << "Source: " << f.source << endl;
            cout << "Destination: " << f.destination << endl;
            cout << "Ticket Price: Rs. " << f.price << endl;
            cout << "Available Seats: " << f.seats << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nFlight Not Found!\n";
    }
}

// Sort Flights by Ticket Price
void sortFlights() {
    sort(flights.begin(), flights.end(),
         [](const Flight &a, const Flight &b) {
             return a.price < b.price;
         });

    cout << "\nFlights Sorted by Ticket Price!\n";
    displayFlights();
}

// Book Flight Ticket
void bookTicket() {
    int id, tickets;

    cout << "\nEnter Flight ID: ";
    cin >> id;

    for (Flight &f : flights) {
        if (f.id == id) {
            cout << "Enter Number of Tickets: ";
            cin >> tickets;

            if (tickets > 0 && tickets <= f.seats) {
                f.seats -= tickets;

                cout << "\nBooking Successful!\n";
                cout << "Total Amount: Rs. "
                     << f.price * tickets << endl;
                cout << "Remaining Seats: "
                     << f.seats << endl;
            }
            else {
                cout << "\nSeats Not Available!\n";
            }
            return;
        }
    }

    cout << "\nFlight Not Found!\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n===== FLIGHT RESERVATION SYSTEM =====";
        cout << "\n1. Add Flight";
        cout << "\n2. Display Flights";
        cout << "\n3. Search Flight";
        cout << "\n4. Sort Flights by Price";
        cout << "\n5. Book Ticket";
        cout << "\n6. Exit";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFlight();
                break;

            case 2:
                displayFlights();
                break;

            case 3:
                searchFlight();
                break;

            case 4:
                sortFlights();
                break;

            case 5:
                bookTicket();
                break;

            case 6:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
