// Algorithm to select kth element from an array
// Selects pivot and partitions the array
// Takes O(n) time on average
// But in worst case, O(n^2)

#include <bits/stdc++.h>
using namespace std;

int arr[505050];

// paritions the array
// bool random parameter for randomized pivot
// Use last element of array as pivot by default
int partition(int st, int ed, bool random) {
    srand(time(NULL));
    int tmp; // for swaps
    if(random) { // random
        int pIdx = st + rand() % (ed - st + 1);
        tmp = arr[ed];
        arr[ed] = arr[pIdx];
        arr[pIdx] = tmp;
    }
    int x = arr[ed]; // pivot element
    int i = st - 1;
    for(int j = st; j < ed; ++j) {
        if(arr[j] <= x) {
            // increment i then swap arr[i] and arr[j]
            tmp = arr[j];
            arr[j] = arr[++i];
            arr[i] = tmp;
        }
    }
    tmp = arr[++i];
    arr[i] = arr[ed];
    arr[ed] = tmp;
    return i;
}

// selects kth element from arr[st ... ed]
int kth(int st, int ed, int k) {
    if(st == ed) return arr[st];
    int pivot = partition(st, ed, true);
    int idx = pivot - st + 1;
    // search left
    if(k < idx) return kth(st, pivot - 1, k);
    // search right
    else if(k > idx) return kth(pivot + 1, ed, k - idx);
    // found kth element
    else return arr[pivot];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    printf("%d", kth(0, n - 1, k));
    return 0;
}
