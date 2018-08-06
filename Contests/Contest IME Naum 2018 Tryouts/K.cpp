#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
vector<ii> vec[100001];
int dist[100001][3];

void dijk(int x){
	priority_queue< pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii>>> q;

	q.push({0, {0, x}});
	dist[x][0] = 0, dist[x][1] = 9999999, dist[x][2] = 9999999;

	while(!q.empty()){
		int u = q.top().S.S;
		int qt = q.top().S.F;
		q.pop();

		for(auto i : vec[u]){
			int v = i.S;
			int r = qt%3;
			if(r==0){
				if(dist[v][1] > dist[u][0] + i.F){
					dist[v][1] = dist[u][0] + i.F;
					if(v != n){
					q.push({dist[v][1], {qt+1, v}});
					}
				}
			} else if(r==1){
				if(dist[v][2] > dist[u][1] + i.F){
					dist[v][2] = dist[u][1] + i.F;
					if(v != n){
						q.push({dist[v][2], {qt+1, v}});
					}
				}
			} else if(r==2) {
				if(dist[v][0] > dist[u][2] + i.F){
					dist[v][0] = dist[u][2] + i.F;
					if(v != n){
						q.push({dist[v][0], {qt+1, v}});
					}
				}
			}
		}
	}

	vector<pair<int, string>> ans;
	ans.pb({dist[n][0], "me"});
	ans.pb({dist[n][1], "Gon"});
	ans.pb({dist[n][2], "Killua"});

	sort(ans.begin(), ans.end());

	for(int i=0;i<sz(ans);i++) cout << ans[i].S << endl;
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].pb({c, b});
		vec[b].pb({c, a});
	}
	memset(dist, 9999999, sizeof dist);

	dijk(1);

	return 0;
}