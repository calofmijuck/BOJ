#include <bits/stdc++.h>
using namespace std;

void calculate(int& base, int& width, int& height, int& volume) {
    if (base == 0) {
        base = volume / width / height;
    } else if (width == 0) {
        width = volume / base / height;
    } else if (height == 0) {
        height = volume / base / width;
    } else if (volume == 0) {
        volume = base * width * height;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int base, width, height, volume;
    while (true) {
        cin >> base >> width >> height >> volume;
        if (base == 0 and width == 0 and height == 0 and volume == 0) {
            break;
        }

        calculate(base, width, height, volume);
        cout << base << ' ' << width << ' ' << height << ' ' << volume << '\n';
    }
    return 0;
}
