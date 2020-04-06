#include <bits/stdc++.h>
using namespace std;

#define MAX 0x3f3f3f3f

inline int opD(int x) {
    return (2 * x) % 10000;
}

inline int opS(int x) {
    return (x + 9999) % 10000;
}

inline int opL(int x) {
    int k = x / 1000;
    return (x % 1000) * 10 + k;
}

inline int opR(int x) {
    int k = x % 10;
    return k * 1000 + x / 10;
}

string str[4] = {"D", "S", "L", "R"};

string solve(int x, int y) {
    vector<bool> visited(10000, false);
    queue<pair<int, string>> q;
    visited[x] = true;
    q.push({x, ""});
    while(!q.empty()) {
        pair<int, string> p = q.front();
        q.pop();
        int arr[4] = {opD(p.first), opS(p.first), opL(p.first), opR(p.first)};
        for(int i = 0; i < 4; ++i) {
            if(!visited[arr[i]]) {
                visited[arr[i]] = true;
                q.push({arr[i], p.second + str[i]});
            }
            if(arr[i] == y)
                return p.second + str[i];
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << '\n';
    }
    return 0;
}