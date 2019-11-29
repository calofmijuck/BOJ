#include <bits/stdc++.h>
using namespace std;

int n, op;
int ans = -0x7fffffff;
vector<int> num;
string str;

int calc(int a, int b, char o) {
    switch (o) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return 0;
    }
}

void solve(int curr, int idx, bool par) {
    if(idx == num.size() - 1) {
        ans = max(curr, ans);
        return;
    }
    if(par) {
        char o = str[2 * idx + 3];
        int next = calc(num[idx + 1], num[idx + 2], o);
        o = str[2 * idx + 1];
        curr = calc(curr, next, o);
        if(idx + 4 < num.size())
            solve(curr, idx + 2, true);
        solve(curr, idx + 2, false);
    } else {
        char o = str[2 * idx + 1];
        curr = calc(curr, num[idx + 1], o);
        if(idx + 3 < num.size())
            solve(curr, idx + 1, true);
        solve(curr, idx + 1, false);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> str;
    op = n / 2;
    for(int i = 0; i < str.size(); i += 2) 
        num.push_back(str[i] - '0');
    int curr = num[0];
    if(str.size() > 3)
        solve(curr, 0, true);
    solve(curr, 0, false);
    cout << ans;
    return 0;
}