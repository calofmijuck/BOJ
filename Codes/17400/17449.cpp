#include <bits/stdc++.h>
using namespace std;

int arr[200020];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int r, n;
    cin >> r >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];        
    int mi = r, mx = r;
    for(int i = 0; i < n; ++i) {
        if(mi > arr[i]) mi++, mx++;
        else if(mi == arr[i]) mx++;
        else if(mx >= arr[i]) {
            mi = arr[i];
            mx++;
            if(mx < mi) mx = mi;
        }
    }
    cout << mi << ' ' << mx;
}