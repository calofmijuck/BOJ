#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(int i, int j, int n) {
    ll k = i + j - 1;
    if(k > n) {
        k = 2 * n - 1 - k;
        ll val = k * (k + 1) / 2 + ((k & 1) ? (n - i) : (n - j));
        return (ll) n * n - val;
    } else {
        ll val = k * (k - 1) / 2;
        return val + ((k & 1) ? j : i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    string str;
    cin >> n >> k >> str;
    int i = 1, j = 1;
    ll sum = 1;
    for(int x = 0; x < str.size(); ++x) {
        char c = str[x];
        if(c == 'D') ++i;
        else if(c == 'U') --i;
        else if(c == 'R') ++j;
        else if(c == 'L') --j;
        sum += calc(i, j, n);
    }
    cout << sum;
    return 0;
}