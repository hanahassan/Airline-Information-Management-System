#include <iostream>
using namespace std;

#infdef MY_SEAT_CLASS
#define MY_SEAT_CLASS

class Seat
{
    private:
        int rowM;
        char columnM;
    public:
        char Seat(): rowM(1), columnM('A');
        char Seat(int row, char column);
        int get_row() const;
        char get_column() const;
        void set_row(int row);
        void set_column(char column);
}

#endif