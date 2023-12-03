//seap.cpp

#include "seat.h"

// Constructor implementation
Seat::Seat(int row, char column, bool occupied) : rowM(row), columnM(column), occupiedM(occupied) {}

// Getter implementation
int Seat::get_row() const{
    return rowM;
}

char Seat::get_column() const{
    return columnM;
}

bool Seat::get_occupied() const {
    return occupiedM;
}

// Setter implementation
void Seat::set_row(int row){
    rowM = row;
}

void Seat::set_column(char column){
    columnM = column;
}

void Seat::set_occupied(bool occupied){
    occupiedM = occupied;
}
