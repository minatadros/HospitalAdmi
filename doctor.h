#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
class Hospital; //includes class hospital
class Patient;  //includes class patient




using namespace std;

class Doctor {

	public:
	
		Doctor(); //default constructor
		Doctor(int, string, string, string, string, int); //constructor
		Doctor(const Doctor&); //copy constructor
		~Doctor(); //destructor
		void setAddress(string);
		void setTel(string);
		int getDoctorID(); 
		string getName(); 
		string getAddress(); 
		string getTel(); 
		string getRank(); 
		void addPatient(const Patient&); //adds patient to doctor
		void removePatient(int); //removes patient
		void listAllPatients() const; //displays all patients treated by this doctor
		bool searchPatients(int) const; //searches if a patient is treated by this doctor

	private:
	
		int doctorID;
		string name;
		string address;
		string tel;
		string rank;
		Patient* patients; //list of patient assigned to this doctor
		int numPatients; //current number of patients treated by this doctor

};

#endif