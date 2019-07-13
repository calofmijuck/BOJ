#include <iostream>
using namespace std;

int main() {
    int left = 5000, x;
    while(~scanf("%d", &x)) {
        if(x == 1) left -= 500;
        else if(x == 2) left -= 800;
        else left -= 1000;
    }
    printf("%d", left);
}
