#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        fore(i, 0, n) cin >> a[i]; 
        fore(i, 0, m) cin >> b[i];
        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end());

        int l_a = 0, r_a = n - 1, l_b = 0, r_b = m - 1, p;
        int m_a = n, m_b = m;
        bool tu = true;

        while(m_a > 0 && m_b > 0) {
            if (tu) {
                p = a[r_a];
                a[r_a] -= b[l_b];
                b[l_b] -= p; 

                if(a[r_a] <= 0) {
                    r_a--;
                    m_a--;
                }
                if(b[l_b] <= 0) {
                    l_b++;
                    m_b--;
                }
            } else {
                p = b[r_b];
                b[r_b] -= a[l_a];
                a[l_a] -= p;

                if (b[r_b] <= 0) {
                    r_b--;
                    m_b--;
                }
                if (a[l_a] <= 0) {
                    l_a++;
                    m_a--;
                }
            }
        }

        if (m_a == 0 && m_b == 0) cout << "Draw\n";
        else if (m_a == 0) cout << "Tenzing\n";
        else cout << "Tsondu\n";
    }

    return 0;
}
