#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 99999999999
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
typedef vector<unsigned long long int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
unsigned long long int a[5001];
unsigned long long int dp[5001][5001];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=1;i<=n;i++) dp[i][i] = a[i];

	for(int com = 2; com <= n;com++){
		for(int j = com, i = 1; j <= n;j++, i++){
			dp[i][j] = dp[i][j-1] ^ dp[i+1][j];
		}
	}

	for(int i=2;i<=n;i++){
		for(int j=i,k=1;j<=n;j++,k++){
			dp[k][j] = max(dp[k][j], max(dp[k+1][j], dp[k][j-1]));
		}
	}

	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int aa,b;
		cin >> aa >> b;
		cout << dp[aa][b] << endl;
	}

	return 0;
}