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
        int num_flight(const vector <Flight>& flight_num);
        void set_flights(const vector<Flight>& flights);
        int number_flights(const vector <Flight>& flight_num);
        void set_flights(const vector <Flight>& flight);
        vector<Flight> get_flights() const;
        void addFlight(Flight& new_flight);
        
};

#endif