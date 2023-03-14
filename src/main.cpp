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

	cout << "Welcome to the hotel" << endl;

	while (1) {
MAIN:
		cout << "\n------------\n" << endl;
		cout << "1.Check availability\n";
		cout << "2.Book a room\n";
		cout << "3.Checkout\n";
		cout << "4.Exit" << endl;
		cout << ">> ";

		cin >> choice;

		switch(choice) 
		{
			case 1: { // Displaying number of rooms available
				int i = 0;
				int count = 0;
				
				for (i = 0; i < 5; i++)
					if (rooms[i].vaccancy == true)
						count++;

				cout << endl;
				cout << "AC Single Bed = " << count << endl;

				count = 0;
				for (i = 5; i < 10; ++i)
					if (rooms[i].vaccancy == true)
						count++;

				cout << "AC Double Bed = " << count << endl;

				count = 0;
				for (i = 10; i < 15; ++i)
					if (rooms[i].vaccancy == true)
						count++;

				cout << "Non-AC Single Bed = " << count << endl;

				count = 0;
				for(i = 15; i < 20; ++i)
					if (rooms[i].vaccancy == true)
						count++;

				cout << "Non-AC Double Bed = " << count << endl;

				break;
			}

			case 2: { // Booking a room and taking customer details...
			/* Not the best method to do this, but works.. */

AC:
				cout << "\nDo you want AC or Non-AC? (enter 1 or 2): ";
				cin >> choice;

				if (choice == 1) { // user wants AC room
BED1:
					cout << "Do you want single or double bed (enter 1 or 2): ";
					cin >> choice;

					if (choice == 1) { // AC & single bed

						for(int i = 0; i < 5; ++i) {
							if (rooms[i].vaccancy == true) {
CONF1:
								cout << "\nRoom cost will be Rs." << rooms[i].cost << endl;
								cout << "Do you want to proceed? (enter 1 for yes or 2 for no): ";
								cin >> choice;
								
								if (choice == 1) {
									rooms[i].vaccancy = false;
									rooms[i].checkIn();

									cout << "\nBooking completed!\n";
									cout << "Your room number is " << rooms[i].room_no << endl;
									cout << "Due Payment: Rs." << rooms[i].cust.due_payment << endl;

									flag = 1;
								} else if (choice == 2) {
									goto AC;
								} else {
									cout << "Invalid choice!" << endl;
									exit(1);
								}

								flag = 0;
								goto MAIN;
							}
						}

						if (flag == 0) {
							cout << "\nSorry no vaccancy!\n";
							goto AC;
						}

					} else if (choice == 2) { // AC & double bed

						for(int i = 5; i < 10; ++i) {
							if (rooms[i].vaccancy == true) {
CONF2:
								cout << "\nRoom cost will be Rs." << rooms[i].cost << endl;
								cout << "Do you want to proceed? (enter 1 for yes or 2 for no): ";
								cin >> choice;
								
								if (choice == 1) {
									rooms[i].vaccancy = false;
									rooms[i].checkIn();

									cout << "\nBooking completed!\n";
									cout << "Your room number is " << rooms[i].room_no << endl;
									cout << "Due Payment: Rs." << rooms[i].cust.due_payment << endl;

									flag = 1;
								} else if (choice == 2) {
									goto AC;
								} else {
									cout << "Invalid choice!" << endl;
									exit(1);
								}

								flag = 0;
								goto MAIN;
							}
						}

						if (flag == 0) {
							cout << "\nSorry no vaccancy!\n";
							goto AC;
						}

					} else {
						cout << "Invalid choice!\n";
						exit(1);
					}
					
				} else if (choice == 2) { // user wants Non-AC room
BED2:				
					cout << "Do you want single or double bed (enter 1 or 2): ";
					cin >> choice;

					if (choice == 1) { // Non-AC & single bed

						for(int i = 10; i < 15; ++i) {
							if (rooms[i].vaccancy == true) {
CONF3:
								cout << "\nRoom cost will be Rs." << rooms[i].cost << endl;
								cout << "Do you want to proceed? (enter 1 for yes or 2 for no): ";
								cin >> choice;
								
								if (choice == 1) {
									rooms[i].vaccancy = false;
									rooms[i].checkIn();

									cout << "\nBooking completed!\n";
									cout << "Your room number is " << rooms[i].room_no << endl;
									cout << "Due Payment: Rs." << rooms[i].cust.due_payment << endl;

									flag = 1;
								} else if (choice == 2) {
									goto AC;
								} else {
									cout << "Invalid choice!" << endl;
									exit(1);
								}

								flag = 0;
								goto MAIN;
							}
						}

						if (flag == 0) {
							cout << "\nSorry no vaccancy!\n";
							goto AC;
						}

					} else if (choice == 2) { // Non-AC & double bed

						for(int i = 15; i < 20; ++i) {
							if (rooms[i].vaccancy == true) {
CONF4:
								cout << "\nRoom cost will be Rs." << rooms[i].cost << endl;
								cout << "Do you want to proceed? (enter 1 for yes or 2 for no): ";
								cin >> choice;
								
								if (choice == 1) {
									rooms[i].vaccancy = false;
									rooms[i].checkIn();

									cout << "\nBooking completed!\n";
									cout << "Your room number is " << rooms[i].room_no << endl;
									cout << "Due Payment: Rs." << rooms[i].cust.due_payment << endl;

									flag = 1;
								} else if (choice == 2) {
									goto AC;
								} else {
									cout << "Invalid choice!" << endl;
									exit(1);
								}

								flag = 0;
								goto MAIN;
							}
						}

						if (flag == 0) {
							cout << "\nSorry no vaccancy!\n";
							goto AC;
						}

					} else {
						cout << "Invalid choice!\n";
						exit(1);
					}

				} else {
					cout << "Invalid choice!\n";
					exit(1);
				}


				break;
			}
			case 3: { // user wants to checkout!

				int room_check;
				char name_confirm[30] = {0};

				cout << "Enter what room you are staying in: ";
				cin >> room_check;
				
				--room_check; // to use this as the index for rooms obj arr

				cout << "To confirms it's you, enter the name you used to bookin: ";
				cin >> name_confirm;

				if (strcmp(name_confirm, rooms[room_check].cust.name) == 0) {

					if (rooms[room_check].cust.due_payment > 0) {
						cout << "\nPls finish due payment before checking out!" << endl;
						cout << "Would you like to pay now? (enter 1 for yes, 2 for no): ";
						cin >> choice;

						if (choice == 1) {
							rooms[room_check].cust.due_payment = 0;

						} else {
							cout << "\nSorry cannot checkout with pending payment!\n";
							break;
						}
					}
					
					rooms[room_check].checkOut();

				} else {
					cout << "\nFailed to checkout!! ";
					cout << "Invalid name entry!" << endl;
					break;
				}

				cout << "\nYou have been checked out succesfully!\nThank you for staying with us!!\n"; 
				break;
			}

			case 4: {
				return;
			}

			default: {
				cout << "\nInvalid choice!" << endl;
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
		if (i >= 0 && i <= 4)
			flag = 1;
		else if (i >= 5 && i <= 9)
			flag = 2;
		else if (i >= 10 && i <= 14)
			flag = 3;
		else if (i >= 15 && i <= 19)
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
