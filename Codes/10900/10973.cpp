#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
    int idx = n - 1;
    for(; idx > 0 && vec[idx] >= vec[idx - 1]; idx--);
    if(idx <= 0) {
        cout << -1;
        return 0;
    }
    int j = idx - 1;
    while(j + 1 <= n - 1 && vec[j + 1] <= vec[idx - 1]) j++;
    swap(vec[idx - 1], vec[j]);
    reverse(vec.begin() + idx, vec.end());
    for(int i = 0; i < n; ++i) cout << vec[i] << ' ';
    return 0;
}
