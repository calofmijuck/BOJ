// kth smallest element in O(n) time
// Using median of medians as pivot
// Assuming that all elements are distinct

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int arr[5050505];

// finding median in a small array
int median(int arr[], int n) {
    sort(arr, arr + n);
    return arr[n / 2];
}

// partition arr[st ... ed] with x as pivot
int partition(int arr[], int st, int ed, int x) {
    int i, tmp;
    // search for x in arr, and move it to the end
    for(i = st; i < ed; ++i) {
        if(arr[i] == x) break;
    }
    tmp = arr[ed];
    arr[ed] = arr[i];
    arr[i] = tmp;

    // Partition
    i = st - 1;
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

// kth smallest element from arr[st ... ed]
int kth(int arr[], int st, int ed, int k) {
    int n = ed - st + 1;
    int i, med[(n + 4) / 5]; // divide into ceil(n / 5) groups
    for(i = 0; i < n / 5; ++i) {
        med[i] = median(arr + st + 5 * i, 5);
    }
    if(5 * i < n) { // last group
        med[i] = median(arr + st + 5 * i, n % 5);
        ++i;
    }
    // choose median of medians
    int medOfMed = (i == 1) ? med[i - 1] : kth(med, 0, i - 1, i / 2);
    int pivot = partition(arr, st, ed, medOfMed);
    int idx = pivot - st + 1;
    // found
    if(idx == k) return arr[pivot];
    // search left
    else if(idx > k) return kth(arr, st, pivot - 1, k);
    // search right
    else return kth(arr, pivot + 1, ed, k - idx);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    printf("%d", kth(arr, 0, n - 1, k));
    return 0;
}
