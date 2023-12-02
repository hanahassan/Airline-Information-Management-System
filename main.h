//main.h

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

void populate_flight(Flight& f);

#endif