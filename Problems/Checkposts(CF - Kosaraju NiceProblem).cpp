#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
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
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n, m;
vi vec[100001], vec2[100001];

lli c[100001];
int vis[100001];
// vi tempo;
stack<int> tempo;
vector<lli> aa;

void dfs(int x){
	vis[x] = 1;
	for(int i=0;i<sz(vec[x]);i++){
		int u = vec[x][i];
		if(!vis[u]) dfs(u);
	}
	// tempo.pb(x);
	tempo.push(x);
}

void dfs2(int x){
	vis[x] = 1;
	aa.pb(c[x]);
	for(int i=0;i<sz(vec2[x]);i++){
		int u = vec2[x][i];
		if(!vis[u]) dfs2(u);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	// for(int i=1;i<=n;i++) scanf("%lld", &c[i]);
	for(int i=1;i<=n;i++) cin >> c[i];
	cin >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		// scanf("%d %d", &a, &b);
		vec[a].pb(b);
		vec2[b].pb(a);
	}

	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

	memset(vis, 0, sizeof vis);
	lli ans = 0, ans2 = 1;
	while(sz(tempo)){
		int u = tempo.top();
		// cout << "U : " << u << endl;
		tempo.pop();
		if(vis[u]) continue;
		dfs2(u);
		// sort(aa.begin(), aa.end());
		// bb.pb(aa);
		int aux2 = 0;
		lli cc = 99999999999999999;
		for(int i=0;i<sz(aa);i++) if(aa[i] < cc) cc = aa[i];
		for(int i=0;i<sz(aa);i++) if(aa[i] == cc) aux2++;
		ans += cc;
		ans2 = (ans2 * aux2)%MOD;

		aa.clear();
	}

	// printf("%lld %lld\n", ans, ans2);
	cout << ans << " " << ans2 << endl;

	return 0;
}