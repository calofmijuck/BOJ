#include <bits/stdc++.h>
using namespace std;

int cleopatra(vector<int>& limits, int start) {
    int people = (int) limits.size();
    int pitch = start;
    int i = 0;
    while (true) {
        if (pitch > limits[i]) {
            break;
        }

        pitch++;
        i = (i + 1) % people;
    }
    return i + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, start;
    cin >> n >> start;

    vector<int> limits(n);
    for (int& e : limits) {
        cin >> e;
    }

    cout << cleopatra(limits, start);
    return 0;
}
