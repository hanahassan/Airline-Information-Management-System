#include "main.h"
#include <fstream>
using namespace std;


void pressEnter() {
    cout << "<< Press Enter to Continue >>";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}


int menu(){
    int choice = 1;

    cout << "Please select one of the following option:\n";
    cout << "1. Display Flight Seat Map.\n";
    cout << "2. Diaplay Passengers Information. \n";
    cout << "3. Add a New Passenger. \n";
    cout << "4. Remove an Existing Passenger \n";
    cout << "5. Save Data \n";
    cout << "6. Quit \n";

    cin >> choice; 
    return choice;
}

void displayHeader(){
    cout<< "Version: 1.0\n";
    cout<< "Term Project - Flight Mangement Program in C++\n";
    cout<< "Produced by: Kamand Ghorbanzadeh, Hana Hassan, Hasnain Haider\n";
}


Flight populate_flight(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string id;
    int rows, columns;
    file >> id >> rows >> columns;

    Flight flight(id, rows, columns);

    while (!file.eof()) {
        std::string firstName, lastName, phoneNumber;
        int idM, seatNumber;

        file >> firstName >> lastName >> phoneNumber >> idM >> seatNumber;

        Passenger passenger(firstName, lastName, phoneNumber, idM, seatNumber);
        flight.addPassenger(passenger);
    }

    file.close();

    return flight;
}


int main(){
    Flight f;
    displayHeader();
    f = populate_flight("flight_info.txt");
    int choice = 1;
    /*while (choice !=0){
        switch(menu()){
            case 1:
                f.show_seat_map();
                pressEnter();
                break;
            
            case 2:
                f.displayPassenger();
                pressEnter();
                break;
            
            case 3:
                f.add_Passenger();
                pressEnter();
                break;

        }
    }*/

}