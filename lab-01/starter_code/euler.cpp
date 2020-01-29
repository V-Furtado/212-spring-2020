#include <iostream>
#include <string.h>
#include <iomanip>
#include <time.h>

long double euler1(int n) {
    long double sum = 0;
    long double fact;
    for (int i = 0 ; i <= n ; i ++) {
        fact = 1;
        for (int j = 2 ; j <= i ; j++) {
            fact *= j;
        }
        sum += (1.0 / fact);
    }

    return sum;
}

long double euler2(int n) {
    long double sum = 0;
    long double fact = 1;

    for (int i = 0 ; i <= n ; i++) {
        sum += (1.0 / fact);
        fact *= (i+1);
    }

    return sum;
}

void time_func(uint16_t n, const char *name) {
    long double val;
    clock_t tic, toc;

    if (! strcmp(name, "euler1")) {
        tic = clock();
        val = euler1(n);
        toc = clock();
        
    }
    if (! strcmp(name, "euler2")) {
        tic = clock();
        val = euler2(n);
        toc = clock();
        
    }
    
    float output = ((float)(toc - tic)) / CLOCKS_PER_SEC;

    std::cout << name << "(" << n << "):\t";
    
    std::cout << std::fixed << std::setprecision(4) << "Time: " << output << "\tOutput: " << val << std::endl;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./euler <n> <alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\talgorithm to be used (euler1 or euler2)\n";
        return 0;
        
    }

    uint16_t n = (uint16_t) atoi(argv[1]);
    time_func(n, argv[2]);
}