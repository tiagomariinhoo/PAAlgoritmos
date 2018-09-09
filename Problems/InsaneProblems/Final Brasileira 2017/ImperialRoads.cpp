#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

#define MAXN 200001
#define MAXL 20

/*
	Problema: Dada uma MST, falar a nova MST tal que
	tenha obrigatoriamente a aresta da query

	Caso a aresta já esteja na MST, a resposta é a MST 
	Caso contrário, pega a maior aresta no caminho do vértice
	x até y, tira ela e inclui a nova aresta (x, y) Pois garante
	que não terá ciclo, já que vc só pode ter 1 caminho entre cada
	par de nós.

*/

int n, m, q;
vector<ii> vec[MAXN];
int pai[MAXN];
int peso[MAXN];
int vis[MAXN];

int ancestral[MAXN][MAXL];
int distancia[MAXN][MAXL];
int pai2[MAXN];
int nivel[MAXN];
int pw[MAXN];

map<ii, int> cam;
multiset<ii> have;

int proc(int x){
	if(pai[x] == x) return x;
	return pai[x] = proc(pai[x]);
}

void junta(int a, int b){
	a = proc(a);
	b = proc(b);

	if(peso[a] < peso[b]){
		pai[a] = b;
	} else if(peso[a] > peso[b]){
		pai[b] = a;
	} else {
		pai[a] = b;
		peso[b]++;
	}

}

void dfs(int x){
	vis[x] = 1;
	for(auto i : vec[x]){
		int y = i.S;
		if(vis[y]) continue;
		int xx = x, yy = y;
		if(xx > yy) swap(xx, yy);
		if(have.find({xx, yy}) == have.end()) continue;
		pai2[y] = x;
		nivel[y] = nivel[x] + 1;
		pw[y] = i.F;
		dfs(y);
	}
}

void build(){
	memset(ancestral, -1, sizeof ancestral);
	memset(pai2, -1, sizeof pai2);
	dfs(1);

	for(int i=1;i<=n;i++) ancestral[i][0] = pai2[i];
	for(int i=1;i<=n;i++) distancia[i][0] = pw[i];

	for(int j=1;j<MAXL;j++){
		for(int i=1;i<=n;i++){
			ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}
	}

	for(int j=1;j<MAXL;j++){
		for(int i=1;i<=n;i++){
			distancia[i][j] = max(distancia[i][j-1], distancia[ancestral[i][j-1]][j-1]);
		}
	}

}

int LCA(int u, int v){
	if(nivel[u] < nivel[v]) swap(u, v);
	for(int i=MAXL-1;i>=0;i--){
		if(nivel[u] - (1 << i) >= nivel[v]){
			u = ancestral[u][i];
		}
	}

	if(u == v) return u;

	for(int i=MAXL-1;i>=0;i--){
		if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}

	return pai2[u];
}

int LCAPath(int u, int v){
	if(nivel[u] < nivel[v]) swap(u, v);
	// int path = max(pw[u], pw[v]);
	int path = 0;
	// cout << "U : " << u << " ; " << pw[u] << endl;
	// cout << "V : " << v << " ; " << pw[v] << endl;
	for(int i=MAXL-1;i>=0;i--){
		if(nivel[u] - (1 << i) >= nivel[v]){
			path = max(path, distancia[u][i]);
			// path = max(path, pw[u]);
			u = ancestral[u][i];
			// path = max(path, pw[u]);
			// path = max(path, distancia[u][i]);
		}
	}
	// cout << u << " -- " << v << " : " << path << endl;
	if(u == v) return path;

	for(int i=MAXL-1;i>=0;i--){
		if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]){
			path = max({path, distancia[u][i], distancia[v][i]});
			// path = max(path, pw[u]);
			// path = max(path, pw[v]);
			path = max({path, distancia[u][i], distancia[v][i]});
			u = ancestral[u][i];
			v = ancestral[v][i];
			// path = max(path, pw[u]);
			// path = max(path, pw[v]);
		}
	}
	path = max({path, pw[u], pw[v]});
	// cout << u << " --- " << v << endl;
	// cout << "Pai : " << pai2[u] << " - " << pai2[v] << endl;
	return path;
}

int main(){ 
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i=1;i<=n;i++) pai[i] = i;

  vector< pair<int, ii> > edges;
  for(int i=0;i<m;i++){
  	int a, b, c;
  	cin >> a >> b >> c;
  	vec[a].pb({c, b});
  	vec[b].pb({c, a});
  	cam[{a,b}] = c;
  	cam[{b,a}] = c;
  	edges.pb({c, {a, b}});
  }

  sort(edges.begin(), edges.end());

  lli ans = 0;
  for(int i=0;i<sz(edges);i++){
  	int x = edges[i].S.F, y = edges[i].S.S;
  	int w = edges[i].F;
  	if(proc(x) != proc(y)){
  		ans += w;
  		if(x > y) swap(x, y);
  		have.insert({x, y});
  		junta(x, y);
  	}
  }

  build();

  // for(auto i : have) cout << i.F << " - " << i.S << " - " << cam[{i.F, i.S}] << endl;

  // for(int i=1;i<=n;i++) cout << i << " - " << pai2[i] << " : " << pw[i] << endl;

  cin >> q;
  for(int i=0;i<q;i++){
  	int a, b;
  	cin >> a >> b;
  	if(a > b) swap(a, b);
  	if(have.find({a, b}) != have.end()) cout << ans << endl;
  	else {
  		// if(a > b) swap(a, b);
  		// cout << "Query : " << a << " " << b << endl;
  		// cout << "LCA : " << LCA(a, b) << endl;
  		// cout << a << " - " << b << " : " << LCAPath(a, b) << endl;
  		// cout << "Cam : " << cam[{a, b}] << endl;
  		cout << ans - LCAPath(a,b) + cam[{a, b}] << endl;
  	}
  }

   return 0; 
} 