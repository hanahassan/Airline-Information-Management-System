#include "airline.h"

int num_flights(const vector<Flight> &flights){
    return flights.size();
}

vector<Flight> Airline::get_flights() const
{
    return flights;
}

void Airline::set_flights(const vector<Flight>& flights)
{
    this->flights = flights;
}