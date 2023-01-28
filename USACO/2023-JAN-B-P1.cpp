#include <bits/stdc++.h>
using namespace std;

using str = string;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    str s;
    cin >> N >> s;

    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    set<int> g_leader, h_leader;
    for (int i = 0; i < N; i++) {
        bool leader = true;
        char breed = s[i];
        for (int j = w[i]; j < N; j++) {
            if (s[j] == breed) {
                leader = false;
            }
        }

        for (int j = 0; j < i; j++) {
            if(s[j] == breed) {
                leader = false;
            }
        }

        if (leader && breed == 'G') {
            g_leader.insert(i);
        } else if (leader && breed == 'H') {
            h_leader.insert(i);
        }
    }

    int ans = 0;
    for (auto i = g_leader.begin(); i != g_leader.end(); i++) {
        for (auto j = h_leader.begin(); j != h_leader.end(); j++) {
            ans++;
        }
    }

    for (int i = 0; i < N; i++) {
        char breed = s[i];
        for (int j = i + 1; j < w[i]; j++) {
            if (breed == 'G' && s[j] == 'H' && h_leader.find(j) != h_leader.end()) {
                ans++;
            }
            else if (breed == 'H' && s[j] == 'G' && g_leader.find(j) != g_leader.end()) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
