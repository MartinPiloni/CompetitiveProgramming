#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

bool is_good(str s) {
    for (int i = 0; i <= sz(s) / 2; i++) {
        if (s[i] == s[sz(s) - i - 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        str s;
        cin >> n >> s;

        if (n & 1) {cout << "-1\n"; continue;}
        else if (is_good(s)) {cout << "0\n\n"; continue;}

        else {
            int cnt = 0;
            vector<int> ans;
            while (!is_good(s) && cnt <= 300) {
                for (int i = 0; i <= sz(s) / 2; i++) {
                    if (s[i] == s[sz(s) - i - 1] && s[i] == '0') {
                        cnt++;
                        ans.pb(sz(s) - i);
                        s = s.substr(0, sz(s) - i) + "01" + s.substr(sz(s) - i);
                        break;
                    } else if (s[i] == s[sz(s) - i - 1] && s[i] == '1') {
                        cnt++;
                        if (i == 0) {
                            s = "01" + s;
                            ans.pb(0);
                        } else {
                            s = s.substr(0, i) + "01" + s.substr(i);
                            ans.pb(i);
                        }
                        break;
                    }
                }
            }

            if (cnt <= 300 && is_good(s)) {
                cout << cnt << "\n";
                for (auto e : ans) cout << e << " ";
                cout << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}
