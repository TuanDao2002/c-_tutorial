  #include <iostream>
  
  int main(int argc, char *argv[]) {
      
      //Process input to get the decimal number
      int num;
      if (argc > 2) {
          std::cerr << "Invalid number of arguments. Guide: ./a.exe num \n";
          return -1;
      } else if (argc == 2) {
          num = atoi(argv[1]);
      } else {
          std::cout << "Input an integer: ";
          std::cin >> num;
      }
      
      //Check ZERO value (not defined in Roman number)
      if (num == 0) {
          std::cout << "Not defined ! ";
          return -2;
      }
  
      //Convert to Roman number
      int dec_vals[]            = { 1,   4,    5,    9,  10,   40,  50,  90,   100, 400,  500, 900, 1000};
      const char *roman_symbs[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
      
      std::cout << "> Converted Roman number: "; 
      for (int i = 12; i >=0; i--) {
          while (num >= dec_vals[i]) {
              std::cout << roman_symbs[i];
              num = num - dec_vals[i];
          }
      }
  
      return 0;
  }