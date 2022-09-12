#include <bits/stdc++.h>
using namespace std;

int eval(int a, int b, int x) {
    return x * x + 2 * a * x + b;
}

vector<int> solve_quadratic(int a, int b) {
    vector<int> solutions;
    for (int i = -1000; i <= 1000; ++i) {
        if (eval(a, b, i) == 0) {
            solutions.push_back(i);
        }
    }
    return solutions;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    vector<int> solutions = solve_quadratic(a, b);
    for (int e : solutions) {
        cout << e << ' ';
    }
    return 0;
}
