 /*
  Name: Lucas Boyer
  Course: CPSC 1020 Spring Semester
  Project #: 2
  Instructor: Cathy Kittelstad
  Program Description: Using a vector to keep inventory of watercrafts
*/

#ifndef WATERCRAFT_H
#define WATERCRAFT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "accessories.h"
using namespace std;


class watercraft {
	private:
		string type;      // [15] e.g. pontoon, sport boat, sailboat, fishing, 
	                    	//      canoe, kayak, jetski, etc.
		string make;      // [20]
		string model;     // [30]
		int propulsion;   // 0 = none; 1 = outBoard; 2 = inBoard; 
		string engine;    // [15] Suzuki, Yamaha, etc.
		int hp;			   // horse power	
		string color;     // [25]
		int length;       // feet
		double base_price;
		double total_price;
		accessories extras;
	
	public:
		//watercraft(); //used intiailization list and default values so dont need default constructor
		watercraft(string wType = " ", string wMake = " ", string wModel = " ", 
						int wPropulsion = 0, string wEngine = " ", int wHP = 0, 
						string wColor = " ", int wLength = 0, double wBPrice = 0, 
						double wTPrice = 0, double wBimini = 0, double wTowbar = 0,
						double wStereo = 0, double wTable = 0, double wGPS = 0,
						double wAnchor = 0, double wPaddles = 0);

		watercraft( ifstream &inFile );
		void printWatercraft ( int index );
		string getType( ) { return type; }
		double getTPrice( ) { return total_price; }
		int getPropulsion( ) { return propulsion; }
		accessories getExtras( ) { return extras; }
		double getBPrice( ) { return base_price; }
};



#endif /* WATERCRAFT_H */
