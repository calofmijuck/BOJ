#include <iostream>
using namespace std;

int score[1000];

double above_average_rate() {
    int n;
    cin >> n;

    int score_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
        score_sum += score[i];
    }

    double average = (double) score_sum / n;

    int above_average = 0;
    for (int i = 0; i < n; ++i) {
        if (score[i] > average) {
            above_average++;
        }
    }

    return (double) above_average / n * 100;
}

int main() {
    cout << fixed;
    cout.precision(3);

    int c;
    cin >> c;
    while (c--) {
        cout << above_average_rate() << "%\n";
    }
    return 0;
}
