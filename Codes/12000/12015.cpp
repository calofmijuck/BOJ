#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;
    vector<int> lis;
    lis.push_back(-1);
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(lis.back() < x) lis.push_back(x);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            *it = x;
        }
    }
    cout << lis.size() - 1;
    return 0;
}
