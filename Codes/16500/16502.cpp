#include <bits/stdc++.h>
using namespace std;

double init[4][4], res[4][4], tmp[4][4], ans[4], p;

void matmul() {
    double c;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            c = 0;
            for(int k = 0; k < 4; ++k)
                c += res[i][k] * init[k][j];
            tmp[i][j] = c;
        }
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j)
            res[i][j] = tmp[i][j];
    }
}

int main() {
    int t, m;
    string st, ed;
    cin >> t >> m;
    for(int i = 0; i < m; ++i) {
        cin >> st >> ed >> p;
        init[st.at(0) - 'A'][ed.at(0) - 'A'] = p;
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j)
            res[i][j] = init[i][j];
    }
    for(int i = 1; i < t; ++i) matmul();
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j)
            ans[j] += res[i][j];
    }
    for(int i = 0; i < 4; ++i) printf("%.2f\n", ans[i] * 25);
    return 0;
}
