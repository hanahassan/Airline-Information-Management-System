#include "Seat.h"

Seat::Seat(int row, char column, char status) : rowM(row), columnM(column), statusM(status) {}

int Seat::get_row() const
{
    return rowM;
}

char Seat::get_column() const
{
    return columnM;
}

char Seat::get_status() const
{
    return statusM;
}

void Seat::set_row(int row)
{
    rowM = row;
}

void Seat::set_column(char column)
{
    columnM = column;
}

void Seat::set_status(char status)
{
    statusM = status;
}

bool Seat::isOccupied() const 
{
    return occupied;
}

void Seat::assignPassenger(const Passenger& passenger){
    this-> passenger = passenger;
    occupied = true;
}
