#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, width, height;
    cin >> n >> width >> height;

    int hypot_squared = width * width + height * height;
    for (int i = 0; i < n; ++i) {
        int length;
        cin >> length;
        if (length * length > hypot_squared) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
