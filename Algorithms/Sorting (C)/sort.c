#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000

int arr[MAX_N], buf[MAX_N];

void swap(int*, int*);
void sort(int);
void insertion_sort(int);
void selection_sort(int);
void bubble_sort(int);
void merge_sort(int, int);
void quick_sort(int, int);
int partition(int, int, int);
void heap_sort(int);
void heapify(int, int);
void radix_sort(int, int);

int main() {
    srand(time(NULL));
    int n = MAX_N;
    // FILE *g = fopen("in", "w");
    for (int i = 0; i < n; ++i) {
        arr[i] = rand();
        // fprintf(g, "%d\n", arr[i]);
    }

    clock_t begin = clock();

    sort(n);

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    FILE* f = fopen("out", "w");
    fprintf(f, "%d\n", arr[0]);
    for (int i = 1; i < n; ++i) {
        fprintf(f, "%d\n", arr[i]);
        if (arr[i] < arr[i - 1]) {
            puts("Not sorted!");
            exit(1);
        }
    }
    printf("Sorted in %lf ms\n", time_spent * 1000);
    return 0;
}

void sort(int n) {
    // insertion_sort(n);
    // selection_sort(n);
    // bubble_sort(n);
    // merge_sort(0, n);
    // quick_sort(0, n);
    // heap_sort(n);
    // radix_sort(n, 10);
}

void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void insertion_sort(int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j] < arr[j - 1])
                swap(&arr[j - 1], &arr[j]);
        }
    }
}

void selection_sort(int n) {
    for (int i = 0; i < n; ++i) {
        int mi = arr[i], idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < mi) {
                mi = arr[j];
                idx = j;
            }
        }
        swap(&arr[i], &arr[idx]);
    }
}

void bubble_sort(int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void merge_sort(int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid, r);
    int i = l, j = mid, idx = l;
    while (i < mid && j < r) {
        if (arr[i] <= arr[j])
            buf[idx] = arr[i++];
        else
            buf[idx] = arr[j++];
        idx++;
    }
    while (i < mid) {
        buf[idx] = arr[i++];
        idx++;
    }
    while (j < r) {
        buf[idx] = arr[j++];
        idx++;
    }
    for (int x = l; x < r; ++x)
        arr[x] = buf[x];
}

void quick_sort(int l, int r) {
    if (r - l <= 1) return;
    int p = r - 1;
    int k = partition(l, r, p);
    quick_sort(l, k);
    quick_sort(k, r);
}

int partition(int l, int r, int p) {
    int k = l;
    for (int i = l; i < r; ++i) {
        if (arr[i] < arr[p]) {
            swap(&arr[i], &arr[k]);
            k++;
        }
    }
    swap(&arr[k], &arr[p]);
    return k;
}

void heap_sort(int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(i, n);

    for (int i = n - 1; i >= 0; --i) {
        swap(&arr[0], &arr[i]);
        heapify(0, i);
    }
}

void heapify(int i, int n) {
    int max = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[max])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != i) {
        swap(&arr[i], &arr[max]);
        heapify(max, n);
    }
}

void radix_sort(int n, int base) {
    long long d = 1;
    while (1) {
        int* bucket = (int*) calloc(base, sizeof(int));
        for (int i = 0; i < n; ++i)
            bucket[(arr[i] / d) % base]++;
        if (bucket[0] == n) break;
        int prev = 0, next = 0;
        for (int i = 0; i < base; ++i) {
            next += bucket[i];
            bucket[i] = prev;
            prev = next;
        }
        for (int i = 0; i < n; ++i)
            buf[bucket[(arr[i] / d) % base]++] = arr[i];
        for (int i = 0; i < n; ++i)
            arr[i] = buf[i];
        d *= base;
        free(bucket);
    }
}
