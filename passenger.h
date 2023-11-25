#include <iostream>
#include <string>
#include "seat.h"
using namespace std;

#ifndef MY_PASSENGER_CLASS
#define MY_PASSENGER_CLASS

class Passenger
{
private:
    string first_nameM;
    string last_nameM;
    string phone_numberM;
    int iDM;
    Seat *seat_passengerM;

public:
    Passenger() : first_nameM("NA"), last_nameM("NA"), phone_numberM("0"), iDM(0), seat_passengerM(nullptr) {}

    Passenger(string first, string last, string phonenumber, int iD, Seat *seat);

    string get_firstnameM() const;
    string get_lastnameM() const;
    string get_phonenumberM() const;
    int get_iDM() const;
    Seat *get_seatpassengerM() const;

    void set_firstnameM(string first);
    void set_lastnameM(string last);
    void set_phonenumberM(string phone);
    void set_iDM(int id);
    void set_seatpassengerM(Seat *seat);
};

#endif
