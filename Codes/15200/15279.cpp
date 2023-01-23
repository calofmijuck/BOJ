#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        double beats, seconds;
        scanf("%lf %lf", &beats, &seconds);

        double bpm = 60 * beats / seconds;
        double max_abpm = 60 / (seconds / (beats + 1));
        double min_abpm = 60 / (seconds / (beats - 1));
        printf("%.5lf %.5lf %.5lf\n", min_abpm, bpm, max_abpm);
    }
    return 0;
}
