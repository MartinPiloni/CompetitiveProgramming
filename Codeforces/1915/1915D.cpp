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

        int len = 0;
        for (int i = 0; i < n; i++) {
            if (len < 2) {
                cout << s[i];
                len++;
            } else {
                if (n - i == 1) cout << s[i]; 
                else if (n - i == 2 && (s[i] == 'b' || s[i] == 'c' || s[i] == 'd')) {
                    cout << "." << s[i];
                    len = 1;
                }
                else if ((s[i + 2] == 'b' || s[i + 2] == 'c' || s[i + 2] == 'd')) {
                    cout << ".";
                    cout << s[i];
                    len = 1;
                } else {
                    cout << s[i];
                    if (i != n - 1) cout << ".";
                    len = 0;
                }
            }
        }
        cout << "\n";

    }

    return 0;
}
