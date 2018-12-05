
#include "sieve.h"

// for size_t
#include <cstring>
#include <algorithm>
#include <iostream>


std::vector<int> sieve::primes(const int n) {

    constexpr int startindex = 2;
    std::vector<bool> current_sieve(n+1);
    // 0 & 1 are not prime
    current_sieve[0] = true;
    current_sieve[1] = true;

    int c_index = startindex;

    // sieve via erathosthenes
    while (c_index <= n) {
        // colour in all future multiples of this number
        for (int colouring_index = c_index+c_index; colouring_index <= n;  colouring_index += c_index) {
            current_sieve[colouring_index] = true;
        }

        // fast forward until the next prime
        while (c_index <= n && current_sieve[++c_index] != false);
    }

    // populate return array with all elements that haven't been coloured (i.e. == false)
    std::vector<int> ret_sieve;
    for (int i = 0; i < static_cast<int>(current_sieve.size()); ++i) {
        if (!current_sieve[i]) ret_sieve.push_back(i);
    }

    return ret_sieve;
}
