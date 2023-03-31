#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int diff, foot1, foot2;
    cin >> diff >> foot1 >> foot2;

    cout << (diff % (foot1 + foot2) < foot1);
    return 0;
}
