#include <iostream>
#include <vector>
using namespace std;

pair<int, int> find_min_max(vector<int>& numbers) {
    int minimum = 1e6;
    int maximum = -1e6;
    for (int e : numbers) {
        if (e < minimum) {
            minimum = e;
        }

        if (e > maximum) {
            maximum = e;
        }
    }
    return { minimum, maximum };
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    auto [minimum, maximum] = find_min_max(numbers);
    cout << minimum << ' ' << maximum;
    return 0;
}
