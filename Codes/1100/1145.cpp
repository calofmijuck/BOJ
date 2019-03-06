#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5], ans = 1, cnt;
    for(int i = 0; i < 5; ++i) scanf("%d", a + i);
    while(true) {
        cnt = 0;
        for(int i = 0; i < 5; ++i) {
            if(ans % a[i] == 0) cnt++;
        }
        if(cnt > 2) break;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
