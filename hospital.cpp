#include "patient.h"
#include "doctor.h"
#include "hospital.h"
#include "room.h"



// Functions for to Hospital



Hospital::Hospital() { //default constructor

	Hname = "";              
	Haddress = ""; 
	Htelephone = ""; 		
}

Hospital::Hospital(string NAME, string ADDRESS, string TELEPHONE, int HnumDoctors, int HnumPatients, int HnumRooms) { //constructor

	Hname = NAME; 
	Haddress = ADDRESS; 
	Htelephone = TELEPHONE; 
	patients = new Patient[5]; 
	doctor = new Doctor[5]; 
	room = new Room[5]; 
	hnumDoctors = HnumDoctors; 
	hnumPatients = HnumPatients;
	hnumRooms = HnumRooms; 
}

Hospital::Hospital(const Hospital& hospital) { //copy constructor

	Hname = hospital.Hname;
	Haddress = hospital.Haddress;
	Htelephone = hospital.Htelephone;
	hnumDoctors = hospital.hnumDoctors; 
	hnumPatients = hospital.hnumPatients;
	hnumRooms = hospital.hnumRooms; 
	patients = new Patient[5]; 
	doctor = new Doctor[5]; 
	room = new Room[5]; 

	//copies data members for all elements in the array 
	for (int i = 0; i< hnumPatients; i++){

		patients[i] = hospital.patients[i];
	}
	
	for (int i = 0; i< hnumDoctors; i++){

		doctor[i] = hospital.doctor[i];
	}

	for (int i = 0; i< hnumRooms; i++){

		room[i] = hospital.room[i];
	}

}
		
Hospital:: ~Hospital() { //destructor, deletes all elements in the arrays doctors, patients, room
		
		delete[]doctor; 
		doctor = NULL; 

		delete[]patients; 
		doctor = NULL; 

		delete[]room; 
		room = NULL; 
}

void Hospital::addDoctor( const Doctor& D) {       //adds doctor to hospital, checks if hospital has max number of doctors      

	if (hnumDoctors < 5) {

		doctor[hnumDoctors] = D;           
		hnumDoctors++;                    
	}
	else {

	cout << "Hospital already has max number of docors"; 
	}
}

void Hospital::listAllDoctors() const {					//lists all doctors affiliated with this hospital								

	for (int i = 0; i < hnumDoctors; i++)  {       

		cout <<"Doctor " << i+1 << " :" <<  "\n\n";
		cout << "Doctor ID: " << doctor[i].getDoctorID() << "\n";
        cout << "Name: " << doctor[i].getName() << "\n";
		cout << "Telephone #: " << doctor[i].getTel() << "\n";
		cout << "Address: " << doctor[i].getAddress() << "\n";
		cout << "Rank: " << doctor[i].getRank() << "\n";
        cout << "\n\n";
    }

}

bool Hospital::searchAllDoctors(int doctorID) const { //search for doctor affiliated with hospital 

	for(int i =0; i < hnumDoctors; i++) {

		if(doctor[i].getDoctorID() == doctorID){

			return true; 
		}
	}

	return false; 
}

void Hospital::removeDoctor(int doctorID) { //if doctor exists, dismisses doctor from hospital, if not, displays error message

	if(searchAllDoctors(doctorID)){

		for(int i = 0; i < hnumDoctors-1; i++) {     
			doctor[i] = doctor[i+1]; 
		}
			hnumDoctors--;
			return;
	}

	else{

		cout << "This particular Doctor is not assigned to this Hospital";
	}
}


void Hospital::addPatient( const Patient& P) {       //checks if hospital can accomodate mor patients, if yes, admits patient into hospital, if not, displays errpor message      

	if (hnumPatients < 5) {

		patients[hnumPatients] = P;           
		hnumPatients++;                    
	}

	else {

	cout << "The number of patients that can be added to the hospital has been exceeded" << "\n\n"; 
	}
}

void Hospital::listAllPatients() const {		//lists all patients admitted into the hospital										

	for (int i = 0; i < hnumPatients; i++)   {  //goes through the array of patients

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

bool Hospital::searchAllPatients(int PatientNum) const { //searches for a patient admitted to the hospital. If founf, return true, if not, return false

	for(int i =0; i < hnumPatients; i++) {

		if(patients[i].getpatientNum() == PatientNum)

			return true; 
	}
	return false; 
}

void Hospital::removePatient(int PatientNum) { //if patient exists, remove patient, if not, display error message

	if(searchAllPatients(PatientNum)){

		for(int i = 0; i < hnumPatients-1; i++) {  

			doctor[i] = doctor[i+1]; 
		}
			hnumPatients--;
			return;
	}

	else{

		cout << "This particular Patient is not assigned to this Hospital";
	}
}

void Hospital::addRoom(const Room& R) { //if hospital can accomodate more rooms, add room into the hospital. If not, display error message

	if (hnumRooms < 5) {

		room[hnumRooms] = R;           
		hnumRooms++;                    
	}

	else {

	cout << "The number of rooms that can be added to the hospital has been exceeded" << "\n\n"; 
	}
}

void Hospital::listAllRooms() const { //lists all rooms by going through the array and displays room info (ID and location)

		for (int i = 0; i < hnumRooms; i++) {        
			
			cout <<"Room " << i+1 << " :" <<  "\n";
			cout <<"Room ID:" << room[i].getRoomID() <<  "\n";
			cout << "Room Location: " << room[i].getRoomLocation() << "\n\n";
		}
}

bool Hospital::searchAllRooms(string roomID) const { //searches for a room in the hospital. If room exists, return tryue, if not, return false

	for(int i =0; i < hnumRooms; i++) {

		if(room[i].getRoomID() == roomID){

			return true; 
		}
	}
	return false; 
}

void Hospital::removeRoom(string roomID) { //removes a room from the hospital, if it exists. If not, display error message

	if(searchAllRooms(roomID)){

		for(int i = 0; i < hnumRooms-1; i++) {

			room[i] = room[i+1]; 
		}

		hnumRooms--;
		return;
	}

	else{
		cout << "This particular Room is not assigned to this Hospital";
	}
}
