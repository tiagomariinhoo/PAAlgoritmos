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

int n,a,b;
int ans[1001][1001];
vi vec[1001];
int vis[1001];

void dfs(int u){
	vis[u] = 1;
	for(auto i : vec[u]){
		int v = i;
		if(!vis[v]){
			ans[v][u] = 1;
			ans[u][v] = 1;
			dfs(v);
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> a >> b;


	if(min(a,b) > 1 or (n<=3 and n >= 2 and a == 1 and b == 1)){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	if(a == 1 and b == 1){
		for(int i=1;i<=n-1;i++) ans[i][i+1] = 1, ans[i+1][i] = 1;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout << ans[i][j];
				cout << endl;
		}
		return 0;

	}

	if(a == 1){

		for(int i=1;i<=n-b;i++){
			ans[i][i+1] = 1;
			ans[i+1][i] = 1;
		}
		for(int i=1;i<=n;i++) ans[i][i] = 1;

		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[i][j] ^= 1;

		// for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout << ans[i][j];
				cout << endl;
		}

	} else {
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n-a+1;j++){
		// 		if(i == j) continue;
		// 		ans[i][j] = 1;
		// 		ans[j][i] = 1;
		// 	}
		// }
		for(int i=1;i<=n-a;i++){
			ans[i][i+1] = 1;
			ans[i+1][i] = 1;
		}

		// for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout << ans[i][j];
				cout << endl;
		}
	}


	


	return 0;
}
