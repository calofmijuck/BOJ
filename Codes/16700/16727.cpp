#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int persepolis[2], esteghlal[2];
    cin >> persepolis[0] >> esteghlal[0] >> esteghlal[1] >> persepolis[1];

    int persepolis_total = persepolis[0] + persepolis[1];
    int esteghlal_total = esteghlal[0] + esteghlal[1];

    if (persepolis_total > esteghlal_total) {
        cout << "Persepolis";
    } else if (esteghlal_total > persepolis_total) {
        cout << "Esteghlal";
    } else if (esteghlal[0] < persepolis[1]) {
        cout << "Persepolis";
    } else if (esteghlal[0] > persepolis[1]) {
        cout << "Esteghlal";
    } else {
        cout << "Penalty";
    }
    return 0;
}
