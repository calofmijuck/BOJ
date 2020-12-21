#include <bits/stdc++.h>
using namespace std;

int cheat_on_card(int idx, int last_card, vector<int>& odd_psum, vector<int>& even_psum) {
    int score = 0, n = (int) odd_psum.size() - 1;
    if (idx % 2 == 0) {
        score = odd_psum[idx - 1] + even_psum[n - 2] - even_psum[idx - 2];
    } else {
        score = (idx - 2 >= 0) ? odd_psum[idx - 2] : 0;
        score += last_card + even_psum[n - 2] - even_psum[idx - 1];
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    vector<int> odd_psum(n + 1), even_psum(n + 1);
    odd_psum[1] = vec[1];
    even_psum[2] = vec[2];
    for (int i = 3; i <= n; i += 2) {
        odd_psum[i] = vec[i] + odd_psum[i - 2];
        even_psum[i + 1] = vec[i + 1] + even_psum[i - 1];
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, cheat_on_card(i, vec[n], odd_psum, even_psum));
    }
    cout << mx;
    return 0;
}