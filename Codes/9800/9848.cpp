#include <bits/stdc++.h>
using namespace std;

int main() {
    int records, diff;
    scanf("%d %d", &records, &diff);

    vector<int> record(records);
    for (int i = 0; i < records; ++i) {
        scanf("%d", &record[i]);
    }

    int gift = 0;
    for (int i = 1; i < records; ++i) {
        if (record[i - 1] - record[i] >= diff) {
            gift++;
        }
    }

    printf("%d", gift);
    return 0;
}
