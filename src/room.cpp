#include <iostream>
using namespace std;
#include "hotel.h"

/* ROOM STRUCTURE

	Total Rooms = 20

	Flag Val	Room no
		1		1 - 5 => AC | single bed
		2		6 - 10 => AC | double bed
		3		11 - 15 => Non-AC | single bed
		4		16 - 20 => Non-AC | double bed

*/

class Room {
	public:
		bool ac, vaccancy;
		int cost, room_no, bed_count;

		struct Customer {
			char name[30];
			int adv_payment;
			int due_payment;
		} cust;

		Room();
		void checkIn(void);
		void checkOut(void);
};

/* Default constructor */
Room::Room() 
{
	this->room_no = 0;
	this->ac = false;
	this->bed_count = 0;
	this->cost = 0;
	this->vaccancy = true;

	memset(this->cust.name, 0, strlen(this->cust.name) * sizeof(char));
}

void Room::checkIn(void) 
{
	cout << "\nEnter your name: ";
	cin >> this->cust.name;
	cout << "Enter the advance payment: ";
	cin >> this->cust.adv_payment;

	cust.due_payment = this->cost - this->cust.adv_payment;

	return;
}


void Room::checkOut(void) 
{
	this->vaccancy = true;
	
	memset(this->cust.name, 0, strlen(this->cust.name) * sizeof(char));
	this->cust.adv_payment = 0;
	this->cust.due_payment = 0;

	return;
}
