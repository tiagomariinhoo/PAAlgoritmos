#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 9999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) (lli)(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
 
int vec[101][101];
int e,t,m,n;
 
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
			}
		}
	}
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> e >> t >> m;
 
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) vec[i][j] = INF;
 
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		vec[a][b] = c;
	}
	floyd();
 
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(i == e) continue;
		// cout << i << " - " << e << " : " << vec[i][e] << endl;
		if(vec[i][e] <= t) ans++;
	}
 
	cout << ans + 1<< endl;
 
	return 0;
} 