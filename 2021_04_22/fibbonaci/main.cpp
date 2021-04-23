#include <iostream>
#include <vector>
#include "fibbonaci_recursive.h"
#include "fibbonaci_dynamic.h"
#include "fibbonaci_iterative.h"

int main(int argc, char** argv) {
    std::vector<unsigned int> nums {1, 2, 3, 5, 8, 24, 30};

    for (unsigned int num : nums)
    {
        std::cout << "Fibbonaci (recursive) for " << num << " ... ";
        const unsigned int result = FibbonaciRecursive::fibbonaci(num);
        std::cout << result << std::endl;
    }
    for (unsigned int num : nums)
    {
        std::cout << "Fibbonaci (iterative) for " << num << " ... ";
        const unsigned int result = FibbonaciIterative::fibbonaci(num);
        std::cout << result << std::endl;
    }
    for (unsigned int num : nums)
    {
        FIBBONACI_DYNAMIC_STORAGE_TYPE _fibbonaci_dynamic_storage;
        _fibbonaci_dynamic_storage = FibbonaciDynamic::create_fibbonaci_dynamic_storage(num);
        std::cout << "Fibbonaci (dynamic) for " << num << " ... ";
        const unsigned int result = FibbonaciDynamic::fibbonaci(num);
        std::cout << result << std::endl;
    }
    return 0;
}