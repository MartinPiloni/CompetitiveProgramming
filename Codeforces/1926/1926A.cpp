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
        
        int cnt_a = 0, cnt_b = 0;
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'A') cnt_a++;
            else cnt_b++;
        }

        (cnt_a > cnt_b ? cout << "A\n" : cout << "B\n");
    }

    return 0;
}
