#include <bits/stdc++.h>
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,gmat=b;i<gmat;++i)
#define sz(x) (ll)x.size()
#define pb push_back
using namespace std;

using ll = long long;
using str = string;

template<typename T>
T randin(T a, T b){
  static random_device rd;
  static mt19937_64 gen(rd());
  uniform_int_distribution<T> dis(a,b-1);
  return dis(gen);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Generate two integers n in [2, 5] and x in [2, 10]
    ll n = randin(2,5);
    ll x = randin(2,10);
    cout << n << " " << x << "\n";

    // Generate n numbers in [1, 20]
    for (int i = 0; i < n; i++) {
      ll a = randin(1,20);
      cout << a << " ";
    }
    cout << "\n";
}
