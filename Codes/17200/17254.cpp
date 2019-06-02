#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, char> tiic;

vector<tiic> vec;

int main() {
    int n, m, a, b;
    char c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %c", &a, &b, &c);
        vec.push_back(make_tuple(b, a, c));
    }
    sort(vec.begin(), vec.end());
    for(tiic t : vec) {
        printf("%c", get<2>(t));
    }
    return 0;
}
