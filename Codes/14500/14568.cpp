#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 2; i <= n - 2; i += 2) {
        sum += (n - i - 2) / 2;
    }
    cout << sum;
}
