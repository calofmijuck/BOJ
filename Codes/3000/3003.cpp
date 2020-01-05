#include <bits/stdc++.h>
using namespace std;

int main() {
    int king, queen, rook, bishop, knight, pawn;
    scanf("%d%d%d%d%d%d", &king, &queen, &rook, &bishop, &knight, &pawn);
    printf("%d %d %d %d %d %d", 1 - king, 1 - queen, 2 - rook, 2 - bishop, 2 - knight, 8 - pawn);
    return 0;
}
