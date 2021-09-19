#include <bits/stdc++.h>
using namespace std;

vector<int> red(1), green(1), blue(1);

void read_prices(int n) {
    for (int i = 0; i < n; ++i) {
        int r, g, b;
        cin >> r >> g >> b;
        red.push_back(r);
        green.push_back(g);
        blue.push_back(b);
    }
}

int find_min_cost(int n) {
    vector<int> last_red(n + 1), last_green(n + 1), last_blue(n + 1);
    for (int i = 1; i <= n; ++i) {
        last_red[i] = red[i] + min(last_green[i - 1], last_blue[i - 1]);
        last_green[i] = green[i] + min(last_red[i - 1], last_blue[i - 1]);
        last_blue[i] = blue[i] + min(last_red[i - 1], last_green[i - 1]);
    }
    return min({last_red[n], last_green[n], last_blue[n]});
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    read_prices(n);
    int minimum = find_min_cost(n);
    cout << minimum;
    return 0;
}
