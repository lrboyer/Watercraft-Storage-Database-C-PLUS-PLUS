 /*
  Name: Lucas Boyer
  Course: CPSC 1020 Spring Semester
  Project #: 2
  Instructor: Cathy Kittelstad
  Program Description: Using a vector to keep inventory of watercrafts
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "accessories.h"
#include "watercraft.h"
using namespace std;

int printMenu( );
void TAV( vector<watercraft *> inventory ); 
void printSpecs( vector<watercraft *> inventory ); 
void deleteWatercraft( vector<watercraft *> &inventory ); 
void searchByType( vector<watercraft *> inventory );
void searchByMotorType( vector<watercraft *> inventory );
void printByPrice( vector<watercraft *> inventory ); 
bool order(watercraft*, watercraft*);  
//i made this func to sort watercraft by price lowest to highest

#endif /* FUNCTIONS_H */

