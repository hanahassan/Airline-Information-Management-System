#include "main.h"
#include "flight.h"
#include "passenger.h"
#include "seat.h"
#include "airline.h"

using namespace std;


void pressEnter() {
    cout << "Press Enter to continue...";
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

int main(){
    //Flight f;
    displayHeader();
    pressEnter();
    //f = populate_flight("flight_info.txt");
    int choice = 1;
   /* while choice(choice !=0){
        switch(menu()){
            case 1:
                f.show_seat_map();
                pressEnter();
                break;
            
            case 2:
                displayPassenger();
                pressEnter();
                break;
            
            case 3:
            add_Passenger();
            pressEnter();
            break;

        }
    }*/

}