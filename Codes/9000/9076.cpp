#include <bits/stdc++.h>
using namespace std;

int score[5];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 5; ++i) scanf("%d", &score[i]);
        sort(score, score + 5);
        if(score[3] - score[1] >= 4) puts("KIN");
        else printf("%d\n", score[1] + score[2] + score[3]);
    }
    return 0;
}
