#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if(n != 8) printf("%d %d", n % (n / 2 + 1) + 1, n / 2 + 1);
    else printf("4 3");
    return 0;
}
