#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define int long long
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using str = string;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
      for (int j = 0; j < sz(jmp[k]); j++) {
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
      }
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
      int n, d, k;
      cin >> n >> d >> k;

      int l = 0, r = 0;
      vector<ll> open(n + 1), close(n + 2);
      for (int i = 0; i < k; i++) {
        cin >> l >> r;
        open[l]++;
        close[r + 1]++;
      }

      for (int i = 1; i < n + 1; i++) {
        open[i] = open[i - 1] + open[i];
        close[i] = close[i - 1] + close[i];
      }

      //for (auto e : open) cout << e << " ";
      //cout << endl;
      //for (auto e : close) cout << e << " ";
      //cout << endl;

      pair<ll, ll> mx = {0, 1}, mn = {1e18, 1};
      for (int i = 0; i < n; i++) {
        if (i + d == n + 1) break;
        
        if (open[i + d] - close[i + 1] > mx.fst) {
          mx.fst = open[i + d] - close[i + 1];
          mx.snd = i + 1;
        }
        if (open[i + d] - close[i + 1] < mn.fst) {
          mn.fst = open[i + d] - close[i + 1];
          mn.snd = i + 1;
        }
      }
      cout << mx.snd << " " << mn.snd << "\n";
    }

    return 0;
}
