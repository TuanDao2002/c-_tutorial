#pragma once

#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
	Book(string id, string title);
	Book(string id, string title, bool rare);
	~Book();
	bool borrowing();
	bool returning();
	string getId();
	string getTitle();
	bool isRare();

private:
	string id;
	string title;
	bool rare;
	bool borrowed;
};

