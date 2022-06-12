#include <bits/stdc++.h>
using namespace std;

int count_369(int x) {
    int count = 0;
    while (x > 0) {
        int r = x % 10;
        if (r == 3 or r == 6 or r == 9) {
            count++;
        }
        x /= 10;
    }
    return count;
}

int clap_count(int n) {
    int total_count = 0;
    for (int i = 1; i <= n; ++i) {
        total_count += count_369(i);
    }
    return total_count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    cout << clap_count(n);
    return 0;
}
