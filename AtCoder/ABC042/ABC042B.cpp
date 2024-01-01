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

    int n, l;
    cin >> n >> l;
    vector<str> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));
    for (int i = 0; i < n; i++) cout << v[i];
    cout << endl;

    return 0;
}
