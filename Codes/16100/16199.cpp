#include <bits/stdc++.h>
using namespace std;

int birth_year, birth_month, birth_day;
int year, month, day;

int legal_age() {
    int age = year - birth_year;
    if (make_pair(birth_month, birth_day) > make_pair(month, day)) {
        age--;
    }
    return age;
}

int counting_age() {
    return year - birth_year + 1;
}

int year_age() {
    return year - birth_year;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> birth_year >> birth_month >> birth_day;
    cin >> year >> month >> day;

    cout << legal_age() << '\n' << counting_age() << '\n' << year_age();
    return 0;
}
