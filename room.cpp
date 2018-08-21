#include "patient.h"
#include "doctor.h"
#include "hospital.h"
#include "room.h"
#include "bed.h"


// Functions for Room

Room::Room(){	//default constructor

	roomID = ""; 
	location = ""; 
	capacity = 0;
}

Room::Room(string ROOMID, string LOCATION, int CAPACITY){ //constructor

	roomID = ROOMID; 
	location = LOCATION;
	capacity = CAPACITY;
	bed = new Bed[5]; 
}

Room::~Room() {		//destructor
}

Room::Room(const Room& room) { //copy constructor  

	roomID = room.roomID; 
	location = room.location;
	capacity = room.capacity;
	bed = new Bed[5]; 

	for (int i = 0; i < capacity; i++){

	bed[i] = room.bed[i];
	}
}

string Room:: getRoomID() {

	return roomID; 
} 

string Room:: getRoomLocation() {

	return location; 
} 

void Room::setRoomInfo(string ROOMID, string LOCATION, int CAPACITY) { //sets roomID, location, capacity

	roomID = ROOMID; 
	location = LOCATION; 
	capacity = CAPACITY; 
}

void Room::addBed(const Bed& B){ //adds bed to room if capacity of room not exceded, if capacity exceded, return error message

	if (capacity < 5) {

		bed[capacity] = B;  
		capacity++;                    
	}

	else {
	cout << "The number of beds that can be added to this room has reached its limit "; 
	}
}

void Room::listAllBeds() const {		//lists all beds in the room and outputs bed info (id, type)											

	for (int i = 0; i < capacity; i++){   

	cout <<"Bed " << i+1 << " :" <<  "\n";
	cout <<"Bed ID: " << bed[i].getBedID() << "\n";
	cout <<"Bed Type:" << bed[i].getBedType() <<  "\n\n";
	}
}

bool Room::searchAllBeds(int bedID) const { //search bed ID, if it exists, return true, if not return false

	for(int i=0; i < capacity; i++) {

		if (bed[i].getBedID() == bedID){

			return true;
		}
	}
	return false;
}

void Room::removeBed(int bedID) { //remove bed from room, if it exists. If not, disp error nmessage

	if(searchAllBeds(bedID)){ //search for bed ID

		for(int i = 0; i < capacity-1; i++) {     //delete bed
			
			bed[i] = bed[i+1]; 
		}
	capacity--; //decrement capacity
	return;
	}

	else{
		cout << "This particular Bed is not assigned to this Room";
	}
}
