#include <bits/stdc++.h>
using namespace std;

void print_triangle(int number, vector<int>& sides) {
    cout << "Triangle #" << number << '\n';

    int squared = 0;
    int index = find(begin(sides), end(sides), -1) - begin(sides);
    if (index == 0) {
        squared = sides[2] * sides[2] - sides[1] * sides[1];
    } else if (index == 1) {
        squared = sides[2] * sides[2] - sides[0] * sides[0];
    } else if (index == 2) {
        squared = sides[0] * sides[0] + sides[1] * sides[1];
    } else {
        // ignore
    }

    if (squared <= 0) {
        cout << "Impossible.\n\n";
        return;
    }

    cout << fixed << char('a' + index) << " = " << sqrt(squared) << "\n\n";
}

bool finish(vector<int>& sides) {
    return sides[0] == 0 and sides[1] == 0 and sides[2] == 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout.precision(3);

    vector<int> sides(3);
    int number = 1;
    while (true) {
        for (int i = 0; i < 3; ++i) {
            cin >> sides[i];
        }

        if (finish(sides)) {
            break;
        }

        print_triangle(number, sides);
        number++;
    }
    return 0;
}
