#include <bits/stdc++.h>
using namespace std;

int get_spacing(int count, int space) {
    return (int) ceil((double) count / (space + 1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    cout << get_spacing(h, n) * get_spacing(w, m);
    return 0;
}
