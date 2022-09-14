#include <bits/stdc++.h>
using namespace std;

int calculate(vector<int>& phone) {
    int usage = 0;
    int prev = 0, prev_usage = 0;
    for (int curr : phone) {
        if (curr != prev) {
            prev_usage = 2;
        } else {
            prev_usage *= 2;
        }
        usage += prev_usage;
        prev = curr;

        if (usage >= 100) {
            usage = 0;
            prev_usage = 0;
            prev = 0;
        }
    }
    return usage;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> phone(n);
    for (int i = 0; i < n; ++i) {
        cin >> phone[i];
    }

    cout << calculate(phone);
    return 0;
}
