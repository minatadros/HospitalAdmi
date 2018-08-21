#include "patient.h"
#include "doctor.h"
#include "hospital.h"


// Functions for Doctor


Doctor::Doctor(){ //default constructor

	doctorID = 0;
	name = "";
	address = ""; 
	tel = "";
	rank = "";
	numPatients = 0;

}

Doctor::Doctor(int ID, string Name, string addr, string Tel, string Rank, int numPat){ //constructor

	doctorID = ID;
	name = Name;
	address = addr;
	tel = Tel;
	rank = Rank;
	numPatients = numPat;
	patients = new Patient[5];

}

Doctor::~Doctor() {
}

Doctor::Doctor(const Doctor & doctor) { //copy constructor

	doctorID = doctor.doctorID;
	name = doctor.name;
	address = doctor.address;
	tel = doctor.tel;
	patients = new Patient[5]; 
	rank = doctor.rank;
	numPatients = doctor.numPatients;
	for (int i = 0; i< numPatients; i++){

	patients[i] = doctor.patients[i];

	}

}

void Doctor::addPatient(const Patient& P)  {            // adds patient to a doctor 

	if (numPatients < 5)  { //checks if doctor has maximal number of patients, if doctor has less than 5 patients, add patient

		patients[numPatients] = P;  
		numPatients+=1;           //increments number of patients         

	}

	else {
	cout << " This doctor is not available "; //display message if doctor has max number of patients
	}

}

void Doctor::removePatient(int pat) {						//remove patient from doctor
															
	for (int i = 0; i < numPatients; i++) {                 // We need to search for it first

		if (patients[i].getpatientNum() == pat) {
													
				for (int j = i; j < numPatients-1; j++) {   // We need to shift the elements of the array

						patients[j] = patients[j+1]; 

				}

		numPatients--;
		return;

		}
	}

	cout << "Passenger cannot be found " << endl; //if patient does not exist, display message

}

void Doctor::setAddress(string addr){ //sets doctor address

	address = addr;

}

void Doctor::setTel(string Tel){	//sets doctor phone number

	tel = Tel;

}

void Doctor::listAllPatients() const	//list all patients
{

	for(int i=0; i < numPatients; i++){  //goes through all patients in the array and displays their info

		cout <<"Patient " << i+1 << " :" <<  "\n\n";
		cout << "Patient Number: " << patients[i].getpatientNum() << "\n";
		cout << "Name: " << patients[i].getName() << "\n";
		cout << "Address: " << patients[i].getAddress() << "\n";
		cout << "Telephone #: " << patients[i].getTel() << "\n";
		cout << "Gender: " << patients[i].getGender() << "\n";
		cout << "Birthdate: " << patients[i].getBirthdate() << "\n";
        cout << "\n\n";
	}

}

bool Doctor::searchPatients(int PatientNum) const { //search for a patient

	for(int i=0; i < numPatients; i++) { 

		if (patients[i].getpatientNum() == PatientNum) //if this patient exists, return true

			return true;
	}
	return false;

}

int Doctor::getDoctorID(){ //returns doctor id

	return doctorID; 

}

string Doctor::getName(){ //returns doctor name

	return name; 

}

string Doctor::getAddress(){ //returns doctor address

	return address;

}

string Doctor::getTel() { //returns doctor telephone

		return tel; 

}

string Doctor:: getRank() { //returns doctor rank

	return rank; 
}