#include <bits/stdc++.h>
using namespace std;

vector<int> query[100010];

int main() {
    int n, m, k, x;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &k);
        for(int j = 0; j < k; ++j) {
            scanf("%d", &x);
            query[i].push_back(x);
        }
    }
    vector<int> state(n + 1), init(n + 1), fin(n + 1);
    for(int i = 1; i <= n; ++i) 
        scanf("%d", &state[i]);
    copy(state.begin(), state.end(), fin.begin());
    for(int i = m - 1; i >= 0; --i) {
        bool safe = false;
        for(int j = 0; j < query[i].size(); ++j) {
            if(state[query[i][j]] == 0) {
                safe = true;
                break;
            }
        }
        if(safe) {
            for(int j = 0; j < query[i].size(); ++j)
                state[query[i][j]] = 0;
        }
    }
    copy(state.begin(), state.end(), init.begin());
    for(int i = 0; i < m; ++i) {
        int safe = true;
        for(int j = 0; j < query[i].size(); ++j) {
            if(state[query[i][j]] == 1) {
                safe = false;
                break;
            }
        }
        if(!safe) {
            for(int j = 0; j < query[i].size(); ++j)
                state[query[i][j]] = 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(state[i] != fin[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i = 1; i <= n; ++i)
        printf("%d ", init[i]);
    return 0;
}