#include <bits/stdc++.h>

using namespace std;

tuple<int, int*, int> merge_and_count(int* arr1, int n1, int* arr2, int n2) {
    //cout << n1 << endl << n2 << endl;
    int i = 0;
    int j = 0;
    int* arr = (int*)malloc(sizeof(int) * (n1 + n2));
    long long r = 0;
    for (int k=0; k<n1+n2; k++) {
        if (i == n1) {
            arr[k] = arr2[j];
            j++;
        } else
        if (j == n2) {
            arr[k] = arr1[i];
            i++;
        } else
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
            r += n1-i;
        }
    }
    //cout << "ans after merge: " << r << endl;
    return make_tuple(r, arr, n1+n2);
}

tuple<long long, int*, int> sort_and_count(int* arr, int n) {
    if (n == 1) {
        return make_tuple(0, arr, n);
    }
    tuple<long long, int*, int> t1 = sort_and_count(arr, n/2);
    tuple<long long, int*, int> t2 = sort_and_count(arr+(n/2), n%2==0? n/2 : n/2+1);
    tuple<long long, int*, int> t12 = merge_and_count(get<1>(t1), get<2>(t1), get<1>(t2), get<2>(t2));
    return make_tuple(get<0>(t1) + get<0>(t2) + get<0>(t12), get<1>(t12), get<2>(t12));
}

int main() {
    // init input stream and open file
    ifstream f;
    f.open("../test.inp");

    // n is const
    int n = 100000;

    // read array from file
    int* arr = (int*) malloc(sizeof(int) * n);
    for (int i=0; i<n; i++) f >> arr[i];

    cout << get<0>(sort_and_count(arr, n))<<endl;

    // close stream
    f.close();
    return 0;
}