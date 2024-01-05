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

    str s;
    cin >> s;
    map<char, int> freq;
    for (int i = 0; i < sz(s); i++) {
        freq[s[i]]++;
    }
    bool ok = true;
    for (auto e : freq) {
        if (e.snd & 1) {
            ok = false;
            break;
        }
    }
    (ok ? cout << "Yes\n" : cout << "No\n");

    return 0;
}
