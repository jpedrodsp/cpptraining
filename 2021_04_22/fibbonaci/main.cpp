#include <iostream>
#include <vector>
#include <chrono>
#include "fibbonaci_recursive.h"
#include "fibbonaci_dynamic.h"
#include "fibbonaci_iterative.h"

void benchmark_recursive(std::vector<unsigned int>& fibnums)
{
    std::chrono::steady_clock::time_point timer_start, timer_end;
    int64_t diff;
    for (unsigned int num : fibnums)
    {
        std::cout << "Fibbonaci (recursive) for " << num << " ... ";
        timer_start = std::chrono::steady_clock::now();
        const unsigned int result = FibbonaciRecursive::fibbonaci(num);
        timer_end = std::chrono::steady_clock::now();
        diff = std::chrono::duration_cast<std::chrono::microseconds>(timer_end - timer_start).count();
        std::cout << result;
        std::cout << " - " << diff << "[µs]" << std::endl;
    }
}
void benchmark_iterative(std::vector<unsigned int>& fibnums)
{
    std::chrono::steady_clock::time_point timer_start, timer_end;
    int64_t diff;
    for (unsigned int num : fibnums)
    {
        std::cout << "Fibbonaci (iterative) for " << num << " ... ";
        timer_start = std::chrono::steady_clock::now();
        const unsigned int result = FibbonaciIterative::fibbonaci(num);
        timer_end = std::chrono::steady_clock::now();
        diff = std::chrono::duration_cast<std::chrono::microseconds>(timer_end - timer_start).count();
        std::cout << result;
        std::cout << " - " << diff << "[µs]" << std::endl;
    }
}
void benchmark_dynamic(std::vector<unsigned int>& fibnums)
{
    std::chrono::steady_clock::time_point timer_start, timer_end;
    int64_t diff;
    for (unsigned int num : fibnums)
    {
        FIBBONACI_DYNAMIC_STORAGE_TYPE _fibbonaci_dynamic_storage;
        _fibbonaci_dynamic_storage = FibbonaciDynamic::create_fibbonaci_dynamic_storage(num);
        std::cout << "Fibbonaci (dynamic) for " << num << " ... ";
        timer_start = std::chrono::steady_clock::now();
        const unsigned int result = FibbonaciDynamic::fibbonaci(num, _fibbonaci_dynamic_storage);
        timer_end = std::chrono::steady_clock::now();
        diff = std::chrono::duration_cast<std::chrono::microseconds>(timer_end - timer_start).count();
        std::cout << result;
        std::cout << " - " << diff << "[µs]" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::vector<unsigned int> nums {1, 2, 3, 5, 8, 24, 30};
    benchmark_recursive(nums);
    benchmark_iterative(nums);
    benchmark_dynamic(nums);
    return 0;
}