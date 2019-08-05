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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s, e, st = 0x3fffffff, ed = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s >> e;
        st = min(st, e);
        ed = max(ed, s);
    }
    if(ed - st <= 0)
        cout << 0;
    else
        cout << ed - st;
}