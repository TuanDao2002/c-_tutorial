#include <iostream>
#define NUM_INT 5


//0: false,  any value not 0 is true

// char value is stored with ascii code
// 'A' --> is stored with value 65

//to check a string is a valid integer value or not
int is_integer_num(char str[]) {   //"-12324"

    //check first character (decimal digit or + or - sign)
    if (( str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+') {
        return 0; //false
    }

    //check for other digits
    for (int i = 1; str[i] != '\0'; i++) {
        if ( str[i] < '0' || str[i] > '9'){
            return 0; //false
        }
    } 

    //All digits are valid
    return 1; //true
}





int main(int argc, char *argv[]) {
    if (argc != NUM_INT + 1) {
        std::cerr << "Invalid number of arguments \n";
        return -1;
    }

    //go through all argument strings
    for (int i = 1; i < argc; i++) {
        if (is_integer_num(argv[i]) == 0) {
            std::cerr << "At least one argument is not valid integer \n";
            return -2;
        }
    }

    //  All arguments are valid integer numbers
    int arr[NUM_INT];
    int i;
    int *p;
    p = arr; //p got address of arr[0]

    /*
    p + 1// refer to address of arr[1]
    p + i - 1// refer to address of arr[i - 1]

    //dereferencing *p ---> access the value at the address stored in the pointer
    *(p + i - 1)   //refer to the value of arr[i - 1]
    */
    
    std::cout << "Got valid integers: ";
    for (i = 1; i < argc; i++) {
        //arr[i - 1] = atoi(argv[i]);  //convet to int and store
        *(p + (i - 1)) = atoi(argv[i]);  //convet to int and store
        std::cout << *(p + (i - 1)) << " ";
    }

    return 0; //exit status: return success
    //the return value of main is error code of the program
    //return 0: no error. return other value than 0: error (different values indicate different errors)
}