//seap.cpp

#include "seat.h"

Seat::Seat(int row, char column, char status) : rowM(row), columnM(column), statusM(status) {}

int Seat::get_row() const{
    return rowM;
}

char Seat::get_column() const{
    return columnM;
}

char Seat::get_status() const{
    return statusM;
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

void Seat::set_status(char status){
    statusM = status;
}

void Seat::set_occupied(bool occupied){
    occupiedM = occupied;
}

// void Seat::assignPassenger(const Passenger& passenger){
//    //assignedPassenger = passenger;
//     occupied = true;
// }
