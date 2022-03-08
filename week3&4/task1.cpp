#include<iostream>
#include<fstream>

bool is_float(std::string float_str) {
    int len = float_str.length();
    bool dot_flag = false;
    for (int i = 0; i < len; i++) {
        // continue if there is negative sign at the beginning
        if (i == 0 && float_str[i] == '-') {
            continue;
        }

        if (!dot_flag && i != 0 && i != len - 1 && float_str[i] == '.') {
            dot_flag = true;
            continue;
        }

        if (!isdigit(float_str[i])) {
            return false;
        }
    }

    return dot_flag;
}

#define ARRAY_MAX 10
int main(){
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
        cout << "Enter float number " << i + 1 << " : " ;
        cin >> input_str;

        if (!is_float(input_str)) {
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
        cout << "Float number " << j + 1 << " : " << arr[j] << endl;
    }

    return 0;
}