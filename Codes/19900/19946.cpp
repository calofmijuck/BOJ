#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int pop_count(ull x) {
    int ret = 0;
    while(x > 0) {
        ret += (x & 1);
        x >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ull n;
    cin >> n;
    int x = pop_count(n);
    cout << x;
    return 0;
}