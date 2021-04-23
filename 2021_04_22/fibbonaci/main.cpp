#include <iostream>
#include <vector>
#include "fibbonaci_recursive.h"
#include "fibbonaci_dynamic.h"
#include "fibbonaci_iterative.h"

void benchmark_recursive(std::vector<unsigned int>& fibnums)
{
    for (unsigned int num : fibnums)
    {
        std::cout << "Fibbonaci (recursive) for " << num << " ... ";
        const unsigned int result = FibbonaciRecursive::fibbonaci(num);
        std::cout << result << std::endl;
    }
}
void benchmark_iterative(std::vector<unsigned int>& fibnums)
{
    for (unsigned int num : fibnums)
    {
        std::cout << "Fibbonaci (iterative) for " << num << " ... ";
        const unsigned int result = FibbonaciIterative::fibbonaci(num);
        std::cout << result << std::endl;
    }
}
void benchmark_dynamic(std::vector<unsigned int>& fibnums)
{
    for (unsigned int num : fibnums)
    {
        FIBBONACI_DYNAMIC_STORAGE_TYPE _fibbonaci_dynamic_storage;
        _fibbonaci_dynamic_storage = FibbonaciDynamic::create_fibbonaci_dynamic_storage(num);
        std::cout << "Fibbonaci (dynamic) for " << num << " ... ";
        const unsigned int result = FibbonaciDynamic::fibbonaci(num);
        std::cout << result << std::endl;
    }
}

int main(int argc, char** argv) {
    std::vector<unsigned int> nums {1, 2, 3, 5, 8, 24, 30};
    benchmark_recursive(nums);
    benchmark_iterative(nums);
    benchmark_dynamic(nums);
    return 0;
}