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
        bool occupiedM;
    public:
        Seat(): rowM(1), columnM('A'), occupiedM(false) {};
        Seat(int row, char column, bool occupied);
        int get_row() const;
        char get_column() const;
        bool get_occupied() const;
        void set_row(int row);
        void set_column(char column);
        void set_occupied(bool occupied);
        
        //void assignPassenger(const Passenger& passenger);
};

#endif