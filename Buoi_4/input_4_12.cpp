#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outfile("data_test4_4_12.txt");
    if (!outfile.is_open()) {
        return 1;
    }

    for (int i =1; i<=490000; i++){
        outfile << "100" << " ";
    }
    outfile.close();
    return 0;
}
