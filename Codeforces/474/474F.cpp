#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

pair<int, int> oper(pair<int, int> x, pair<int, int> y) {
    pair<int, int> res = {0, 0};
    res.fst = gcd(x.fst, y.fst);
    if (res.fst == x.fst) res.snd += x.snd;
    if (res.fst == y.fst) res.snd += y.snd;
    return res;
}

#define NEUT {0, 0}
struct STree { 
	vector<pair<int, int>> st;int n;
	STree(int n): st(4*n+5), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]={v, 1};return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	pair<int, int> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	pair<int, int> query(int a, int b){return query(1,0,n,a,b);}
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    STree st(n);
    for (int i = 0; i < n; i++) st.upd(i, v[i]);

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << r - l - st.query(l, r).snd << "\n";
    }

    return 0;
}
