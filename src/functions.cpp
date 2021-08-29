 /*
  Name: Lucas Boyer
  Course: CPSC 1020 Spring Semester
  Project #: 2
  Instructor: Cathy Kittelstad
  Program Description: Using a vector to keep inventory of watercrafts
*/

#include "functions.h"
using namespace std;

//this prints out a menu for the user to choose a choice then returns that choice
int printMenu( ) {
    int num;
    
    cout << " 1. load inventory of watercraft from file" << endl
    << " 2. add additional watercraft to front of list" << endl
    << " 3. add additional watercraft to end of list" << endl
    << " 4. number of watercraft in inventory" << endl
    << " 5. print inventory of watercraft" << endl
    << " 6. print specs of chosen watercraft" << endl
    << " 7. delete chosen watercraft" << endl
    << " 8. search watercraft by type" << endl
    << " 9. search watercraft by motor type" << endl
    << "10. sort watercraft by price" << endl
    << "11. total asset value in inventory" << endl
    << "12. quit program" << endl;

    cout << endl << "- - > ";
    cin >> num;
    cout << endl << endl;
    return num;
}

//this gets the inventory, totals the total prices of every watercraft
// in the inventory, and prints it out
void TAV( vector<watercraft *> inventory ) {
    double sum = 0;

    //iterates thru vector to get each total price then adds those to the total
    for (vector<watercraft *>::iterator b = inventory.begin(); b != inventory.end(); b++) {
        sum += (*b)->getTPrice();
    }
    cout << "Total asset value of all inventory is: $" << fixed << setprecision(2) << sum << endl << endl << endl;
}

//this gets the inventory, gets the user to choose a watercraft then prints out its specs
void printSpecs( vector<watercraft *> inventory ) {
    long unsigned int num;
    long unsigned int i = 0;
    //makes iterator that starts at the beginning
    vector<watercraft *>::iterator iter = inventory.begin();
    
    if (inventory.size() == 0) {
        cout << "The list is empty" << endl << endl << endl;
    }
    else {
        cout << "Watercraft in list:" << endl << endl;
        //this prints out the watercraft
        for (iter = inventory.begin(); iter != inventory.end(); iter++) {
            (*iter)->printWatercraft(i);
            i++;
        }
        cout << endl << endl << endl;

        cout << "Enter the # of the watercraft for the specs:";
        cout << endl << "- - > ";
        cin >> num;
        
        //checks to see if num entered is a valid watercraft # in the list
        if (num > 0 && num <= inventory.size()) {
            //starts at head of list and goes until on the selected watercraft
            iter = inventory.begin();
            for (i = 0; i < num - 1; i++) {
                iter++;
            }
            
            //this prints out the selected watercraft
            (*iter)->printWatercraft(num-1);

            //prints out: 0 for no motor, 1 for out-board motor, and 2 for in-board 
            if ((*iter)->getPropulsion() == 0) {
                cout << endl << "\tno motor";
            }
            if ((*iter)->getPropulsion() == 1) {
                cout << endl << "\tout-board motor";
            }
            if ((*iter)->getPropulsion() == 2) {
                cout << endl << "\tin-board motor";
            }

            cout << endl << "\tbase price: $" << setw(11) << fixed << setprecision(2)
            << right << (*iter)->getBPrice() << endl;

            //this makes an accessory object so it can access the functions in the 
            //accessory class
            accessories temp = (*iter)->getExtras();

            //these will check to see if the price of the accessory isn't
            // 0 so it doesn't print out 0 for the price of an accessory
            if (temp.get_bimini() != 0) {
                cout << "\tbimini:     $" << setw(11) << fixed << setprecision(2) 
                << right << temp.get_bimini() << endl;
            }
            if (temp.get_towbar() != 0) {
                cout << "\ttowbar:     $" << setw(11) << fixed << setprecision(2) 
                << right << temp.get_towbar() << endl;
            }
            if (temp.get_stereo() != 0) {
                cout << "\tstereo:     $" << setw(11) << fixed << setprecision(2) 
                << right << temp.get_stereo() << endl;
            }
            if (temp.get_table() != 0) {
                cout << "\ttable:      $" << setw(11) << fixed << setprecision(2) 
                << right << temp.get_table() << endl;
            }
            if (temp.get_gps() != 0) {
                cout << "\tgps:        $" << setw(11) << fixed << setprecision(2) 
                << right << temp.get_gps() << endl;
            }
            if (temp.get_anchor() != 0) {
                cout << "\tanchor:     $" << setw(11) << fixed << setprecision(2) 
                << right << temp.get_anchor() << endl;
            }
            if (temp.get_paddles() != 0) {
                cout << "\tpaddles:    $" << setw(11) << fixed << setprecision(2) 
                << right << temp.get_paddles() << endl;
            }

            cout << endl << endl << endl;
        }
        else {
            cout << "That watercraft doesn't exist" << endl << endl;
        }
    }
}

//this gets the inventory and any changes made here will affect the list in main
//it gets the user to choose a watercraft then deletes it from the vector
void deleteWatercraft( vector<watercraft *> &inventory ) {
    unsigned long int num;
    int i = 0;
    
    if (inventory.size() == 0) {
        cout << "The list is empty" << endl << endl << endl;
    }
    else {
        cout << "Watercraft in list:" << endl << endl;
        for (vector<watercraft *>::iterator b = inventory.begin(); b != inventory.end(); b++) {
            (*b)->printWatercraft(i);
            i++;
        }
        cout << endl << endl << endl;

        cout << "Enter the # of the watercraft to delete from inventory:" << endl;
        cout << endl << "- - > ";
        cin >> num;
        cout << endl << endl;

        //checks to see if valid watercraft #
        if (num > 0 && num <= inventory.size()) {
            //deletes the selected watercraft
            inventory.erase(inventory.begin() + num - 1);
           
            //decrements the size of list
            inventory.shrink_to_fit();
        } 
        else {
            cout << "That watercraft doesn't exist" << endl << endl;
        }
    }
}

//this gets the whole inventory
//this ask the user to print out a type of watercraft
//then prints it out
void searchByType( vector<watercraft *> inventory ) {
    int type, i = 0;
    string boat;
    bool found = false;
    bool valid = true;

    if (inventory.size() == 0) {
        cout << "The list is empty" << endl << endl << endl;
    }
    else {
        cout << "Type of watercraft to search for:" << endl;
        cout << " 1. pontoon" << endl;
        cout << " 2. fishing" << endl;
        cout << " 3. sport boat" << endl;
        cout << " 4. kayak" << endl;
        cout << " 5. canoe" << endl;
        cout << " 6. sailboat" << endl << endl;

        cout << "- - > ";
        cin >> type;
        cout << endl << endl << endl;
        
        //this has a case for whichever type is chosen
        //turns the number input into a string
        switch (type) {
            case 1: boat = "pontoon"; break;
            case 2: boat = "fishing"; break;
            case 3: boat = "sport boat"; break;
            case 4: boat = "kayak"; break;
            case 5: boat = "canoe"; break;
            case 6: boat = "sailboat"; break;
            default: 
                cout << endl << endl << "That is not a valid type"; 
                valid = false;
            break;
        }
        
        if (valid == true) {
            //this goes thru the vector to find boats 
            //that match the selected type
            //if match it prints it out
            for (vector<watercraft *>::iterator iter = inventory.begin(); iter != inventory.end(); iter++) {
                if ((*iter)->getType() == boat) {
                    found = true;
                    (*iter)->printWatercraft(i);
                }
                i++;
            }
            if (found == false) {
                cout << "Type not fond" << endl << endl;
            }
            else {
                cout << endl << endl << endl;
            }
        }

    }
    
}

//this is the same as searchbytype except prints by motor type
void searchByMotorType( vector<watercraft *> inventory ) {
    int type, i = 0;
    bool found = false;
    bool valid = true;

    if (inventory.size() == 0) {
        cout << "The list is empty" << endl << endl << endl;
    }
    else {
        cout << "Type of watercraft to search for:" << endl;
        cout << " 1. no motor" << endl;
        cout << " 2. out-board" << endl;
        cout << " 3. in-board" << endl << endl;

        cout << "- - > ";
        cin >> type;
        
        cout << endl << endl << endl;

        //this turns the input to the type of propulsion
        //the choices are one more than the data in the class
        //so they are decremented here
        switch(type) {
            case 1:
                type--; break;
            case 2:
                type--; break;
            case 3:
                type--; break;
            default:
                printf("That is not a valid motor type\n\n");
                valid = false;
            break;
        }

        if (valid == true) {
            //same as searchbytype
            //prints out if matches the propulsion type
            for (vector<watercraft *>::iterator iter = inventory.begin(); iter != inventory.end(); iter++) {
                if ((*iter)->getPropulsion() == type) {
                    found = true;
                    (*iter)->printWatercraft(i);
                }
                i++;
            }
            if (found == false) {
                cout << "Motor type not fond" << endl << endl;
            }
            else {
                cout << endl << endl << endl;
            }
        }
    }
}

//this gets the vector inventory, sorts a local copy, then prints the sorted list
void printByPrice( vector<watercraft *> inventory ) {
    
    if (inventory.size() == 0) {
        cout << "The list is empty" << endl << endl << endl;
    }
    else {
        //this makes a local copy of the main list
        vector<watercraft*> sorted = inventory;

        //this sorts the local list least expensive to most
        sort(sorted.begin(), sorted.end(), order);

        //then it prints out the sorted list
        cout << "Watercraft in list:" << endl << endl;
        int i = 0;
        for (vector<watercraft *>::iterator b = sorted.begin(); b != sorted.end(); b++) {
            (*b)->printWatercraft(i);
            i++;
        }
        cout << endl << endl << endl;
    }
}

//this tells the sort function how to sort
//gets 2 watercraft pointers and returns which total price is smaller
bool order(watercraft *a, watercraft *b) {
    double A, B;
    A = a->getTPrice();
    B = b->getTPrice();

    return A < B; 
}