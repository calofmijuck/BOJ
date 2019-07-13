#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> prob;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, k, e, h;
    cin >> n >> l >> k;
    for(int i = 0; i < n; ++i) {
        cin >> e >> h;
        prob.push_back({e, h});
    }
    ll score = 0;
    int tmp = 0;
    for(int i = 0; k != 0 && i < n; ++i) {
        pii curr = prob[i];
        if(curr.second <= l) {
            score += 140;
            k--;
        } else if(curr.first <= l) tmp++;
    }
    score += min(tmp, k) * 100;
    cout << score;
    return 0;
}
