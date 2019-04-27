//#ifndef __COUNTING__CPP__
//#define __COUNTING__CPP__
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

/*
*
*   Counting sort algorithm
*   @para: a[1..n]
*   @vari: b[1..n] hold sorted array
*   c[1..k] provides temprary working storage
*
*/

void countingSort(int a[], int n) {
    /* k is the max of array */
    int k = 0;
    for (int i = 0; i < n; i++) k = max(k, a[i]);

    int c[k+1]; memset(c, 0, sizeof(c));
    int b[n];
    /* init array c */
    for (int i = 0; i < n; i++) c[a[i]]++;
    /* accumulate array c */
    for (int i = 1; i <= k; i++) c[i] = c[i-1] + c[i];

    /* construct array b */
    for (int i = n-1; i >= 0; i--) { b[c[a[i]] - 1] = a[i]; c[a[i]]--; }

    /* copy b to a */
    for (int i = 0; i < n; i++) a[i] = b[i];
}

int default_key_func(int &element) {
    return element;
}

void countingSortWithKey(int a[], int n, int (key(int &element))= &default_key_func) {
    /* k is the max of array */
    int k = 0;
    for (int i = 0; i < n; i++) k = max(k, key(a[i]));
    int c[k+1]; memset(c, 0, sizeof(c));
    int b[n];

    /* init array c */
    for (int i = 0; i < n; i++) c[key(a[i])]++;
    /* accumulate array c */
    for (int i = 1; i <= k; i++) c[i] = c[i-1] + c[i];
    /* construct array b */
    for (int i = n-1; i >=0; i--) {
        b[c[key(a[i])] - 1] = a[i];
        c[key(a[i])]--;
    }

    /* copy b to a */
    for (int i = 0; i < n; i++) a[i] = b[i];
}

//#endif

/* TESTING */
int testKeyFunction(int &element) {
    return 5-element;
}

/*
int main() {
    int a[5] = {5,2,3,1,4};
    countingSortWithKey(a, 5, testKeyFunction);
    for (int i = 0; i < 5; i++) {
        //assert(i == a[i]-1);
        cout << a[i] << endl;
    }
}
*/
