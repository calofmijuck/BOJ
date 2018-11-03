#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long x = 0, y = 1, z;
    if(n == 0) printf("0");
    else if(n == 1) printf("1");
    else {
        for(int i = 2; i <= n; i++) {
            z = x + y;
            x = y;
            y = z;
        }
        printf("%lld\n", y);
    }
}
