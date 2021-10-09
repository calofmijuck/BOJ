#include <bits/stdc++.h>
using namespace std;

int interview_score[100001];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        interview_score[x] = y;
    }

    int accepted = 0;
    int min_interview_score = n;
    for (int i = 1; i <= n; ++i) {
        if (interview_score[i] <= min_interview_score) {
            accepted++;
            min_interview_score = interview_score[i];
        }
    }
    cout << accepted << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
