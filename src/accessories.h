 /*
  Name: Lucas Boyer
  Course: CPSC 1020 Spring Semester
  Project #: 2
  Instructor: Cathy Kittelstad
  Program Description: Using a vector to keep inventory of watercrafts
*/

#ifndef ACCESSORIES_H
#define ACCESSORIES_H

#include <fstream>
#include <vector>
#include <string>
using namespace std;


class accessories {
	private:
		double bimini;  	   // 1 yes, 0 no
		double towbar;			// cost of the add-on
		double stereo;
		double table;
		double gps;
		double anchor;
		double paddles;
	public:
		//accessories();
		accessories(double wBimini = 0, double wTowbar = 0, double wStereo = 0,
		            double wTable = 0, double wGPS = 0, double wAnchor = 0,
						double wPaddles = 0);

		void set_bimini( double price ) { bimini = price; }
		void set_towbar( double price ) { towbar = price; }
		void set_stereo( double price ) { stereo = price; }
		void set_table( double price ) { table = price; }
		void set_gps( double price ) { gps = price; }
		void set_anchor( double price ) { anchor = price; }
		void set_paddles( double price ) { paddles = price; }
		 
		double get_bimini() { return bimini; }
		double get_towbar() { return towbar; }
		double get_stereo() { return stereo; }
		double get_table() { return table; }
		double get_gps() { return gps; }
		double get_anchor() { return anchor; }
		double get_paddles() { return paddles; }
		
};


#endif /* ACCESSORIES_H */
