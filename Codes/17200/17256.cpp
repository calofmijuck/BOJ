#include <cstdio>
using namespace std;

int main() {
    int a[3], c[3];
    scanf("%d %d %d %d %d %d", a, a + 1, a + 2, c, c + 1, c + 2);
    printf("%d %d %d", c[0] - a[2], c[1] / a[1], c[2] - a[0]);
}
