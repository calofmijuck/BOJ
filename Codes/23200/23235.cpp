#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i = 1;
    string line;
    while (true) {
        getline(cin, line);
        if (line[0] == '0') {
            break;
        }

        cout << "Case " << i << ": Sorting... done!\n";
        i++;
    }
    return 0;
}
