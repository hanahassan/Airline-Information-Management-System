#include "airline.h"

void Airline::set_name(string airline_name){
    name = airline_name;
}

string Airline::get_name(){
    return name;
}

int number_flights(const vector<Flight> &flight_num){
    return flights.size();
}

vector<Flight> Airline::get_flights() const
{
    return flights;
}

void Airline::set_flights(const vector<Flight>& flight)
{
    this->flights = flights;
}

void Airline::addFlight(const Flight& new_flight)
{
    flights.push_back(new_flight);

}