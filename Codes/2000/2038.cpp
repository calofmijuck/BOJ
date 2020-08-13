#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> G;

ll getG(int n) {
    vector<int>::iterator it = upper_bound(G.begin(), G.end(), n);
    int idx = it - G.begin();
    return idx - 1;
}

int main() {
    ll n;
    scanf("%lld", &n);
    G.push_back(0); G.push_back(1);
    ll idx = 1, i = 1, num = 2;
    while(idx < n) {
        int k = getG(i);
        for(int x = 1; x <= k; ++x) {
            idx += i;
            G.push_back(idx);
        }
        i++;
    }
    printf("%lld ", getG(n));
    return 0;
}