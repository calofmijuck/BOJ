#include <bits/stdc++.h>
using namespace std;

const int limit = 500;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int count = 0;
    for (int b = 1; b <= limit; ++b) {
        for (int a = b; a <= limit; ++a) {
            if (a * a == b * b + n) {
                count++;
            }
        }
    }

    cout << count;
    return 0;
}
