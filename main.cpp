#include <iostream>
#include "hotel.h"
using namespace std;

int main(void)
{
	char paswd[10];
	int choice;

retry:
	memset(paswd, 0, 10 * sizeof(char));	
	cout << "\n1.Admin\n2.Customer\nSelect user: ";
	cin >> choice;

	if (choice == 1) { // admin
paswd:
		cout << "\nEnter the paswd: ";
		cin >> paswd;

		if (strstr(paswd, "admin") != 0) { // admin pasword is correct
			cout << "Welcome admin!" << endl;
			// call admin panel here
		} else {
			cout << "\nIncorrect paswd!" << endl;
			cout << "1.Try again\n2.Change user\nEnter your choice: ";
			cin >> choice;

			if (choice == 1) { // user wants to retry 
				goto paswd;
			} else if (choice == 2) { // change user
				goto retry;
			}
		}
	} else if (choice == 2) { // customer
		cout << "\nWelcome Customer!" << endl;
		// call customer panel here
	}

	return 0;
}
