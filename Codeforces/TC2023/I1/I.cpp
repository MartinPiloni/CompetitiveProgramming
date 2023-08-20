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

    map<str, int> c = {
        {"purple", 0},
        {"green", 1},
        {"blue", 2},
        {"orange", 3},
        {"red", 4},
        {"yellow", 5},
    };

    map<int, str> g = {
        {0, "Power"},
        {1, "Time"},
        {2, "Space"},
        {3, "Soul"},
        {4, "Reality"},
        {5, "Mind"},
    };
   
    vector<bool> seen(6);
    int n;
    cin >> n;
    str gem;
    for (int i = 0; i < n; i++) {
        cin >> gem;
        seen[c[gem]] = 1;
    }
    
    int cnt = 0;
    vector<str> ans;
    for (int i = 0; i < 6; i++) {
        if (!seen[i]) {cnt++; ans.pb(g[i]);}
    }
    cout << cnt << "\n";
    for (auto e : ans) cout << e << "\n";
    return 0;
}
