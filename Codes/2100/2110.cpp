#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, c;
    cin >> n >> c;
    vl vec;
    vec.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(all(vec));
    ll right = (vec[n - 1] - vec[0]), left = 0;
    while(left <= right) {
        ll mid = (right + left) / 2;
        ll curr = vec[0], cnt = 1;
        for(int i = 1; i < n; ++i) {
            if(vec[i] - curr >= mid) {
                cnt++;
                curr = vec[i];
            }
        }
        if(cnt >= c) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << left - 1;
    return 0;
}
