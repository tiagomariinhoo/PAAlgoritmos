#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<lli, lli> iil;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
int mat[15][15];
int c[15][15];
vector<ii> vec[150];
int dist[150];
int marc[150];

void cons(int x, int y){
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 and xx < n and yy >= 0 and yy < m){
			if(mat[xx][yy] == 1 or mat[xx][yy] == 0 or mat[xx][yy] == 3){
				int a = c[xx][yy];
				int b = c[x][y];
				vec[a].pb({1, b});
			}
		}
	}
}

void dijk(int x){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0, x});
	dist[x] = 0;

	while(!pq.empty()){
		int u = pq.top().S;
		pq.pop();
			for(int i=0;i<sz(vec[u]);i++){
				ii v = vec[u][i];
				if(dist[v.S] > dist[u] + v.F){
					dist[v.S] = dist[u] + v.F;
					pq.push({dist[v.S], v.S});
				}
			}	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i=0;i<150;i++) dist[i] = 999999;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin >> mat[i][j];
	}
	int com = 0;
	int cnt = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			c[i][j] = cnt++;
			if(mat[i][j] == 3) com = c[i][j];
			if(mat[i][j] == 0) marc[c[i][j]] = 1;
		}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cons(i, j);
		}
	}

	dijk(com);

	int ans = 99999;
	for(int i=0;i<=n*m;i++){
		if(dist[i] < ans and marc[i]) ans = dist[i];
	}


	cout << ans << endl;

	return 0;
}