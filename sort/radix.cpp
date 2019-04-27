#ifndef __RADIX_CPP___
#define __RADIX_CPP___

//#include "counting.cpp"
#include <algorithm>
#include <iostream>
#include "counting.cpp"

using namespace std;

/*
*   Radix sort algorithm
*   d: amount of digit
*   Principle: sort from least significant digit to most significant digit
*/

/*
* Number of digit 
* @param an integer
*/
int digitNum(int n) {
    int res = 0;
    while (n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

/*
* Funtion use when compare two 
* @param array a
* @param number of element
* @return sorted array
*/

static int radixBase = 1;
int keyFunction(int &element) {
    return (element / radixBase) % 10;
}

void radixSort(int a[], int n) {
    /* caculate d */
    int d = 0;
    for (int i = 0; i < n; i++) d = max(d, digitNum(a[i]));

    for (int i = 1; i <= d; i++) {
        // implement sort
        countingSortWithKey(a, n, keyFunction);
        radixBase *= 10;
    }
}

#endif


int main(int argc, char* argv[]) {
    int a[5] = {199,389,21,555,40};
    radixSort(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
}
