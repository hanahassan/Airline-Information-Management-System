#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
using namespace std;

#ifndef airline_class
#define airline_class

class Airline
{
    private:
        string name;
        vector <Flight> flights;
        int num_flights;
    public:
        void set_name(string airline_name) const;
        string get_name();
        int num_flights(const vector <Flight>& flights);
        void set_flights(const vector<Flight>& flights);
        vector<Flight> get_flights() const;
        void addFlight(const Flight& new_flight);
        
}

#endif