#include <iostream>
using namespace std;
typedef long long ll;

int val[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int arr[250];

int main() {
    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    int i = 0, j = 0, k = m + n;
    while(i < n && j < m) {
        arr[i++ + j] = val[A[i] - 'A'];
        arr[i + j++] = val[B[j] - 'A'];
    }
    while(i < n) arr[i++ + j] = val[A[i] - 'A'];
    while(j < m) arr[i + j++] = val[B[j] - 'A'];
    for(int i = 0; i < k - 2; ++i) {
        for(int j = 0; j < k - 1 - i; ++j) arr[j] = (arr[j] + arr[j + 1]) % 10;
    }
    printf("%d%%", 10 * arr[0] + arr[1]);
}
