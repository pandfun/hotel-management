/* Standard headers */
#include <iostream>
#include <string.h>

/* Class declarations */
class Room;
class Customer;


/* Objects declaration */
extern Room rooms[20];

/* Function declarations */

// inside room.cpp
void createRooms(void);
void setAttributes(Room &, int);

// inside menu.cpp
void userInterface(void);