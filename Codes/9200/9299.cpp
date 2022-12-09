#include <bits/stdc++.h>
using namespace std;

void print_derivative(vector<int>& coeff, int deg) {
    printf("%d ", deg - 1);
    for (int i = 0; i < deg; ++i) {
        printf("%d ", (deg - i) * coeff[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);

        int deg;
        scanf("%d", &deg);

        vector<int> coeff(deg + 1, 0);
        for (int j = 0; j <= deg; ++j) {
            scanf("%d", &coeff[j]);
        }
        print_derivative(coeff, deg);
    }
    return 0;
}
