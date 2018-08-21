#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

class Doctor; //include class doctor


using namespace std; 

class Patient {

	public:   //public data members                           
													
		Patient();	//default constructor
		Patient(int, string, string, string, string, string, int); //user input constructor
		~Patient();//destructor
		Patient (const Patient&); //copy constructor 
		int getpatientNum();
		string getName();
		string getAddress(); 
		string getTel(); 
		string getGender(); 
		string getBirthdate(); 
		void addDoctor(const Doctor&); //adds doctor
		void listAllDoctors() const; //lists all doctors
		void removeDoctors(int); //removes doctor
		bool searchDoctors(int) const; //searches for doctor

	private: //private data members

		int patientNum;
		string name; 
		string address;
		string tel; 
		string gender;
		string birthdate; 
		Doctor * doctor; //lists all doctors
		int numDoctors; //number of doctors
								
};

#endif



               