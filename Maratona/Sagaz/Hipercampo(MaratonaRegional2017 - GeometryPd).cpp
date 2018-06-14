#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX INT_MAX
#define MAXLL LLONG_MAX
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

#define pdd pair<double, double>

int n;
pdd x1, x2;
vector<int> vec[150];
pdd graph[150];
int vis[150];

int dp[150];

pdd lineIntersection(pdd A, pdd B, pdd C, pdd D){
	double a1 = B.S - A.S;
	double b1 = A.F - B.F;
	double c1 = a1*(A.F) + b1*A.S;

	double a2 = D.S - C.S;
	double b2 = C.F - D.F;
	double c2 = a2*C.F + b2*C.S;

	double det = a1*b2 - a2*b1;
	if(det == 0){
		return {FLT_MAX, FLT_MAX};
	} else {
		double x = (b2*c1 - b1*c2)/det;
		double y = (a1*c2 - a2*c1)/det;
		return {x,y};
	}
}

bool check(pdd a, pdd b){
	pdd aa = lineIntersection(a, x1, b, x2);
	pdd bb = lineIntersection(a, x2, b, x1);
	if(a.S <= b.S){
		if(aa.S > a.S and bb.S > a.S) return true;
	} else {
		if(aa.S > b.S and bb.S > b.S) return true;
	}
	return false;
}

int dfs(int x, int a){
	if(dp[x] != -1) return dp[x];

	int aa = 1;
	vis[x] = 1;
	for(int i=0;i<sz(vec[x]);i++){
		int u = vec[x][i];
		aa = max(aa, dfs(u, a) + 1);
	}
	return dp[x] = aa;
}

bool comp(pdd a, pdd b){
	return a.S > b.S;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double aa, bb;
	cin >> n;
	cin >> aa >> bb;
	
	memset(dp, -1, sizeof dp);

	x1 = {aa, 0}, x2 = {bb, 0};

	for(int i=0;i<n;i++){
		double a,b;
		cin >> a >> b;
		graph[i] = {a,b};
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j) continue;
			if(graph[i].S > graph[j].S){
				if(check(graph[i], graph[j])) vec[i].pb(j);
			}
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, dfs(i, 1));
	}

	cout << ans << endl;

	return 0;
}
