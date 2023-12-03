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

        string firstName = line.substr(0, 20);

// Read next 20 characters as the last name
        string lastName = line.substr(20, 20);
        string phoneNumber = line.substr(40,20);
        string seat = line.substr(60,4);
        string idStr = line.substr(64,5);
        // Read first name, middle/last names, phone number, seat, and ID
      
        

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
/*bool isValidPassengerID(const string& id){
    // Check if the length is 5
    if (id.length() != 5) {
        return false;
    }

    // Check if all characters are digits
    for (char ch : id) {
        if (!isdigit(ch)) {
            return false;
        }
    }

    // If all checks pass, the ID is valid
    return true;
}
bool hasDigits(const string& str) {
    // Check if the string contains any digits
    for (char ch : str) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

bool isValidPhoneNumber(const string& phoneNumber) {
    // Check if the length is 12 (including spaces)
    if (phoneNumber.length() != 12) {
        return false;
    }

    // Check if characters at appropriate positions are spaces
    if (phoneNumber[3] != '-' || phoneNumber[7] != '-') {
        return false;
    }

    // Check if all characters, except spaces, are digits
    for (size_t i = 0; i < phoneNumber.length(); ++i) {
        if (i != 3 && i != 7 && !isdigit(phoneNumber[i])) {
            return false;
        }
    }

    // If all checks pass, the phone number is valid
    return true;
}

void add_passenger(Flight& f) {
    string firstName, lastName, phoneNumber, id;
    char seat;
    int row;

    // Get passenger ID
    do {
        cout << "Please enter the passenger ID (in this form XXXXX): ";
        cin >> id;

        if (!isValidPassengerID(id)) {
            cout << "Invalid format. Please enter a 5-digit ID." << endl;
        }
    } while (!isValidPassengerID(id));

    // Get passenger first name
    do {
        cout << "Please enter the passenger first name: ";
        cin >> firstName;

        if (hasDigits(firstName)) {
            cout << "Invalid input. Please enter a first name without any numbers." << endl;
        }
    } while (hasDigits(firstName));

    // Get passenger last name
    do {
        cout << "Please enter the passenger last name: ";
        cin >> lastName;

        if (hasDigits(lastName)) {
            cout << "Invalid input. Please enter a last name without any numbers." << endl;
        }
    } while (hasDigits(lastName));

    // Get passenger phone number
    do {
        cout << "Please enter the passenger phone number (in this format XXX-XXX-XXXX): ";
        cin >> phoneNumber;

        if (!isValidPhoneNumber(phoneNumber)) {
            cout << "Invalid format. Please enter a 10-digit phone number with spaces." << endl;
        }
    } while (!isValidPhoneNumber(phoneNumber));

    // Get passenger desired row
    do {
        cout << "Enter the passenger's desired row: ";
        cin >> row;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
        } else if (row < 1 || row > 24) {
            cout << "Invalid row number. Please enter a number between 1 and 24." << endl;
        }
    } while (row < 1 || row > 24);

    // Get passenger desired seat
    do {
        cout << "Enter passenger's desired seat (A, B, C, D, E, or F): ";
        cin >> seat;

        // Convert the entered character to uppercase for case-insensitivity
        seat = toupper(seat);

        // Check if input is a valid character
        if (cin.fail() || (seat < 'A' || seat > 'F')) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid seat character (A, B, C, D, E, or F)." << endl;
        }
    } while (seat < 'A' || seat > 'F');

    // Create a Passenger object and add it to the flight
    Passenger newPassenger(stoi(id), firstName, lastName, phoneNumber, seat, row);
    f.add_passenger(newPassenger);

}*/
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
                
                //add_passenger(f);
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
