#include "Fibo.h"
#include <cstring>
#include <ctime>

//Algorithm 1 for Fibonacci**
uint64_t Fibo::fib_r(uint16_t n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return fib_r(n-1) + fib_r(n-2);
    }
}

//Algorithm 2 for Fibonacci**
uint64_t Fibo::fib_i(uint16_t n)
{
    uint64_t sum = 0u;
    uint64_t prev[] = {0, 1};
    if (n < 2)
    {
        return n;
    }
    for (uint16_t i = 2 ; i <= n ; i++ ) {
        sum = prev[0] + prev[1];
        prev[0] = prev[1];
        prev[1] = sum;
    }
    return sum;
}

double Fibo::time_func(uint16_t n, const char *name, uint64_t* sum)
{
    uint64_t val = 0u;
    clock_t tic = 0, toc;

    if (! strcmp(name, "fib_r")) {
        tic = clock();
        val = fib_r(n);
        toc = clock();

    }
    if (! strcmp(name, "fib_i")) {
        tic = clock();
        val = fib_i(n);
        toc = clock();

    }
    if (sum != nullptr)
        *sum = val;

    double output = (static_cast<double>(clock()) - tic) / CLOCKS_PER_SEC;
    return output;
}
