#include "pch.h"
#include "Book.h"


Book::Book(string id, string title)
{
	this->id = id;
	this->title = title;
	this->rare = false;		// assume a book item is a normal book
	this->borrowed = false;
}

Book::Book(string id, string title, bool rare)
{
	this->id = id;
	this->title = title;
	this->rare = rare;
	this->borrowed = false;
}

Book::~Book()
{
}

bool Book::borrowing() {
	if (!this->borrowed)	this->borrowed = true;
	return this->borrowed;
}

bool Book::returning() {
	if (this->borrowed)	this->borrowed = false;
	return !this->borrowed;
}

string Book::getId() {
	return this->id;
}

string Book::getTitle() {
	return this->title;
}

bool Book::isRare() {
	return this->rare;
}