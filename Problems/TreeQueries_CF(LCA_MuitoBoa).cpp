#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2 * 1e5 + 1)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/**
 * Problema: Dava uma árvore, terão queries e em cada query, terá um conjunto
 * de vértices que pertencem a árvore. Para cada query, deverá ser respondido
 * se existe algum nó na árvore que você pode ir da raiz até esse nó e assim,
 * todos os vértices da query devem ter distância <= 1 para algum node desse
 * caminho até o nó escolhido.
 * 
 * Solução: Utilizando LCA, basta pegar o nó mais fundo do conjunto e verificar
 * se o LCA deste nó mais fundo com todos os outros nós do conjunto tem distância
 * <= 1
 * 
 */ 

int n, q;
vector<int> vec[MAXN];
int dist[MAXN];
int nivel[MAXN];
int pai[MAXN];
int ancestral[MAXN][MAXL];

void dfs(int u) {
  for(int i=0;i<sz(vec[u]);i++) {
    int v = vec[u][i];
    if(nivel[v] == -1) {
      pai[v] = u;
      nivel[v] = nivel[u] + 1;
      dfs(v);
    }
  }
}

void build(){
	memset(pai, -1, sizeof pai);
	memset(nivel, -1, sizeof nivel);
	memset(ancestral, -1, sizeof ancestral);

	nivel[1] = 0;
	dfs(1);

	for(int i=1;i<=n;i++) ancestral[i][0] = pai[i];

	for(int j=1;j<MAXL;j++){
		for(int i=1;i<=n;i++){
      if(ancestral[i][j-1] >= 0 and ancestral[i][j-1] <= n)
			ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
		}
	}
}
int LCA(int u, int v){
	if(nivel[u] < nivel[v]) swap(u, v);
	//Sobe o nivel pra deixar igual em no max logn passos
	for(int i = MAXL - 1; i>=0;i--){
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

  cin >> n >> q;
  for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  build();
  dfs(1);
  

  while(q--) {
    vector<int> aux;
    int a;
    cin >> a;
    int cam = 1, pathAtual = 0;
    for(int i=0;i<a;i++){
      int b;
      cin >> b;
      aux.push_back(b);
      if(nivel[b] > pathAtual) {
        cam = b;
        pathAtual = nivel[b];
      }
    }

    set<int> path;

    bool at = false;
    for(auto i : aux) {
      if (i == cam) continue;
      int comp = LCA(i, cam);
      if(nivel[i] - nivel[comp] > 1) at = true;
      
    }

    if(!at) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}