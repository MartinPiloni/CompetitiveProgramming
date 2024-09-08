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
      str a, b;
      cin >> a >> b;
      if (a == b) cout << "=\n";
      else if (a.back() == b.back() && a.back() == 'S') {
        (sz(a) > sz(b) ? cout << "<\n" : cout << ">\n");
      } else if (a.back() == b.back() && a.back() == 'L') {
        (sz(a) > sz(b) ? cout << ">\n" : cout << "<\n");
      } 
      else if (a.back() == 'S' && b.back() == 'L') cout << "<\n";
      else if (a.back() == 'L' && b.back() == 'S') cout << ">\n";
      else if (a.back() == 'S' && b.back() == 'M') cout << "<\n";
      else if (a.back() == 'M' && b.back() == 'S') cout << ">\n";
      else if (a.back() == 'L' && b.back() == 'M') cout << ">\n";
      else if (a.back() == 'M' && b.back() == 'L') cout << "<\n";
    } 

    return 0;
}
