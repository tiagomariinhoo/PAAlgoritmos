#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 1e5 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int

int n;
vector<int> vec[MAXN];
int vis[MAXN];

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  queue<pair<int, pair<int, long double> > > q;
  q.push({1, {0, 1}});

  long double ans = 0;
  int qt = 0;
  while(!q.empty()){
    int u = q.front().F;
    long double dist = q.front().S.S;
    int nv = q.front().S.F;
    vis[u] = 1;
    q.pop();

    bool at = false;
    long double aux = 0;
    // cout << u << " " << dist << endl;
    for(auto i : vec[u]){
      if(vis[i]) continue;
      aux++;
    }
    for(auto i : vec[u]){
      if(vis[i]) continue;
      q.push({i, {nv+1, 1/aux * dist}});
      at = true;
    }
    if(!at) ans += (dist)*nv, qt++;
  }

  printf("%.15Lf", ans);


  return 0;
}