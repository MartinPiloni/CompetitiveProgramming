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

    vector<int> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];
    sort(all(v));
    if (v[0] + v[1] <= v[2]) cout << "S\n";
    else cout << "N\n";

    return 0;
}
