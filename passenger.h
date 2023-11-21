#include <iostream>
#include <string>
using namespace std;

#infdef MY_PASSENGER_CLASS
#define MY_PASSENGER_CLASS

class Passenger
{
    private:
        string first_name;
        string last_name;
        int phone_number;
        int iD_passenger;
        char * seat_passenger; 
    public:
        int Passenger(): first_name("NA"), last_name("NA"), phone_number(0), id(0), seat(nullptr);
        int Passenger(string first, string last, int phonenumber, int iD, char * seat);
        char get_firstname() const;
        char get_lastname() const;
        int get_phonenumber() const;
        int get_iD() const;
        char * get_seatpassenger() const;

        void set_firstname() const;
        void set_lastname() const;
        void set_phonenumber() const;
        void set_iD() const;
        void * set_seatpassenger() const;    
}

#endif