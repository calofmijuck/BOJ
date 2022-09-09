#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int distance, train, airplane;
    while (true) {
        cin >> distance >> train >> airplane;
        if (distance == 0 and train == 0 and airplane == 0) {
            break;
        }

        double train_time = double(distance) / train * 3600;
        double airplane_time = double(distance) / airplane * 3600;

        int diff = int(round(train_time - airplane_time));

        int hour = diff / 3600;
        int minute = (diff % 3600) / 60;
        int second = diff % 60;

        cout << hour << ':';
        cout << setfill('0') << setw(2) << minute << ':';
        cout << setfill('0') << setw(2) << second << '\n';
    }
    return 0;
}
