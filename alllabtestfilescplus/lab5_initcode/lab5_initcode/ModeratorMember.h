#pragma once

#include <string>
#include "Book.h"

#define MAXBORROW_NORMAL 3
#define MAXBORROW_RARE 1

class ModeratorMember
{
public:
	ModeratorMember(string id, string name);
	~ModeratorMember();
	string getId();
	string getName();
	bool borrowing(Book *item);
	bool returning(Book *item);

private:
	string name;
	string id;
	int numBorrowedNormal;
	int numBorrowedRare;
	Book* borrowList[MAXBORROW_NORMAL+MAXBORROW_RARE];
};

