#include <bits/stdc++.h>
using namespace std;

int calculate_character_sum(string& s) {
    int sum = 0;
    for (char c : s) {
        if ('a' <= c && c <= 'z') {
            sum += c - 'a' + 1;
        } else if ('A' <= c && c <= 'Z') {
            sum += c - 'A' + 27;
        }
    }
    return sum;
}

bool is_prime(int n) {
    if (n <= 2) {
        return true;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string str;
    cin >> str;

    int sum = calculate_character_sum(str);
    if (is_prime(sum)) {
        printf("It is a prime word.");
    } else {
        printf("It is not a prime word.");
    }
    return 0;
}
