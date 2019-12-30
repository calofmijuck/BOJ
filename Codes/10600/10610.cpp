#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    int digit[10] = {0};
    for(int i = 0; i < str.size(); ++i) {
        digit[str[i] - '0']++;
        cnt += str[i] - '0';
    }
    if(digit[0] != 0 && cnt % 3 == 0) {
        for(int k = 9; k >= 0; --k) {
            for(int i = 0; i < digit[k]; ++i) cout << k;
        }
    } else cout << -1;
    return 0;
}
