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

//void populate_flight(const string& filename);

Flight populate_flight(const string& fileName);

#endif