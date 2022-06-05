#include <bits/stdc++.h>
using namespace std;

int fib_calls(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    int prev = 1, curr = 1;
    int next;
    for (int i = 3; i <= n; ++i) {
        next = curr + prev;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << fib_calls(n) << ' ' << n - 2;
    return 0;
}
