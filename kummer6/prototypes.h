// File: prototypes.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog6
// Modified: 10/24/20

#pragma once
#include <string>
#include "Measurment.h"

// prototypes
void PopulateArraysFromFile(Measurment unitArray[], std::string fileName);
bool UnitCompatible(Measurment unitArray[], std::string unitOne, std::string unitTwo);
void PrintUnits(Measurment units[]);