#ifndef SEAT_H
#define SEAT_H

//Sorry Vyda! I think I finished the whole struct here...
struct Seat
{
	char booking;	//A '-' means the seat is empty, an 'X' means the seat is booked.
	bool isEmpty;	//True - the seat is empty (NOT booked). False - the seat is NOT empty (IS booked).
};
#endif