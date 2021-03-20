// File: prototypes.h
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog3
// Modified: 9/29/20

#pragma once
#include <string>

// prototypes
void PopulateArraysFromFile(std::string unitArray[], std::string unitTypeArray[], std::string fileName);
bool UnitCompatible(std::string unitArray[], std::string unityTypeArray[], std::string unitOne, std::string unitTwo);
void PrintUnits(std::string units[]);