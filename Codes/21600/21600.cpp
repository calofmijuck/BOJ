#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> histogram) {
    deque<int> dq;

    int answer = 0;
    int height = 1;
    for (int e : histogram) {
        if (height <= e) {
            height++;
        } else {
            int pop_count = max(0, int(dq.size()) - e + 1);
            while (pop_count--) {
                dq.pop_front();
            }
            height = e + 1;
        }
        dq.push_back(e);
        answer = max(answer, (int) dq.size());
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> histogram(n);
    for (int& e : histogram) {
        cin >> e;
    }

    cout << solve(histogram);
    return 0;
}
