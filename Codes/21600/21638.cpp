#include <bits/stdc++.h>
using namespace std;

string storm_warning = "A storm warning for tomorrow! Be careful and stay home if possible!";
string cold_snap = "MCHS warns! Low temperature is expected tomorrow.";
string strong_wind = "MCHS warns! Strong wind is expected tomorrow.";
string no_message = "No message";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int today_temp, today_wind, tomorrow_temp, tomorrow_wind;
    cin >> today_temp >> today_wind >> tomorrow_temp >> tomorrow_wind;

    if (tomorrow_temp < 0 and tomorrow_wind >= 10) {
        cout << storm_warning;
    } else if (tomorrow_temp < today_temp) {
        cout << cold_snap;
    } else if (tomorrow_wind > today_wind) {
        cout << strong_wind;
    } else {
        cout << no_message;
    }
    return 0;
}
