#include "Flight.h"
#include "main.h"

Flight::Flight() : idM(0), num_rowsM(0), num_columnsM(0)
{
    seatmap.resize(num_rowsM, vector<Seat>(num_columnsM));
}

Flight::Flight(string id, int rows, int columns) : idM(id), num_rowsM(rows), num_columnsM(columns)
{
    seatmap.resize(num_rowsM, vector<Seat>(num_columnsM));
}

string Flight::get_idM() const
{
    return idM;
}

int Flight::get_rowsM() const
{
    return num_rowsM;
}

int Flight::get_columnsM() const
{
    return num_columnsM;
}

vector<Passenger> Flight::get_passengers() const
{
    return passengers;
}

vector<vector<Seat>> Flight::get_seatmap() const
{
    return seatmap;
}

void Flight::set_idM(string id)
{
    idM = id;
}

void Flight::set_numrowsM(int rows)
{
    num_rowsM = rows;
}

void Flight::set_numcolumnsM(int columns)
{
    num_columnsM = columns;
}

void Flight::set_passengers(const vector<Passenger>& passengers)
{
    this->passengers = passengers;
}

void Flight::set_seatmap(const vector<vector<Seat>>& seatmap)
{
    this->seatmap = seatmap;
}

void Flight::addPassenger(const Passenger& passenger)
{
    passengers.push_back(passenger);

    for (int i = 0; i < num_rowsM; ++i)
    {
        for (int j = 0; j < num_columnsM; ++j)
        {
            if (!seatmap[i][j].isOccupied())
            {
                seatmap[i][j].assignPassenger(passenger);
                return;
            }
        }
    }

    cout << "No available seats." << endl;
}

void Flight::displaySeatMap() const
{
    for (int i = 0; i < num_rowsM; ++i)
    {
        for (int j = 0; j < num_columnsM; ++j)
        {
            cout << seatmap[i][j].getSeatInfo() << " ";
        }
        cout << endl;
    }
}
