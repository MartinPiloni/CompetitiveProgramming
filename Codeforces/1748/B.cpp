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
        int n;
        str s;
        cin >> n >> s;

        int ans = 0, max_freq = 0, digits = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(10);
            max_freq = 0;
            digits = 0;
            for (int j = i; j < n && j < i + 100; j++) {
                freq[s[j] - '0']++;
                if (freq[s[j] - '0'] == 1) digits++;
                max_freq = max(max_freq, freq[s[j] - '0']);

                if (max_freq <= digits) ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
