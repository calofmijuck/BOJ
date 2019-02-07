#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int date, month, year;
    bool operator<(const Person &p) const {
        if(year == p.year) {
            if(month == p.month) {
                return date < p.date;
            } else return month < p.month;
        } else return year < p.year;
    }
};

Person p[101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i].name >> p[i].date >> p[i].month >> p[i].year;
    }
    sort(p, p + n);
    cout << p[n - 1].name << '\n' << p[0].name;
    return 0;
}
