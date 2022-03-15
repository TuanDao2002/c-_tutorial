#include <iostream>
#include <fstream>

class student {
    private:
        int score;
        std::string password;

    public:
        std::string name;
        student(std::string name_val, int score_val) {
            name = name_val;
            score = score_val;
        }

        int get_score() {
            return score;
        }

        void display() {
            std::cout << "Name: " << name << "\tScore: " << get_score() << "\n";
        }

        void write_file(std::string val) {
            std::fstream myfile;
            myfile.open(name + ".data", std::ios::out);

            if (!myfile) {
                std::cout << "Cannot open file" << "\n";
                return;
            }
            
            myfile << password << "\n";
            
            std::cout << "Password is saved!" << "\n"; 
            myfile.close();
        }

        void change_pwd() {
            if (password.empty()) {
                std::cout << "Enter a password: ";
                std::getline(std::cin, password); // only use cin.ignore when we use std::cin before std::getline

                write_file(password);
            } else {
                std::string new_password;
                std::string prev_password;
                std::cout << "Enter the previous password to check: ";
                std::getline(std::cin, prev_password);

                if (password != prev_password) {
                    std::cout << "Wrong password" << "\n";
                    return;
                }

                std::cout << "Enter your new password: ";
                std::getline(std::cin, new_password);

                password = new_password;

                write_file(new_password);
            }
        }
};

int main() {
    student s1("tuan", 80);
    student s2("khatun", 81);

    s1.display();
    s2.display();

    student s3("dao", 82);
    student studentArray[3] = {s1, s2, s3};

    student highestScoreStudent = studentArray[0];
    for (int i = 1; i < 3; i++) {
        if (studentArray[i].get_score() > highestScoreStudent.get_score()) {
            highestScoreStudent = studentArray[i];
        }
    }

    std::cout << "Student with the highest score: " << "\n";
    highestScoreStudent.display();

    s1.change_pwd();
    s1.change_pwd();
    return 0;
}