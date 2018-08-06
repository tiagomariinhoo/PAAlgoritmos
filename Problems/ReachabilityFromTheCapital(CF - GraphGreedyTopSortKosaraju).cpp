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
typedef vector<int> vi;
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

int n,m,s;
vi vec[5001];
int vis[5001];
int pd[5001];
int grau[5001];
vi aa;

int dfs(int x, bool at){
	vis[x] = 1;
	if(at) aa.pb(x);
	int aux = 0;

	for(auto i : vec[x]){
		if(!vis[i]) aux += dfs(i, at) + 1;
	}
	return pd[x] = aux;
}

bool comp(ii a, ii b) { return a.F > b.F; }

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> s;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		vec[a].pb(b);
		grau[b]++;
	}

	dfs(s, true);
	sort(aa.begin(), aa.end());
	int ans = 0;
	vector<ii> can;
	memset(vis, 0, sizeof vis);
	for(int i=1;i<=n;i++){
		// if(!vis[i]){
			can.pb({dfs(i, false)+1, i});
			memset(vis, 0, sizeof vis);
		// }
	}

	sort(can.begin(), can.end(), comp);
	for(int i=1;i<=n;i++) if(!grau[i] and i != s){
		dfs(i, false);
		ans++;
	}

	for(int i=0;i<sz(can);i++){
		int u = can[i].S;
		if(!vis[u] and !binary_search(aa.begin(), aa.end(), u)){
			ans++;
			dfs(u, false);
		}
	}

	cout << ans << endl;

	return 0;
}