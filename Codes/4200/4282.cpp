#include <bits/stdc++.h>
using namespace std;

typedef tuple<float, float, float> coordinate;

const coordinate origin = make_tuple(0, 0, 0);

coordinate sub(coordinate a, coordinate b) {
    return make_tuple(get<0>(a) - get<0>(b), get<1>(a) - get<1>(b), get<2>(a) - get<2>(b));
}

float norm(coordinate a) {
    return sqrt(get<0>(a) * get<0>(a) + get<1>(a) * get<1>(a) + get<2>(a) * get<2>(a));
}

float dot_product(coordinate a, coordinate b) {
    return get<0>(a) * get<0>(b) + get<1>(a) * get<1>(b) + get<2>(a) * get<2>(b);
}

float cos(coordinate a, coordinate b) {
    float norm_a = norm(a);
    float norm_b = norm(b);
    if (norm_a == 0 || norm_b == 0) {
        return 0;
    }

    return dot_product(a, b) / (norm_a * norm_b);
}

void solve(int satellites, int targets) {
    vector<coordinate> satellite;
    vector<coordinate> target;

    for (int i = 0; i < satellites; ++i) {
        float x, y, z;
        cin >> x >> y >> z;
        satellite.push_back(make_tuple(x, y, z));
    }

    for (int i = 0; i < targets; ++i) {
        float x, y, z;
        cin >> x >> y >> z;
        target.push_back(make_tuple(x, y, z));
    }

    vector<bool> can_target(satellites, false);
    for (auto s : satellite) {
        for (int i = 0; i < targets; ++i) {
            if (can_target[i]) {
                continue;
            }

            auto t = target[i];
            if (cos(sub(s, t), sub(origin, t)) <= 0) {
                can_target[i] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < satellites; ++i) {
        if (can_target[i]) {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, k;
    cin >> m >> k;
    while (m != 0 && k != 0) {
        solve(m, k);
        cin >> m >> k;
    }
    return 0;
}
