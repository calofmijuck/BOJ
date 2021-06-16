#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int init_temp, target_temp, t_frozen, t_melt, t_normal;
    cin >> init_temp >> target_temp >> t_frozen >> t_melt >> t_normal;
    int total = 0;
    if (init_temp < 0) {
        total = -init_temp * t_frozen + t_melt + target_temp * t_normal;
    } else {
       total = (target_temp - init_temp) * t_normal;
    }
    cout << total;
    return 0;
}
