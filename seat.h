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
        //Constructors
        Seat(): rowM(1), columnM('A'), occupiedM(false) {};
        Seat(int row, char column, bool occupied);

        //seat getter functions
        int get_row() const;
        char get_column() const;
        bool get_occupied() const;

        //seat setter functions
        void set_row(int row);
        void set_column(char column);
        void set_occupied(bool occupied);
        
};

#endif