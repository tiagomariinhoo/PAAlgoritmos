#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(0)
#define MAXN 50500
#define MAXL 20
#define MIN -2000000
#define INF (1<<30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
int c[MAXN];
int par[MAXN];

int nivel[MAXN];
int pai[MAXN];
int ancestral[MAXN][MAXL];

vi lista[MAXN];

void dfs(int u){
	for(int i=0;i<(int)lista[u].size();i++){
		int v = lista[u][i];
		if(nivel[v] == -1){
			nivel[v] = nivel[u] + 1;
			pai[v] = u;
			dfs(v);
		}
	}
}

int LCA(int u, int v){
	if(nivel[u] < nivel[v]) swap(u,v);

	for(int i=MAXL-1;i>=0;i--)
		if(nivel[u] - (1<<i) >= nivel[v]) u = ancestral[u][i];

	if(u == v) return u;

	for(int i=MAXL-1;i>=0;i--)
		if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
		return pai[u];
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		if(c[a]){
			par[i] = c[a];
			par[c[a]] = i;
		}
		c[a] = i;
	}

	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		lista[a].pb(b);
		lista[b].pb(a);
	}

	for(int i=0;i<MAXN;i++) pai[i] = nivel[i] = -1;

	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXL;j++) ancestral[i][j] = -1;

	nivel[1] = 0;
 dfs(1);

 for(int i=1;i<=n;i++) ancestral[i][0] = pai[i];

 	for(int j=1;j<MAXL;j++)
 		for(int i=1;i<=n;i++) ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];

 	lli ans = 0LL;
 	for(int i = 1;i <= n;i++)
		ans += ( nivel[i] + nivel[par[i]] - 2*nivel[ LCA(i, par[i]) ]);
 

 cout << ans/2<<endl;

}