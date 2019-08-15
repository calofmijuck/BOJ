#include <iostream>
using namespace std;

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)) {
        int stamp = n;
        int ans = n;
        while(stamp / k > 0) {
            int order = stamp / k;
            stamp %= k;
            ans += order;
            stamp += order;
        }
        cout << ans << '\n';
    }
}
