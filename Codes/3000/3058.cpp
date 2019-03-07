#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int sum = 0, in, mi = 200;
        for(int i = 0; i < 7; ++i) {
            scanf("%d", &in);
            if(in % 2 == 0) {
                sum += in;
                mi = min(mi, in);
            }
        }
        printf("%d %d\n", sum, mi);
    }
    return 0;
}
