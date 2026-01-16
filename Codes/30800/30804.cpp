#include <bits/stdc++.h>
using namespace std;

inline int count_nonzeros(vector<int> counter) {
    int ret = 0;
    for (int i = 1; i <= 9; ++i) {
        ret += counter[i] != 0;
    }
    return ret;
}

int solve(int fruit) {
    vector<int> tanghuru(fruit);
    vector<int> counter(10);
    for (auto& f : tanghuru) {
        cin >> f;
    }

    int left = 0, right = 0, ans = 0;
    counter[tanghuru[left]]++;
    while (left < fruit && right < fruit) {
        int check = count_nonzeros(counter);
        if (check <= 2) {
            ans = max(ans, right - left + 1);
            right++;
            counter[tanghuru[right]]++;
        } else {
            counter[tanghuru[left]]--;
            left++;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}
