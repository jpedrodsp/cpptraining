#include "fibbonaci_iterative.h"

unsigned int FibbonaciIterative::fibbonaci(unsigned int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        unsigned int cached_n1 = 1;
        unsigned int cached_n2 = 1;
        unsigned int aux;
        for (unsigned int i = 3; i <= n; i++)
        {
            aux = cached_n2;
            cached_n2 = cached_n1;
            cached_n1 = aux + cached_n1;
        }

        return cached_n1;
    }
}
