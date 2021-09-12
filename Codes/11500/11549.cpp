#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int answer, guess, correct = 0;
    cin >> answer;
    for (int i = 0; i < 5; ++i) {
        cin >> guess;
        if (guess == answer) {
            correct++;
        }
    }
    cout << correct;
    return 0;
}
