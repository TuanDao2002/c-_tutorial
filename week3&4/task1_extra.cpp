#include<iostream>
#include<fstream>

bool is_integer(std::string int_str) {
    int len = int_str.length();
    for (int i = 0; i < len; i++) {
        // continue if there is negative sign at the beginning
        if (i == 0 && int_str[i] == '-') {
            continue;
        }

        if (!isdigit(int_str[i])) {
            return false;
        }
    }

    return true;
}

#define ARRAY_MAX 10
int main() {
    using namespace std;
    float arr[ARRAY_MAX];

    // the current length of arr
    unsigned int arr_length = 0; 

    // use string as char* cannot be written to file using cerr
    string input_str;

    fstream error_stream;
    error_stream.open("task1.txt", ios::ate | ios::out);

    // get stream buffer of cerr
    streambuf* cerrbuf = cerr.rdbuf();

    // put file stream to cerr
    cerr.rdbuf(error_stream.rdbuf());

    for (int i = 0; i < 10; i++) {
        cout << "Enter integer number " << i + 1 << " : " ;
        cin >> input_str;

        if (!is_integer(input_str)) {
            cerr << "Invalid: " << input_str << endl;
        } else {
            // add valid float to array and increase the array length
            arr[arr_length++] = stof(input_str);
        }
    }

    // retore back the buffer stream of cerr
    cerr.rdbuf(cerrbuf);

    // close file stream
    error_stream.close();

    for (int j = 0; j < arr_length; j++) {
        cout << "Integer number " << j + 1 << " : " << arr[j] << endl;
    }

    return 0;
}