#include <bits/stdc++.h>
using namespace std;

vector<int> threshold = { 97, 90, 87, 80, 77, 70, 67, 60, 0 };
vector<string> grades = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F" };

string grade(int score) {
    int index = 0;
    while (score < threshold[index] && index < (int) threshold.size()) {
        index++;
    }
    return grades[index];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string name;
    int score;
    for (int i = 0; i < n; ++i) {
        cin >> name >> score;
        cout << name << ' ' << grade(score) << '\n';
    }
    return 0;
}
