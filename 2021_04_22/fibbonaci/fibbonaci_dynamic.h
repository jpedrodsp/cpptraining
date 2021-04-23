#pragma once
#include <vector>

typedef std::vector<unsigned int> FIBBONACI_DYNAMIC_STORAGE_TYPE;

/*!
*   Fibbonaci Algorithm (Dynamic Programming)
*/
class FibbonaciDynamic {
    private:
    public:
    static FIBBONACI_DYNAMIC_STORAGE_TYPE create_fibbonaci_dynamic_storage(const unsigned int capacity);
    static unsigned int fibbonaci(const unsigned int n, FIBBONACI_DYNAMIC_STORAGE_TYPE& _dynamic_storage);
};