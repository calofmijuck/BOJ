#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int v_kappa, j_kappa, v_lambda, j_lambda, v_heavy, d_heavy, j_heavy;
    cin >> v_kappa >> j_kappa >> v_lambda >> j_lambda >> v_heavy >> d_heavy >> j_heavy;

    cout << (long long) v_heavy * d_heavy * j_heavy * (v_kappa * j_kappa + v_lambda * j_lambda);
    return 0;
}
