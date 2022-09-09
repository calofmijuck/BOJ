#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int width, height, area;
    while (true) {
        cin >> width >> height >> area;
        if (width == 0 and height == 0 and area == 0) {
            break;
        }

        if (area == 0) {
            area = width * height;
        }

        if (height == 0) {
            height = area / width;
        }

        if (width == 0) {
            width = area / height;
        }

        cout << width << ' ' << height << ' ' << area << '\n';
    }
    return 0;
}
