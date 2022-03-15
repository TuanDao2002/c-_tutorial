#include <iostream>
#include <fstream>


int main() {
    char hexArray[] {0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F};
    int size = sizeof(hexArray)/ sizeof(char);

    // insertion method
    std::ofstream outfile_insert("insertion_operator", std::ios::out | std::ios::binary);
    if (!outfile_insert) {
        std::cout << "Cannot open file!" << "\n";
        return -1;
    }

    for (int i = 0; i < size; i++) {
        outfile_insert << hexArray[i];
    } 

    outfile_insert.close();

    // put method
    std::ofstream outfile_put("put_method", std::ios::out | std::ios::binary);
    if (!outfile_put) {
        std::cout << "Cannot open file!" << "\n";
        return -2;
    }

    for (int j = 0; j < size; j++) {
        outfile_put.put(hexArray[j]);
    }

    outfile_put.close();

    // write method
    std::ofstream outfile_write("write_method", std::ios::out | std::ios::binary);
    if (!outfile_write) {
        std::cout << "Cannot open file!" << "\n";
        return -3;
    }

    outfile_write.write(hexArray, size);
    outfile_write.close();

    return 0;
}