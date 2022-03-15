#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;


/* 
 * IMPLEMENT YOUR OVERLOADED FUNCTIONS HERE
 */


/* this function takes a string and
 * returns 1 if the string represents a decimal
 * returns 2 if the string represents a floating point
 * returns 3 if the string represents a binary
 * returns 4 if the string represents a hexadecimal
 * return 0 if the input string is anything else
 */
int check_type(char *input) {
	int res = 1;
	int len = strlen(input);
	int	i;
	
	// check the first char for special sign chars [-,+] and '.'
	char first = input[0];
	char second = input[1];
	if (first=='-' && first=='+') {
		if (second=='.') {
			res = 2;
		}
	}
	// got a '.' from the beginning, got a float
	else if(first=='.') {
		if (second=='.')	return 0;
		res = 2;
	}
	//check to see if we got a prefix 0b --> expect a binary
	else if (first=='0' && second=='b')
		res = 3;
	// check to see if we got a prefix 0x --> expect a hexa
	else if(first=='0' && second=='x')
		res = 4;
	else if(first>='0'||first<='9') {
		if (second=='.')
			res = 2;
	}
	else if ( (first<'0'||first>'9') && (second<'0'||second>'9') )
		return 0;
	
	for (i=2; i<len; i++) {
		// already expecting a float, no more '.'
		if (res==2) {
			if (input[i]=='.' || (input[i]<'0'||input[i]>'9'))
				return 0;
		}
		// already expecting a binary, only '0' or '1'
		else if (res==3) {
			if (input[i]!='0' && input[i]!='1')
				return 0;
		}
		// already expecting a hexa, only [0-9] or [A-F]
		else if (res==4) {
			if ( (input[i]<'0'||input[i]>'9') && (input[i]<'A'||input[i]>'F') )
				return 0;
		}
		// still seeing integer, could be a float with a '.'
		else if (res==1) {
			if (input[i]=='.')	res = 2;
			else if (input[i]<'0' || input[i]>'9')
				return 0;
		}
	}
	return res;
}

int main(int argc, char* argv[]) {
	int type;

	if (argc!=2) {
		cerr << "Wrong number of inputs" << endl;
		return 0;
	}
	type = check_type(argv[1]);
	if (type==1) {
		doubleup(atoi(argv[1]));
	}
	else if (type==2) {
		doubleup(stof(argv[1]));
	}
	else if (type==3) {
		doubleup(argv[1]);
	}
	else if (type==4) {
		doubleup(string(argv[1]));
	}
	else {
		cerr << "Invalid input" << endl;
	}

	return 0;
}