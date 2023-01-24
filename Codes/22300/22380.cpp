#include <bits/stdc++.h>
using namespace std;

void collect_money(int people, int money) {
    int per_people = money / people;
    int collectable = 0;
    for (int i = 0; i < people; ++i) {
        int x;
        scanf("%d", &x);

        collectable += (x >= per_people) ? per_people : x;
    }
    printf("%d\n", collectable);
}

int main() {
    while (true) {
        int people, money;
        scanf("%d %d", &people, &money);
        if (people == 0 && money == 0) {
            break;
        }

        collect_money(people, money);
    }
    return 0;
}
