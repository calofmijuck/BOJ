#include <bits/stdc++.h>
using namespace std;

int get_class(int height, int weight) {
    double bmi = weight / pow(height * 0.01, 2);

    if (height < 140.1) {
        return 6;
    }

    if (height < 146) {
        return 5;
    }

    if (height < 159) {
        return 4;
    }

    if (height < 161) {
        if (16 <= bmi and bmi < 35) {
            return 3;
        }

        return 4;
    }

    if (height < 204) {
        if (20 <= bmi and bmi < 25) {
            return 1;
        }

        if ((18.5 <= bmi and bmi < 20) or (25 <= bmi and bmi < 30)) {
            return 2;
        }

        if ((16 <= bmi and bmi < 18.5) or (30 <= bmi and bmi < 35)) {
            return 3;
        }

        return 4;
    }

    return 4;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int people;
    cin >> people;
    while (people--) {
        int height, weight;
        cin >> height >> weight;

        cout << get_class(height, weight) << '\n';
    }
    return 0;
}
