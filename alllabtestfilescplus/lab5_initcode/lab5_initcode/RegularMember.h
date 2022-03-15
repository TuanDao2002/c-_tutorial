#pragma once
#include <string>
#include "Book.h"

#define MAXBORROW 2

class RegularMember
{
public:
	RegularMember(string id, string name);
	~RegularMember();
	string getId();
	string getName();
	bool borrowing(Book *item);
	bool returning(Book *item);

private:
	string name;
	string id;
	int numBorrowed;
	Book* borrowList[MAXBORROW];
};

