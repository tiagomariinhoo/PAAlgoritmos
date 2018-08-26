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
#define lli unsigned long long int
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

int n;
vi vec[200001];
int dist[200001];
int pai[200001];
vector<ii> aux;
int ans;
int vis[200001];

void dfs(int x, int p, int atual){
	vis[x] = 1;
	pai[x] = p;
	dist[x] = atual;
	aux.pb({dist[x], x});
	for(auto i : vec[x]){
		if(!vis[i]) dfs(i, x, atual+1);
	}
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for(int i=0;i<n-1;i++){
  	int a, b;
  	cin >> a >> b;
  	vec[a].pb(b);
  	vec[b].pb(a);
  	pai[a] = a, pai[b] = b;
  }

  dfs(1, 1, 0);

  sort(aux.begin(), aux.end());
  memset(vis, 0, sizeof vis);
  for(int i=sz(aux)-1;i>=0;i--){
  	if(aux[i].F <= 2) break;
  	if(vis[aux[i].S]) continue;
  	ans++;
  	vis[pai[aux[i].S]] = 1;
  	for(auto j : vec[pai[aux[i].S]]) vis[j] = 1;
  }

	cout << ans << endl;

  return 0;
}