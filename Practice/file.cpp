#include <bits/stdc++.h>

int main() {
	using namespace std;
	string name;
	int age;
	int score;
	int total;
	string line;

	ifstream infile("test.txt", ios::in);

	if (!infile) {
		cerr << "error" << endl;
		return 0;
	} else {	
		getline(infile, line);
		cout << line << endl;

		while (getline(infile, line)) {
			stringstream stream (line);
			stream >> name >> age >> score;
			cout << name << " " << age << " " << score << endl;

			total += score;
		}
	}

	cout << total;

	infile.close();
	return 0;
}