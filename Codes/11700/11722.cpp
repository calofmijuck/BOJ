#include <iostream>
using namespace std;

int arr[1010], lds[1010];

int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i) lds[i] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(arr[j] > arr[i]) lds[i] = max(lds[i], lds[j] + 1);
        }
    }
    for(int i = 0; i < n; ++i)
        ans = max(ans, lds[i]);
    printf("%d", ans);
}
