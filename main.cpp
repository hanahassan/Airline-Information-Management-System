#include "main.h"
#include "flight.h"
#include "passenger.h"
#include "seat.h"
#include "airline.h"

void pressEnter() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();
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

int main(){
    Flight f;
    displayHeader();
    f = populate_flight("flight.txt");
    int choice = 1;
    while choice(choice !=0){
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
    }

}