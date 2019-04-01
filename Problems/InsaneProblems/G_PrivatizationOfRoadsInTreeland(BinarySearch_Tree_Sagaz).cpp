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

int n, k;
vector<pair<int, int> > vec[MAXN];
int vis[MAXN];
int ans[MAXN];
int ans2[MAXN];
int vis2[MAXN];
set<int> have[MAXN];

bool solve(int atual){
  memset(vis, 0, sizeof vis);
  memset(vis2, 0, sizeof vis2);
  queue<pair<int, int>> q;
  q.push({1, 0});

  for(int i=1;i<=n;i++) have[i].clear();

  int aux = 1;
  while(!q.empty()){
    int u = q.front().F;
    int cor = q.front().S;
    q.pop();
    vis[u] = 1;

    for(auto i : vec[u]){
      int v = i.S;
      int idx = i.F;
      if(vis[v]) continue;

      if(aux == cor){
        aux++;
        if(aux > atual) aux = 1;
      }

      ans[idx+1] = aux;
      q.push({v, aux});
      if(have[u].find(aux) != have[u].end()) vis2[u]++;
      if(have[v].find(aux) != have[v].end()) vis2[v]++;
      have[u].insert(aux), have[v].insert(aux);
      aux++;
      if(aux > atual) aux = 1;
    }
  }

  int c = 0;
  for(int i=1;i<=n;i++) if(vis2[i]) c++;
  if(c <= k){
    for(int i=1;i<=n-1;i++) ans2[i] = ans[i];
    return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    vec[a].push_back({i ,b});
    vec[b].push_back({i, a});
  }

  int com = 1, fim = n;
  while(com < fim){
    int mid = (com + fim) >> 1;
    if(solve(mid)){
      fim = mid;
    } else com = mid + 1;
  }

  cout << fim << endl;
  for(int i=1;i<=n-1;i++) cout << ans2[i] << " ";
  cout << endl;

  return 0;
}