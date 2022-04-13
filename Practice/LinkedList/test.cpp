#include <iostream>
#include "LinkedList.h"

// compile and run this file with this command line: g++ -g test.cpp Linkedlist.cpp node.cpp;./a.exe

int main() {
	LinkedList list = LinkedList(12);
	list.headInsert(99);
	list.headInsert(100);
	list.tailAppend(99);

	std::cout << "Current linkedlist:\n";
	list.printList();
	
	std::cout << "\nLinkedlist after removing 100:\n";
	list.removeNode(100);
	list.printList();
	if (list.findData(100)) {
		std::cout << "100 is found\n"; 
	} else {
		std::cout << "100 is not found\n";
	}

	std::cout << "\nLinkedlist after adding 3142 after 99:\n";
	node* find = list.findNode(99);
	list.insertNodeAfter(find, 3142);
	list.printList();
	
	std::cout << "\nThe current size of linkedlist is: " << list.size() << std::endl;
	return 0;
}