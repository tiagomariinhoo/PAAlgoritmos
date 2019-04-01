#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<int> vec[MAXN], vec2[MAXN];
int c[MAXN];
int f[MAXN];
int vis[MAXN];
int comp[MAXN];
vector<pair<int, int> > edges;

/*
Comprime a árvore e acha o diametro
Resposta: diametro+1 / 2
Para achar o diametro basta usar 2 dfs

Pega um node arbitrario e pega o node mais longe à esse (pos2)
Roda um dfs e pega o node mais longe ao pos2==root;
*/

void dfs(int x, int pai, int cor){
  vis[x] = 1;
  for(auto i : vec[x]){
    if(vis[i]) continue;
    if(c[i] == c[x]){
      dfs(i, pai, cor);
    } else {
      edges.push_back({pai, i});
      dfs(i, i, c[i]);
    }
  }
}

void compress(){

  set<int> aux;
  int a = 1;
  for(auto i : edges) aux.insert(i.F), aux.insert(i.S);
  for(auto i : aux) comp[i] = a++;

  for(int i=0;i<edges.size();i++){
    edges[i].F = comp[edges[i].F];
    edges[i].S = comp[edges[i].S];
  }
}

int aa, pos;

void dfs2(int x, int pai, int dis){
  if(dis > aa) aa = dis, pos = x;
  for(auto i : vec2[x]){
    if(i == pai) continue;
    dfs2(i, x, dis+1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++) cin >> c[i];

  for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  dfs(1, 1, c[1]);
  compress();

  int nn = edges.size() + 1;
  for(auto i : edges){
    vec2[i.F].push_back(i.S);
    vec2[i.S].push_back(i.F);
  }

  dfs2(1, 1, 0);

  aa = 0;
  dfs2(pos, pos, 0);
  cout << (aa + 1)/2 << endl;

  return 0;
}