#include <iostream>
#include <string.h>
#include <iomanip>
#include <time.h>

uint64_t fib_r(uint16_t n) {
    if (n < 2) {
        return n;
    } else {
        return fib_r(n-1) + fib_r(n-2);
    }
}

uint64_t fib_i(uint16_t n) {
    uint64_t sum;
    uint64_t prev[] = {0, 1};
    if (n < 2) {
        return n;
    }
    for (uint16_t i = 2 ; i <= n ; i++ ) {
        sum = prev[0] + prev[1];
        prev[0] = prev[1];
        prev[1] = sum;
    }
    return sum;
}

void time_func(uint16_t n, const char *name) {
    uint64_t val;
    clock_t tic, toc;

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
    
    float output = ((float) clock() - tic)/CLOCKS_PER_SEC;

    std::cout << name << "(" << n << "):\t";
    
    std::cout << std::fixed << std::setprecision(4) << "Time: " << output << "\tOutput: " << val << std::endl;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./fib <n> <alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\talgorithm to be used (fib_r or fib_i)\n";
        return 0;
        
    }

    uint16_t n = (uint16_t) atoi(argv[1]);
    time_func(n, argv[2]);
}