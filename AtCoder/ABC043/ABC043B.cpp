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
    str s, ans = "";
    cin >> s;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '0') ans.pb('0');
        else if (s[i] == '1') ans.pb('1');
        else if (!ans.empty()) ans.pop_back();
    } 
    cout << ans << "\n";
    return 0;
}

