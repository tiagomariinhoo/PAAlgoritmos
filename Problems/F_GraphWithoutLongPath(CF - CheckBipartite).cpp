#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int n, m;
vector<int> vec[MAXN];
map<pair<int, int>, int> visEdge, edge;
int vis[MAXN];
int saida[MAXN];
int cor[MAXN];

// void dfs(int x){
//   vis[x] = 1;
//   for(auto i : vec[x]){
//     if(saida[x] == saida[i]){
//       cout << "NO" << endl;
//       exit(0);
//     }
//     if(vis[i]) continue;
//     if(saida[x] == 1){
//       saida[i] = 2;
//       if(visEdge[{x, i}]) edge[{x,i}] = 1;
//       else if(visEdge[{i, x}]) edge[{i, x}] = 0;
//       dfs(i);
//     } else {
//       saida[i] = 1;
//       if(visEdge[{x, i}]) edge[{x,i}] = 0;
//       else if(visEdge[{i, x}]) edge[{i, x}] = 1;
//       dfs(i);
//     }
//   }
// }

void dfs(int x){
  vis[x] = 1;
  for(auto i : vec[x]){
    if(vis[i]) continue;
    if(cor[x] == cor[i]){
      cout << "NO" << endl;
      exit(0);
    }
    if(cor[x] == 1) cor[i] = 2;
    else cor[i] = 1;
    dfs(i); 

  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  vector<pair<int, int> > aux;
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    aux.push_back({a, b});
    vec[a].push_back(b);
    vec[b].push_back(a);
    visEdge[{a, b}] = 1;
  }

  int root;
  int xd = 0;
  for(int i=1;i<=n;i++){
    if(vec[i].size() > xd) xd = sz(vec[i]), root = i;
  }

  saida[root] = 1;
  cor[root] = 1;
  dfs(root);

  for(auto i : aux){
    if(cor[i.F] == cor[i.S]){
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  for(auto i : aux){
    int u = i.F, v = i.S;
    if(cor[u] == 1 and cor[v] == 2){
      cout << 1;
    } else if(cor[u] == 2 and cor[v] == 1){
      cout << 0;
    } else {
    }

  }
  cout << endl;
  // for(int i=0;i<sz(aux);i++){
    // cout << edge[aux[i]];
  // } cout << endl;



  return 0;
}