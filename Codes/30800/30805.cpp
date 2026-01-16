#include <bits/stdc++.h>
using namespace std;

using hint_map = map<int, vector<int>*>;

hint_map* preprocess(vector<int>& vec) {
    hint_map* hint = new hint_map();
    for (int i = 0; i < (int) vec.size(); ++i) {
        if (hint->find(vec[i]) == hint->end()) {
            hint->emplace(vec[i], new vector<int>());
        }
        hint->at(vec[i])->push_back(i);
    }
    return hint;
}

int find_first(vector<int>& vec, int idx) {
    for (int e : vec) {
        if (e > idx) {
            return e;
        }
    }
    return -1;
}

void solve(vector<int>& a, vector<int>& b) {
    hint_map* a_hint = preprocess(a);
    hint_map* b_hint = preprocess(b);

    auto a_it = a_hint->rbegin();
    auto b_it = b_hint->rbegin();

    vector<int> answer;

    int a_idx = -1, b_idx = -1;
    while (a_it != a_hint->rend() && b_it != b_hint->rend()) {
        // shared value in sequence
        int a_val = a_it->first;
        int b_val = b_it->first;

        if (a_val == b_val) {
            // do something
            int a_first = find_first(*a_it->second, a_idx);
            int b_first = find_first(*b_it->second, b_idx);
            // cannot add this number to sequence
            if (a_first == -1 || b_first == -1) {
                a_it++;
                b_it++;
            } else {
                a_idx = a_first;
                b_idx = b_first;
                answer.push_back(a_val);
            }
        } else if (a_val < b_val) {
            b_it++;
        } else {
            a_it++;
        }
    }

    cout << answer.size() << '\n';
    for (int e : answer) {
        cout << e << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& e : a) {
        cin >> e;
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (auto& e : b) {
        cin >> e;
    }

    solve(a, b);
    return 0;
}
