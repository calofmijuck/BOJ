#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    string str;
    cin >> n >> str;
    for(int i = 0; i < str.size(); i++) {
        sum += str.at(i) - '0';
    }
    printf("%d", sum);
}
