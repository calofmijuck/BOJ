#include <iostream>
using namespace std;

int arr[1010], lis[1010], lds[1010];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i) lis[i] = lds[i] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(arr[j] < arr[i]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    for(int i = n - 2; i >= 0; --i) {
        for(int j = n - 1; j > i; --j) {
            if(arr[j] < arr[i]) lds[i] = max(lds[i], lds[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, lis[i] + lds[i] - 1);
    printf("%d", ans);
}
