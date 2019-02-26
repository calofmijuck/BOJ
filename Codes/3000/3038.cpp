#include <cstdio>
using namespace std;

int n, arr[33000], tmp[33000];

void preorder(int x) {
    if(x >= (1 << n)) return;
    printf("%d ", arr[x]);
    preorder(2 * x);
    preorder(2 * x + 1);
}

int main() {
    scanf("%d", &n);
    arr[1] = 1;
    for(int i = 2; i <= n; ++i) {
        int len = 1 << (i - 1);
        for(int j = 1; j < len; ++j) tmp[j] = arr[j];
        int k = 1;
        for(int j = 1; j < i; ++j) {
            int offset = 1 << (j - 1);
            int len = (1 << j) - 1;
            for(; k <= len; ++k) {
                if(j != i - 1) {
                    arr[k + offset] = 2 * tmp[k] + 1;
                    arr[k + 2 * offset] = 2 * tmp[k];
                } else {
                    arr[k + offset] = 2 * tmp[k];
                    arr[k + 2 * offset] = 2 * tmp[k] + 1;
                }
            }
        }
    }
    preorder(1);
    return 0;
}
