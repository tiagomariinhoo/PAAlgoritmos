#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
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
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001
#define MAXL 20

/*
	
	LCA Problem, verifica o nivel dos dois nodes
	Se o nivel for igual, sobe e cortas as subarvores

	Se o nivel for diferente, pega o node mais fundo até
	o node de distancia/2 e corta a subarvore

*/

int n;
int nivel[MAXN];
int ancestral[MAXN][MAXL];
int pai[MAXN];
int vis[MAXN];
int subtree[MAXN];
vi vec[MAXN];

int dfs(int x){
	vis[x] = 1;
	for(auto i : vec[x]){
		if(!vis[i]){
			pai[i] = x;
			nivel[i] = nivel[x] + 1;
			subtree[x] += dfs(i);
		}
	}
	return subtree[x];
}

void build(){

	pai[1] = 1;
	for(int i=1;i<=n;i++) subtree[i] = 1;

	dfs(1);
	
	for(int i=1;i<=n;i++) ancestral[i][0] = pai[i];


	for(int j=1;j<MAXL;j++){
		for(int i=1;i<=n;i++){
			ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}
	}
}

int LCA(int u, int v){
	if(nivel[v] > nivel[u]) swap(u, v);
	for(int i=MAXL-1;i>=0;i--){
		if(nivel[u] - (1 << i) >= nivel[v]) u = ancestral[u][i];
	}

	if(u == v) return u;
	for(int i=MAXL-1;i>=0;i--){
		if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}
	return pai[u];
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		vec[a].pb(b);
		vec[b].pb(a);
	}

	build();

	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int a, b;
		cin >> a >> b;
		int dist = nivel[a] + nivel[b] - 2*nivel[LCA(a, b)];
		int anc = LCA(a, b);
		if(dist%2!=0) cout << 0 << endl;
		else {
			if(a == b){
				cout << n << endl;
				continue;
			}
			if(nivel[a] == nivel[b]) {
 				int aux = a, aux2 = b, anterior, anterior2;
 				while(1){
 					if(pai[aux] == pai[aux2]) break;
 					anterior = a, anterior2 = b;
 					aux = pai[aux], aux2 = pai[aux2];
 				}
 				cout << n - subtree[aux] - subtree[aux2] << endl;
			} else {
				if(nivel[b] > nivel[a]) swap(a, b);
				int aux = a;
				int anterior;
				int met = dist/2;
				while(dist > met){
					anterior = aux;
					aux = pai[aux];
					dist--;
				}
				// cout << anterior << " " << aux << " " << dist << endl;
				cout << subtree[aux] - subtree[anterior] << endl;
			}			
		}
	}



	return 0;
}
