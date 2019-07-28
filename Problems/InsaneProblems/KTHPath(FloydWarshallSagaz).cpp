#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define MOD2 (lli) 998244353  
#define lli long long int
#define sz(a) int(a.size())
#define M_PI 3.1415
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};
 
/*
K = 400
Ordena as arestas e gera um novo grafo só com essas arestas
Tem 800 nodes e 400 arestas no maximo
Floyd warshall
5 * 10^8, passa no tempo de 2s
 */

int n, m, k;
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n >> m >> k;
 
  vector<pair<lli, pair<int, int> > > edges;
  for(int i=0;i<m;i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c, {a, b}});
  }
 
  sort(edges.begin(), edges.end());
 
  set<int> aux;
  vector<int> vert;
  for(int i=0;i<min(m, k);i++){
    aux.insert(edges[i].S.S);
    aux.insert(edges[i].S.F);
  }
 
  for(auto i : aux) vert.push_back(i);
  sort(vert.begin(), vert.end());
 
  lli vec[1000][1000];
  
  for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) vec[i][j] = 1e15;
 
  for(int i=0;i<1000;i++) vec[i][i] = 0;
 
  for(int i=0;i<min(m, k);i++){
    int x = lower_bound(vert.begin(), vert.end(), edges[i].S.F) - vert.begin();
    int y = lower_bound(vert.begin(), vert.end(), edges[i].S.S) - vert.begin();
    vec[x][y] = vec[y][x] = min(vec[x][y], edges[i].F);
  }
 
  for(int kk = 0; kk < sz(vert); kk++){
    for(int i=0;i<sz(vert);i++){
      for(int j=0;j<sz(vert);j++){
        vec[i][j] = min(vec[i][j], vec[kk][i] + vec[j][kk]);
      }
    }
  }
 
  vector<lli> ans;
  for(int i=0;i<sz(vert);i++){
    for(int j=i+1;j<sz(vert);j++){
      ans.push_back(vec[i][j]);
    }
  }
 
  sort(ans.begin(), ans.end());
 
  cout << ans[k-1] << endl;
 
  return 0;
}