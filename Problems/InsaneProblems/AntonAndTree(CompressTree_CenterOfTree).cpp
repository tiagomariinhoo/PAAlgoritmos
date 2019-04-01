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

/*
  Dada uma árvore
  Pintar todo o conjunto de um node, tal que todos os nodes
  que ele alcança, tem a cor igual a ele

  Basta comprimir a árvore para deixar apenas um node ligado de cada cor

  A resposta é o centro da árvore comprimida

  Para pegar o centro da árvore comprimida, basta pegar
  as folhas da árvore (f[i] == 1) e colocar em uma fila
  ao pegar ela e tirar as arestas, se o que sobrou for folha
  bota na fila, o último node, é o centro.
*/

int n;
vector<int> vec[MAXN], vec2[MAXN];
int c[MAXN];
int f[MAXN];
int vis[MAXN];
int comp[MAXN];
vector<pair<int, int> > edges;

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

int dfs2(int x, int pai){
  int a = 0;
  for(auto i : vec2[x]){
    if(i == pai) continue;
    a = max(a, dfs2(i, x) + 1);
  }
  return a;
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
    f[i.F]++, f[i.S]++;
  }
  queue<int> q;
  for(int i=1;i<=nn;i++) if(f[i] == 1) q.push(i);

  int root;

  if(!sz(q)){
    cout << 0 << endl;
    return 0;
  }

  while(!q.empty()){
    root = q.front();
    q.pop();
    for(auto i : vec2[root]){
      f[i]--;
      if(f[i] == 1) q.push(i);
    }
  }

  cout << dfs2(root, root) << endl;

  return 0;
}