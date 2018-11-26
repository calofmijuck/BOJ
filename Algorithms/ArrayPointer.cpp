/*
    This is an example code to pass 1D, 2D array to a function as a parameter.
    When passing 2D array as a parameter, if you will use int* for the type,
    you must cast it to a int*, or use the address of element arr[0][0].

    Ex)
    int arr[10][10];
    foo((int *) arr);
    or
    foo(&arr[0][0]);
*/
#include <bits/stdc++.h>
using namespace std;

void copy1D(int* src, int* dst, int n) {
    for(int i = 0; i < n; ++i) {
        dst[i] = src[i];
    }
}

void copy2D(int* src, int* dst, int n, int m) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            *(dst + m * i + j) = *(src + m * i + j);
        }
    }
}

void print2D(int* dst, int n, int m) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%2d ", *(dst + m * i + j));
        }
        puts("");
    }
}

int main() {
    int n = 10, m = 10;
    // int arr[n], dst[n];
    // for(int i = 0; i < n; ++i) {
    //     arr[i] = 2 * i + 1;
    // }
    // copy1D(arr, dst, n);
    // for(int i = 0; i < n; ++i) {
    //     printf("%d ", dst[i]);
    // }
    int arr[n][m], dst[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            arr[i][j] = i + j;
        }
    }
    copy2D(&arr[0][0], &dst[0][0], n, m);
    print2D(&dst[0][0], n, m);
    return 0;
}
