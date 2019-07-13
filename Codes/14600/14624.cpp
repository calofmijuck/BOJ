#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n % 2 == 0) {
        puts("I LOVE CBNU");
        return 0;
    }
    for(int i = 0; i < n; ++i) printf("*");
    puts("");
    for(int i = 0; i < n / 2; ++i) printf(" ");
    printf("*");
    puts("");
    for(int i = 1; i < (n + 1) / 2; ++i) {
        for(int j = n / 2 - i; j > 0; --j) printf(" ");
        printf("*");
        for(int j = 0; j < 2 * i - 1; ++j) printf(" ");
        printf("*");
        puts("");
    }
    return 0;
}
