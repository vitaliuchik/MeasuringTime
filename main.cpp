#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void file_read(std::string path);

int main() {
    std::cout << "Hello, World!" << std::endl;
    file_read("nums.txt");
    return 0;
}

void file_read(std::string path) {
    std::vector<int> v;
    std::ifstream  file(path);

    if(!file){
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    int x;
    int sum = 0, n = 0;
    while( file >> x ){
        sum += x;
        ++n;
        v.push_back(x);
    }

    std::cout << "Sum = " << sum << std::endl << "N = " << n << std::endl << "Average = " << sum/n << std::endl;

}
