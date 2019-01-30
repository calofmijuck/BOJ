#include <bits/stdc++.h>
using namespace std;

int score[52];

int main() {
    int k, n, prev, in, c = 0;
    scanf("%d", &k);
    while(k-- && ++c) {
        scanf("%d", &n);
        int mini = 200, maxi = -100, gap = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &in);
            score[i] = in;
            mini = min(in, mini);
            maxi = max(in, maxi);
        }
        sort(score, score + n);
        for(int i = 1; i < n; ++i) gap = max(gap, score[i] - score[i - 1]);
        printf("Class %d\nMax %d, Min %d, Largest gap %d\n", c, maxi, mini, gap);
    }
    return 0;
}
