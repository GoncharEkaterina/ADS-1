#include <cstdint>
#include "alg.h"
#include <stdlib.h>
#include <iostream>
bool checkPrime(uint64_t value);
uint64_t nPrime(uint64_t n);
uint64_t nextPrime(uint64_t value);
uint64_t sumPrime(uint64_t hbound);

bool checkPrime(uint64_t value) {
    for(long long i=2; i <= sqrt(value); i++)
		if(value % i==0)
			return false;
	return true;
}
uint64_t nPrime(uint64_t n) {
    long long ch = 0;
    for (int num = 0; ; num++) {
        if (checkPrime(num) == true) {
            ch++;
        }
        if (num == n) {
            return num;
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
    long long mean = 0;
    for (int num = 0; num < hbound; num++) {
        mean += i;
        num++;
    }
  return mean;
}

int main () {
    int a = 0;
    std::cin >> a;
    std::cout << checkPrime(a);
    std::cout << nPrime(a);
    std::cout << nextPrime(a);
    std::cout << sumPrime(a);
    
    return 0;
}
