#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>
#include <chrono>
#include <atomic>

inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D& d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}


std::vector<int> file_read(const std::string& path);
void sstream_convert(std::vector<int> *int_v, std::string *str_arr);
void to_string_convert(std::vector<int> *int_v, std::string *str_arr);


int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cerr << "Error input arguments" << std::endl;
    }



    std::vector<int> int_v;
    int_v = file_read(argv[2]);
    int length = int_v.size();
    auto* str_arr = new std::string[length];

    std::chrono::high_resolution_clock::time_point start_time, finish_time;
    if (std::stoi(argv[1]) == 1) {
        start_time = get_current_time_fenced();
        sstream_convert(&int_v, str_arr);
        finish_time = get_current_time_fenced();
    }
    if (std::stoi(argv[1]) == 2) {
        start_time = get_current_time_fenced();
        to_string_convert(&int_v, str_arr);
        finish_time = get_current_time_fenced();
    }

    std::cout << to_us(finish_time - start_time) <<  std::endl;

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




