#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii arr[55];
int ans[55];

int main() {
    int n, in;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &in);
        arr[i] = {in, i};
    }
    stable_sort(arr, arr + n, less<pii>());
    for(int i = 0; i < n; ++i) ans[arr[i].second] = i;
    for(int i = 0; i < n; ++i) printf("%d ", ans[i]);
    return 0;
}
