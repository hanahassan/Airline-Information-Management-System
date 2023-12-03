//seat.h

#include <iostream>
#include "passenger.h"
using namespace std;

#ifndef MY_SEAT_CLASS
#define MY_SEAT_CLASS

class Seat
{
    private:
        int rowM;
        char columnM;
        char statusM;
        bool occupiedM;
    public:
        Seat(): rowM(1), columnM('A'), statusM(0), occupiedM(false) {};
        Seat(int row, char column, char status);
        int get_row() const;
        char get_column() const;
        char get_status() const;
        bool get_occupied() const;
        void set_row(int row);
        void set_column(char column);
        void set_status(char status);
        void set_occupied(bool occupied);
        

        //Function to assign a passenger to the seat
        //void assignPassenger(const Passenger& passenger);
};

#endif