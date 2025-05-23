#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using Iterator = vector<int>::iterator;

// partition vec[st ... ed] with a random pivot
int random_partition(vector<int>& vec, int st, int ed) {
    int pivot_idx = st + rand() % (ed - st + 1);
    swap(vec[pivot_idx], vec[ed]);

    // Partition
    int i = st - 1;
    for (int j = st; j < ed; ++j) {
        if (vec[j] < vec[ed] || (vec[j] == vec[ed] && j < pivot_idx)) {
            swap(vec[++i], vec[j]);
        }
    }
    swap(vec[++i], vec[ed]);
    return i;
}

// kth smallest element from vec[st ... ed]
int kth(vector<int>& vec, int st, int ed, int k) {
    int pivot = random_partition(vec, st, ed);
    int idx = pivot - st + 1;
    if (idx == k) {
        return vec[pivot];
    } else if (idx > k) {
        return kth(vec, st, pivot - 1, k);
    } else {
        return kth(vec, pivot + 1, ed, k - idx);
    }
}

int kth(vector<int>& vec, int k) {
    return kth(vec, 0, vec.size() - 1, k);
}
