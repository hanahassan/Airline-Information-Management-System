#include "main.h"

void displayHeader(){
    cout<< "Version: 1.0\n";
    cout<< "Term Project - Flight Mangement Program in C++\n";
    cout<< "Produced by: Kamand Ghorbanzadeh, Hana Hassan, Hasnain Haider\n";
    cout<< "Year: 2023\n\n";
    pressEnter();
}

int menu(){
    int choice = 1;

    cout << "Please select one of the following options:\n\n";
    cout << "1. Display Flight Seat Map.\n";
    cout << "2. Display Passengers Information. \n";
    cout << "3. Add a New Passenger. \n";
    cout << "4. Remove an Existing Passenger \n";
    cout << "5. Save Data \n";
    cout << "6. Quit \n";
    cout << "\nEnter you choice: (1,2,3,4,5 or 6) ";

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

Flight populate_flight(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return Flight();
    }

    int rows, columns;
    string name;
    file >> name >> rows >> columns;
    // cout << name << " " << rows << " " << columns << endl;

    Flight flight(name, rows, columns);

    // Read passenger information
    string line;
    while (getline(file, line)) {

        // Kept getting an error where it tried to read the first line as empty
        if (line.empty()) {
            continue;
        }

        // All lines are strictly 69 characters long
        if (line.length() < 69) { // haha funny
            cerr << "Error: Line is too short. Length: " << line.length() << endl;
            continue;
        }

        // Manually parse the line
        string firstName = line.substr(0, 20);  // 20 Characters long
        string lastName = line.substr(20, 20);  // 20 Characters long
        string phoneNumber = line.substr(40, 15);  // 12 characters
        string seat = line.substr(60, 4);  // 4 characters
        stoi(line.substr(64, 5));  // 5 characters

        // cout << "First Name: " << firstName << " Last Name: " << lastName
        //     << " Phone Number: " << phoneNumber << " Seat: " << seat << " ID: " << id << endl;

        size_t row_part = seat.find_first_not_of("0123456789");

        // Extract the numeric part
        stoi(seat.substr(0, row_part));

        // Extract the character part
        seat[row_part];

        // cout << "Numeric part: " << row << endl;
        // cout << "Character part: " << cols << endl;
    }

    file.close();
    return flight;
}
void quit() {
    cout << "Terminating the program. Goodbye!\n";
    exit(0);
}

int main(){
    displayHeader();
    cleanStandardInputStream();
    Flight f = populate_flight("flight_info.txt");
    int choice = 1;
    while (choice !=0){
        switch(menu()){
            case 1:
                //f.show_seat_map();
                pressEnter();
                break;
            
            case 2:
                //f.display_passengers();
                pressEnter();
                break;
            
            case 3: {
                string firstName, lastName, phoneNumber, seat;
                int id, row;

                // Get passenger information from the user
                cout << "Please enter the passenger id (in this format XXXXX): ";
                cin >> id;
                cleanStandardInputStream();
                cout << "Please enter the passenger first name: ";
                cin >> firstName;
                cleanStandardInputStream();
                cout << "Please enter the passenger last name: ";
                cin >> lastName;
                cleanStandardInputStream();
                cout << "Please enter the passenger phone number (in this format XXX XXX XXXX): ";
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
                //f.remove_passenger();
                pressEnter();
                break;
            case 5:
                //f.save_info();
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