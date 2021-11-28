#include <bits/stdc++.h>
using namespace std;

int formula(vector<int>& v) {
    int score = 1;
    int len = (int) v.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            score = score * (v[i] + v[j]) % 100;
        }
    }
    return score;
}

vector<int> calculate_variables(string& name, string& team_name) {
    vector<int> variables(4);
    char chars[4] = {'L', 'O', 'V', 'E'};
    for (int i = 0; i < 4; ++i) {
        variables[i] = count(name.begin(), name.end(), chars[i]) + count(team_name.begin(), team_name.end(), chars[i]);
    }
    return variables;
}

string find_winning_team(string& name, vector<string>& team_names) {
    int max_score = -1;
    string winning_team;
    for (string& team_name : team_names) {
        vector<int> variables = calculate_variables(name, team_name);
        int score = formula(variables);
        if (score > max_score) {
            max_score = score;
            winning_team = team_name;
        }
    }
    return winning_team;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string name;
    int teams;
    cin >> name >> teams;

    vector<string> team_names(teams);
    for (int i = 0; i < teams; ++i) {
        cin >> team_names[i];
    }
    sort(team_names.begin(), team_names.end());

    cout << find_winning_team(name, team_names);
    return 0;
}
