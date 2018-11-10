#include <cstdio>
#include <algorithm>
using namespace std;

int card[10101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", card + i);
    sort(card, card + n);
    printf("%d", max(card[0] * card[1], max(card[n - 1] * card[n - 2], max(card[n - 1] * card[n - 2] * card[n - 3], card[0] * card[1] * card[n - 1]))));
}
