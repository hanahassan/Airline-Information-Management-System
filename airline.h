#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
using namespace std;

#ifndef airline_class
#define airline_class

class Airline {
private:
    string name;
    vector<Flight> flights;

public:
    void set_name(string airline_name);
    string get_name() const;
    int number_flights() const;
    void set_flights(const vector<Flight>& flight);
    vector<Flight> get_flights() const;
    void addFlight(const Flight& new_flight);
};

#endif