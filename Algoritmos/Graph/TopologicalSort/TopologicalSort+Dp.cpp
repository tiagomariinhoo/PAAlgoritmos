#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 500
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
// #define lli unsigned long long int
#define lb long double
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//ios_base::sync_with_stdio(false);
//g++ -std=c++11 sol.cpp -o sol.exe && sol.exe < in.txt > output.txt
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
int grau[300002];
vi vec[300002];
int dp[300002][30];
int esp[300002];
string s;

int main(){
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		grau[b]++;
		vec[a].pb(b);
	}

	for(int i=0;i<sz(s);i++){
		esp[i+1] = s[i] - 'a';
		dp[i+1][s[i]-'a'] = 1;
	}
	
	queue<int> q;
	for(int i=1;i<=n;i++) if(!grau[i]) q.push(i);

	int a = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i];
			grau[v]--;
			for(int j='a';j<='z';j++){
				if(j-'a' == esp[v]){
					dp[v][j-'a'] = max(dp[v][j-'a'], dp[u][j-'a']+1);
				} else dp[v][j-'a'] = max(dp[v][j-'a'], dp[u][j-'a']);
			}
			if(!grau[v]) q.push(v);
		}
		a++;
	}

	if(a != n){
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j='a';j<='z';j++) ans = max(ans, dp[i][j-'a']);
	}

	cout << ans << endl;

	return 0;
}
