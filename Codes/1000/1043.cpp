#include <bits/stdc++.h>
using namespace std;

bool party[100];
vector<int> people[100], partypeople[100];
bool mvisited[100], pvisited[100];

void dfs(int v) {
    mvisited[v] = true;
    for(int next : people[v]) {
        if(pvisited[next])
            continue;
        party[next] = true;
        pvisited[next] = true;
        vector<int> pp = partypeople[next];
        for(int nextp : pp) {
            if(!mvisited[nextp])
                dfs(nextp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x, t, p, ans = 0;
    cin >> n >> m >> t;
    vector<int> truth;
    for(int i = 0; i < t; ++i) {
        cin >> x;
        truth.push_back(x);
    }
    for(int i = 0; i < m; ++i) {
        cin >> p;
        for(int j = 0; j < p; ++j) {
            cin >> x;
            people[x].push_back(i + 1);
            partypeople[i + 1].push_back(x);
        }
    }
    for(int v : truth)
        dfs(v);
    for(int i = 1; i <= m; ++i) {
        if(!party[i]) ans++;
    }
    cout << ans;
    return 0;
}
