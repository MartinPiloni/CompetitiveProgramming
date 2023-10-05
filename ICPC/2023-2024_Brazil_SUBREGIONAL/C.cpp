#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

#define oper max 
#define NEUT 0 
struct STree { 
	vector<int> st;int n;
	STree(int n): st(4*n+5, NEUT), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; 

const int MAXN = 1e5 + 10;
vector<int> g[MAXN];
bool vis[MAXN];
int ans[MAXN];
vector<ll> v;
STree st = {MAXN};
int n;

void dfs(int x) {
    vis[x] = true;
    
    auto prev = st.query(v[x], v[x] + 1);
    st.upd(v[x], st.query(0, v[x]) + 1);
    ans[x] = st.query(0, n + 1);
    for (auto e : g[x]) {
        if (!vis[e]) dfs(e);
    }
    st.upd(v[x], prev);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int x;
    for (int i = 1; i < n; i++) {
        cin >> x; x--;
        g[i].pb(x);
        g[x].pb(i);
    }
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
	
    // Compress cordinates
    auto c = v;
    sort(all(c));
    for (int i = 0; i < n; i++) v[i] = lower_bound(all(c), v[i]) - c.begin();

    dfs(0);
    for (int i = 1; i < n; i++) cout << ans[i] << " \n"[i == n - 1];

    return 0;
}
