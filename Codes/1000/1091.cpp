#include <bits/stdc++.h>
using namespace std;

int mix[50], card[50];

void shuffleCards(int n) {
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        v[mix[i]] = card[i];
    for(int i = 0; i < n; ++i)
        card[i] = v[i];
}

bool check(int n) {
    for(int i = 0; i < n; ++i) {
        if(card[i] != (i % 3))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> card[i];
    for(int i = 0; i < n; ++i)
        cin >> mix[i];
    int cnt = 0;
    for(; cnt < 2e5; ++cnt) {
        if(check(n)) {
            cout << cnt;
            return 0;
        }
        shuffleCards(n);
    }
    cout << -1;
    return 0;
}