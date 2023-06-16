#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;
        vector<int> v;
        int x;
        
        cin >> x;
        v.push_back(x);
        cout << "1";

        bool s = true;
        for (int i = 0; i < q - 1; i++) {
            cin >> x;
            if (s) {
                if (x >= v.back()) {
                    cout << "1";
                    v.push_back(x);
                } else if (x <= v[0]) {
                    cout << "1";
                    v.push_back(x);
                    s = false;
                } else {
                    cout << "0";
                }
            } else {
                if (x <= v[0] && x >= v.back()) {
                    cout << "1";
                    v.push_back(x);
                } else {
                    cout << "0";
                }
            }
        }

        cout << "\n";
    }
    return 0;
}


/*
2 estados - ascendente y descendente

Secuencia ascendente ++
Cuando deje de ser ascendente para agregar
el nuevo debe ser menor al primero y los siguientes
deben ser mayores al primero que no es ascendente
pero menores al primero


Secuencia descendente
3 2 2 3

*/