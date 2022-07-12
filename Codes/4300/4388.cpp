#include <bits/stdc++.h>
using namespace std;

queue<int> convert(int x) {
    queue<int> q;
    if (x == 0) {
        q.push(0);
        return q;
    }

    while (x > 0) {
        q.push(x % 10);
        x /= 10;
    }

    return q;
}

int count_carry(int a, int b) {
    queue<int> q_a = convert(a);
    queue<int> q_b = convert(b);

    int carry_count = 0;
    int carry = 0;
    while (!q_a.empty() and !q_b.empty()) {
        int top_a = q_a.front(), top_b = q_b.front();
        q_a.pop(), q_b.pop();

        int sum = top_a + top_b + carry;
        if (sum >= 10) {
            carry_count++;
            carry = sum / 10;
        }
    }

    while (!q_a.empty()) {
        int top_a = q_a.front();
        q_a.pop();

        int sum = top_a + carry;
        if (sum >= 10) {
            carry_count++;
            carry = sum / 10;
        }
    }

        while (!q_b.empty()) {
        int top_b = q_b.front();
        q_b.pop();

        int sum = top_b + carry;
        if (sum >= 10) {
            carry_count++;
            carry = sum / 10;
        }
    }

    return carry_count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == 0 and b == 0) {
            break;
        }

        cout << count_carry(a, b) << '\n';
    }
    return 0;
}
