#include <bits/stdc++.h>
using namespace std;

struct param {
    int left;
    int right;
    int access;
};

int binary[500000];
int ternary[500000];

void generate_binary_search(int size) {
    queue<param> q;
    q.push({ 0, size - 1, 0 });

    while (!q.empty()) {
        auto [left, right, access] = q.front();
        q.pop();

        int mid = (left + right) / 2;
        binary[mid] = access;

        if (mid != left) {
            q.push({ left, mid - 1, access + 1 });
        }

        if (mid != right) {
            q.push({ mid + 1, right, access + 1 });
        }
    }
}

void generate_ternary_search(int size) {
    queue<param> q;
    q.push({ 0, size - 1, 0 });

    while (!q.empty()) {
        auto [left, right, access] = q.front();
        q.pop();

        if (right < left) {
            continue;
        }

        int left_third = left + (right - left) / 3;
        int right_third = right - (right - left) / 3;

        ternary[left_third] = access;
        if (right_third != left_third) {
            ternary[right_third] = access + 1;
        }

        q.push({ left, left_third - 1, access + 2 });
        q.push({ left_third + 1, right_third - 1, access + 2 });
        q.push({ right_third + 1, right, access + 2 });
    }
}

void print_results(int size) {
    int less = 0, equal = 0, greater = 0;
    for (int i = 0; i < size; ++i) {
        if (binary[i] < ternary[i]) {
            less++;
        } else if (binary[i] == ternary[i]) {
            equal++;
        } else {
            greater++;
        }
    }
    printf("%d\n%d\n%d", less, equal, greater);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    generate_binary_search(n);
    generate_ternary_search(n);

    print_results(n);
    return 0;
}
