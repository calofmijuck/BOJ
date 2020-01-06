#include <bits/stdc++.h>
using namespace std;

int arr[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int mx = 0, curr = 0;
    for(int i = 1; i < n; ++i) {
        if(arr[i] > arr[i - 1]) {
            curr += arr[i] - arr[i - 1];
        } else {
            mx = max(curr, mx);
            curr = 0;
        }
    }
    mx = max(curr, mx);
    cout << mx;
    return 0;
}
