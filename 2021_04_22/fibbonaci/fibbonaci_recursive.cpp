#include "fibbonaci_recursive.h"

unsigned int FibbonaciRecursive::fibbonaci(unsigned int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return FibbonaciRecursive::fibbonaci(n - 1) + FibbonaciRecursive::fibbonaci(n - 2);
    }
}