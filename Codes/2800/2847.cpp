#include <bits/stdc++.h>
using namespace std;

int arr[105];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = n - 2; i >= 0; --i) {
        if(arr[i] >= arr[i + 1]) {
            int nScore = arr[i + 1] - 1;
            ans += arr[i] - nScore;
            arr[i] = nScore;
        }
    }
    cout << ans;    
    return 0;
}
