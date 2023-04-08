#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int stops;
    cin >> stops;

    long energy = 0, prev;
    cin >> prev;
    for (int i = 1; i <stops; ++i) {
        int next;
        cin >> next;

        energy += pow(next - prev, 2);
        prev = next;
    }
    cout << energy;
    return 0;
}
