#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>

class Patient; 
class Doctor; 
class Room; 


using namespace std;

class Hospital { //creates class hospital

	public:
	
		Hospital(); //default constructor
		Hospital(string, string, string, int,int,int); //constructor
		Hospital(const Hospital &); //copy constructor
		~Hospital();  //destructor

		//member functions for doctor
		void addDoctor(const Doctor&); 
		void listAllDoctors() const; 
		bool searchAllDoctors(int) const; 
		void removeDoctor(int); 
	
		//member functions for patient
		void addPatient(const Patient&); 
		void listAllPatients() const; 
		bool searchAllPatients(int) const; 
		void removePatient(int); 
	
		//member functions for room
		void addRoom(const Room&);
		void listAllRooms() const;
		bool searchAllRooms(string) const; 
		void removeRoom(string); 
	

		//private data members
	private:
	
		string Hname;
		string Haddress;
		string Htelephone;
		Patient* patients ; //list of patients
		Doctor * doctor ;	//list of doctors
		Room * room; //list of rooms
		int hnumDoctors; 
		int hnumPatients; 
		int hnumRooms; 

};

#endif