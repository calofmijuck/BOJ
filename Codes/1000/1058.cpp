#include <bits/stdc++.h>
using namespace std;

char in[60];
bitset<60> f[50];
int mx;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", in);
        for(int j = 0; j < n; ++j) {
            if(in[j] == 'Y') f[i][j] = true;
            else f[i][j] = false;
        }
    }
    bitset<60> cnt, tmp;
    for(int i = 0; i < n; ++i) {
        cnt.reset();
        tmp.reset();
        cnt |= f[i];
        for(int j = 0; j < n; ++j) {
            if(f[i][j] == true) {
                tmp |= f[j];
            }
        }
        cnt |= tmp;
        int x = cnt.count();
        mx = max(cnt[i] ? x - 1 : x, mx);
    }
    printf("%d", mx);
    return 0;
}
