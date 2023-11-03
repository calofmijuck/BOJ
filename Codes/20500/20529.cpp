#include <bits/stdc++.h>
using namespace std;

int mbti_to_int(string& mbti) {
    int result = 0;
    for (char c : mbti) {
        if (c == 'I') {
            result += 8;
        } else if (c == 'N') {
            result += 4;
        } else if (c == 'F') {
            result += 2;
        } else if (c == 'P') {
            result += 1;
        }
    }
    return result;
}

int emotional_distance(int x, int y) {
    return __builtin_popcount(x ^ y);
}

void find_min_emotional_distance() {
    int n;
    cin >> n;

    string mbti;

    vector<int> mbti_count(16);
    vector<int> mbtis;

    for (int i = 0; i < n; ++i) {
        cin >> mbti;
        int converted = mbti_to_int(mbti);

        if (mbti_count[converted] < 3) {
            mbtis.push_back(converted);
        }

        mbti_count[converted]++;
    }

    for (int i = 0; i < 16; ++i) {
        if (mbti_count[i] >= 3) {
            cout << 0 << '\n';
            return;
        }
    }

    int min_distance = 0x7FFFFFFF;

    int size = mbtis.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int dist_ij = emotional_distance(mbtis[i], mbtis[j]);
            for (int k = j + 1; k < size; ++k) {
                int dist_jk = emotional_distance(mbtis[j], mbtis[k]);
                int dist_ki = emotional_distance(mbtis[k], mbtis[i]);

                int sum = dist_ij + dist_jk + dist_ki;
                if (sum < min_distance) {
                    min_distance = sum;
                }
            }
        }
    }
    cout << min_distance << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        find_min_emotional_distance();
    }
    return 0;
}
