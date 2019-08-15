#include <iostream>
using namespace std;

int main() {
    int p, n;
    long double d, a, b, f;
    scanf("%d", &p);
    while(p--) {
        scanf("%d", &n);
        scanf("%Lf %Lf %Lf %Lf", &d, &a, &b, &f);
        double ans = d / (a + b) * f;
        printf("%d %.6lf\n", n, ans);
    }
    return 0;
}
