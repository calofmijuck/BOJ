#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[55];
int visited[55];
int match[55];

struct Shark {
    int a, b, c;
    Shark(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector<Shark> vec;

bool dfs(int v) {
    if(visited[v]) return false;
    visited[v] = true;
    for(int next : adj[v]) {
        if(!match[next] || dfs(match[next])) {
            match[next] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.emplace_back(a, b, c);
    }
    for(int i = 0; i < n; ++i) {
        Shark s = vec[i];
        for(int j = i + 1; j < n; ++j) {
            Shark t = vec[j];
            if(s.a >= t.a && s.b >= t.b && s.c >= t.c) adj[i + 1].push_back(j + 1);
            if(s.a == t.a && s.b == t.b && s.c == t.c) continue;
            if(s.a <= t.a && s.b <= t.b && s.c <= t.c) adj[j + 1].push_back(i + 1);
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 2; ++j) {
            memset(visited, 0, sizeof(visited));
            if(dfs(i)) ret++;
        }
    }
    cout << n - ret;
    return 0;
}
