#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define fore(i,a,b) for (int i = (a); i < (b); ++i)

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, g;
    cin >> n; n--;

    vector<str> v(n);
    str s; cin >> s;
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> g; vector<str> q(g);
    for (int i = 0; i < g; i++) cin >> q[i];

    map<str, int> freq;
    freq["*****"] = 1;
    str c = "";
    for (int i = 0; i < n; i++) {
        c = "";
        for (int j = 0; j < 5; j++) {
            if (s[j] == v[i][j]) c += '*';
            else if (s.find(v[i][j]) != str::npos) c += '!';
            else c += 'X';
        }
        freq[c]++;
    }

    for (int i = 0; i < g; i++) {
        cout << freq[q[i]] << "\n";
    }

    return 0;
}