#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[500000], bucket[8001];

ll round(ll sum, int n) {
    return (ll) round(sum * 1.0 / n);
}

int mode(int occ) {
    int res = 0;
    bool min2 = false, min = false;
    for(int i = 0; i < 8001; i++) {
        if(occ == bucket[i]) {
            if(!min) {
                res = i - 4000;
                min = true;
            } else if(!min2) {
                min2 = true;
                res = i - 4000;
                break;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, input, max = -4001, min = 4001, occ_max = -1;
    ll sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input;
        arr[i] = input;
        bucket[input + 4000]++;
        if(bucket[input + 4000] > occ_max) {
            occ_max = bucket[input + 4000];
        }
        sum += input;
    }
    cout << round(sum, n) << '\n';
    sort(arr, arr + n);
    cout << arr[n/2] << '\n' << mode(occ_max) << '\n' << arr[n - 1] - arr[0];
}
