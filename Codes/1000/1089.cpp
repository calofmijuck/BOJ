#include <bits/stdc++.h>
using namespace std;

string light[5];

int num[] = {0x7b6f, 0x4924, 0x73e7, 0x79e7, 0x49ed, 0x79cf, 0x7bcf, 0x4927, 0x7bef, 0x79ef};

int parse(int x) {
    int ret = 0, mask = 1;
    for(int i = 0; i < 5; ++i) {
        for(int j = x; j < x + 3; ++j) {
            if(light[i][j] == '#') ret |= mask;
            mask <<= 1;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    double ans = 0;
    bool flag = true;
    cin >> n;
    for(int i = 0; i < 5; ++i) cin >> light[i];
    for(int t = 0; t < n; ++t) {
        int p = parse(4 * t);
        int curr = 0, cnt = 0;
        for(int j = 0; j < 10; ++j) {
            if((num[j] & p) == p) {
                curr += j;
                cnt++;
            }
        }
        if(cnt != 0)
            ans += curr * pow(10, n - 1 - t) / (double) cnt;
        else 
            flag = false;
    }
    if(!flag) cout << -1;
    else cout << ans;
    return 0;
}