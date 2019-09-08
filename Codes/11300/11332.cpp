#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int c;
    cin >> c;
    while(c--) {
        string str;
        ll n, t, l;
        cin >> str >> n >> t >> l;
        long double limit = 1.0 * l * 100000000LL / t;
        ll op;
        if(str == "O(N)") {
            op = n;
        } else if(str == "O(N^2)") {
            op = n * n;
        } else if(str == "O(N^3)") {
            op = n * n * n;
        } else if(str == "O(2^N)") {
            long double x = log2(1.0 * limit);
            if(n > x) cout << "TLE!\n";
            else cout << "May Pass.\n";
            continue;
        } else {
            long double x = 1.0 * limit;
            ll prod = 1;
            bool flag = true;
            for(int i = 1; i <= n; ++i) {
                prod *= i;
                if(prod > x) {
                    flag = false;
                    cout << "TLE!\n";
                    break;
                }
            }
            if(flag) cout << "May Pass.\n";
            continue;
        }
        if(op > limit) cout << "TLE!\n";
        else cout << "May Pass.\n";
    }
}