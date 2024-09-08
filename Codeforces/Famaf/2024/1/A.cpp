#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
      int x;
      cin >> x;
      
      if (x < 1400) cout << "Division 4\n";
      else if (x < 1600) cout << "Division 3\n";
      else if (x < 1900) cout << "Division 2\n";
      else cout << "Division 1\n";
    }

    return 0;
}
