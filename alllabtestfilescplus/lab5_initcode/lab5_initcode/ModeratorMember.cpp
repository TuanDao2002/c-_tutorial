#include "pch.h"
#include "ModeratorMember.h"

ModeratorMember::ModeratorMember(string id, string name)
{
	this->name = name;
	this->id = id;
	this->numBorrowedNormal = 0;
	this->numBorrowedRare = 0;
	for (int i = 0; i < MAXBORROW_NORMAL+ MAXBORROW_RARE; i++) {
		this->borrowList[i] = NULL;
	}
}

// detructor implementation
ModeratorMember::~ModeratorMember() {}

// getters for this class
string ModeratorMember::getId() {
	return this->id;
}

string ModeratorMember::getName() {
	return this->name;
}

// Borrowing a book item for this member
bool ModeratorMember::borrowing(Book *item) {
	if (item->isRare()) {	//	check if the book item to be borrowed is rare
		if (this->numBorrowedRare >= MAXBORROW_RARE) {
			cout << "Borrow failed be cause member " << this->getId() << " have borrowed " << MAXBORROW_RARE << " rare book item(s)!" << endl;
			return false;
		}
		// perform the borrowing act using the book object
		if (item->borrowing()) {
			cout << "Member " << this->getId() << " borrowed book item: " << item->getTitle() << endl;
			this->borrowList[this->numBorrowedRare++] = item;
			return true;
		}
	}
	// check if the member already borrowed 3 normal book items
	if (this->numBorrowedNormal >= MAXBORROW_NORMAL) {
		cout << "Borrow failed be cause member " << this->getId() << " have borrowed " << MAXBORROW_NORMAL << " normal book items!" << endl;
		return false;
	}
	// perform the borrowing act using the book object
	if (item->borrowing()) {
		cout << "Member " << this->getId() << " borrowed book item: " << item->getTitle() << endl;
		this->borrowList[this->numBorrowedNormal++] = item;
		return true;
	}

	// if failed to borrow then the book is not available
	cout << "The item id " << item->getId() << " is not available!" << endl;
	return false;
}

// Returning a book item for this member
bool ModeratorMember::returning(Book *item) {
	bool found = false;
	// check if the customer really borrow this book
	for (int i = 0; i < MAXBORROW_NORMAL+MAXBORROW_RARE; i++) {
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
		if (item->isRare())
			this->borrowList[this->numBorrowedRare--] = NULL;
		else
			this->borrowList[this->numBorrowedNormal--] = NULL;
		return true;
	}
	cout << "The item id " << item->getId() << " is available so returning failed!" << endl;
	return false;
}