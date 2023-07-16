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

    int n;
    cin >> n;
    
    set<str> st;
    for (int i = 0; i < n; i++) {
        str s, r;
        cin >> s;
        r = s;
        reverse(r.begin(), r.end());
        
        if (st.count(s) || st.count(r)) continue; 
        else st.insert(s);
    }

    cout << sz(st) << "\n"; 
    return 0;
}
