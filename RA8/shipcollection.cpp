#include <iostream>
#include <string>

#include "ship.h"     // Ships class definitions
#include "cruise.h"
#include "cargo.h"

using namespace std;

/***ship methods***/
void Ship::print() const{
    cout << "Name: " << getShName() << "   Year: " << getShYear() << endl;
}
    

/***cargo methods***/
Cargo::Cargo(string name, int year, int capacity) :
            Ship(name,year){
                vesselType="Cargo";
    cargoCapacity=capacity;
}

int Cargo::getCapacity() const{return cargoCapacity;}

void Cargo::setCapacity(int capacity){
    cargoCapacity=capacity;
}

void Cargo::print() const{
    cout << "Name: " << getShName() << "   Year: " << getShYear();
    cout << "   Capacity (in tons): " << getCapacity() << endl;
}


/***cruise methods***/
Cruise::Cruise(string name, int year, int max) :
            Ship(name,year){
                vesselType="Cruise";
    maxPassengers=max;
}

int Cruise::getmaxPassengers() const{return maxPassengers;}

void Cruise::setmaxPassengers(int passengers){
    maxPassengers=passengers;
}

void Cruise::print() const{
    cout << "Name: " << getShName() << "   Year: " << getShYear();
    cout << "   Maximum Passengers: " << getmaxPassengers() << endl;
}
