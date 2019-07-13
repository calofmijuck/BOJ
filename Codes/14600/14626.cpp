#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int sum = 0, mult;
    for(int i = 0; i < str.size(); ++i) {
        char c = str[i];
        if(c != '*') {
            if(i % 2 == 0) sum += str[i] - '0';
            else sum += 3 * (str[i] - '0');
        } else {
            if(i % 2 == 0) mult = 1;
            else mult = 3;
        }
    }
    for(int i = 0; i < 10; ++i) {
        if((sum + mult * i) % 10 == 0) printf("%d", i);
    }
}
