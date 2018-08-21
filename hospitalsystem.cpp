#include "doctor.h"
#include "hospital.h"
#include "patient.h"
#include "bed.h"
#include "room.h"

int main() {

// Create the Hospital 
Hospital h("General Hospital","4343", "(450) 343-2443", 0, 0,0);


// Creating doctors 
Doctor d1(23443, "Mohammad Ali", "5125", "(450) 434-2343", "Surgeon", 0);
Doctor d2(34332, "Ahmed", "2343", "(450) 432-4323", "Family Doctor", 0);
	

// Creating patients
Patient p1(130, "Chung Hu", "4323", "(450) 259-9284","Female", "02/02/1990",0);
Patient p2(131, "Maria", "1344", "(450) 928-3940","Female", "00/01/1985",0);
Patient p3(132, "Naweed", "5432", "(450) 490-0294","Male", "01/03/2004",0);


//Creating a room
Room r1("30493", "Floor C", 0 ); 
Room r2("3232", "Floor D", 0); 


// Creating Beds
Bed b1(12113, "A",0);
Bed b2(23343, "B",0);
Bed b3(32434, "B",0); 


// Assign room to hospital
h.addRoom(r1); 
h.addRoom(r2); 


// List the rooms belonging to General Hospital 
cout << "\n" << "The Rooms assigned to the General Hospital are:" << "\n"; 
h.listAllRooms(); 



//Assign Bed to room 
r1.addBed(b1); 
r1.addBed(b2);
r1.addBed(b3);




// List bed belonging to room 1
cout << "\n" << "The beds assigned to Room 1 are:" << "\n"; 
r1.listAllBeds(); 


//Assign patient to bed
b1.addOnePatient(p1); 
b2.addOnePatient(p2); 
b3.addOnePatient(p3); 



// List the patient for each bed

cout << "\n" << "The patient assigned to Bed 1 in Room 1 is :" << "\n"; 
b1.listOnePatient(); 

cout << "\n" << "The patient assigned to Bed 2 in Room 1 is :" << "\n"; 
b2.listOnePatient();

cout << "\n" << "The patient assigned to Bed 3 in Room 1 is :" << "\n"; 
b3.listOnePatient(); 


// Remove functions 

b1.removeOnePatient(130);  // Removing patient from bed 1

r1.removeBed(12113);      // Removing bed 1 from Room 1

h.removeRoom("30493");   // Removing room 1 from Hospital 



// Listing all the previously listed functions to check remove functions 
cout << "\n" << "The rooms assigned to General Hospital after update are:" << "\n"; 
h.listAllRooms(); 

cout << "\n" << "The beds assigned to Room 1 after update are:" << "\n"; 
r1.listAllBeds();
	
cout << "\n" << "The patient assigned to bed 1 in Room 1  after update are:" << "\n"; 
b1.listOnePatient(); 




cout << "\n\n" << "To check the few conditions"; 

// 1 - No more than one patient per bed 

cout << "\n\n"; b3.addOnePatient(p2); 

// 2 - The same bed cannot be in different rooms; 

r2.addBed(b2); 
r2.addBed(b3); 

return 0; 

}