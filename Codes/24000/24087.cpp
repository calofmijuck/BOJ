#include <bits/stdc++.h>
using namespace std;

const int default_cost = 250;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int height, default_height, layer_height;
    cin >> height >> default_height >> layer_height;

    if (default_height >= height) {
        cout << default_cost;
        return 0;
    }

    int layer_cost = (int) ceil((double) (height - default_height) / layer_height) * 100;
    cout << default_cost + layer_cost;
    return 0;
}
