#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

bool is_vowel(char c) {
    c = (char)tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str s, ans;
    cin >> s;

    for (int i = 0; i < sz(s); i++) {
        if (!is_vowel(s[i])) {ans += '.'; ans += (char)tolower(s[i]);}
    }
    cout << ans << "\n";

    return 0;
}
