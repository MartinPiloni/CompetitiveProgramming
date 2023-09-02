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

    vector<int> v(8);
    bool ok = true;
    for (int i = 0; i < 8; i++) {
        cin >> v[i];
        if (v[i] == 9) ok = false;
    }
    (ok ? cout << "S\n" : cout << "F\n");

    return 0;
}
