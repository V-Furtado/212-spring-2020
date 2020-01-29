#include <iostream>
#include <fstream>
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

float time_func(uint16_t n, const char *name) {
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

    float output = ((float) (toc - tic))/CLOCKS_PER_SEC;
    return output;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./fib <n> <alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\talgorithm to be used (fib_r or fib_i)\n";
        return 0;
    }

    uint16_t Max_Number = (uint16_t) atoi(argv[1]);
    std::ofstream myfile;
    
    myfile.open(std::to_string(Max_Number)+ "_" + (char *)argv[2]+".csv");

    myfile << "input" << "," << "time" << '\n';

    for (int i = 0; i <= Max_Number; i++){
        float function_time = time_func(i, argv[2]);
        myfile << i << "," << std::fixed << std::setprecision(4) << function_time<<'\n';
        
    }
    myfile.close();
    return 0;
}