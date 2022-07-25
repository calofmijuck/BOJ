#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int start, end, portal[2];
    cin >> start >> end >> portal[0] >> portal[1];

    int without_teleportation = abs(start - end);
    int with_teleportation = min(abs(start - portal[0]) + abs(end - portal[1]), abs(start - portal[1]) + abs(end - portal[0]));

    cout << min(with_teleportation, without_teleportation);
    return 0;
}
