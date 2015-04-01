// Carrie Hadley
// 3-31-2015

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "battleship.h"


using std::cout; using std::cin; using std::endl;


// LOCATION FUNCTIONS

location::location(){
    // void constructor
    
    x = -1;
    y = -1;

}

void location::pick(){
    // picks a random location
    
    srand(int(time(0)));
    x = rand() % 5 + 1;
    y = rand() % 5 + 1;
    
    switch (y) {
        case 1:
            y = 'a';
            break;
        case 2:
            y = 'b';
            break;
        case 3:
            y = 'c';
            break;
        case 4:
            y = 'd';
            break;
        case 5:
            y = 'e';
            break;
    }
}

void location::fire(){
    // asks the user to input coordinates of the next shot
    
    cout << "Where will you take your next shot? (Coordinates 1-5 a-e separated by a space): ";
    cin >> x >> y;
}

void location::print() const {
    // prints location in format "a1"
    
    cout << "The ship is at: " << x  << y << endl;
}

bool compare(location userShot, location mySpot){
    // returns true if the two locations match
        
        if (userShot.x == mySpot.x && userShot.y == mySpot.y)
            return true;
        else
            return false;

}


// SHIP FUNCTIONS

ship::ship(){
    // void constructor
    
    sunk = false;
    }

bool ship::match(location& userShot) const {
    // returns true if this location matches
    // the ship's location
    
    return compare(loc, userShot);
}

void ship::sink(){
    // sets sunk to true
    
    sunk = true;
}

void ship::setLocation(const location& mySpot) {
    // deploys the ship at the specified location
    loc = mySpot;
    }

void ship::printShip() const{
    // prints location and status of the ship
    loc.print();
    cout << "Status of ship: ";
    if (sunk == true)
        cout << "The ship is still alive!" << endl;
    else
        cout << "The ship was sunk!" << endl;
}

//    location loc;
//    bool sunk;
