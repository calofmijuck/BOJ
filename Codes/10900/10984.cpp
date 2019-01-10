#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, c, sumc;
    double g, weightsum;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        sumc = 0;
        weightsum = 0;
        for(int j = 0; j < n; j++) {
            scanf("%d %lf", &c, &g);
            sumc += c;
            weightsum += c * g;
        }
        printf("%d %.1lf\n", sumc, weightsum / sumc + 0.001);
    }
    return 0;
}
