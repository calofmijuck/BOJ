#include <bits/stdc++.h>
using namespace std;

vector<int> compute_prefix_sum(vector<int>& numbers) {
    vector<int> prefix_sum(numbers.size());
    for (int i = 1; i <= (int) numbers.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + numbers[i];
    }
    return prefix_sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> numbers(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> numbers[i];
    }

    vector<int> prefix_sum = compute_prefix_sum(numbers);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int left, right;
        cin >> left >> right;
        cout << prefix_sum[right] - prefix_sum[left - 1] << '\n';
    }
    return 0;
}
