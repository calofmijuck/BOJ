#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int sides[2][2];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                scanf("%d", &sides[i][j]);
            }
        }

        long long paris = (long long) sides[0][0] * sides[0][1];
        long long eurecom = (long long) sides[1][0] * sides[1][1];
        if (paris > eurecom) {
            printf("TelecomParisTech\n");
        } else if (paris < eurecom) {
            printf("Eurecom\n");
        } else {
            printf("Tie\n");
        }
    }
    return 0;
}
