#include <iostream>

class student {
    private:
        int score;
    
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

    return 0;
}