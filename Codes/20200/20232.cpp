#include <bits/stdc++.h>
using namespace std;

unordered_set<int> spbsu = { 1996, 1997, 2000, 2007, 2008, 2013, 2018 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int year;
    cin >> year;

    if (year == 2006) {
        cout << "PetrSU, ITMO";
    } else if (spbsu.find(year) != end(spbsu)) {
        cout << "SPbSU";
    } else {
        cout << "ITMO";
    }
    return 0;
}
