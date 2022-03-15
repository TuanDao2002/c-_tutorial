#include "pch.h"
#include "RegularMember.h"

// contructor implementation
RegularMember::RegularMember(string id, string name)
{
	this->name = name;
	this->id = id;
	this->numBorrowed = 0;
	for (int i = 0; i < MAXBORROW; i++) {
		this->borrowList[i] = NULL;
	}
}

// detructor implementation
RegularMember::~RegularMember() {}

// getters for this class
string RegularMember::getId() {
	return this->id;
}

string RegularMember::getName() {
	return this->name;
}

// Borrowing a book item for this member
bool RegularMember::borrowing(Book *item) {
	// check if itemis rar book item
	if (item->isRare()) {
		cout << "Member " << this->getId() << " cannot borrow book item " << item->getTitle() << " because it's rare!" << endl;
		return false;
	}
	// check if the member already borrowed 2 items
	if (numBorrowed >= MAXBORROW) {
		cout << "Borrow failed be cause member " << this->getId() << " have borrowed " << MAXBORROW << " items!" << endl;
		return false;
	}
	// perform the borrowing act using the book object
	if (item->borrowing()) {
		cout << "Member " << this->getId() << " borrowed book item: " << item->getTitle() << endl;
		this->borrowList[numBorrowed++] = item;
		return true;
	}

	// if failed to borrow then the book is not available
	cout << "The item id " << item->getId() << " is not available!" << endl;
	return false;
}

// Returning a book item for this member
bool RegularMember::returning(Book *item) {
	bool found = false;
	// check if the customer really borrow this book
	for (int i = 0; i < MAXBORROW; i++) {
		// if an item exists in this borrowList
		if (this->borrowList[i] != NULL) {
			// check that item has the same id with the returning book item
			if (item->getId().compare(this->borrowList[i]->getId()) == 0) {
				found = true;
				break;
			}
		}
	}
	// no book item in the list match the book item, then failed to return the book
	if (!found) {
		cout << "Member " << this->getId() << " does not borrow book item: " << item->getTitle() << endl;
		return false;
	}
	// if a book item is really currently borrowed by this member
	// then return it
	if (item->returning()) {
		cout << "Member " << this->getId() << " returned book item: " << item->getTitle() << endl;
		this->borrowList[numBorrowed--] = NULL;
		return true;
	}
	cout << "The item id " << item->getId() << " is available so returning failed!" << endl;
	return false;
}