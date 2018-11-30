#include <bits/stdc++.h>
using namespace std;

int arr[6];

bool ccw() {
    int t = (arr[0] - arr[2]) * (arr[3] - arr[5]) - (arr[1] - arr[3]) * (arr[2] - arr[4]);
    if(t) return false;
    else return true;
}

int main() {
    for(int i = 0; i < 6; ++i)
        scanf("%d", arr + i);
    if(ccw()) printf("WHERE IS MY CHICKEN?");
    else printf("WINNER WINNER CHICKEN DINNER!");
    return 0;
}
