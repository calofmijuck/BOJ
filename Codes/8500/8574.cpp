#include <bits/stdc++.h>
using namespace std;

double distance(pair<int, int> &p1, pair<int, int> &p2) {
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int children, vision;
    pair<int, int> safety;
    cin >> children >> vision >> safety.first >> safety.second;

    int unsafe = 0;
    for (int i = 0; i < children; ++i) {
        pair<int, int> location;
        cin >> location.first >> location.second;

        if (distance(safety, location) > vision) {
            unsafe++;
        }
    }
    cout << unsafe;
    return 0;
}
