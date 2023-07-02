#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))

using ll = long long;
using str = string;

bool valid(int x) {
    return (100 <= x && x <= 675 && x % 25 == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool ok = true;
    int in, prev = -1;
    fore(i, 0, 8) {
        cin >> in;
        if (!valid(in) || in < prev) {
            ok = false;
            break;
        }
        prev = in;
    }

    (ok ? cout << "Yes\n" : cout << "No\n");
    return 0;
}
