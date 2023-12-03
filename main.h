//main.h

#include <limits>
#include <fstream>
#include "flight.h"
using namespace std;

#ifndef MAIN_H
#define MAIN_H

// Displays the header at the beginning
void displayHeader();

// Brings up the menu
int menu();

void pressEnter();

void cleanStandardInputStream();

void quit();

// Reads the text file
void populate_flight(Flight& f);

// Save the new information to the text file
void save_info(const Flight& f);

#endif
