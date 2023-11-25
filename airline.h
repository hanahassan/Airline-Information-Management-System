#include <iostream>
#include <string>
#include <vector>
#include "flight.h"
using namespace std;

#if(1)
#define 

class Airline
{
    private:
        string name;
        vector <Flight> flights;
        int num_flights;
    public:
        void set_name(string name) const;
        string get_name();
        int num_flights(vector <Flight> flights);
        
}

#endif