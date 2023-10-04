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

    int n; cin >> n;
    vector<int> v(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != i + 1) {
            cnt++;
            int x = v[i];
            v[i] = i + 1;
            v[pos[i + 1]] = x;
            pos[x] = pos[i + 1];
            pos[i + 1] = i;
        }
    }

    if (cnt & 1) cout << "Smokin Joe!\n";
    else cout << "Oh No!\n";

    return 0;
}
