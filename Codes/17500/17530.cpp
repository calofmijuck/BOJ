#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int max = 0, index = 0;
    for (int i = 0; i < n; ++i) {
        int votes;
        cin >> votes;
        if (votes > max) {
            max = votes;
            index = i + 1;
        }
    }

    cout << (index == 1 ? "S" : "N");
    return 0;
}
