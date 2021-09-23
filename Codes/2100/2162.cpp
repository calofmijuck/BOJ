#include <bits/stdc++.h>
using namespace std;

template <typename T>
T sgn(T x) {
    return (x > 0) - (x < 0);
}

template <typename T>
class line_segment {
public:
    class point {
    public:
        T x, y;

        static point subtract(point p1, point p2) {
            return {p1.x - p2.x, p1.y - p2.y};
        }

        static T cross_product(point p1, point p2) {
            return p1.x * p2.y - p1.y * p2.x;
        }

        static T ccw(point p1, point p2, point p3) {
            return sgn(cross_product(subtract(p2, p1), subtract(p3, p2)));
        }

        bool operator==(const point& other) {
            return x == other.x && y == other.y;
        }

        bool operator<(const point& other) {
            return (x < other.x) || (!(other.x < x) && y < other.y);
        }

        bool operator<=(const point& other) {
            return (x < other.x) || (!(other.x < x) && y <= other.y);
        }
    } p, q;

    static bool check_intersection(line_segment<T> l1, line_segment<T> l2) {
        int x = point::ccw(l1.p, l1.q, l2.p) * point::ccw(l1.p, l1.q, l2.q);
        int y = point::ccw(l2.p, l2.q, l1.p) * point::ccw(l2.p, l2.q, l1.q);
        if (x == 0 && y == 0) {
            if (l1.q < l1.p) {
                swap(l1.p, l1.q);
            }
            if (l2.q < l2.p) {
                swap(l2.p, l2.q);
            }
            return l1.p <= l2.q && l2.p <= l1.q;
        }
        return x <= 0 && y <= 0;
    }
};

class disjoint_set {
private:
    vector<int> p, rank, size;
public:
    disjoint_set(int n) {
        rank.assign(n, 0);
        p.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }

    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void union_set(int i, int j) {
        int x = find_set(i), y = find_set(j);
        if (x == y) return;

        if (rank[x] > rank[y]) {
            p[y] = x;
            size[x] += size[y];
        } else {
            p[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }

    int get_size(int i) {
        return size[find_set(i)];
    }
};

pair<int, int> find_segment_groups(int n, vector<line_segment<int>>& segments) {
    int union_count = 0;

    disjoint_set ds(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds.is_same_set(i, j)) {
                continue;
            }

            bool intersects = line_segment<int>::check_intersection(segments[i], segments[j]);
            if (intersects) {
                ds.union_set(i, j);
                union_count++;
            }
        }
    }

    int max_group_size = 0;
    for (int i = 0; i < n; ++i) {
        max_group_size = max(max_group_size, ds.get_size(i));
    }

    return make_pair(n - union_count, max_group_size);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    vector<line_segment<int>> segments(n);
    for (line_segment<int>& line : segments) {
        cin >> line.p.x >> line.p.y >> line.q.x >> line.q.y;
    }

    auto [group_count, max_group_size] = find_segment_groups(n, segments);
    cout << group_count << '\n' << max_group_size;
    return 0;
}
