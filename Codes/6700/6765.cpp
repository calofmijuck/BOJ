#include <bits/stdc++.h>
using namespace std;

string icon[3] = {"*x*", " xx", "* *"};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    int lines = 3 * k;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < lines; ++j) {
            cout << icon[i / k][j / k];
        }
        cout << '\n';
    }
    return 0;
}
