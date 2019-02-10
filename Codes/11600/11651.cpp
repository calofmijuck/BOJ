#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& a) const {
        if(y == a.y) return x < a.x;
        else return y < a.y;
    }
};

Point arr[101010];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d %d", &arr[i].x, &arr[i].y);
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i) printf("%d %d\n", arr[i].x, arr[i].y);
    return 0;
}
