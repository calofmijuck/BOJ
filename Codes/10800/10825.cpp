#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string name;
    int kor, eng, math;
} student;

bool operator<(student a, student b) {
    if(a.kor != b.kor) return a.kor > b.kor;
    if(a.eng != b.eng) return a.eng < b.eng;
    if(a.math != b.math) return a.math > b.math;
    return (a.name).compare(b.name) < 0;
}

vector<student> vec;

int main() {
    int n, kor, eng, math;
    string str;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> str >> kor >> eng >> math;
        vec.push_back({str, kor, eng, math});
    }
    sort(vec.begin(), vec.end());
    for(student s : vec) cout << s.name << '\n';
    return 0;
}
