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
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 1) {
            cout << "0\n";
            continue;
        }
        else if (a == 0 && b == 0 && c > 1) {
            cout << "-1\n";
            continue;
        }
        
        vector<int> cn(a + b);
        set<int> need_p;
        set<int> need_c;
        need_c.insert(0);

        str root;
        if (a == 0 && b > 0) root = "b";
        else if (a == 0 && b == 0) root = "c";
        else root = "a";
        
        if (root == "a") cn[0] = 2;
        else if (root == "b") cn[0] = 1;

        for (int i = 1; i < a; i++) {
            need_p.insert(i);
            need_c.insert(i);
            cn[i] = 2;
        }
        for (int i = 0; i < b; i++) {
            if (root == "b" && i == 0) continue;
            need_p.insert(a + i);
            need_c.insert(a + i);
            cn[a + i] = 1;
        }
        for (int i = 0; i < c; i++) {
            if (root == "c" && i == 0) continue;
            need_p.insert(a + b + i);
        }

        vector<vector<int>> g(a + b + c);
        bool can = true;
        while (!empty(need_p)) {
            if (need_c.empty()) {
                can = false;
                break;
            }

            g[*need_p.begin()].pb(*need_c.begin());
            g[*need_c.begin()].pb(*need_p.begin());

            need_p.erase(need_p.begin());
            cn[*need_c.begin()]--;
            if (cn[*need_c.begin()] == 0) need_c.erase(need_c.begin());
        }

        if (!empty(need_p) || !empty(need_c)) {
            can = false;
        }

        if (!can) cout << "-1" << endl;
        else {
            vector<int> dist(a + b + c, -1);
            queue<int> q;
            q.push(0);
            dist[0] = 0;
            while (!empty(q)) {
                auto p = q.front(); q.pop();
                for (auto e : g[p]) {
                    if (dist[e] == -1) {
                        q.push(e);
                        dist[e] = dist[p] + 1;
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < a + b + c; i++) {
                ans = max(ans, dist[i]);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
