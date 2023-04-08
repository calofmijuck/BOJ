#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(10);

    int problems, solved, total_average, estimated_average;
    cin >> problems >> solved >> total_average >> estimated_average;

    double answer = (problems * total_average - solved * estimated_average) / double(problems - solved);
    if (answer < 0 || answer > 100) {
        cout << "impossible";
    } else {
        cout << fixed << answer;
    }
    return 0;
}
