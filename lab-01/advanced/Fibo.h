#ifndef FIBO_H
#define FIBO_H

#include <iostream>

class Fibo
{
public:
    static uint64_t fib_r(uint16_t n);
    static uint64_t fib_i(uint16_t n);
    static double time_func(uint16_t n, const char *name, uint64_t *sum);
};

#endif // FIBO_H
