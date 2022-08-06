#include <bits/stdc++.h>
using namespace std;

struct person {
    int number;
    int score;
    int submit_count;
    int upload_time;
};

bool compare(person& p1, person& p2) {
    if (p1.score != p2.score) {
        return p1.score > p2.score;
    }

    if (p1.submit_count != p2.submit_count) {
        return p1.submit_count < p2.submit_count;
    }

    if (p1.upload_time != p2.upload_time) {
        return p1.upload_time < p2.upload_time;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<person> participants;

    int score, submit_count, upload_time;
    for (int i = 0; i < n; ++i) {
        cin >> score >> submit_count >> upload_time;

        person p = { i + 1, score, submit_count, upload_time };
        participants.push_back(p);
    }

    sort(begin(participants), end(participants), compare);

    cout << participants[0].number;
    return 0;
}
