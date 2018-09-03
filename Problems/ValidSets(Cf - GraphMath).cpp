#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100001
#define MAXL 20
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001

int n, d;
vi vec[MAXN];
lli c[MAXN], f[MAXN];
int vis[MAXN];

void dfs(int x, int root){
	vis[x] = 1;

	f[x]++;
	for(auto i : vec[x]){
		if(vis[i]) continue;
		if(c[i] < c[root] or c[i] > c[root] + d) continue;
		if(c[i] == c[root] and i < root) continue;
		dfs(i, root);
		f[x] = (f[x] * (f[i] + 1))%MOD;
	}
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> d >> n;
  for(int i=1;i<=n;i++) cin >> c[i];
  	for(int i=0;i<n-1;i++){
  		int a, b;
  		cin >> a >> b;
  		vec[a].pb(b);
  		vec[b].pb(a);
  	}

  	lli ans = 0;
  	for(int i=1;i<=n;i++){
  		for(int j=1;j<=n;j++) vis[j] = 0, f[j] = 0;
  		dfs(i, i);
  		ans = (ans + f[i])%MOD;
  	}

  	cout << ans << endl;

  return 0;
}