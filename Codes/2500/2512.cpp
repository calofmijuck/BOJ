#include <bits/stdc++.h>
using namespace std;

int calculate_budget(vector<int>& budget, int x) {
    int sum = 0;
    for (int e : budget) {
        sum += min(e, x);
    }
    return sum;
}

int binary_search(vector<int>& budget, int total, int max_budget) {
    int left = 0, right = max_budget;
    while (left < right) {
        int mid = (left + right) / 2;
        int sum = calculate_budget(budget, mid);
        if (sum > total) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, total;
    cin >> n;
    vector<int> budget;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        budget.push_back(x);
    }
    cin >> total;

    int sum = 0, max_budget = 0;
    for (int e : budget) {
        sum += e;
        max_budget = max(max_budget, e);
    }

    if (sum <= total) {
        cout << max_budget;
    } else {
        cout << binary_search(budget, total, max_budget);
    }
    return 0;
}
