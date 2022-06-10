#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int laptop_width, laptop_height, sticker_width, sticker_height;
    cin >> laptop_width >> laptop_height >> sticker_width >> sticker_height;

    cout << (int) ((laptop_width - 2 >= sticker_width) and (laptop_height - 2 >= sticker_height));
    return 0;
}
