#include <bits/stdc++.h>
using namespace std;

string add(string &a, string &b) {
    string c(max(a.size(), b.size()), '0');
    bool carry = false;
    for(int i = 0; i < c.size(); ++i) {
        int tmp = carry;
        carry = false;
        if(i < a.size()) tmp += a[a.size() - i - 1] - '0';
        if(i < b.size()) tmp += b[b.size() - i - 1] - '0';
        if(tmp >= 10) {
            carry = true;
            tmp -= 10;
        }
        c[c.size() - i - 1] = tmp + '0';
    }
    if(carry) c.insert(c.begin(), '1');
    return c;
}

string mult(string &a, string& b) {
    string c = "0";
    for(int i = 0; i < b.size(); ++i) {
        string line(a);
        int carry = 0;
        for(int j = a.size() - 1; j >= 0; --j) {
            int tmp = carry;
            carry = 0;
            tmp += (a[j] - '0') * (b[b.size() - i - 1] - '0');
            if(tmp >= 10) {
                carry = tmp / 10;
                tmp %= 10;
            }
            line[j] = tmp + '0';
        }
        if(carry > 0) line.insert(line.begin(), carry + '0');
        line += string(i, '0');
        c = add(c, line);
    }
    return c;
}

string dp[251] = {"1", "1", "3"};

int main() {
    int n;
    string two = "2";
    for(int i = 3; i <= 250; ++i) {
        string tmp = mult(dp[i - 2], two);
        dp[i] = add(dp[i - 1], tmp);
    }
    while(~scanf("%d", &n)) cout << dp[n] << '\n';
    return 0;
}
