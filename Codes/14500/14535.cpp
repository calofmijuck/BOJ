#include <bits/stdc++.h>
using namespace std;

vector<string> MONTHS = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

void print_birthday_graph(int data) {
    vector<int> count(12, 0);
    for (int i = 0; i < data; ++i) {
        int day, month, year;
        scanf("%d %d %d", &day, &month, &year);

        count[month - 1]++;
    }

    for (int i = 0; i < 12; ++i) {
        printf("%s:", MONTHS[i].c_str());
        for (int j = 0; j < count[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int tc = 1;
    while (true) {
        int data;
        scanf("%d", &data);
        if (data == 0) {
            break;
        }

        printf("Case #%d:\n", tc);
        print_birthday_graph(data);

        tc++;
    }
    return 0;
}
