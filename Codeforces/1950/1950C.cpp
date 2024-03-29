#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        str s;
        cin >> s;

        str hour = s.substr(0, 2);
        str minutes = s.substr(3, 2);

        if (stoi(hour) == 0) {
            cout << "12:" << minutes << " AM\n";
        } else if (stoi(hour) < 12) {
            cout << hour << ":" << minutes << " AM\n";
        } else {
            if (stoi(hour) - 12 == 0) cout << "12" << ":" << minutes << " PM\n";
            else if (stoi(hour) - 12 < 10) cout << "0" << to_string(stoi(hour) - 12) << ":" << minutes << " PM\n";
            else cout << to_string(stoi(hour) - 12) << ":" << minutes << " PM\n";
        }
    }

    return 0;
}
