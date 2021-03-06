#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ramen[1000100];
ll n, b, c, ans;

void transform_one(int i) {
    ans += b * ramen[i];
    ramen[i] = 0;
}

void transform_two(int i) {
    ll buy = min(ramen[i], ramen[i + 1] - ramen[i + 2]);
    ramen[i] -= buy;
    ramen[i + 1] -= buy;
    ans += (b + c) * buy;
}

void transform_three(int i) {
    ll buy = min({ramen[i], ramen[i + 1], ramen[i + 2]});
    ramen[i] -= buy;
    ramen[i + 1] -= buy;
    ramen[i + 2] -= buy;
    ans += (b + 2 * c) * buy;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> b >> c;
    for(int i = 0; i < n; ++i)
        cin >> ramen[i];
    if(b < c)
        c = b;
    for(int i = 0; i < n; ++i) {
        if(ramen[i + 1] > ramen[i + 2]) {
            transform_two(i);
            transform_three(i);
        } else {
            transform_three(i);

            ll buy = min(ramen[i], ramen[i + 1]);
            ramen[i] -= buy;
            ramen[i + 1] -= buy;
            ans += (b + c) * buy;
        }
        transform_one(i);
    }
    cout << ans;
    return 0;
}