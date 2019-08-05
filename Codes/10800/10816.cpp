#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()
#define pb push_back

int cnt[20000010];

int main() {
    int bias = 1e7;
    int n, m, x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        cnt[x + bias]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        printf("%d ", cnt[x + bias]);
    }
}