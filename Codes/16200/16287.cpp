#include <bitset>
#include <cstdio>
using namespace std;

int arr[5050];
bitset<400005> flag;

int main() {
    int w, n;
    scanf("%d %d", &w, &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr + i);
    for(int i = 1; i < n - 2; ++i) {
        for(int j = 0; j < i; ++j) flag[arr[i] + arr[j]] = true;
        for(int j = i + 2; j < n; ++j) {
            int curr = w - arr[i + 1] - arr[j];
            if(curr >= 0 && curr <= 400000 && flag[curr]) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
