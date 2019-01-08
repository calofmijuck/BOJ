#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> vec;

void solve(int n, ll sum) {
    if(n < 0) vec.push_back(sum);
    else {
        solve(n - 1, sum);
        solve(n - 1, 10 * sum + n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    solve(9, 0);
    sort(vec.begin(), vec.end());
    if(n >= vec.size() - 1) printf("-1");
    else printf("%lld", vec[n + 1]);
    return 0;
}
