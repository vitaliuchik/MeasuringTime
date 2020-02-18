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
inline void sstream_convert(std::vector<int> *int_v, std::string *str_arr);
inline void to_string_convert(std::vector<int> *int_v, std::string *str_arr);
inline void custom_itos(std::vector<int> *int_v, std::string *str_arr);


int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cerr << "Error input arguments" << std::endl;
        return 1;
    }

    std::vector<int> int_v;
    int_v = file_read(argv[2]);
    int length = int_v.size();
    auto *str_arr = new std::string[length];
//    std::string str_arr[length];

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
    if (std::stoi(argv[1]) == 3) {
        start_time = get_current_time_fenced();
        custom_itos(&int_v, str_arr);
        finish_time = get_current_time_fenced();
    }

    std::cout << to_us(finish_time - start_time) <<  std::endl;

//    int len = 0;
//    for (std::string &word: *str_arr) {
//        std::cout << word << std::endl;
//        len += word.length();
//    }

    int len = 0;
    for (int i = 0; i < length; ++i) {
        len += str_arr[i].length();
    }

    std::ofstream file(argv[3]);
    if(!file){
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }
    file << len << std::endl << (double)len/length << std::endl;
    file.close();

    return 0;
}

std::vector<int> file_read(const std::string& path) {
    std::vector<int> v;
    std::ifstream file(path);

    if(!file){
        std::cerr << "Error opening input file" << std::endl;
        return v;
    }

    int x;
    while( file >> x )
        v.push_back(x);
    file.close();
    return v;
}

inline void sstream_convert(std::vector<int> *int_v, std::string *str_arr){
    int i = 0;
    std::stringstream ss;
    for (int num: *int_v) {
        ss << num;
        ss >> str_arr[i];
        ss.clear();
        i++;
    }
}

inline void to_string_convert(std::vector<int> *int_v, std::string *str_arr){
    int i = 0;
    for (int num: *int_v) {
        str_arr[i] = std::to_string(num);
        i++;
    }
}

inline void custom_itos(std::vector<int> *int_v, std::string *str_arr){
    int i = 0;
    for (int num: *int_v) {

        if (num == 0) {
            str_arr[i] = "0";


        }
        else {
            str_arr[i]  = "";
            while (num > 0) {
                str_arr[i] += (num % 10) + '0'; // converting int to char
                num /= 10;

            }

        }
        ++i;

    }
}






