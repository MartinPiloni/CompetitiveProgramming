#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; 
        char d;
        str s;
        cin >> n >> d >> s;

        int j = n;
        fore(i, 0, n) {
            if (s[i] < d) {j = i; break;}
        }

        fore(i, 0, j) cout << s[i];
        cout << d;
        fore(i, j, n) cout << s[i]; 
        cout << "\n";
    }

    return 0;
}
