#ifndef BED_H
#define BED_H

#include <iostream>
#include <string>

class Bed;
class Patient; 


using namespace std; 


class Bed { 

	public: //public data members

		Bed(); //default constructor
		Bed(int, string,int); //constructor 
		~Bed(); //destructor
		Bed(const Bed&); //copy constructor
		void addOnePatient(const Patient&); //adds patient on the bed 
		void removeOnePatient(int); //removes patient from the bed
		void listOnePatient() const; //list info of patient on the bed
		int getBedID(); 
		string getBedType(); 

	private: //private data members

		int bedID;
		string type; 
		Patient * patient2; 
		int rnumPatients; 

};

#endif