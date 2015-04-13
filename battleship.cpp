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
    y = 'X';
}

void location::pick(){
    // picks a random location
    srand(int(time(nullptr)));
    x = rand() % 5 + 1;
    y = 'a' + rand() % 5;
}

void location::fire(){
    // asks the user to input coordinates of the next shot
    
    cout << "Where will you take your next shot? (Coordinates a-e 1-5 separated by a space): ";
    cin >> y >> x;
}

void location::print() const {
    // prints location in format "a1"
    
    cout << "The ship is at: " << y  << x << endl;
    
}

bool compare(const location userShot, const location mySpot){
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

bool ship::match(const location& userShot) const {
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
    if (sunk == false)
        cout << "The ship is still alive!" << endl;
    else
        cout << "The ship was sunk!" << endl;
}


// FLEET FUNCTIONS

void fleet::deployFleet() {
    // deploys the ships in random locations
    // of the ocean
    
    int i = 0;
    location tmp;
    do {
        tmp.pick();
        if (check(tmp) == -1) {
            ships[i].setLocation(tmp);
            i = i + 1;
        }
        else
            tmp.pick();
    }
    while (i < fleetSize);

}

bool fleet::operational() const{
    // returns true if at least
    // one ship in the fleet is not sunk
    
    for(int i = 0; i < fleetSize; i++) {
        if(ships[i].isSunk() == false)
            return true;
    }
    return false;
}

bool fleet::isHitNSink(const location &userShot) {
    // returns true if there was a deployed
    // ship at this location (hit) and sinks it
    // otherwise returns false (miss)
    
    for(int i = 0; i < 5; i++) {
        if(ships[i].match(userShot)) {
            if (ships[i].isSunk() == false) {
                ships[i].sink();
                return true;
            }
        }
    }
    return false;
}

void fleet::printFleet() const{
    // prints out locations of ships in fleet
    
    for(int i = 0; i < 5; i++) {
        ships[i].printShip();
    }
}

int fleet::check(const location &userShot) const {
// returns index of the ship
// that matches location
// -1 if none match
    
    for (int i = 0; i < fleetSize; ++i)
        if (ships[i].match(userShot)) {
            return i;
        }
    return -1;
}
