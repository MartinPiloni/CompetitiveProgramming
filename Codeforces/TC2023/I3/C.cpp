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

    int n, q;
    str s;
    cin >> n >> s >> q;

    vector<int> pos[26];
    for (int i = 0; i < n; i++) pos[s[i] - 'a'].pb(i + 1);

    str name;
    for (int i = 0; i < q; i++) {
        int ans = 0;
        cin >> name;
        
        vector<int> cnt(26);
        for (int j = 0; j < sz(name); j++) cnt[name[j] - 'a']++;
        for (int j = 0; j < 26; j++) if (cnt[j] != 0) ans = max(ans, pos[j][cnt[j] - 1]);

        cout << ans << "\n";
    }
    return 0;
}
