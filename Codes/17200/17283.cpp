#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
    ll l, r;
    cin >> l >> r;
    ll ans = 0, k = 2;
    l = l * r / 100;
    while(l > 5) {
        ans += k * l;
        l = l * r / 100;
        k <<= 1;
    }
    cout << ans;
}