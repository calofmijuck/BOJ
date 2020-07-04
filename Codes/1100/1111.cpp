#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[55];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> num[i];
    if(n == 1) {
        cout << 'A';
        return 0;
    } else if(n == 2) {
        if(num[0] == num[1])
            cout << num[1];
        else
            cout << 'A';
        return 0;
    }
    ll d1 = num[1] - num[0], d2 = num[2] - num[1], a, b;
    if(d1 == 0) {
        a = 1;
        b = 0;
    } else {
        a = d2 / d1;
        if(d2 % d1 != 0) {
            cout << 'B';
            return 0;
        }
        b = num[1] - a * num[0];
    }
    bool flag = false;
    for(int i = 1; i < n; ++i) {
        if(num[i] != a * num[i - 1] + b) {
            flag = true;
            break;
        }
    }
    if(flag)
        cout << 'B';
    else
        cout << a * num[n - 1] + b;
    return 0;
}