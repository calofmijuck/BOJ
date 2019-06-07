#include <bits/stdc++.h>
using namespace std;

int str[100], n;

void solve(int idx) {
    for(int i = 1; i <= idx / 2; ++i) {
        if(equal(str + idx - i, str + idx, str + idx - 2 * i)) return;
    }
    if(idx == n) {
        for(int i = 0; i < n; ++i) printf("%d", str[i]);
        exit(0);
    }
    for(int i = 1; i < 4; ++i) {
        str[idx] = i;
        solve(idx + 1);
    }
}

int main() {
    cin >> n;
    solve(0);
    return 0;
}
