#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii age[101010];
string name[101010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    string str;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> age[i].first >> name[i];
        age[i].second = i;
    }
    stable_sort(age, age + n);
    for(int i = 0; i < n; ++i) cout << age[i].first << ' ' << name[age[i].second] << '\n';
    return 0;
}
