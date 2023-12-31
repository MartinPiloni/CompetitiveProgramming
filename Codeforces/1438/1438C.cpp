#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 2e4 + 10; // Max number of variables
const int MAXM = 1e2 + 10; // Max numbers of rows/columns
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
ll matrix[MAXM][MAXM];
int N, M;

// MAXN: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
    for (int i = 0; i < n; i++)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addor(int a, int b){g[neg(a)].pb(b);g[neg(b)].pb(a);}
bool satisf(int _nvar){
	nvar=_nvar;n=MAXN;scc();
	for (int i = 0; i < nvar; i++) if(cmp[i]==cmp[neg(i)])return false;
	return true;
}

bool valid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < 4; k++) {
                    if (!valid(i + dx[k], j + dy[k])) continue;

                    if (matrix[i][j] == matrix[i + dx[k]][j + dy[k]]) {
                        addor(i * M + j, (i + dx[k]) * M + (j + dy[k]));
                        addor(neg(i * M + j), neg((i + dx[k]) * M + (j + dy[k])));
                    } else if (matrix[i][j] == matrix[i + dx[k]][j + dy[k]] + 1) {
                        addor(neg(i * M + j), (i + dx[k]) * M + (j + dy[k]));
                        addor(i * M + j, neg((i + dx[k]) * M + (j + dy[k])));
                    }
                }
            }
        }

        satisf(N * M); 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << matrix[i][j] + truth[cmp[i * M + j]] << " \n"[j == M - 1];
            }
        }

        for (int i = 0; i < MAXN; i++) {
            g[i].clear();
        }
    }

    return 0;
}
