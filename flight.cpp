//flight.cpp

#include "flight.h"
#include <iomanip>
#include <algorithm>

// Default constructor
Flight::Flight() : num_rowsM(0), num_columnsM(0) {
}

// Parameterized constructor
Flight::Flight(string id, int rows, int columns) : idM(id), num_rowsM(rows), num_columnsM(columns) {
}

// Copy constructor - idk if we need this?
Flight::Flight(const Flight& source) : idM(source.idM), num_rowsM(source.num_rowsM), num_columnsM(source.num_columnsM) {
    // Implement copying for other members if needed
}

// Destructor - idk if we need this?
Flight::~Flight() {
    // Implement any necessary cleanup
}

// Getter functions
string Flight::get_idM() const {
    return idM;
}

int Flight::get_rowsM() const {
    return num_rowsM;
}

int Flight::get_columnsM() const {
    return num_columnsM;
}

vector<Passenger> Flight::get_passengers() const {
    return passengers;
}

vector<vector<Seat>> Flight::get_seatmap() const {
    return seatmap;
}

// Setter functions
void Flight::set_idM(string id) {
    idM = id;
}

void Flight::set_numrowsM(int rows) {
    num_rowsM = rows;
}

void Flight::set_numcolumnsM(int columns) {
    num_columnsM = columns;
}

void Flight::set_passengers(const vector<Passenger>& passengers) {
    this->passengers = passengers;
}

// Function to add a passenger to the flight
void Flight::add_passenger(const Passenger& passenger) {
    passengers.push_back(passenger);
}

// Function to display passenger information
void Flight::display_passengers() const {
    // Display headers
    cout << left << setw(20) << "First Name" << setw(20) << "Last Name" << setw(25) << "Phone" << setw(8) << "Row" << setw(8) << "Seat" << setw(8) << "ID\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    
    for (const Passenger& passenger : passengers) {
        // Display passenger details
        cout << left << setw(20) << passenger.getFirstName() << setw(20) << passenger.getLastName() << setw(25) << passenger.getPhoneNumber()
             << setw(8) << passenger.getSeatNumber() << setw(8) << passenger.getSeat() << setw(8) << passenger.getID() << "\n";
        
        // Print a long dashed line after each row
        cout << "--------------------------------------------------------------------------------------------\n";
    }
}

void Flight::remove_passenger(int passengerID) {
    try {
        // Convert the input to an integer
        int convertedID = std::stoi(std::to_string(passengerID));

        // Check if the converted ID is a 5-digit number
        if (convertedID < 10000 || convertedID > 99999) {
            std::cout << "Invalid passenger ID. Please enter a 5-digit ID.\n";
            return;
        }

        // Use lambda function to find the passenger
        auto it = std::remove_if(passengers.begin(), passengers.end(),
            [convertedID](const Passenger& passenger) { return passenger.getID() == convertedID; });

        if (it != passengers.end()) {
            passengers.erase(it, passengers.end());
            std::cout << "Passenger with ID " << convertedID << " removed successfully.\n";
        } else {
            std::cout << "Passenger with ID " << convertedID << " not found.\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input. Please enter a valid integer ID.\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Invalid input. The entered ID is out of range.\n";
    }
}

// Function to display the seat map
// void Flight::displaySeatMap() const {
//     Implement as needed
// }

// Function to populate_flight
// void Flight::populate_flight(const string& filename) {
//     Implement as needed
// }

// Function to clean buffer
// void Flight::cleanStandardInputStream(void) {
//     Implement as needed
// }