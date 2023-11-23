#include <iostream>
using namespace std;

#ifndef MY_SEAT_CLASS
#define MY_SEAT_CLASS

class Seat
{
    private:
        int rowM;
        char columnM;
        char status;
    public:
        char Seat(): rowM(1), columnM('A'), status('NA');
        char Seat(int row, char column, char status);
        int get_row() const;
        char get_column() const;
        char get_status() const;
        void set_row(int row);
        void set_column(char column);
        void set_status(char column, int row)
}

#endif