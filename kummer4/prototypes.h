// File: prototypes.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog4
// Modified: 10/12/20

#pragma once
#include <string>
#include "structs.h"

// prototypes
void PopulateArraysFromFile(unitMeasurement unitArray[], std::string fileName);
bool UnitCompatible(unitMeasurement unitArray[], std::string unitOne, std::string unitTwo);
void PrintUnits(unitMeasurement units[]);