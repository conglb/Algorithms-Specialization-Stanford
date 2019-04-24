#ifndef __COUNTING__CPP__
#define __COUNTING__CPP__
#include <algorithm>

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

    int c[k+1];
    int b[n+1];
    /* init array c */
    for (int i = 0; i < n; i++) c[a[i]]++;
    /* accumulate array c */
    for (int i = 1; i <= k; i++) c[i] = c[i-1] + c[i];

    /* construct array b */
    for (int i = n-1; i >= 0; i--) { b[c[a[i]] - 1] = a[i]; c[a[i]]--; }

    /* copy b to a */
    for (int i = 0; i < n; i++) a[i] = b[i];
}

#endif