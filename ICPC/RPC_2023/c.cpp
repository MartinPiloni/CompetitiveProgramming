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

    ll n; cin >> n;
    string s; cin >> s;

    ll l = sz(s);

    char v[n][n];
    
    ll x = n/2;
    ll y = x;
    
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            v[i][j] = '#';
        }
    }
    ll aux = 1;
    ll k = 0;
    bool b = true;
    bool a = true;
    v[x][y] = s[k]; k++;
    while (k < l){
        for (ll i = 0; i < aux; i++){
            if (a && b){
                y--;
            } else if (a && !b){
                y++;
            } else if (!a && b){
                x++;
            } else {
                x--;
            }
            if (k < l){ v[x][y] = s[k]; k++;}
        }
        if (a && b) {
            a = false;
        } else if (!a && b){
            b = false; aux++; a = true;
        } else if (a && !b){
            a = false;
        } else {
            b = true; aux++; a = true;
        }
    }
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            if (v[j][i] != '#'){
                cout << v[j][i];
            }
        }
    }
    cout << '\n';

    return 0;
}