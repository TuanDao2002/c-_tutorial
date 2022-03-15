#include <iostream>
#include <fstream>


int main() {
    char hexArray[] {0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F};

    std::ofstream outfile("insertion_operator.bin", std::ios::out | std::ios::binary);
    if (!outfile) {
        std::cout << "Cannot open file!" << "\n";
        return -1;
    }

    outfile.write(hexArray, 11);

    outfile.close();
    return 0;
}