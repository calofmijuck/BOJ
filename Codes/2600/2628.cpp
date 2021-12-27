#include <bits/stdc++.h>
using namespace std;

int width, height;
vector<int> horizontal, vertical;

int find_max_diff(vector<int>& vec) {
    int max_diff = 0, prev = 0;
    for (int i = 0; i < (int) vec.size(); ++i) {
        int diff = vec[i] - prev;
        max_diff = max(diff, max_diff);
        prev = vec[i];
    }
    
    return max_diff;
}

int find_max_area() {
    sort(horizontal.begin(), horizontal.end());
    sort(vertical.begin(), vertical.end());

    int max_horizontal_diff = find_max_diff(horizontal);
    int max_vertical_diff = find_max_diff(vertical);

    return max_horizontal_diff * max_vertical_diff;
}

int main() {
    cin >> width >> height;

    int cuts;
    cin >> cuts;
    for (int i = 0; i < cuts; ++i) {
        int direction, location;
        cin >> direction >> location;
        if (direction == 0) {
            horizontal.push_back(location);
        } else {
            vertical.push_back(location);
        }
    }

    horizontal.push_back(height);
    vertical.push_back(width);

    cout << find_max_area();
    return 0;
}
