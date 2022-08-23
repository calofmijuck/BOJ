#include <bits/stdc++.h>
using namespace std;

map<int, string> single = {
    {1, "Yakk"},
    {2, "Doh"},
    {3, "Seh"},
    {4, "Ghar"},
    {5, "Bang"},
    {6, "Sheesh"}
};

map<int, string> same = {
    {1, "Habb Yakk"},
    {2, "Dobara"},
    {3, "Dousa"},
    {4, "Dorgy"},
    {5, "Dabash"},
    {6, "Dosh"}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << i << ": ";

        if ((a == 5 and b == 6) or (a == 6 and b == 5)) {
            cout << "Sheesh Beesh";
        } else if (a == b) {
            cout << same[a];
        } else {
            if (a < b) {
                swap(a, b);
            }

            cout << single[a] << ' ' << single[b];
        }

        cout << '\n';
    }
    return 0;
}
