#include <iostream>
#include "LinkedList.h"

// 2 ways to compile and run the template class Linkedlist

// + First solution: if the implementation is in .cpp files and declaration is in .h header files (Note: there must be explicit types of template specified in cpp files)
// => compile and run this file with this command line: g++ -g test.cpp Linkedlist.cpp node.cpp;./a.exe

// + Second solution: if the implementation and declaration are all in the .h header files (no need to have explicit types of template specified in .h header files)
// => compile and run test.cpp file only

int main() {
	LinkedList<std::string> list("1");
	list.headInsert("2");
	list.headInsert("3");
	list.tailAppend("4");

	std::cout << "Current linkedlist:\n";
	list.printList();
	
	std::cout << "\nLinkedlist after removing 2:\n";
	list.removeNode("2");
	list.printList();
	if (list.findData("3")) {
		std::cout << "3 is found\n"; 
	} else {
		std::cout << "3 is not found\n";
	}

	std::cout << "\nLinkedlist after adding \"hello\" after 1:\n";
	node<std::string>* find = list.findNode("1");
	list.insertNodeAfter(find, "hello");
	list.printList();
	
	std::cout << "\nThe current size of linkedlist is: " << list.size() << std::endl;
	return 0;
}