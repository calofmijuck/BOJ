#include <bits/stdc++.h>
using namespace std;

int p[2][2];

int main() {
    int r, c, t = 0, in;
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            scanf("%d", &in);
            if(in == 1) {
                p[t][0] = i;
                p[t][1] = j;
                t++;
            }
        }
    }
    printf("%d", abs(p[0][0] - p[1][0]) + abs(p[0][1] - p[1][1]));
    return 0;
}
