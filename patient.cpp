#include "patient.h"
#include "doctor.h"
#include "hospital.h"



// Functions for Patient 

Patient::Patient() { // The default constructor 

	numDoctors = 0; 
	patientNum = 0; 
	name = ""; 
	address = ""; 
	tel = ""; 
	gender = ""; 
	birthdate = "";  

}

Patient::Patient(int PatientN, string NAME , string ADDRESS, string TEL, string GENDER, string BIRTHDATE, int numDoc) { //user input constructor

	patientNum = PatientN; 
	name = NAME; 
	address = ADDRESS; 
	tel = TEL; 
	gender = GENDER; 
	birthdate = BIRTHDATE; 
	numDoctors = numDoc; 
	doctor = new Doctor[5];

}

Patient:: ~Patient() { //destructor
}

Patient::Patient (const Patient& patient){ //copy constructor;

	patientNum = patient.patientNum;
	name =  patient.name; 
	address = patient.address;
	tel = patient.tel; 
	doctor = new Doctor[5]; 
	gender = patient.gender; 
	birthdate = patient.birthdate; 
	
	for ( int i = 0; i < numDoctors; i++) {

		doctor[i] = patient.doctor[i]; 
	}

}

int Patient::getpatientNum()  { //returns patient number

	return patientNum;

}

bool Patient::searchDoctors(int doctorID) const { //searches for doctor affiliated with this patient

	for(int i=0; i < numDoctors; i++) {

		if ( doctor[i].getDoctorID() == doctorID) //if doctor exists, return true

			return true; 
	}
	return false; //else, return false

}

void Patient::addDoctor( const Doctor& D) {      //adds a doctor to the patient      

	if (numDoctors < 5) {						//checks if the patient can accomodate more doctors

			doctor[numDoctors] = D;			    //if patient can accomodate more doctors, add doctor
			numDoctors++;                       //increment number of doctors

	}
	
	else {

			cout << "This Doctor is not available at the current moment "; //if patient has reached maximal number of doctors, display error message
	}

}

void Patient::listAllDoctors() const {			 //list all doctors affiliated with this patient

	for (int i = 0; i < numDoctors; i++) {       //goes through the array of doctors and displays their info

		cout <<"Doctor " << i+1 << " :" <<  "\n\n";
		cout << "Doctor ID: " << doctor[i].getDoctorID() << "\n";
        cout << "Name: " << doctor[i].getName() << "\n";
		cout << "Telephone #: " << doctor[i].getTel() << "\n";
		cout << "Address: " << doctor[i].getAddress() << "\n";
		cout << "Rank: " << doctor[i].getRank() << "\n";
        cout << "\n\n";

    }

}

void Patient::removeDoctors(int DoctorID)  { //dismisses doctor from patient

	if(searchDoctors(DoctorID)){ //searches if doctor to be removed is affiliated with this patient

		for(int i = 0; i < numDoctors-1; i++) {   //if yes, remove doctor  

			doctor[i] = doctor[i+1]; 
		}

		numDoctors--; //decrement number of doctors

		return;

	}

	else{

		cout << "This particular Doctor is not assigned to this Patient"; //else, displays error message
	}

}

string Patient::getName(){ //returns patient name

	return name; 

}

string Patient::getAddress(){ //returns patient address

	return address; 
}

string Patient::getTel(){ //returns patient tel number

	return tel; 
}

string Patient::getGender(){ //returns patient gender

	return gender; 
}

string Patient::getBirthdate(){ //returns patient birthdate

	return birthdate; 
}


