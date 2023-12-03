//flight.h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "passenger.h"
#include "seat.h"
using namespace std;


#ifndef MY_CLASS_FLIGHT
#define MY_CLASS_FLIGHT

class Flight
{
private:
    string idM;
    int num_rowsM;
    int num_columnsM;
    vector<Passenger> passengers;
    vector<vector<Seat>> seatmap;

public:
    Flight();
    Flight(string id, int rows, int columns);
    Flight(const Flight& source);

    ~Flight();

    string get_idM() const;
    int get_rowsM() const;
    int get_columnsM() const;
    vector<Passenger> get_passengers() const;
    vector<vector<Seat>> get_seatmap() const;

    void set_idM(string id);
    void set_numrowsM(int rows);
    void set_numcolumnsM(int columns);
    void set_passengers(const vector<Passenger>& passengers);
    //void set_seatmap(const vector<vector<Seat>>& seatmap);

    // Function to add a passenger to the flight
    void add_passenger(const Passenger& passenger);

    // Function to display the seat map
    //void displaySeatMap() const;

    //Function to populate_flight
    //void populate_flight(const string& filename);

    //Function to display passenger information
    void display_passengers() const;

    void remove_passenger(int passengerID);

    

};

#endif
