#include <bits/stdc++.h>
using namespace std;

int arr[1010];

// Bubble Sort
int main() {
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
