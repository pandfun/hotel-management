#include <iostream>
#include "hotel.h"
using namespace std;


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

// global objects of Room class
Room rooms[20];


int main(void)
{
	createRooms();
	userInterface();

	return 0;
}


void userInterface(void) 
{
	int choice, flag = 0;

	while (1) {
MAIN:
		cout << "\n------ Welcome to the Hotel ------\n" << endl;
		cout << "1.Check availability\n";
		cout << "2.Book a room\n";
		cout << "3.Checkout\n";
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";

		cin >> choice;

		switch(choice) 
		{
			case 1: {
				/* TODO: write a func to display how many rooms are 
				vaccant for all 4 types of rooms */
				break;
			}

			case 2: { // Booking a room and taking customer details...

AC:
				cout << "\nDo you want AC or Non-AC? (enter 1 or 2): ";
				cin >> choice;

				if (choice == 1) { // user wants AC room
BED1:
					cout << "Do you want single or double bed (enter 1 or 2): ";
					cin >> choice;

					if (choice == 1) { // AC & single bed

						for(int i = 0; i < 6; ++i) {
							if (rooms[i].vaccancy == true) {
CONF:
								cout << "\nRoom cost will be Rs." << rooms[i].cost << endl;
								cout << "Do you want to proceed? (enter 1 for yes or 2 for no): ";
								cin >> choice;
								
								if (choice == 1) {
									rooms[i].vaccancy = false;
									rooms[i].checkIn();

									cout << "Booking completed!\n";
									cout << "Due Payment: Rs." << rooms[i].cust.due_payment << endl;

									flag = 1;
								} else if (choice == 2) {
									goto AC;
								} else {
									cout << "Invalid choice!" << endl;
									goto CONF;
								}

								goto MAIN;
							}
						}

						if (flag == 0) {
							cout << "Sorry no room found!\n";
							goto AC;
						}

						flag = 0;

					} else if (choice == 2) { // AC & double bed

						for(int i = 6; i < 11; ++i) {
							if (rooms[i].vaccancy == true) {
								rooms[i].vaccancy = false;
								rooms[i].checkIn();
								flag = 1;
							}
						}

						if (flag == 0) {
							cout << "Sorry no vaccancy!\n";
							goto AC;
						}

						flag = 0;

					} else {
						cout << "Invalid choice!\n";
						goto BED1;
					}
					
				} else if (choice == 2) { // user wants Non-AC room
BED2:				
					cout << "Do you want single or double bed (enter 1 or 2): ";
					cin >> choice;

					if (choice == 1) { // Non-AC & single bed

						for(int i = 11; i < 16; ++i) {
							if (rooms[i].vaccancy == true) {
								rooms[i].vaccancy = false;
								rooms[i].checkIn();
								flag = 1;
							}
						}

						if (flag == 0) {
							cout << "Sorry no room found!\n";
							goto AC;
						}

						flag = 0;

					} else if (choice == 2) { // Non-AC & double bed

						for(int i = 15; i < 21; ++i) {
							if (rooms[i].vaccancy == true) {
								rooms[i].vaccancy = false;
								rooms[i].checkIn();
								flag = 1;
							}
						}

						if (flag == 0) {
							cout << "Sorry no vaccancy!\n";
							goto AC;
						}

						flag = 0;

					} else {
						cout << "Invalid choice!\n";
						goto BED2;
					}

				} else {
					cout << "Invalid choice!\n";
					goto AC;
				}


				break;
			}
			case 3: { // user wants to checkout!
				/* TODO : write function for this,
				 clear all details in room obj*/
				break;
			}

			case 4: {
				return;
			}

			default: {
				cout << "\nerr: Do not use alphabets!" << endl;
				exit(1);
			}
		}

	}

	return;
}

/* NOTE: This function must be called! */
/* Function to set attributes for room objects */
void createRooms(void)
{
	int flag = 0;

	for (int i = 0; i < 20; ++i) {
		
		// setting flags
		if (i < 6)
			flag = 1;
		else if (i < 11)
			flag = 2;
		else if (i < 16)
			flag = 3;
		else if (i < 21)
			flag = 4;
		
		rooms[i].room_no = i+1;
		setAttributes(rooms[i], flag);
	}

	return;
}

/* IMP: Do not invoke this function anywhere!! */
void setAttributes(Room &r, int flag)
{
	if (flag == 1) { // AC & single bed
		r.bed_count = 1;
		r.ac = true;
		r.cost = 1200;

	} else if (flag == 2) { // AC & double bed
		r.bed_count = 2;
		r.ac = true;
		r.cost = 1600;

	} else if (flag == 3) { // Non-AC & single bed
		r.bed_count = 1;
		r.ac = false;
		r.cost = 300;
	
	} else if (flag == 4) { // Non-AC & double bed
		r.bed_count = 2;
		r.ac = false;
		r.cost = 500;

	}

	return;
}
