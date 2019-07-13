#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

pii arr[110];
int lis[110];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i) lis[i] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(arr[j].second < arr[i].second) lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    int mlen = 0;
    for(int i = 0; i < n; ++i) mlen = max(mlen, lis[i]);
    printf("%d", n - mlen);
}
