#include <bits/stdc++.h>
using namespace std;

int ans[10], choice[10], cnt = 0;

void check_ans() {
    int score = 0;
    for(int i = 0; i < 10; ++i)
        score += (ans[i] == choice[i]);
    if(score >= 5)
        cnt++;
}

void solve(int k) {
    if(k == 10) {
        check_ans();
        return;
    }
    for(int i = 1; i <= 5; ++i) {
        if(k >= 2 && choice[k - 2] == choice[k - 1] && choice[k - 1] == i)
            continue; 
        choice[k] = i;
        solve(k + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 10; ++i)
        cin >> ans[i];
    solve(0);
    cout << cnt;
    return 0;
}