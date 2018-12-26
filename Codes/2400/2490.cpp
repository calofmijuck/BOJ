#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, cnt = 0;
    for(int i = 0; i < 3; ++i) {
        cnt = 0;
        for(int j = 0; j < 4; ++j) {
            scanf("%d", &x);
            if(!x) cnt++;
        }
        if(cnt == 0) puts("E");
        else printf("%c\n", (char) ('A' + cnt - 1));
    }
    return 0;
}
