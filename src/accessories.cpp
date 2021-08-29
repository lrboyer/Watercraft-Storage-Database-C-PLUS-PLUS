 /*
  Name: Lucas Boyer
  Course: CPSC 1020 Spring Semester
  Project #: 2
  Instructor: Cathy Kittelstad
  Program Description: Using a vector to keep inventory of watercrafts
*/

#include "accessories.h"
using namespace std;

//accessories::accessories() {}

//uses initialization list and has default values in .h file so only needs one constructor
accessories::accessories(double wBimini, double wTowbar, double wStereo,
            double wTable, double wGPS, double wAnchor,
                double wPaddles) : bimini(wBimini), towbar(wTowbar),
                stereo(wStereo), table(wTable), gps(wGPS),
                anchor(wAnchor), paddles(wPaddles) { ; }