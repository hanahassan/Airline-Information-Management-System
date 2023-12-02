// airline.cpp
#include "airline.h"

void Airline::set_name(std::string airline_name) {
    name = airline_name;
}

std::string Airline::get_name() const {
    return name;
}

int Airline::number_flights() const {
    return flights.size();
}

void Airline::set_flights(const std::vector<Flight>& flight) {
    this->flights = flight;
}

std::vector<Flight> Airline::get_flights() const {
    return flights;
}

void Airline::addFlight(const Flight& new_flight) {
    flights.push_back(new_flight);
}