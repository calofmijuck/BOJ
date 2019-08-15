#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if(a + b >= 2 * c) {
        cout << (a + b - 2 * c);
    } else cout << a + b;
}
