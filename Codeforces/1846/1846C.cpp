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
        ll n, m, h;
        cin >> n >> m >> h;

        vector<vector<ll>> v(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            sort(all(v[i]));
        }

        vector<pair<pair<ll, ll>, ll>> table(n);
        ll score, penalty, time; 
        for (int i = 0; i < n; i++) {
            time = 0;
            score = 0;
            penalty = 0;
            for (int j = 0; j < m; j++) {
                if (v[i][j] + time <= h) {
                    score++;
                    time += v[i][j];
                    penalty += time;
                }
            }

            table[i] = {{-score, penalty}, i};
        }
        sort(all(table));

        for(int i = 0; i < n; i++) {
            cout << "table: " << i << endl;
            cout << "score: " << table[i].fst.fst << endl;
            cout << "penalty: " << table[i].fst.snd << endl;
            cout << "id: " << table[i].snd << endl;
            cout << "\n";
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (table[i].snd == 0) {
                ans = i + 1;
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
