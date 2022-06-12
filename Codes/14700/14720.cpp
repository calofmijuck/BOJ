#include <bits/stdc++.h>
using namespace std;

int get_next_milk(int n) {
    return (n + 1) % 3;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int store;
    cin >> store;

    int drinkable = 0;
    int milk_state = 0;
    for (int i = 0; i < store; ++i) {
        int next_store;
        cin >> next_store;

        if (next_store == milk_state) {
            drinkable++;
            milk_state = get_next_milk(milk_state);
        }
    }

    cout << drinkable;
    return 0;
}
