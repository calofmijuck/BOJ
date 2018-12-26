#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int main() {
    string a, b;
    cin >> a >> b;
    int sa = a.size(), sb = b.size();
    for(int i = 1; i <= sa; ++i) {
        for(int j = 1; j <= sb; ++j)
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a.at(i - 1) == b.at(j - 1))});
    }
    printf("%d", dp[sa][sb]);
    return 0;
}
