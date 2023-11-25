#include <iostream>
#include <string>
#include <vector>
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

    string get_idM() const;
    int get_rowsM() const;
    int get_columnsM() const;
    vector<Passenger> get_passengers() const;
    vector<vector<Seat>> get_seatmap() const;

    void set_idM(string id);
    void set_numrowsM(int rows);
    void set_numcolumnsM(int columns);
    void set_passengers(const vector<Passenger>& passengers);
    void set_seatmap(const vector<vector<Seat>>& seatmap);

    // Function to add a passenger to the flight
    void addPassenger(const Passenger& passenger);

    // Function to display the seat map
    void displaySeatMap() const;
};

#endif
