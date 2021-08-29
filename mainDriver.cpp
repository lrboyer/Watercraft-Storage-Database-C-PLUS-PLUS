/*
  Name: Lucas Boyer
  Course: CPSC 1020 Spring Semester
  Project #: 2
  Instructor: Cathy Kittelstad
  Program Description: Using a vector to keep inventory of watercrafts
*/

#include "src/watercraft.h"
#include "src/functions.h"
using namespace std;

int main(int argc, char* argv[]) {
    ifstream inFile(argv[1]); //opens input file from cmd line
    
    int choice;
    bool read = false;
    cout << endl;
    vector<watercraft *> list; //makes vector of watercraft pointers

    //this will keep printing the menu and asking for a choice until the user inputs 12
    while (choice != 12) { 
        choice = printMenu(); //prints menu and gets choice back
        //this manages each case for each one of the 12 choices on the menu
        switch(choice) {
            case 1:
                if (read == false) {
                    while (!inFile.eof()) { //reads from file until the end
                        watercraft newVehicle(inFile); //creates object and gets info from file
                        watercraft *ptr = new watercraft(newVehicle); //makes pointer from object
                        list.push_back(ptr); //adds it to the vector
                    }
                    cout << "Loaded watercraft from file." << endl << endl << endl;
                    inFile.close();
                    read = true;
                }
                else {
                    cout << "** List is already initialized. **" << endl << endl << endl;
                }
                break;
            case 2: { //adds to front
                watercraft newVehicle; //makes vechicle and gets all info from user
                watercraft *ptr = new watercraft(newVehicle); //makes pointer
                list.insert(list.begin(), ptr); //adds to front of vector
            }
                break;
            case 3: { //adds to end
                watercraft newVehicle;
                watercraft *ptr = new watercraft(newVehicle);
                list.push_back(ptr); //adds to end of vector
            }
                break;
            case 4:
                cout << "There are " << list.size() << " watercraft in inventory." << endl << endl << endl;
                break;
            case 5: {
                if (list.size() == 0) {
                    cout << "The list is empty" << endl << endl << endl;
                }
                else {
                    cout << "Watercraft in list:" << endl << endl;
                    int i = 0;
                    //iterates thru vector and prints each watercraft one by one
                    for (vector<watercraft *>::iterator b = list.begin(); b != list.end(); b++) {
                        (*b)->printWatercraft(i);
                        i++;
                    }
                    cout << endl << endl << endl;
                }
            }
                break;
            case 6:
                printSpecs(list);
                break;
            case 7: 
                deleteWatercraft(list);
                break;
            case 8:
                searchByType(list);
                break;
            case 9:
                searchByMotorType(list);
                break;
            case 10:
                printByPrice(list);
                break;
            case 11: 
                TAV(list);
                break;
            case 12: //quits and deallocates memory
                for (long unsigned int i = 0; i < list.size(); i++) {
                    delete list[i];
                }
                break;
            default:
                cout << "please select an option 1-12" << endl << endl << endl;
                break;
        }  
    }
    
    return 0;
}