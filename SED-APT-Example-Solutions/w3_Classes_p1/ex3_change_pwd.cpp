#include <iostream>
#include <fstream>
#include <cstring>
#define MAXSIZE 100

class Student{
    private:
        int score; //private attribute
        int password; 

    public:
        std::string name; //public attribute
        
        //constructor
        Student(std::string name_val, int score_val) {
            name = name_val;
            score = score_val;
        }

        //public method
        void show_info() {
            std::cout   << "Name = " << name
                        << ", Score = " << score << "\n";
        }

        //provide access to the socre (read only)
        int get_score() {
            return score;
        }


        /* Method to change password */
        int change_pwd() {
            //Open the file to read
            std::fstream myfile;
            myfile.open(name + ".dat", std::ios::in); 

            if (!myfile) {
                std::cerr << "Fail to open " << name + ".dat";
                return -1;
            }

            //read from the file
            char pre_pwd[MAXSIZE], in_pwd[MAXSIZE], new_pwd[MAXSIZE];
            myfile.getline(pre_pwd, sizeof(pre_pwd)); //must use C-type string with getline from the file
            myfile.close();

            if (strlen(pre_pwd) == 0) { //File is empty
                std::cout << "No existing password. \nPlease set your password: ";
            } else { 
                /* there is an existing password */
                //Ask user to input password
                std::cout << "Enter your previous password: ";
                std::cin.getline(in_pwd, sizeof(in_pwd));

                //Check with previous password store in the file
                if (strcmp(pre_pwd, in_pwd) == 0) { //
                    std::cout << "Enter your new password: ";
                } else {
                    std::cout << "Wrong password! \n";
                    return -2;
                }
            }

            //Save the new password to the file
            myfile.open(name + ".dat", std::ios::out);
            std::cin.getline(new_pwd, sizeof(new_pwd));
            myfile << new_pwd;
            myfile.close();

            return 0; //no error
        }
};


int main() {
    //Test the class method
    Student stu("Thu Nguyen", 100);
    stu.change_pwd();

    return 0;
}