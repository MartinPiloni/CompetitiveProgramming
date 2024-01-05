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

    str a, b, c;
    int ind_a = 0, ind_b = 0, ind_c = 0;
    cin >> a >> b >> c;
    char turn = 'a';

    char winner;
    while (true) {
        if (turn == 'a') {
            if (ind_a == sz(a)) {
                winner = 'A';
                break;
            }
            turn = a[ind_a];
            ind_a++;
        } else if (turn == 'b') {
            if (ind_b == sz(b)) {
                winner = 'B';
                break;
            }
            turn = b[ind_b];
            ind_b++;
        } else {
            if (ind_c == sz(c)) {
                winner = 'C';
                break;
            }
            turn = c[ind_c];
            ind_c++;
        }
    }
    cout << winner << "\n";

    return 0;
}
