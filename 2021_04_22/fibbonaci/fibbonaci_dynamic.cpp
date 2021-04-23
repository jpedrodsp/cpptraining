#include "fibbonaci_dynamic.h"

FIBBONACI_DYNAMIC_STORAGE_TYPE FibbonaciDynamic::create_fibbonaci_dynamic_storage(const unsigned int capacity = 2)
{
    FIBBONACI_DYNAMIC_STORAGE_TYPE fibbonaci_dynamic_storage = FIBBONACI_DYNAMIC_STORAGE_TYPE();
    if (capacity > 2)
    {
        fibbonaci_dynamic_storage.reserve(capacity);
    }
    else
    {
        fibbonaci_dynamic_storage.reserve(2);
    }
    fibbonaci_dynamic_storage[0] = 1;
    fibbonaci_dynamic_storage[1] = 1;

    return fibbonaci_dynamic_storage;
}

unsigned int FibbonaciDynamic::fibbonaci(const unsigned int n, FIBBONACI_DYNAMIC_STORAGE_TYPE& _dynamic_storage)
{
    const unsigned int fibbonaci_stored_value = _dynamic_storage.at(n - 1);
    if (fibbonaci_stored_value == 0)
    {
        _dynamic_storage[n - 1] = FibbonaciDynamic::fibbonaci(n - 1, _dynamic_storage) + FibbonaciDynamic::fibbonaci(n - 2, _dynamic_storage);
    }
    return _dynamic_storage[n - 1];
}