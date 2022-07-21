#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(2);

    int hot_dogs, people;
    while (cin >> hot_dogs >> people) {
        cout << fixed << double(hot_dogs) / people << '\n';
    }
    return 0;
}
