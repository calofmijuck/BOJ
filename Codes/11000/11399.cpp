#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, input;
    long long sum = 0;
    scanf("%d", &n);
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        scanf("%d", &input);
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++) sum += (n - i) * vec[i];
    printf("%lld", sum);
}
