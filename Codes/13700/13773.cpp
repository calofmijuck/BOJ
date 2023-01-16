#include <bits/stdc++.h>
using namespace std;

bool is_world_war(int year) {
    return (1914 <= year && year <= 1918) || (1939 <= year && year <= 1945);
}

void check_year(int year) {
    printf("%d ", year);
    if (year < 1896 || year % 4 != 0) {
        puts("No summer games");
        return;
    }

    if (is_world_war(year)) {
        puts("Games cancelled");
        return;
    }

    if (year >= 2024) {
        puts("No city yet chosen");
        return;
    }

    puts("Summer Olympics");
    return;
}

int main() {
    int year;
    while (true) {
        scanf("%d", &year);
        if (year == 0) {
            break;
        }

        check_year(year);
    }
    return 0;
}
