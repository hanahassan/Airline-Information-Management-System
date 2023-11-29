#include "Passenger.h"

// Seat::Seat(int row, char column, char status) : rowM(row), columnM(column), statusM(status) {}

Passenger::Passenger(string first, string last, string phonenumber, int iD, int seatNumber): first_nameM(first), last_nameM(last), phone_numberM(phonenumber), iDM(iD) {
    seat_passengerM = new Seat(seatNumber);
}

string Passenger::get_firstnameM() const
{
    return first_nameM;
}

string Passenger::get_lastnameM() const
{
    return last_nameM;
}

string Passenger::get_phonenumberM() const
{
    return phone_numberM;
}

int Passenger::get_iDM() const
{
    return iDM;
}

Seat* Passenger::get_seatpassengerM() const
{
    return seat_passengerM;
}

void Passenger::set_firstnameM(string first)
{
    first_nameM = first;
}

void Passenger::set_lastnameM(string last)
{
    last_nameM = last;
}

void Passenger::set_phonenumberM(string phone)
{
    phone_numberM = phone;
}

void Passenger::set_iDM(int id)
{
    iDM = id;
}

void Passenger::set_seatpassengerM(Seat* seat)
{
    seat_passengerM = seat;
}
