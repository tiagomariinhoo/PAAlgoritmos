#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
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
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
vector<ii> vec[10001];
int vis[10001][2];
lli ans = MAXLL;
lli dist[10001][2];

/*
	vis[u][0] == par
	vis[u][1] == impar
*/

void dijk(int x){
	priority_queue< pair<int, ii>, vector<pair<int, ii> > , greater<pair<int,ii>> > q;
	q.push({x,{0,0}});
	dist[x][0] = 0, dist[x][1] = INF;

	while(!q.empty()){
		int u = q.top().F;
		int qt = q.top().S.F;
		q.pop();

		for(auto i : vec[u]){
			int v = i.S;
			if(qt%2==0){
				if(dist[v][1] > dist[u][0] + i.F){
					dist[v][1] = dist[u][0] + i.F;
					q.push({v, {qt+1, dist[v][1]}});
				}
			} else {
				if(dist[v][0] > dist[u][1] + i.F){
					dist[v][0] = dist[u][1] + i.F;
					q.push({v, {qt+1, dist[v][0]}});
				}
			}
		}
	}

	if(dist[n][0] == MAXLL) cout << -1 << endl;
	else cout << dist[n][0] << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].pb({c,b});
		vec[b].pb({c,a});
	}


	for(int i=1;i<=n;i++) for(int j=0;j<=1;j++) dist[i][j] = INT_MAX;

	dijk(1);

	return 0;
}
