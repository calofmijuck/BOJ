#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cards(m);
    vector<bool> used(m, false);
    for(int i = 0; i < m; ++i)
        cin >> cards[i];
    sort(cards.begin(), cards.end());
    for(int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        int idx = upper_bound(cards.begin(), cards.end(), x) - cards.begin();
        while(used[idx])
            idx++;
        cout << cards[idx] << '\n';
        used[idx] = true;
    }
    return 0;
}