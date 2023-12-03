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

void save_info(const Flight& f);

#endif

/*
2. use set occupied in main when assigning passengers
3. when adding passenger - use set occupied
4. when removing passenger - use set occupied
*/