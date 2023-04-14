#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    int t, x, last_call = 0;
    set<int> s;
    for (int i = 0; i < Q; i++) {
        cin >> t;
        if (t == 1) {
            s.insert(last_call + 1);
            last_call++;
        } else if (t == 2) {
            cin >> x;
            s.erase(x);
        } else {
            cout << *s.begin() << "\n";
        }
    }
    return 0;
}
