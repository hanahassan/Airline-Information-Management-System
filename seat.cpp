//seap.cpp

#include "seat.h"

Seat::Seat(int row, char column, bool occupied) : rowM(row), columnM(column), occupiedM(occupied) {}

int Seat::get_row() const{
    return rowM;
}

char Seat::get_column() const{
    return columnM;
}

bool Seat::get_occupied() const {
    return occupiedM;
}

void Seat::set_row(int row){
    rowM = row;
}

void Seat::set_column(char column){
    columnM = column;
}

void Seat::set_occupied(bool occupied){
    occupiedM = occupied;
}

void Seat::assignPassenger(const Passenger& passenger){

    
}

// void Seat::assignPassenger(const Passenger& passenger,const Flight& flight) {
//     columnM = passenger.getSeat();
//     rowM = passenger.getSeatNumber();
//     Seat * x = flight.get_seatmap();
//     x[columnM][rowM] -> occupiedM = true;
// }