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
    int n, m, x;
    vi vec;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> x;
        vec.pb(x);
    }
    int mx = 0;
    for(int i = 1; i < vec.size(); ++i)
        mx = max(mx, (vec[i] - vec[i - 1] + 1) / 2);
    mx = max(mx, vec[0]);
    mx = max(mx, n - vec[m - 1]);
    cout << mx;
    return 0;
}