//flight.cpp
#include <algorithm>
#include "flight.h"
#include <iomanip>
#include <limits>
#include <fstream>
#include <string>
#include "flight.h"
using namespace std;


// Default constructor
Flight::Flight() : num_rowsM(0), num_columnsM(0) {
    resize_seat_map(0, 0);
}

// Parameterized constructor
Flight::Flight(string id, int rows, int columns) : idM(id), num_rowsM(rows), num_columnsM(columns) {
}

// Getter implementation
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

// Setter implementation
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
    cout << left << setw(20) << "First Name" << setw(20) << "Last Name" << setw(25) << "Phone" << setw(8) << "Row" << setw(8) << "Seat" << setw(8) << "ID";
    cout << "\n--------------------------------------------------------------------------------------------\n";
    
    for (const Passenger& passenger : passengers) {
        // Display passenger details
        cout << left << setw(20) << passenger.getFirstName() << setw(20) << passenger.getLastName() << setw(25) << passenger.getPhoneNumber()
             << setw(8) << passenger.getSeatNumber() << setw(8) << passenger.getSeat() << setw(8) << passenger.getID() << "\n";
        
        // Print a long dashed line after each row
        cout << "--------------------------------------------------------------------------------------------\n";
    }
}

// Function to remove a passenger to the flight
void Flight::remove_passenger(int passengerID) {
    auto it = std::remove_if(passengers.begin(), passengers.end(),
                             [passengerID](const Passenger& passenger) { return passenger.getID() == passengerID; });

        if (it != passengers.end()) {
            passengers.erase(it, passengers.end());
            std::cout << "Passenger with ID " << passengerID << " removed successfully.\n";
        } else {
            std::cout << "Passenger with ID " << passengerID << " not found.\n";
        }
    }

 // Function to create an empty seat map
void Flight::create_empty_seat_map() {
    // Ensure rows and columns are non-negative
    if (num_rowsM <= 0 || num_columnsM <= 0) {
        std::cerr << "Invalid number of rows or columns. Please set valid values.\n";
        return;
    }

    // Resize the seat map to the specified number of rows and columns
    seatmap.resize(num_rowsM + 1, vector<Seat>(num_columnsM));

    // Initialize each seat in the seat map
    for (int i = 0; i <= num_rowsM; ++i) {
        for (int j = 0; j < num_columnsM; ++j) {
            seatmap[i][j] = Seat(); // Assuming Seat has a default constructor
        }
    }
}

// Function to resize the seat map
void Flight::resize_seat_map(int rows, int columns) {
    // Ensure rows and columns are non-negative
    if (rows <= 0 || columns <= 0) {
        std::cerr << "Invalid number of rows or columns. Please set valid values.\n";
        return;
    }

    // Resize the seat map to the specified number of rows and columns
    seatmap.resize(rows + 1, vector<Seat>(columns));

    // Initialize each seat in the seat map
    for (int i = 0; i <= rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            seatmap[i][j] = Seat(); // Assuming Seat has a default constructor
        }
    }

    // Update the member variables
    num_rowsM = rows;
    num_columnsM = columns;
}

// Function to display the seat map
void Flight::display_seat_map() const {
    // Check if the seat map has been initialized
    cout << "Flight Seat Map for Flight " << idM << ":" << endl;
    cout << "     ";
    for (int i = 0; i < num_columnsM; ++i) {
        cout << static_cast<char>('A' + i) << "   ";
    }
    std::cout << std::endl;



    for (int i = 1; i <= num_rowsM; ++i) {
        std::cout << std::setw(2) << i << " ";
        for (int j = 0; j < num_columnsM; ++j) {
            bool is_occupied = false;
            for (size_t k = 0; k < passengers.size(); ++k) {
                int row = passengers[k].getSeatNumber();
                string myString = passengers[k].getSeat();
                char seat = myString[0];
                if (row == i && j == seat - 'A') {
                    std::cout << "| X ";
                    is_occupied = true;
                    break;
                }
            }
            if (!is_occupied) {
                std::cout << "|   ";
            }
        }
        std::cout << "|" << std::endl << "   ";
        for (int j = 0; j < num_columnsM; ++j) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }
}

void Flight::save_info() {
    char response;
   
    cout << "Do you want to save the data in the 'flight_info.txt'? Please answer < Y or N > ";
    cin >> response;

    if(response == 'Y' || response == 'y') {
         std::ifstream inputFile("flight_info.txt");
           if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file for reading." << std::endl;
        
    }
     std::string firstLine;
    std::getline(inputFile, firstLine);
    inputFile.close();
     std::ofstream outputFile("flight_info.txt", std::ios::trunc);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open the file for writing." << std::endl;
       
    }
    outputFile << firstLine << std::endl;
    outputFile.close();

        ofstream outFile("flight_info.txt", ios::app);
    

        if (!outFile.is_open()) {
            cerr << "Error: Could not open or create file flight_info.txt" << endl;
            return;

        }

       


        for (const Passenger& passenger : passengers) {
        
        string firstName = passenger.getFirstName();
        firstName.resize(20,' ');
        string lastName = passenger.getLastName();
        lastName.resize(20,' ');
        string phoneNumber = passenger.getPhoneNumber();
        phoneNumber.resize(20,' ');
        int row = passenger.getSeatNumber();
        string rowNew = to_string(row);
        string seatChar = passenger.getSeat();
        string seatStr = rowNew+seatChar;
        seatStr.resize(4,' ');
        int id = passenger.getID();
        string idNew = to_string(id);
    

   

    // Write passenger details to the file
    outFile << firstName<< lastName << phoneNumber << seatStr << id << '\n';
    
    // Write passenger details to the file
    }

       
        outFile.close();

        cout << "Flight information saved successfully.\n";
    } else {
        cout << "Okay, let's exit out" << endl;
       
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