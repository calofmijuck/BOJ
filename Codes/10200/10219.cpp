#include <bits/stdc++.h>
using namespace std;

char str[20];

int main() {
    int t, w, h;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d\n", &h, &w);
        for(int i = 0; i < h; ++i) {
            scanf("%s", str);
            for(int j = w - 1; j >= 0; --j) printf("%c", str[j]);
            puts("");
        }
    }
    return 0;
}
