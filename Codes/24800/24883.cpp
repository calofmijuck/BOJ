#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    char alphabet;
    cin >> alphabet;

    if (alphabet == 'N' or alphabet == 'n') {
        cout << "Naver D2";
    } else {
        cout << "Naver Whale";
    }
    return 0;
}
