 /*
  Name: Lucas Boyer
  Course: CPSC 1020 Spring Semester
  Project #: 2
  Instructor: Cathy Kittelstad
  Program Description: Using a vector to keep inventory of watercrafts
*/

#include "watercraft.h"
using namespace std;

//this is the default constructor and ask the user for each piece of info
//then sets it equal to the class vars and sends the accessorys to extra
//using the accessory functions
watercraft::watercraft(string wType, string wMake, string wModel, 
						int wPropulsion, string wEngine, int wHP, 
						string wColor, int wLength, double wBPrice, 
						double wTPrice, double wBimini, double wTowbar,
						double wStereo, double wTable, double wGPS,
						double wAnchor, double wPaddles) : type(wType), 
						make(wMake), model(wModel), propulsion(wPropulsion), 
						engine(wEngine), hp(wHP), color(wColor),
						length(wLength), base_price(wBPrice),
						total_price(wTPrice), extras(wBimini, wTowbar,
						wStereo, wTable, wGPS, wAnchor, wPaddles)  { 

    string sPropulsion, sHP, sLength; //for stoi conversion
    string sBPrice, sTPrice; //for stod conversion
    string bim, tow, ster, tab, gp, anc, pad; //for stod conversion
    
    cin.ignore();
    cout << endl << "Enter watercraft type:" << endl << "\t";
    getline(cin, type);

    cout << endl << "Enter watercraft make:" << endl << "\t";
    getline(cin, make);

    cout << endl << "Enter watercraft model:" << endl << "\t";
    getline(cin, model);

    cout << endl << "Enter 0 for no motor, 1 for out-board, 2 for in-board:" << endl << "\t";
    getline(cin, sPropulsion); //getline gives you a string
    propulsion = stoi(sPropulsion); //so stoi converts the string to int

    cout << endl << "Enter engine make:" << endl << "\t";
    getline(cin, engine);

    cout << endl << "How much horsepower does the engine have?" << endl << "\t";
    getline(cin, sHP);
    hp = stoi(sHP);

    cout << endl << "Enter color of watercraft:" << endl << "\t";
    getline(cin, color);

    cout << endl << "Length of watercraft:" << endl << "\t";
    getline(cin, sLength);
    length = stoi(sLength);

    cout << endl << "Base price of watercraft:" << endl << "\t";
    getline(cin, sBPrice);
    base_price = stod(sBPrice);

    //extras
    cout << endl << "Cost of bimini (if there is an extra cost):" << endl << "\t";
    getline(cin, bim);
    wBimini = stod(bim);

    cout << endl << "Cost of towbar (if there is an extra cost):" << endl << "\t";
    getline(cin, tow);
    wTowbar = stod(tow);

    cout << endl << "Cost of stereo (if there is an extra cost):" << endl << "\t";
    getline(cin, ster);
    wStereo = stod(ster);

    cout << endl << "Cost of table (if there is an extra cost):" << endl << "\t";
    getline(cin, tab);
    wTable = stod(tab);

    cout << endl << "Cost of gps (if there is an extra cost):" << endl << "\t";
    getline(cin, gp);
    wGPS = stod(gp);

    cout << endl << "Cost of anchor (if there is an extra cost):" << endl << "\t";
    getline(cin, anc);
    wAnchor = stod(anc);
    
    cout << endl << "Cost of paddles (if there is an extra cost):" << endl << "\t";
    getline(cin, pad);
    wPaddles = stod(pad);

    //this calculates the total price
    total_price = base_price + wBimini
     + wTowbar + wStereo + wTable 
      + wGPS + wAnchor + wPaddles;

    //this uses the accessory function to set the extras info
    extras.set_bimini(wBimini);
    extras.set_towbar(wTowbar);
    extras.set_stereo(wStereo);
    extras.set_table(wTable);
    extras.set_gps(wGPS);
    extras.set_anchor(wAnchor);
    extras.set_paddles(wPaddles);
    
    cout << endl << endl << endl;
}

//this constructor is for reading the file
//gets a file parameter and sets all info from file
watercraft::watercraft(ifstream &inFile) {
    string wPropulsion, wHP, wLength; //for stoi conversion
    string wBPrice, wTPrice; //for stod conversion
    string bim, tow, ster, tab, gp, anc, pad; //for stod conversion
    double wBimini, wTowbar, wStereo, wTable, wGPS, wAnchor, wPaddles; //for sending to to extras
    string wholeLine;

    getline(inFile, wholeLine); //gets whole line from file
    stringstream line(wholeLine); //puts the string into a format i can getline on

    getline(line, type, ','); //will read until comma and put into variable
    getline(line, make, ',');
    getline(line, model, ',');
    getline(line, wPropulsion, ',');
    propulsion = stoi(wPropulsion); //b/c propulsion is an int i have to convert the string to int
    getline(line, engine, ',');
    getline(line, wHP, ',');
    hp = stoi(wHP);
    getline(line, color, ',');
    getline(line, wLength, ',');
    length = stoi(wLength);
    getline(line, wBPrice, ',');
    base_price = stod(wBPrice);
    getline(line, wTPrice, ',');
    total_price = stod(wTPrice);

    //extras
    getline(line, bim, ',');
    wBimini = stod(bim);
    getline(line, tow, ',');
    wTowbar = stod(tow);
    getline(line, ster, ',');
    wStereo = stod(ster);
    getline(line, tab, ',');
    wTable = stod(tab);
    getline(line, gp, ',');
    wGPS = stod(gp);
    getline(line, anc, ',');
    wAnchor = stod(anc);
    getline(line, pad, ',');
    wPaddles = stod(pad);

    extras.set_bimini(wBimini);
    extras.set_towbar(wTowbar);
    extras.set_stereo(wStereo);
    extras.set_table(wTable);
    extras.set_gps(wGPS);
    extras.set_gps(wAnchor);
    extras.set_paddles(wPaddles);

}

//this gets an int parameter to know what place the
//watercraft is in the list
//then prints out all the watercraft data
void watercraft::printWatercraft (int index) {

    cout << endl;
    cout << setw(2) << right << index + 1 << ". "
    << setw(13) << left << type << setw(20) << left << make
    << setw(23) << left << model << setw(11) << left << engine
    << setw(4) << right << hp << "hp    " << setw(19) << left << color
    << setw(4) << right << length << "ft  " << "$" << setw(11) << fixed
    << setprecision(2) << right << total_price;
}