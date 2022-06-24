#include <bits/stdc++.h>
using namespace std;

int cup[5] = {0, 1, 2, 3, 4};

pair<int, int> get_transposition(char c) {
    switch (c) {
        case 'A':
            return { 1, 2 };
        case 'B':
            return { 1, 3 };
        case 'C':
            return { 1, 4 };
        case 'D':
            return { 2, 3 };
        case 'E':
            return { 2, 4 };
        case 'F':
            return { 3, 4 };
        default:
            return { 0, 0 };
    }
}

void apply_permutation(string& mix) {
    for (char c : mix) {
        pair<int, int> transposition = get_transposition(c);
        swap(cup[transposition.first], cup[transposition.second]);
    }
}

int index_of(int x) {
    for (int idx = 1; idx <= 4; ++idx) {
        if (cup[idx] == x) {
            return idx;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string mix;
    cin >> mix;

    apply_permutation(mix);

    cout << index_of(1) << '\n' << index_of(4);
    return 0;
}
