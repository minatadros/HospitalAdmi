#include "patient.h"
#include "doctor.h"
#include "hospital.h"
#include "room.h"
#include "bed.h"

using namespace std; 

// Functions for Bed


int Bed::getBedID(){ //returns bedID

	return bedID;
}

string Bed::getBedType(){ //returns bed type

	return type;
}

Bed::Bed() { //default constructor

	bedID = 0;
	type = "";
	rnumPatients = 0; 
}

Bed::Bed(int BEDID,string TYPE, int NUMPATIENTS) { //user input constructor

	bedID = BEDID; 
	type = TYPE; 
	patient2 = new Patient[1]; 
	rnumPatients = NUMPATIENTS; 

}

Bed::~Bed() { //destructor
}

Bed::Bed(const Bed& bed) { //copy constructor

	bedID = bed.bedID; 
	type = bed.type;
	patient2 = new Patient[1];
}

void Bed::listOnePatient() const { //lists the patient on the current bed and displays its info

	for (int i = 0; i < rnumPatients; i++){  

		cout <<"Patient 1:" <<  "\n\n";
		cout << "Patient Number: " << patient2[i].getpatientNum() << "\n";
		cout << "Name: " << patient2[i].getName() << "\n";
		cout << "Address: " << patient2[i].getAddress() << "\n";
		cout << "Telephone #: " << patient2[i].getTel() << "\n";
		cout << "Gender: " << patient2[i].getGender() << "\n";
		cout << "Birthdate: " << patient2[i].getBirthdate() << "\n";
        cout << "\n\n";
	}        

}

void Bed::addOnePatient(const Patient& P){ //books a patient to the bed

	if (rnumPatients < 1)  { //checks if the bed is empty

		patient2[rnumPatients] = P;    //if bed is empty, add patient
		rnumPatients++; //increments numPatients
	}

	else {

	cout << "A patient is already assigned to this bed"; //if bed is full, display error message
	}
}

void Bed::removeOnePatient(int PatientNum) {				//removes patient from bed
															// We need to search for it first
	for (int i = 0; i < rnumPatients; i++) {

		if (patient2[i].getpatientNum() == PatientNum) {    //if we find the patient
															// We need to shift the elements of the array
			for (int j = i; j < rnumPatients-1; j++) {

					patient2[j] = patient2[j+1]; 
			}

	rnumPatients--; //decrement numPatients
	return;

		}
	}

	cout << "Patient cannot be found " << endl;
}