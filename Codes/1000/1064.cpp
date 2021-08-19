#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void init_point(pii& p) {
    cin >> p.first >> p.second;
}

bool check_colinear(pii& a, pii& b, pii& c) {    
    return (b.second - a.second) * (c.first - b.first) == (c.second - b.second) * (b.first - a.first) 
}

double dist(pii& a, pii& b) {
    return hypot(b.first - a.first, b.second - a.second);
}

pii find_last_point(pii& a, pii& b) {
    // todo
    return make_pair(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pii a, b, c;
    init_point(a);
    init_point(b);
    init_point(c);

    if (check_colinear(a, b, c)) {
        cout << -1;
        return 0;
    }
    // AB is diagonal
    return 0;
}
