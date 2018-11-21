#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, in1, in2, in3, in4;
    cin >> n;
    n *= n;
    long long ans = 0;
    for(int i = 0; i < n / 4; i++) {
            cin >> in1 >> in2 >> in3 >> in4;
            ans += in1 + in2 + in3 + in4;
    }
    cout << ans;
    return 0;
}
