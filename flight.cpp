#include "flight.h"

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

// void Flight::populate_flight(const string& filename) {
//      ifstream file(filename);

//      if (!file.is_open()) {
//          cerr << "Error: Could not open file " << filename << endl;
//          return;
//      }

//      // Read flight information from the first line
//      string flightInfoLine;
//      getline(file, flightInfoLine);
//      istringstream flightInfoStream(flightInfoLine);
//      string flightNumber;
//      int rows, columns;
//     flightInfoStream >> flightNumber >> rows >> columns;

//     set_idM(flightNumber);
//     set_numrowsM(rows);
//     set_numcolumnsM(columns);

//     // Read passenger information from the remaining lines
//     string line;
//     while (getline(file, line)) {
//         istringstream passengerInfoStream(line);

//         string firstName, lastName, phoneNumber, seat;
//         int id, seatNumber;

//         passengerInfoStream >> id >> firstName >> lastName >> phoneNumber >> seat >> seatNumber;

//         // Create a Passenger object and add it to the flight
//         Passenger passenger(id, firstName, lastName, phoneNumber, seat, seatNumber);
//         add_passenger(passenger);
//     }

//     file.close();
//     //return f;
// }
// Function to add a passenger to the flight
void Flight::add_passenger(const Passenger& passenger) {
    passengers.push_back(passenger);
}

// Function to display passenger information
void Flight::display_passengers() const {

    for (const Passenger& passenger : passengers) {
        cout << "ID: " << passenger.getID() << "\n";
        cout << "First Name: " << passenger.getFirstName() << "\n";
        cout << "Last Name: " << passenger.getLastName() << "\n";
        cout << "Phone Number: " << passenger.getPhoneNumber() << "\n";
        cout << "Seat: " << passenger.getSeat() << "\n";
        cout << "Row: " << passenger.getSeatNumber() << "\n";
        cout << "---------------------------\n";
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