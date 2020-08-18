#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

vector<int> xcord, ycord;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        sum += abs(x) + abs(y);
        xcord.push_back(x); ycord.push_back(y);
    }
    sort(all(xcord)); sort(all(ycord));
    string moves;
    cin >> moves;
    x = 0, y = 0;
    for(int i = 0; i < m; ++i) {
        char c = moves[i];
        if(c == 'S') { // north
            int g = ycord.end() - upper_bound(all(ycord), y);
            int le = n - g;
            sum += le - g;
            y++;
        } else if(c == 'J') { // south
            int l = lower_bound(all(ycord), y) - ycord.begin();
            int ge = n - l;
            sum += ge - l;
            y--;
        } else if(c == 'I') { // east
            int g = xcord.end() - upper_bound(all(xcord), x);
            int le = n - g;
            sum += le - g;
            x++;
        } else if(c= 'Z') { // west
            int l = lower_bound(all(xcord), x) - xcord.begin();
            int ge = n - l;
            sum += ge - l;
            x--;
        }
        cout << sum << '\n';
    }
    return 0;
}