#include <bits/stdc++.h>
using namespace std;

int determine_luggage() {
    double length, width, depth, weight;
    cin >> length >> width >> depth >> weight;

    return ((length <= 56 && width <= 45 && depth <= 25) || (length + width + depth) <= 125) && weight <= 7;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int allowed = 0;
    for (int i = 0; i < n; ++i) {
        int result = determine_luggage();
        cout << result << '\n';

        if (result) {
            allowed++;
        }
    }
    cout << allowed;
    return 0;
}
