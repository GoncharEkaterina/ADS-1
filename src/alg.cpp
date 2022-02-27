// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
bool checkPrime(long long value);
uint64_t nPrime(uint64_t n);
uint64_t nextPrime(uint64_t value);
uint64_t sumPrime(uint64_t hbound);

int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
}

long long proverka(long long x, long long y, long long z) {
    if (y == 1)
      return x;
    if (y % 2 == 0) {
      long long t = proverka(x, y / 2, z);
      return (2 * t) % z;
    }
  return (proverka(x, y - 1, z) + x) % z;
}

long long steps(long long x, long long y, long long z) {
    if (y == 0)
      return 1;
    if (y % 2 == 0) {
      long long t = steps(x, y / 2, z);
      return proverka(t, t, z) % z;
    }
  return (proverka(steps(x, y - 1, z), x, z) % z);
}

bool checkPrime(uint64_t value) {
    if (value == 2)
      return true;
    srand(static_cast<unsingned int>(time(NULL)));
    for (int i = 0; i < 100; i++) {
        long long zh = (rand() % (value - 2)) + 2;
        if (gcd(zh, value) != 1)
          return false;
        if (steps(zh, value - 1, value) != 1)
          return false;
    }
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
