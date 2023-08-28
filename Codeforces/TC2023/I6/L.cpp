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
    vector<str> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    bool s = true;
    for (int i = n - 1; i >= 0; i--) {
        if (s && v[i] == "LIE") s = false;
        else if (!s && v[i] == "LIE") s = true;
    }
    (s ? cout << "TRUTH\n" : cout << "LIE\n");

    return 0;
}
