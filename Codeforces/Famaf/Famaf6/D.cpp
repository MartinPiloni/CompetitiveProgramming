#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

ll oper(ll a, ll b, bool op) {
    if (op) return a | b;
    else return a ^ b;
}

#define NEUT 0
struct STree { 
	vector<ll> st;int n;
	STree(int n): st(4*n+5, 0LL), n(n) {}
	void upd(int k, int s, int e, int p, ll v, bool op){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v,!op);
		else upd(2*k+1,m,e,p,v,!op);
		st[k]=oper(st[2*k],st[2*k+1],op);
	}
    ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b), 1);
	}
	void upd(int p, ll v, bool op){upd(1,0,n,p,v,op);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> v(1<<n);
    for (int i = 0; i < 1 << n; i++) cin >> v[i];

    STree st(1 << n + 1);
    for (int i = 0; i < 1 << n; i++) st.upd(i, v[i], 1);
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        st.upd(a, b, 1);
        cout << st.query(0, 1 << n) << "\n";
    }
    

    return 0;
}
