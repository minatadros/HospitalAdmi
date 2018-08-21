#ifndef room_H
#define room_H

#include <iostream>
#include <string>

class Bed; //includes class bed
class Patient; //includes class patient


using namespace std; 


class Room { //creates clas room

	//public data members
	public:

		Room();  //default constructor
		Room(string, string, int); //constructor
		~Room(); //destructor
		Room(const Room&); //copy constructor
		//getxx member functions
		string getRoomID(); 
		string getRoomLocation(); 
		//set room info
		void setRoomInfo(string, string, int); 
		//add,remove, list, search bed in a room
		void addBed(const Bed&); 
		void removeBed(int); 
		void listAllBeds() const; 
		bool searchAllBeds(int) const; 

	//private data members
	private: 

		string roomID;
		string location; 
		int capacity; 
		Bed * bed; //list of beds in a room
}; 

#endif


