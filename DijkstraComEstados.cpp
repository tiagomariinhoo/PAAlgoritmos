/*
	Dijkstra tentando fazer com que
	passe em m arestas, tal que m%2==0
*/

#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define MAX 11000
#define MAXN 120
#define MIN -2000000
#define INF 0x3f3f3f3f
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<int, ii > iii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
int n,m;
vector < ii > adj[MAX];
ii dist[MAX];

void dijk(int v){
	dist[v].F = 0;
	priority_queue<ii , vector<ii> , greater<ii> > pq;
	pq.push(mp(dist[v].F, v));
	int u;

	while(!pq.empty()){
		u = pq.top().S;
		pq.pop();
			for(ii p : adj[u]){
				if(dist[u].F + p.F < dist[p.S].S){
					dist[p.S].S = dist[u].F + p.F;
					pq.push(mp(dist[p.S].S , p.S));
				}

				if(dist[u].S + p.F < dist[p.S].F){
					dist[p.S].F = dist[u].S + p.F;
					pq.push(mp(dist[p.S].F, p.S));
				}
			}
	}

}

int main(){
	cin >> n >> m;

	for(int i=0;i<=n;i++){
		dist[i].F = INF;
		dist[i].S = INF;
	}

	for(int i=0;i<m;i++){
		int a,b,c;
			cin >> a >> b >> c;
				adj[a].pb(mp(c,b));
				adj[b].pb(mp(c,a));
	}

	dijk(1);

	if(dist[n].F == INF) cout << "-1" << endl;
	else cout << dist[n].F << endl;

	return 0;
}