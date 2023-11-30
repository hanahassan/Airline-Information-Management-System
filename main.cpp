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
    cout << "2. Diaplay Passengers Information. \n";
    cout << "3. Add a New Passenger. \n";
    cout << "4. Remove an Existing Passenger \n";
    cout << "5. Save Data \n";
    cout << "6. Quit \n";
    cout << "\nEnter you choice: (1,2,3,4,5 or 6) ";

    cin >> choice; 
    return choice;
}

void pressEnter() {
    cout << "<< Press Enter to Continue >>";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void cleanStandardInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void quit() {
    cout << "Terminating the program. Goodbye!\n";

    // Exit the program
    exit(0);
}

int main(){
    Flight f;
    displayHeader();
    cleanStandardInputStream();
    f.populate_flight("flight_info.txt");
    int choice = 1;
    while (choice !=0){
        switch(menu()){
            case 1:
                //f.show_seat_map();
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