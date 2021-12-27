#include <bits/stdc++.h>
using namespace std;

map<char, int> nucleotide = {
    {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
};

map<int, char> nucleotide_inv = {
    {0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}
};

int n, m;
int usage[51][4];

pair<char, int> find_max_char(int j) {
    int max_use_count = 0;
    char max_char = 0;
    for (int i = 0; i < 4; ++i) {
        if (usage[j][i] > max_use_count) {
            max_use_count = usage[j][i];
            max_char = nucleotide_inv[i];
        }
    }
    return make_pair(max_char, max_use_count);
}

pair<string, int> find_min_hamming_distance() {
    string min_dna;
    int distance_sum = 0;
    for (int j = 0; j < m; ++j) {
        auto [max_char, use_count] = find_max_char(j);
        min_dna.push_back(max_char);
        distance_sum += n - use_count;
    }
    return make_pair(min_dna, distance_sum);
}

void count_characters(string& s) {
    for (int j = 0; j < m; ++j) {
        char c = s[j];
        usage[j][nucleotide[c]]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string sequence;
    for (int i = 0; i < n; ++i) {
        cin >> sequence;
        count_characters(sequence);
    }

    auto [min_dna, distance_sum] = find_min_hamming_distance();
    cout << min_dna << '\n' << distance_sum;
    return 0;
}
