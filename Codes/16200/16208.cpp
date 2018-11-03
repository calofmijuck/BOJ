#include <cstdio>
using namespace std;
int arr[505050];
int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0, res = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for(int i = 0; i < n; i++) res += arr[i] * (sum -= arr[i]);
    printf("%lld\n", res);
}
