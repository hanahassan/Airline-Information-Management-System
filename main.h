#include <limits>
#include <fstream>
#include "flight.h"
using namespace std;

#ifndef MAIN_H
#define MAIN_H
void displayHeader();

int menu();

void pressEnter();

void cleanStandardInputStream();

void quit();


Flight populate_flight(const string& fileName);


#endif