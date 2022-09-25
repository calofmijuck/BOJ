#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int waist, neck, punches;
    cin >> waist >> neck >> punches;

    int count = 0;
    for (int i = 0; i < punches; ++i) {
        int height;
        cin >> height;

        if (waist <= height and height <= neck) {
            count++;
        }
    }
    cout << count;
    return 0;
}
