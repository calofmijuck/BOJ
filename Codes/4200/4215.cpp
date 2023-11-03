#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<int, char>> program;

const int max_multiplications = 29;
const ll limit = 1e9;

int program_length(program& p) {
    int length = 0;
    for (pair<int, char> command : p) {
        length += command.first;
    }
    return length;
}

vector<program> find_shortest_program(vector<program>& programs) {
    int min_length = 0x7FFFFFFF;

    vector<program> shortest;
    for (program& p : programs) {
        int length = program_length(p);
        if (length < min_length) {
            shortest.clear();
            shortest.push_back(p);
            min_length = length;
        } else if (length == min_length) {
            shortest.push_back(p);
        }
    }
    return shortest;
}

bool compare_programs(program& p1, program& p2) {
    int i = 0;
    while (i < (int) p1.size() && i < (int) p2.size()) {
        pair<int, char> command1 = p1[i];
        pair<int, char> command2 = p2[i];
        if (command1.second != command2.second) {
            return command1.second < command2.second;
        } else if (command1.first != command2.first) {
            if (command1.second == 'M') {
                return command1.first < command2.first;
            } else if (command1.second == 'A') {
                return command1.first > command2.first;
            }
        } else {
            i++;
        }
    }
    return true;
}

program build_candidate(int g, vector<int> additions) {
    program candidate;
    for (int i = 0; i <= g; ++i) {
        if (i < (int) additions.size()) {
            if (additions[i] != 0) {
                candidate.push_back({ additions[i], 'A' });
            }
        }
        if (i != g) {
            candidate.push_back({ 1, 'M' });
        }
    }
    return candidate;
}

vector<int> minimize_addition(int a, int g, int m, ll prod, ll left, ll right) {
    vector<int> addition;
    for (int i = 0; i <= g; ++i) {
        ll u = (left + a * prod - 1) / (a * prod);
        ll v = right / (a * prod);

        if (u <= v) {
            int h = max(u, 0LL);
            addition.push_back(h);
            left -= h * a * prod;
            right -= h * a * prod;
            break;
        } else {
            addition.push_back(v);
            left -= v * a * prod;
            right -= v * a * prod;
        }

        prod /= m;
    }

    if (left > 0) {
        return {}; // does not satisfy
    } else {
        return addition;
    }
}

vector<program> find_candidates(int a, int m, int p, int q, int r, int s) {
    vector<program> candidates;

    ll prod = 1;
    for (int g = 0; g <= max_multiplications; ++g) {
        ll left = r - p * prod;
        ll right = s - q * prod;

        if (right < 0) {
            break;
        }

        if (right < left) {
            continue;
        }

        vector<int> additions = minimize_addition(a, g, m, prod, left, right);
        if (additions.size() != 0) {
            program candidate = build_candidate(g, additions);
            if (candidate.size() != 0) {
                candidates.push_back(candidate);
            }
        }

        prod *= m;
        if (prod > limit) {
            break;
        }
    }
    return candidates;
}

program find_minimal_program(int a, int m, int p, int q, int r, int s) {
    vector<program> candidates = find_candidates(a, m, p, q, r, s);

    // impossible
    if (candidates.size() == 0) {
        return {};
    }

    candidates = find_shortest_program(candidates);
    sort(begin(candidates), end(candidates), compare_programs);

    return candidates[0];
}

program compress_program(program& p) {
    int counter = 0;

    program compressed;
    for (int i = 0; i < (int) p.size(); ++i) {
        pair<int, char> command = p[i];
        if (command.second == 'A') {
            if (command.first != 0) {
                compressed.push_back(command);
            }
        } else {
            if (i + 1 < (int) p.size() && p[i + 1].second == 'M') {
                counter++;
            } else {
                compressed.push_back({ counter + 1, 'M' });
                counter = 0;
            }
        }
    }
    return compressed;
}

void print_program(program& p) {
    p = compress_program(p);
    for (pair<int, char> command : p) {
        cout << command.first << command.second << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, m, p, q, r, s;
    for (int tc = 1; true; tc++) {
        cin >> a >> m >> p >> q >> r >> s;
        if (a == 0 && m == 0 && p == 0 && q == 0 && r == 0 && s == 0) {
            break;
        }

        cout << "Case " << tc << ": ";

        // check empty
        if (r <= p && q <= s) {
            cout << "empty\n";
            continue;
        }

        program minimal = find_minimal_program(a, m, p, q, r, s);
        if (minimal.size() == 0) {
            cout << "impossible\n";
        } else {
            print_program(minimal);
        }
    }
    return 0;
}
