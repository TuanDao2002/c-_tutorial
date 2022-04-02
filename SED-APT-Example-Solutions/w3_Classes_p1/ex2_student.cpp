#include <iostream>

class Student{
    private:
        int score; //private attribute

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

        //provide access to the score (read only)
        int get_score() {
            return score;
        }
};



int main() {
    //Qa
    Student stu1("Nguyen Minh", 73), stu2("David James", 85);
    stu1.show_info();
    stu2.show_info();

    //Qb
    Student stu_arr[3] = {  Student("Nguyen Minh", 73), 
                            Student("David James", 85),
                            Student("Peter Pan", 67) };
    
    //Print out info of all students
    for (int i = 1; i < 3; i++) {
        stu_arr[i].show_info();
    }

    //Check highest score
    Student max_stu = stu_arr[0]; //assume stu0 is the one with highest score
    for (int i = 1; i < 3; i++) { //compare the score with other students' scores
        if (max_stu.get_score() < stu_arr[i].get_score()) {
            max_stu = stu_arr[i];
        }
    }

    std::cout   << "\nStudent with highest score: \n"
                << "Name = " << max_stu.name
                << ", Score = " << max_stu.get_score();

    return 0;
}