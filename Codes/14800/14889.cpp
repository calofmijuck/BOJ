#include <iostream>
using namespace std;

int team[22];
int arr[22][22];
int m, n;
int ans = 0x7fffffff;

void solve(int st, int idx) {
    if(idx == n) return;
    if(st == n / 2) {
        int start = 0, link = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(team[i] == team[j]) {
                    if(team[i] == 1) start += arr[i][j];
                    if(team[i] == 0) link += arr[i][j];
                }
            }
        }
        ans = min(ans, abs(start - link));
        return;
    }
    team[idx] = 1;
    solve(st + 1, idx + 1);
    team[idx] = 0;
    solve(st, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cin >> arr[i][j];
    }
    solve(0, 0);
    cout << ans;
    return 0;
}
