#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

pair<ll, ll> oper(pair<ll, ll> x, pair<ll, ll> y) {
    pair<ll, ll> res;
    res.fst = max({x.fst, x.snd + y.fst, 0LL});
    res.snd = x.snd + y.snd;
    return res;
}

#define NEUT {0, 0}
struct STree { 
	vector<pair<ll, ll>> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]={v, v};return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	pair<ll, ll> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	pair<ll, ll> query(int a, int b){return query(1,0,n,a,b);}
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    STree st(n);
    for (int i = 0; i < n; i++) st.upd(i, v[i]);
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            st.upd(a, b);
        } else {
            cout << st.query(a, b).fst << "\n";
        }
    }

    return 0;
}
