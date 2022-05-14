#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

/**
* @brief calculate the sum of an integer vector
*
* @param v: an integer of vector
* @return the total value of integers in the vector
*/
int sum(vector<int> &v) {
    int total = 0;
    for (int num : v) {
        total += num;
    }

    return total;
}


/**
* @brief calculate the sum of a vector of generic type
*
* @param v: a vector of generic type
* @return the total value of elements in the vector
*/
template<typename type>
type sumFunct(vector<type> &v) {
    type total;
    for (type ele : v) {
        total += ele;
    }

    return total;
}

// template specialization of sumFunct() function for string type
template<>
string sumFunct(vector<string> &v) {
    string result;
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            result += v[i];
        } else {
            result += v[i] + " ";
        }

    }

    return result;
}

int main(){
    // question a
    vector<int> intVector = {1, 5, 8};
    std::cout << "Sum of {1, 5, 8} is " << sum(intVector) << std::endl;

    // quesstion b
    vector<float> floatVector = {6.8, 7.3, 8.1};
    std::cout << "Sum of {6.8, 7.3, 8.1} is " << sumFunct<float>(floatVector) << std::endl;

    vector<string> stringVector = {"Hello" , "Hi" , "Great"};
    std::cout << "Sum of {Hello , Hi , Great} is " << sumFunct<string>(stringVector) << std::endl;
    return 0;
}