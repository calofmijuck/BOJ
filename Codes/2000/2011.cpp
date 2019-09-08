#include <bits/stdc++.h>
using namespace std;

string str;
int dp[5010], pd[5010];
const int mod = 1000000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    int i = 0;
    int num = str[i] - '0';
    if(1 <= num && num <= 9) dp[i] = 1;
    i++;
    num = str[i] - '0';
    if(1 <= num && num <= 9) dp[i] = dp[i - 1];
    num = 10 * (str[i - 1] - '0') + num;
    if(10 <= num && num <= 26) pd[i] = 1;
    i++;
    for(; i < str.size(); ++i) {
        num = str[i] - '0';
        if(1 <= num && num <= 9) dp[i] = (pd[i - 1] + dp[i - 1]) % mod;
        num = 10 * (str[i - 1] - '0') + num;
        if(10 <= num && num <= 26) pd[i] = (dp[i - 2] + pd[i - 2]) % mod;
    }
    cout << (dp[str.size() - 1] + pd[str.size() - 1]) % mod;
    return 0;
}