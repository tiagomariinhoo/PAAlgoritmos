#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 1e5 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int
typedef pair<lli, pair<lli, lli> > iii;

int n, m;
vector<iii> vec[MAXN];
pair<lli, lli> dist[MAXN];
lli pai[MAXN];
lli ans = 0;

void dijkstra(int atual = 1){
  dist[atual].F = 0, dist[atual].S = 0;
  priority_queue<iii, vector<iii>, greater<iii> > pq;
  pq.push({0,{0, atual}});

  for(int i=1;i<=n;i++) pai[i] = LLONG_MAX;
  pai[1] = 0;

  while(!pq.empty()){
    int u = pq.top().S.S;
    pq.pop();
    for(auto i : vec[u]){
      int v = i.S.S;
      lli l = i.F;
      lli c = i.S.F;

      if(dist[v].F > dist[u].F + l){
        dist[v].F = dist[u].F + l;
        dist[v].S = dist[u].S + c;
        pai[v] = c;
        pq.push({dist[v].F,{dist[v].S, v}});
      } else if(dist[v].F == dist[u].F + l){
        if(c < pai[v]){
          dist[v].S = dist[u].S + c;
          pai[v] = c;
          pq.push({dist[v].F,{dist[v].S, v}});
        }
      }
    }
  }

  for(int i=2;i<=n;i++) ans += pai[i];
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vec[a].push_back({c, {d, b}});
    vec[b].push_back({c, {d, a}});
  }

  for(int i=1;i<=n;i++) dist[i].F = dist[i].S = LLONG_MAX;

  dijkstra();

  return 0;
}