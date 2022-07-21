#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int dev_time, run_count, sequential, parallel;
        cin >> dev_time >> run_count >> sequential >> parallel;

        int parallel_time = dev_time + run_count * parallel;
        int sequential_time = run_count * sequential;

        if (parallel_time > sequential_time) {
            cout << "do not parallelize\n";
        } else if (parallel_time < sequential_time) {
            cout << "parallelize\n";
        } else {
            cout << "does not matter\n";
        }
    }
    return 0;
}
