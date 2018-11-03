#include <bits/stdc++.h>
using namespace std;

double point(int n, char c) {
    if(c == '+') return n + 0.3;
    if(c == '0') return n;
    if(c == '-') return n - 0.3;
}

int main() {
    string str, grade;
    int t, n, sum = 0;
    double total = 0;
    scanf("%d", &t);
    while(t--) {
        cin >> str >> n >> grade;
        if(grade.at(0) == 'A') {
            total += n * point(4, grade.at(1));
        } else if(grade.at(0) == 'B') {
            total += n * point(3, grade.at(1));
        } else if(grade.at(0) == 'C') {
            total += n * point(2, grade.at(1));
        } else if(grade.at(0) == 'D') {
            total += n * point(1, grade.at(1));
        }
        sum += n;
    }
    printf("%.2lf\n", floor((total / sum) * 100 + 0.5) / 100.0);

}
