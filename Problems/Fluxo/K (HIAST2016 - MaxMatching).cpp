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
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 2001
#define MAXL 20
#define MOD2 998244353

struct FlowEdge{
  int v, u;
  lli cap, flow = 0;
  FlowEdge(int v, int u, lli cap) : v(v), u(u), cap(cap){}
};

struct Dinic{
  lli flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vi> adj;
  int n, m = 0;
  int s, t;
  vi level, ptr;
  queue<int> q;

  Dinic(int n, int s, int t) : n(n), s(s), t(t){
    adj.resize(n+1), level.resize(n+1), ptr.resize(n+1);
  }

  void add_edge(int v, int u, lli cap){
    edges.pb(FlowEdge(v, u, cap));
    edges.pb(FlowEdge(u, v, 0));
    adj[v].pb(m);
    adj[u].pb(m+1);
    m += 2;
  }

  bool bfs(){
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int id : adj[v]){
        if(edges[id].cap - edges[id].flow < 1) continue;
        if(level[edges[id].u] != -1) continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }

  lli dfs(int v, lli pushed){
    if(pushed == 0) return 0;
    if(v == t) return pushed;
    for(int &cid = ptr[v]; cid < sz(adj[v]);cid++){
      int id = adj[v][cid];
      int u = edges[id].u;
      if(level[v] + 1 != level[u] or edges[id].cap - edges[id].flow < 1) continue;
      lli tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if(tr == 0) continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  lli flow(){
    lli f = 0;
    while(1){
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if(!bfs()) break;
      fill(ptr.begin(), ptr.end(), 0);
      while(lli pushed = dfs(s, flow_inf)) f += pushed;
    }
    return f;
  }

};


int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n,m,w;

    cin >> n >> m >> w;

    Dinic dinic(400, 0, 310);
    vector<ii> aux;
    set<int> sol[210], place[210];

    //+100 place, +1 soldier, +200 weapon
    for(int i=0;i<n;i++){
      int nn;
      cin >> nn;
      for(int j=0;j<nn;j++){
        int a;
        cin >> a;
        aux.pb({a+100, i+1});
      }
    }

    for(int i=0;i<n;i++){
      int nn;
      cin >> nn;
      for(int j=0;j<nn;j++){
        int a;
        cin >> a;
        sol[i+1].insert(a);
      }
    }

    for(int i=0;i<m;i++){
      int nn;
      cin >> nn;
      for(int j=0;j<nn;j++){
        int a;
        cin >> a;
        place[i+101].insert(a);
      }
    }

    for(auto i : aux){
      for(auto k : place[i.F]){
        if(sol[i.S].find(k) != sol[i.S].end()){
          dinic.add_edge(i.S, i.F, 1);
          break;
        }
      }
    }
    for(int i=1;i<=n;i++) dinic.add_edge(0, i, 1);
    for(int i=1;i<=m;i++) dinic.add_edge(i+100, 310, 1);

    cout << dinic.flow() << endl;
    
  }

  return 0;
}