#include <bits/stdc++.h>
using namespace std;

int main() {
    int notes;
    scanf("%d", &notes);

    double length = 0;
    for (int i = 0; i < notes; ++i) {
        int code;
        scanf("%d", &code);
        if (code == 0) {
            length += 2;
        } else {
            length += 1.0 / code;
        }
    }

    printf("%.7lf", length);
    return 0;
}
