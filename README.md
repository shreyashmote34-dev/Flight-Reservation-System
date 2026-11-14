# Flight-Reservation-System
Flight Reservation System using C++ Searching and Sorting

#include <iostream>
#include <vector>
#include <algorithm>
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

    cout << "Enter Flight Name: ";
    cin >> f.name;

    cout << "Enter Source: ";
    cin >> f.source;

    cout << "Enter Destination: ";
    cin >> f.destination;

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

    cout << "\n--- Available Flights ---\n";

    for (const auto &f : flights) {
        cout << "\nFlight ID: " << f.id;
        cout << "\nName: " << f.name;
        cout << "\nSource: " << f.source;
        cout << "\nDestination: " << f.destination;
        cout << "\nPrice: Rs. " << f.price;
        cout << "\nSeats: " << f.seats << "\n";
    }
}

// Linear Search
void searchFlight() {
    int id;
    bool found = false;

    cout << "\nEnter Flight ID to Search: ";
    cin >> id;

    for (const auto &f : flights) {
        if (f.id == id) {
            cout << "\nFlight Found!";
            cout << "\nFlight Name: " << f.name;
            cout << "\nSource: " << f.source;
            cout << "\nDestination: " << f.destination;
            cout << "\nPrice: Rs. " << f.price << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nFlight Not Found!\n";
}

// Bubble Sort by Price
void sortFlights() {
    for (int i = 0; i < (int)flights.size() - 1; i++) {
        for (int j = 0; j < (int)flights.size() - i - 1; j++) {
            if (flights[j].price > flights[j + 1].price) {
                swap(flights[j], flights[j + 1]);
            }
        }
    }

    cout << "\nFlights Sorted by Price!\n";
    displayFlights();
}

// Book Ticket
void bookTicket() {
    int id, count;
    string passenger;
    bool found = false;

    cout << "\nEnter Flight ID: ";
    cin >> id;

    for (auto &f : flights) {
        if (f.id == id) {
            found = true;

            cout << "Enter Passenger Name: ";
            cin >> passenger;

            cout << "Enter Number of Seats: ";
            cin >> count;

            if (count > 0 && count <= f.seats) {
                f.seats -= count;

                cout << "\nTicket Booked Successfully!";
                cout << "\nPassenger: " << passenger;
                cout << "\nFlight: " << f.name;
                cout << "\nTotal Amount: Rs. "
                     << f.price * count << "\n";
            } else {
                cout << "\nSeats Not Available!\n";
            }
            break;
        }
    }

    if (!found)
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
        cout << "\n5. Book Flight Ticket";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice: ";
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

