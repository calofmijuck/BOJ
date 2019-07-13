#include <cstdio>
using namespace std;

int main() {
    int n, m = -1, x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if(x > m) m = x;
    }
    printf("%d", m);
}
