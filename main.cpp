// main.cpp

#include "main.h"
// #include "flight.h"  // Add this line
// #include "passenger.h"  // Add this line


// Function to populate flight
void populate_flight(Flight& f) {
    ifstream inFile;
    string fileName;

    cout << "Enter the directory of your file: ";
    cin >> fileName;
    inFile.open(fileName);

    if (!inFile.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }

    // Read flight information from the first line
    string flightInfoLine;
    getline(inFile, flightInfoLine);
    istringstream flightInfoStream(flightInfoLine);

    string flightNumber;
    int rows, columns;
    flightInfoStream >> flightNumber >> rows >> columns;

    f.set_idM(flightNumber);
    f.set_numrowsM(rows);
    f.set_numcolumnsM(columns);

    // Read passenger information from the remaining lines
    string line;
    while (getline(inFile, line)) {
        istringstream passengerInfoStream(line);

        // Read first name, middle/last names, phone number, seat, and ID
        string firstName, lastName, phoneNumber, seat, idStr;
        passengerInfoStream >> firstName >> lastName >> phoneNumber >> seat >> idStr;

        try {
            // Convert idStr to integer
            int id = stoi(idStr);

            // Separate row and seat from the combined information
            size_t lastDigitIndex = seat.find_last_of("0123456789");
            int row = stoi(seat.substr(0, lastDigitIndex + 1));
            char column = seat.back();

            // Create a Passenger object and add it to the flight
            Passenger newPassenger(id, firstName, lastName, phoneNumber, seat, row);
            f.add_passenger(newPassenger);
        } catch (const std::invalid_argument& e) {
            cerr << "Error: Invalid argument in stoi conversion. Check the input file format." << endl;
            // Handle the error appropriately (e.g., continue reading the next line)
        }
    }

    inFile.close();
}


void displayHeader() {
    cout << "Version: 1.0\n";
    cout << "Term Project - Flight Management Program in C++\n";
    cout << "Produced by: Kamand Ghorbanzadeh, Hana Hassan, Hasnain Haider\n";
    cout << "Year: 2023\n\n";
    pressEnter();
}

int menu() {
    int choice = 1;

    cout << "Please select one of the following options:\n\n";
    cout << "1. Display Flight Seat Map.\n";
    cout << "2. Display Passengers Information.\n";
    cout << "3. Add a New Passenger.\n";
    cout << "4. Remove an Existing Passenger\n";
    cout << "5. Save Data\n";
    cout << "6. Quit\n";
    cout << "\nEnter your choice: (1,2,3,4,5, or 6) ";

    cin >> choice;
    return choice;
}

void pressEnter() {
    cout << "<< Press Enter to Continue >> " << flush;
    cin.clear(); // Clear any remaining errors or flags

    // Wait for a newline character
    while (cin.get() != '\n') {}
}

void cleanStandardInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void quit() {
    cout << "Terminating the program. Goodbye!\n";
    exit(0);
}

int main() {
    Flight f;
    displayHeader();
    cleanStandardInputStream();
    populate_flight(f);
    
    cout << "\nPassengers after populating the flight:\n";
    f.display_passengers();


    int choice = 1;
    while (choice != 0) {
        switch (menu()) {
            case 1:
                // f.show_seat_map();
                pressEnter();
                break;

            case 2:
                f.display_passengers();
                pressEnter();
                break;

            case 3: {
                string firstName, lastName, phoneNumber, seat;
                int id, row;

                // Get passenger information from the user
                cout << "Please enter the passenger id: ";
                cin >> id;
                cleanStandardInputStream();
                cout << "Please enter the passenger first name: ";
                cin >> firstName;
                cleanStandardInputStream();
                cout << "Please enter the passenger last name: ";
                cin >> lastName;
                cleanStandardInputStream();
                cout << "Please enter the passenger phone number: ";
                cin >> phoneNumber;
                cleanStandardInputStream();
                cout << "Enter the passenger's desired row: ";
                cin >> row;
                cleanStandardInputStream();
                cout << "Enter the passenger's desired seat: ";
                cin >> seat;
                cleanStandardInputStream();

                // Create a Passenger object and add it to the flight
                Passenger newPassenger(id, firstName, lastName, phoneNumber, seat, row);
                f.add_passenger(newPassenger);
                pressEnter();
                break;
            }

            case 4:
                // f.remove_passenger();
                pressEnter();
                break;

            case 5:
                // f.save_info();
                pressEnter();
                break;

            case 6:
                quit();
                break;

            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
        cleanStandardInputStream();
    }

    return 0;
}
