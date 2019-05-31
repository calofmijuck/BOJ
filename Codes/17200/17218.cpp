#include <bits/stdc++.h>
using namespace std;

string dp[50][50];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 1; i <= (int) str1.size(); ++i) {
        for(int j = 1; j <= (int) str2.size(); ++j) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].push_back(str1[i - 1]);
            } else {
                if(dp[i - 1][j].size() > dp[i][j - 1].size()) {
                    dp[i][j] = dp[i - 1][j];
                } else dp[i][j] = dp[i][j - 1];
            }
        }
    }
    cout << dp[str1.size()][str2.size()];
    return 0;
}
