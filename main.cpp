#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


std::vector<int> file_read(const std::string& path);
void sstream_convert(std::vector<int> *int_v, std::string *str_arr);
void to_string_convert(std::vector<int> *int_v, std::string *str_arr);


int main() {
    std::vector<int> int_v;
    int_v = file_read("nums.txt");
    int length = int_v.size();
    auto* str_arr = new std::string[length];

//    sstream_convert(&int_v, str_arr)
    to_string_convert(&int_v, str_arr);

    std::cout << str_arr[0] << str_arr[1] << str_arr[2] << str_arr[3] << std::endl;

    return 0;
}

std::vector<int> file_read(const std::string& path) {
    std::vector<int> v;
    std::ifstream file(path);

    if(!file){
        std::cerr << "Error opening file" << std::endl;
        return v;
    }

    int x;
    while( file >> x )
        v.push_back(x);

    return v;
}

void sstream_convert(std::vector<int> *int_v, std::string *str_arr){
    int i = 0;
    std::stringstream ss;
    for (int num: *int_v) {
        ss << num;
        ss >> str_arr[i];
        ss.clear();
        i++;
    }
}

void to_string_convert(std::vector<int> *int_v, std::string *str_arr){
    int i = 0;
    for (int num: *int_v) {
        str_arr[i] = std::to_string(num);
        i++;
    }
}


