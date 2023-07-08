#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

str v[3];

bool win(int i, int j, char c) {
    if (c == '.') return false;

    bool ans = false;
    if (i == 0) {
        ans |= (c == v[i + 1][j] && c == v[i + 2][j]);
    } else if (i == 1) {
        ans |= (c == v[i - 1][j] && c == v[i + 1][j]);
    } else if (i == 2) {
        ans |= (c == v[i - 1][j] && c == v[i - 2][j]); 
    }

    if (j == 0) {
        ans |= (c == v[i][j + 1] && c == v[i][j + 2]);
    } else if (j == 1) {
        ans |= (c == v[i][j - 1] && c == v[i][j + 1]);
    } else if (j == 2) {
        ans |= (c == v[i][j - 1] && c == v[i][j - 2]); 
    }

    if (i == j && i == 0) {
        ans |= (c == v[i + 1][j + 1] && c == v[i + 2] [j + 2]);
    } else if (i == j && i == 1) {
        ans |= (c == v[i - 1][j - 1] && c == v[i + 1] [j + 1]);
    } else if (i == j && i == 2){
        ans |= (c == v[i - 1][j - 1] && c == v[i - 2] [j - 2]);
    }
    
    if (i == 0 && j == 2) {
        ans |= (c == v[i + 1][j - 1] && c == v[i + 2] [j - 2]);
    } else if (i == j && i == 1) {
        ans |= (c == v[i - 1][j + 1] && c == v[i + 1] [j - 1]);
    } else if (i == 2 && j == 0){
        ans |= (c == v[i - 1][j + 1] && c == v[i - 2] [j + 2]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) {
            cin >> v[i];
        }

        bool w = false;
        char winner;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (win(i, j, v[i][j])) {
                    w = true;
                    winner = v[i][j];
                    break;
                }
            }
            
            if (w) break;
        }

        (w ? cout << winner << "\n" : cout << "DRAW\n");
    }

    return 0;
}
