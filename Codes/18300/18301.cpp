#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n1, n2, n12;
    cin >> n1 >> n2 >> n12;
    cout << (n1 + 1) * (n2 + 1) / (n12 + 1) - 1;
    return 0;
}