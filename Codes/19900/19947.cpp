#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int h, y;
    cin >> h >> y;
    int arr[11] = {h};
    for(int i = 1; i <= y; ++i) {
        if(i - 1 >= 0) {
            arr[i] = max(arr[i], int(arr[i - 1] * 1.05));
        }
        if(i - 3 >= 0) {
            arr[i] = max(arr[i], int(arr[i - 3] * 1.2));
        }
        if(i - 5 >= 0) {
            arr[i] = max(arr[i], int(arr[i - 5] * 1.35));
        }
    }
    cout << arr[y];
    return 0;
}