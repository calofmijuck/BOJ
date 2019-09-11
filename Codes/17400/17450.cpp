#include <bits/stdc++.h>
using namespace std;

vector<pair<double, char>> vec;
char c[3] = {'S', 'N', 'U'};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int s, n, u;
    for(int i = 0; i < 3; ++i) {
        int p, w;
        cin >> p >> w;
        int cost = p * 10;
        if(cost >= 5000) {
            cost -= 500;
        }
        double r = 10.0 * w / cost;
        vec.push_back({r, c[i]});
    }
    sort(vec.begin(), vec.end());
    cout << vec[2].second;
}