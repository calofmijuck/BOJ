#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, sum = 0;
    for(int i = 0; i < 5; ++i) {
        cin >> x;
        sum += x;
    }
    cout << sum;
}
