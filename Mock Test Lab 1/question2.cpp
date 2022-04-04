/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Dao Kha Tuan
  ID: s3877347
  Compiler used: gcc 8.1.0
  Created  date: 4/4/2002
  Acknowledgement: None
*/

#include <iostream>
#include <fstream>
#include <sstream>

#define SCORE_SIZE 3

class Student{
	private:
		std::string name;
		int scores[SCORE_SIZE];

	public:

		Student(){}

		// setter for name attribute
		void setName(std::string name) {
			this->name = name;
		}

		// setter for the score of the Student object based on the index of array "scores"
		void setEachScore(int score, int index) {
			scores[index] = score;
		}

		void inputData() {
			std::cout << "Enter name: ";
			std::getline(std::cin, name);

			for (int i = 0; i < SCORE_SIZE; i++) {
				std::cout << "Enter score " << i + 1 << " : ";
				std::cin >> scores[i];
			}

			std::cin.ignore(1, '\n');
		}

		void showInfo() {
			std::cout << "\nName = " << name << "\n"
					  << "Score 1 = " << scores[0] << "\n"
					  << "Score 2 = " << scores[1] << "\n"
					  << "Score 3 = " << scores[2] << "\n\n";
		}
		    
		friend std::istream & operator >> (std::istream &in,  Student &s);
		friend std::ostream & operator << (std::ostream &out, Student &s);

		int operator > (Student s) {
			int avg_this = (scores[0] + scores[1] + scores[2]) / 3; // average score of this object
			int avg_s = (s.scores[0] + s.scores[1] + s.scores[2]) / 3; // average score of s object

			if (avg_this > avg_s) {
				return 1;
			} else {
				return 0;
			}
		}

		friend Student operator + (float n, Student s);
};

std::istream & operator >> (std::istream &in,  Student &s) {
	s.inputData();
	return in;
}

std::ostream & operator << (std::ostream &out, Student &s) {
	s.showInfo();
	return out;
}

Student operator + (float n, Student s) {
	Student result;
	result.name = s.name;
	for (int i = 0; i < SCORE_SIZE; i++) { // assign the scores of s object to result object
		result.scores[i] = s.scores[i] + n;
	}

	return result;
}

int main(){
	
	Student s1, s2, s3;
	std::cin >> s1;
	std::cout << s1;

	// test cin
	std::cin >> s2;

	// test cout
	std::cout << s2;

	// test operator >
	if (s1 > s2) {
		std::cout << "Average scores of student 1 is greater than student 2\n";
	} else {
		std::cout << "Average scores of student 1 is not greater than student 2\n";
	}

	// test float n + object
	s3 = 20 + s1;
	std::cout << s3 << std::endl;
	
	// dynamic array of 10 students
	Student *arr = new Student[10];
	
	std::ifstream input;
	input.open("data.txt");

	if (!input) {
		std::cerr << "Cannot open file" << std::endl;
	}

	std::string temp;
	int count = 1;
	for (int i = 0; i < 10; i++) {
		std::getline(input, temp, ','); // get the first argument before comma "," to assign to the name of Student object
		arr[i].setName(temp);

		// use stringstream to get all 3 scores of Student object
		std::stringstream ss;
		std::getline(input, temp);
		ss.str(temp);

		int score_temp;
		for (int j = 0; j < SCORE_SIZE; j++) {
			ss >> score_temp;
			arr[i].setEachScore(score_temp, j);
		}
	}

	Student highest_avg_stu = arr[0];
	for (Student student : {arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]}) {
		if (student > highest_avg_stu) { // check which Student has the highest average scores
			highest_avg_stu = student;
		}
	}

	std::cout << "Info of student with the highest average score: " << std::endl;
	highest_avg_stu.showInfo();

	input.close();
	delete[] arr;
	return 0;
}
