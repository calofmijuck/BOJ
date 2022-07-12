#include <bits/stdc++.h>
using namespace std;

int calculate_leaves(int age) {
    int leaves = 1;
    int splitting_factor, cut;
    for (int i = 0; i < age; ++i) {
        cin >> splitting_factor >> cut;
        leaves = (long long) leaves * splitting_factor - cut;
    }
    return leaves;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int age;
    while (true) {
        cin >> age;
        if (age == 0) {
            break;
        }

        cout << calculate_leaves(age) << '\n';
    }
    return 0;
}
