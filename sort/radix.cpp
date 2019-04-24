#ifndef __RADIX_CPP___
#define __RADIX_CPP___

#include "counting.cpp"

/*
*   Radix sort algorithm
*   d: amount of digit
*   Principle: sort from least significant digit to most significant digit
*/

int digitNum(int n) {
    int res = 0;
    while (n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

void radixSort(int a[], int n) {
    /* caculate d */
    int d = 0;
    for (int i = 0; i < n; i++) d = max(d, digitNum(a[i]));

    for (int i = 1; i <= d; i++) {
        // implement sort
    }
}

#endif