// Copyright 2022 NNTU-CS
#include "alg.h"
#include <math.h>
#include <cstdint>
#include <iostream>

bool checkPrime(uint64_t value);
uint64_t nPrime(uint64_t n);
uint64_t nextPrime(uint64_t value);
uint64_t sumPrime(uint64_t hbound);

bool checkPrime(uint64_t value) {
    if (value == 0 or value == 1) {
        return false;
    }
    for (uint64_t i = 2; i <= sqrt(value); i++)
                if (value % i == 0)
                    return false;
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t ch = 0;
    for (int i = 0; ; i++) {
        if (checkPrime(i) == true) {
            ch++;
        }
        if (ch == n) {
            return i;
        } else { continue; }
    }
    return 0;
}

uint64_t nextPrime(uint64_t value) {
    while (true) {
        if (checkPrime(++value) == true)
          return value;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t mean = 0;
    for (int num = 2; num < hbound; num++) {
            if (checkPrime(num) == true) {
                mean += num;
            }
    }
  return mean;
}

int main() {
    int a = 0;
    std::cin >> a;
    std::cout << checkPrime(a) << std::endl;
    std::cout << nPrime(a) << std::endl;
    std::cout << nextPrime(a) << std::endl;
    std::cout << sumPrime(a) << std::endl;
    return 0;
}
