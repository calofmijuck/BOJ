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


int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    int x = n;
    while(n > 2) {
        printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n\n", n, n, n - 1);
        n--;
    }
    if(n == 2) {
        printf("2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n\n");
    }
    printf("1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\n\n");
    if(n == 1) {
        printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 1 bottle of beer on the wall.");
    } else {
        printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottles of beer on the wall.", x);
    }
    
 
}

