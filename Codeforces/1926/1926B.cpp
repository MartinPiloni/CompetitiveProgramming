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
        cin >> n;
        vector<str> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];

        bool triangle = false;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (g[i][j] == '1') cnt++;
            }
            if (cnt == 1) triangle = true;
        }

        (triangle ? cout << "TRIANGLE\n" : cout << "SQUARE\n");
    }

    return 0;
}