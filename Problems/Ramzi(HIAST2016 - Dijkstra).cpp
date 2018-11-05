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
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001
#define MAXL 20
#define MOD2 998244353

int t;
int n,m;
vector<pair<int, ii> > vec[101];
ii dis[101];
int x, y;


void solve(){
	priority_queue<pair<int,ii>, vector<pair<int,ii>>, greater<pair<int,ii>>> pq;
	dis[x].F = 0, dis[x].S = 0;
	pq.push({0,{0,x}});

	while(!pq.empty()){
		int u = pq.top().S.S;
		pq.pop();

		for(auto i : vec[u]){
			int type = i.S.S;
			int d = i.S.F;
			int v = i.F;

			if(type == 1){
				// cout << "Type 1 :" << endl;
				// cout << u << " - " << v << endl;
				// cout << dis[u].F << " -- " << dis[v].F << endl;
				if(dis[v].F > dis[u].F + d){
					dis[v].F = dis[u].F + d;
					dis[v].S = dis[u].S;
					pq.push({dis[v].F,{dis[v].S, v}});
				} else if(dis[v].F == dis[u].F + d){
					if(dis[u].S < dis[v].S){
						dis[u].S = dis[v].S;
						pq.push({dis[v].F,{dis[v].S, v}});
					}
				}
			} else {
				// cout << "Type 2 :" << endl;
				// cout << u << " - " << v << endl;
				// cout << dis[u].F << " -- " << dis[v].F << endl;
				if(dis[v].F > dis[u].F){
					dis[v].F = dis[u].F;
					dis[v].S = dis[u].S + d;
					pq.push({dis[v].F,{dis[v].S, v}});
				} else if(dis[v].F == dis[u].F){
					if(dis[v].S > dis[u].S + d){
						dis[v].S = dis[u].S + d;
						pq.push({dis[v].F,{dis[v].S, v}});
					}
				}
			}
		}
	}

	if(dis[y].F != 1e9 and dis[y].S != 1e9) cout << dis[y].F << " " << dis[y].F + dis[y].S << endl;
	else cout << -1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while(t--){
  	cin >> n >> m;
  	for(int i=0;i<=n;i++) vec[i].clear(), dis[i].F = 1e9, dis[i].S = 1e9;
  	for(int i=0;i<m;i++){
  		int a, b, c, d;
  		cin >> a >> b >> c >> d;
  		vec[a].pb({b, {c, d}});
  		vec[b].pb({a, {c, d}});
  	}

  	cin >> x >> y;


  	solve();
  }

    return 0;
}