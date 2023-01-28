#include <bits/stdc++.h>
using namespace std;

using str = string;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;

    vector<string> a(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < Q; i++) {
        int ans = -1;
        bool b = false;
        for (int j = 0; j < (int) size(a[i]) - 2; j++) {
            if (a[i][j] == 'M' && a[i][j + 1] == 'O' && a[i][j + 2] == 'O') {
                ans = (int) size(a[i]) - 3;
                break;
            }
            else if (((a[i][j] == 'M' && a[i][j + 1] == 'O')
                    || (a[i][j + 1] == 'M' && a[i][j + 2] == 'O'
                    && j + 2 != (int) size(a[i]) - 1))
                    && !b) {
                ans = (int) size(a[i]) - 2;
                b = true;
            }
            else if ((((a[i][j] == 'O' && a[i][j + 1] == 'O') && j != 0)
                    || (a[i][j + 1] == 'O' && a[i][j + 2] == 'O'))
                    && !b) {
                ans = (int) size(a[i]) - 2;
                b = true;
            }
            else if(a[i][j] == 'O' && a[i][j + 1] == 'O' && a[i][j + 2] == 'M' && !b){
                ans = (int) size(a[i]) - 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
