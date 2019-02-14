#include <cstdio>
#include <algorithm>
using namespace std;

int arr[101010];

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    scanf("%d", &m);
    int find;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &find);
        if(binary_search(arr, arr + n, find)) puts("1");
        else puts("0");
    }
    return 0;
}
