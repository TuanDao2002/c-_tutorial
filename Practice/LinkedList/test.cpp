#include <iostream>
#include "LinkedList.cpp" // not include header file "LinkedList.h" but have to include "LinkedList.cpp" to use LinkedList
int main() {
	LinkedList list = LinkedList(12);
	list.headInsert(99);
	list.headInsert(99);
	list.tailAppend(100);
	list.removeNode(99);

	node* find = list.findNode(99);
	list.insertNodeAfter(find, 3142);
	
	if (list.findData(99)) {
		std::cout << "99 is found\n"; 
	} else {
		std::cout << "99 is not found\n";
	}

	std::cout << "The size of linkedlist is: " << list.size() << std::endl;
	list.printList();
	return 0;
}